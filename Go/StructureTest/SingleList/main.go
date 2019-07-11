package main

import "fmt"

type container interface {
	Size() int
	Clear()
}

//List holds the element.where each element points to the next element
type List struct {
	first *element
	last  *element
	size  int
}

type element struct {
	value interface{}
	next  *element
}

//New a single list
func New(values ...interface{}) *List {
	list := &List{}
	if len(values) > 0 {
		list.Add(values)
	}
	return list
}

// Add appends a value (one or more) at the end of the list (same as Append())
func (list *List) Add(values ...interface{}) {
	for _, value := range values {
		newElement := &element{value: value}
		if list.size == 0 {
			list.first = newElement
			list.last = newElement
		} else {
			list.last.next = newElement
			// list.last = newElement
			list.last = list.last.next
		}
		list.size++
	}
}

// Remove index node of the list
func (list *List) Remove(index int) bool {
	if index > list.size {
		return false
	}
	if list.size == 1 {
		list.first = nil
		list.last = nil
	}
	preElement := list.first
	lastElement := list.first
	//遍历到该节点
	for e := 0; e != index; e, lastElement = e+1, lastElement.next {
		preElement = lastElement
	}
	//删除第一个节点
	if lastElement == list.first {
		list.first = lastElement.next
	}
	//如果是最后一个节点 删除最后一个节点
	if lastElement.next == nil {
		list.last = preElement
	}
	if preElement != nil {
		preElement.next = lastElement.next
	}
	preElement = nil
	lastElement = nil
	list.size--
	return true
}

// HeadAdd add the nodes in front of list
func (list *List) HeadAdd(value interface{}) {
	e := &element{value: value}
	var temp *element
	temp = list.first
	list.first = e
	list.first.next = temp
	list.size++
}

//Display the element of the list
func (list *List) Display() {
	element := list.first
	for e := 0; element != nil; e, element = e+1, element.next {
		fmt.Printf("%d \n", element.value)
	}
}

//Find find the element from the list and return the index
func (list *List) Find(val int) (bool, int) {
	if list.size == 0 {
		return false, -1
	}
	for e, i := list.first, 0; i != list.size; e, i = e.next, i+1 {
		if e.value == val {
			return true, i
		}
	}
	return false, list.size
}

//Insert insert one node in the front of list
func (list *List) Insert(value interface{}, index int) bool {
	if index > list.size {
		return false
	}
	if index == list.size-1 {
		list.Add(value)
		return true
	}
	var e = list.first
	for i, e := 0, list.first; i != index; i, e = i+1, e.next {

	}
	var tem = &element{value: value}
	var q = e.next
	e.next = tem
	tem.next = q.next
	return true
}

//上面的那些函数返回值都是数组的索引值
func main() {
	list := New()
	list.Add(1, 2, 3, 4)
	// list.HeadAdd(9)
	list.Remove(3)
	list.Insert(10, 2)
	t, i := list.Find(2)
	if t {
		fmt.Printf("find the element in the pos %d \n", i)
	}
	list.Display()
}
