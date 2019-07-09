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

这后面的就是数据结构的方法,我方法的命名规格是驼峰式的，但是如果这个方法我不会用在外接的api我会写成小写的否则首字母是大写的

## New

 第一个是New方法（新建一个线性表）

```go
    func New(values ...interface{})(*List){
        list:=&List{}
        if values.size==0
            return list
        return list.Add(values...)
    }
```

## Add

Add : 向线性表里添加节点

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

expand the array i.e. capacity will be reached the end if we add a element

```go
    func (list *List) growBy(n int) {
        currentCapacity := cap(list.element)
        if list.size+n >= currentCapacity {
            newCapacity := int(growthFactor * float32(currentCapacity+n))
            list.resize(newCapacity)
        }
    }

```

## shrink

shrink the array i.e. when size is shrinkFactor percent of current capacity

```go
    func (list *List)shrink(){
        if shrinkFactor==0{
            return
        }
        currentCapacity:=cap(list.element)
        if list.size<=int((float32)currentCapacity*shrinkFactor){
            list.resize(list.size)
        }
    }
```

## resize

resize : **采用到了make(type[],size,size)创建一个元素个数为size的数组，元素初始为0，并预留size个存储空间**

```go
    func (list *List) resize(size int) {
        newElement := make([]interface{}, size, size)
        copy(newElement, list.element)
        list.element = newElement
    }
```

## Remove

```go
    func (list *List)Remove(index int){
        if index>list.size{
            return
        }
        list.element[index]=nil
        copy(list.element[index:],list.element[index+1:list.size])
        list.size--
        list.shrink()
    }
```

## Size

return the size of array

```go
    func (list *List)Size()int{
        return list.size
    }
```

## Clear

Remove all elements of array

```go
    func (list *List)Clear(){
        list.size=0
        list.element=[]interface{}
    }
```

## Sort

go中的sort函数和C++最大的区别是，他不能自己实现sort方法，而是由go的sort包提供的sort方法，sort方法中有三种排序算法（快排序，堆排序，插入排序）go可以根据你的数据类型来进行选择其中一个作为排序算法，sort的interface定义的三种方法，获取数据集合的长度Len，比较两个数据的大小的Less()和交换两个数据的Swap方法

```go
    type Comparator func(a,b interface{})int
    type sortable struct{
        values []interface{}
        comparator Comparator
    }
    func (a sortable)Len()  int         {return len(a.values)}
    func (a sortable)Swap(i,j int)      {return a.values[i],a.values[j]=a.values[j],a.values[i]}
    func (a sortable)Less(i,j int) bool {return a.comparator(a.values[i],a.values[j])>0}
    //Start write sort function
    func (list *List)Sort(comparator Comparator){
        sort.Sort(sortable{list.element[:list.size],comparator})
    }
```
