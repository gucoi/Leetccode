# 搭建ArrayList数据结构 

结构图
>List
>>element (interface{}),size

翻译成代码就是

```go
    type List struct{
        element []interface{}
        size int
    }
```

为了能够写成C++的STL中的vector动态数组相似的在这里引入了两个常量控制增长倍数和收缩倍数

```go
    const (
        growthFactor=float32(2.0)
        shrinkFactor=float32(0.25)
    )
```

这个是方法的图表

## New

等到这些前提都写好了,我们就可以开始写所需要的各种方法 第一个是New方法（新建一个列表）

```go
    func New(values ...interface{})(*List){
        list:=&List{}
        if values.size==0
            return list
        return list.Add(values...)
    }
```

这里引入了Add方法,不是因为其他的，可能是我已经习惯了这种写法了吧，也可以按你们习惯来，只要能够搭建起来就可以

## Add

```go
   func (list *List) Add(values ...interface{}) {
        list.gorwBy(len(values))
        for _, v := range values {
            list.element[list.size] = v
            list.size++
        }
    }
```

## growBy

```go
    func (list *List) growBy(n int) {
        currentCapacity := cap(list.element)
        if list.size+n >= currentCapacity {
            newCapacity := int(growthFactor * float32(currentCapacity+n))
            list.resize(newCapacity)
        }
    }

```

## resize

**resize采用到了make(type[],size,size)创建一个元素个数为size的数组，元素初始为0，并预留size个存储空间**

```go
    func (list *List) resize(size int) {
        newElement := make([]interface{}, size, size)
        copy(newElement, list.element)
        list.element = newElement
    }
```



