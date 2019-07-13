# 搭建双向链表

双向链表特点：节点可以前后移动，比单向链表增加了灵活性，但是插入，删除节点的时间复杂度和单向链表是一样的。

双向链表结构体
>element
>>pre next val

代码

```go
    type element struct{
        pre *element
        next *element
        val interface{}
    }
```

>List
>>first last size

代码

```go
    type List struct{
        first *List
        last *List
        size int
    }
```

## New

```go
    func New(values ...interface{}) *List {
        var list = &List{}
        if len(values) > 0 {
            list.Add(values...)
        }
        return list
    }
```

## Add

```go
        //Add appends a value at the end of the list
    func (list *List) Add(values ...interface{}) {
        for _, val := range values {
            newElement := &element{value: val, pre: list.last, next: nil}
            if list.size == 0 {
                list.first = newElement
                list.last = newElement
            } else {
                list.last.next = newElement
                list.last = newElement
            }
            list.size++
        }
    }

```

## 后面再补齐