# golang学习笔记

## 引用类型

golang中只有引用，值两种类型。切片slice，字典map，管道channel三种引用类型
其他的都是值类型（数组也是值类型）

用切片传数组参数，既可以达到节约内存的目的，也可以达到合理处理好共享内存的问题。

## go中数组和切片传参

数组作为参数传递时，传递的是值，切片作为参数传递时，传递的是地址值，所以数组中的值是不可更改的，但是切片中的值可以修改

```Go
    func changea(array [3]int)[3]int{
        array[0]=0
        return array
    }
    func changes(slice []int)[]int{
        slice[0]=0
        return slice
    }
    func main(){
        s:=[]int{1,2,3}
        a:=[3]int{1,2,3}
        changea(a)
        changes(s)
        fmt.Println(a)// 1,2,3
        fmt.Println(s)//0,2,3
    }
```

## go中的break可以用lable

* break用于select
  break跳出一个select循环

  ```Go
    select{
        <-case:
            fmt.Println("This case is selected")
            break
        default:
            fmt.Println("This is the default case.")
    }
  ```

* break用于嵌套循环
  在 switch 或 select 语句中，break语句的作用结果是跳过整个代码块，执行后续的代码。但是嵌套循环时，只会跳出最内层的循环，最外层的for循环还是一直在跑。要想跳出最外层的循环可以在 break 后指定标签。用标签决定哪个循环被终止。

  ```Go
        stopLable:
        for {
            time.Sleep(p.Cfg.WatchInterval)
        select {
            case <-ctx.Done():
                return
            default:
                err := p.watchSomeThing(ctx)
                if err != nil {
                    p.Error(zap.Error(errors.Wrap(err, "watch something")))
                    //continue
                    break stopLable//TODO:临时修改
                }
            }
        }
  ```
  
## golang切片扩容的探讨

1. 切片每次新增个数不超过原来的1倍，且每次增加数不超过1024个，且增加后总长度小于1024个，这种情况下扩容为原来的2倍。
2. 切片一次新增个数超过原来的1倍，但不超过1024个，且增加后总长度小于1024个，这种情况下扩容后比实际具有有的总长度还要大一些
3. 原切片长度超过1024，一次增加容量不是2倍而是0.25倍，每次超过预定的都是0.25累乘

## go中的map为hash，每次遍历时的顺序不一定一致

## go中异常处理

go中可以抛出异常，然后再`defer`中通过`recover`捕获这个异常，然后再正常处理，如果同时有多个`defer`，那么异常会被最近的`recover`捕获并正常处理，`recover`必须在`defer`函数中运行，多层嵌套依然无效，必须在`defer`中直接调用才有效

```Go
func test(){
    defer func(){
        fmt.Println("打印前")
    }()
    defer func(){//必须先声明defer 否则不能 recover
        if err:=recover();err!=nil{
            fmt.Println(err)
        }
        fmt.Println("打印中")
    }()
    defer func(){
        fmt.Println("打印后")
    }()
    panic("触发异常")
}
```

## go如何对json数据进行处理

```Go

type student struct {
    Name string//注意这里属性需要大写，因为json.Unmarshal是在其他文件中填入这个属性值的，需要将其设置为public的
}

func main() {
    js := `{
        "name":"11"
    }`
    var p student
    err := json.Unmarshal([]byte(js), &p)
    if err != nil {
        fmt.Println("err", err)
        return
    }
    fmt.Println("p", p)
}

```

## 代码问题

```Go
type People struct {
    Name string
}

func (p *People) String() string {
    return fmt.Sprintf("print: %v", p)
}

func main() {
    p := &People{}
    p.String()
}
//因为%v调用的就是String()方法，无限递归，最后栈溢出
```

## go中为空的变量

当为变量赋nil值时，变量必须有类型，interface{} error都行，
string为空是""，不是nil

## go中没有前置自加自减，只可以后置自加和自减

## 观察代码

```Go
    package main

import "fmt"

type query func(string) string

func exec(name string, vs ...query) string {
	ch := make(chan string)
	fn := func(i int) {
		ch <- vs[i](name)
	}
	for i, _ := range vs {
		go fn(i)
		if v, ok := <-ch; ok {
			return v
		}
	}
	return ""
}
func main() {
	ret := exec("111", func(name string) string {
		return name + "func1"
	}, func(name string) string {
		return name + "func2"
	}, func(name string) string {
		return name + "func3"
	})
	fmt.Println(ret)
}

```

## go中rune切片

go中rune切片针对于汉字utf-8来说的

```Go
    a := "abc我爱你"
    s := []rune(a)
    fmt.Printf("%c\n", s[3])
    fmt.Printf("%c", a[3])
```

## go中make切片中len()和cap()的差别

1. `cap`表示底层数组的大小，`len`是你可以使用的大小。
2. 容量的用处在哪？用append扩展长度时，如果新的长度小于容量，不会更换底层数组，否则，go会申请一个底层数组，拷贝这边的值过去，把原来的数组丢掉。
3. 长度是为了帮助你限制切片可用成员的数量，提供边界查询的，make申请好空间后，不要越界，也就是越`len`

## 如何正确地 抛出 错误 和异常(error/panic/recover)

**错误是业务过程的一部分，而异常不是。**，Golang中引入error接口类型作为错误处理的标准模式，如果函数要返回错误，则返回值类型列表中肯定包含error。error处理过程类似于C语言中的错误码，可逐层返回，直到被处理。
Golang中引入两个内置函数`panic`和`recover`来触发和终止异常处理流程，同时引入关键字`defer`来延迟执行`defer`后面的函数。

## 异常处理的场景

1. 空指针引用
2. 下标越界
3. 除数为0
4. 不应该出现的分支，比如`default`
5. 输入不应该引起函数错误

对于异常，我们可以选择在一个合适的上游去recover，并打印堆栈信息，是的部署后的程序不会终止。

## defer的闭包调用

如果遇到defer的闭包调用，则压入堆栈，当函数返回时，会按照后进先出的顺序调用闭包。

对于闭包的参数是 值传递，而对于外部变量却是 引用传递，所以闭包中的外部变量 err 的值就变成外部函数返回时最新的 err 值。

## recover

运行时恐慌一旦被引发，就会向调用方传播直至程序崩溃。Go 提供了专用于“拦截”运行时恐慌的内建函数 recover，它可以使当前的程序从恐慌状态中恢复并重新获得流程控制权。recover 函数被调用后，会返回一个 interface{} 类型的结果。如果当时的程序正处于运行时恐慌的状态，那么这个结果就会是 非 nil 的。

## panic

该函数用于停止当前的控制流程并引发一个运行时恐慌。它可以接受一个任意类型的参数值，不过这个参数值的类型常常会是 string 或者 error，因为这样更容易描述运行时恐慌的详细信息。请看下面的例子

panic 异常处理机制不会自动将错误信息传递给 error，所以要在 funcA 函数中进行显式的传递，
