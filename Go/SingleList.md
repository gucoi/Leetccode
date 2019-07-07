# 使用go语言创建单向链表

说明一下go单向链表结构的特点，比之C++/C多引入了一个size，引入size更加容易判断长度大小，也可以不引入（直接对其判断是否到达nil）。

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

可以看到我们上面引入了Add方法，实参为多参数，废话不多说 把想象中的Add方法整出来

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

然后我们开始想删除某个节点

```go
    func (list *List)Remove(index int)bool{
        preElement:=list.first
        lastElement:=list.first.next
        for index--;index>0;index--{
            if lastElement==nil{
                return false
            }
            lastElement=lastElement.next
            preElement=preElement.next;
        }
        preElement.next=lastElement.next
    }
```

这个
**乍一写没有内存释放的程序还挺不习惯的哈 if后面没有括号也挺不方便的**

写完之后有感觉总是还缺点什么东西 哦 原来是头插入

```go
    func (list *List) HeadAdd(value interface{}) {
        e := &element{value: value}
        var temp *element
        temp = list.first
        list.first = e
        list.first.next = temp
        list.size++
    }

```

来搞个查找函数

```go
    func (list *List)Find(value interface{})(bool,int){
        for i,e:=0,list.first;i!=list.size;e,i=e.next,i+1{
            if e.val==value{
                return true,i
            }
        }
        return false,list.size
    }
```

紧接着我们想写一下 插入函数 主要逻辑和链表的插入函数相同

```go
    func (list *List)Insert(value interface{},int index)bool{
        if list.size>index{
            return false
        }
        tem:=&element{value:value}
        if list.size-1==index{
            list.last.next=tem
            list.last=tem
            list.size++
            return true
        }
        e:=list.first
        for i:=0;i!=list.size;i,e=i+1,e.next{
        }
        preNode:=e
        e.next=tem
        tem.next=preNode.next.next
        return true
    }
```

然后这样我们就感觉相对来讲比较完美，但也只是相对来讲，我们还缺很多东西，那些东西后面再补，起码我们把总体的框架搭建了起来
