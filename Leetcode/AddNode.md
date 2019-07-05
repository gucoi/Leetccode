# 使用go语言创建链表并增加链表的节点

说明一下数据结构的特点 因为go中的指针元素无法判定是否为空 所以只能采用增加size参数用来限制大小

[并且本篇文章借鉴了GitHub上很好的数据结构源码](https://github.com/emirpasic/gods/)
>List
>>first(element*) last(element*) size(int)

对elemen元素进行构图

>element
>>next(element*) val(interface{})

然后开始代码声明

List的结构体

```go
    type List struct{
        first *element
        last *element
        size int
    }
```

Element的结构体

```go
    type element struct{
        next *element
        value interface{}
    }
```

开始主要的算法 新建链表结构

```go
    func New(values ...interface{})*List{
        list:=&List{}
        if values.size==0{
            return list
        }
        else
            list.Add(values)
    }
```

可以看到我们上面引入了Add方法，参数为多参数，废话不多说 把想象中的Add方法整出来

```go
    func (list *List)Add(values ...interface){
        for _,val=range values{
            newTem:=&element{value:val}
            if list.size==0{
                list.first=newTem
                list.last=newTem
            }
            else{
                list.last.next=newTem
                list.last=newTem
                //为了方便理解也可以写成这样
                //list.last=list.last.next
            }
        }
    }
```

但是我们尽管有了能够放东西进去的算法，我们还想让他输出来瞧瞧看看是不是我们想要加进去的东西 接着我们就开始写了一个Display方法

```go
    func (list *List)Display(){
        element:=list.first
        for e:=0;e<list.size;e,element=e+1,element.next{
            fmt.Printf("element e: %d \n",e,element.val)
        }
    }
```

这样我们就感觉相对来讲比较完美，但也只是相对来讲，我们还缺很多东西，那些东西后面再补，起码我们把总体的框架搭建了起来
