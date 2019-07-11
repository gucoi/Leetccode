package main

import (
	"fmt"
	"sort"
)

// List the node fo List
type List struct {
	size    int
	element []interface{}
}

type Comprator func(a, b interface{}) int

func mycomprator(a, b interface{}) int {
	aAsserted := a.(int)
	bAsserted := b.(int)
	switch {
	case aAsserted > bAsserted:
		return 1
	case aAsserted < bAsserted:
		return -1
	default:
		return 0
	}
}

const (
	growthFactor   = float32(2.0)
	shrinkthFactor = float32(2.0)
)

// New new a list
func New(values ...interface{}) *List {

	list := &List{}
	if len(values) != 0 {
		list.Add(values...)
	}
	return list
}

// Add add a node to the list
func (list *List) Add(values ...interface{}) {
	list.growBy(len(values))
	for _, v := range values {
		list.element[list.size] = v
		list.size++
	}
}

//resize resize the element memory
func (list *List) resize(size int) {
	newElement := make([]interface{}, size, size)
	copy(newElement, list.element)
	list.element = newElement
}

//growBy expend the array if necessary i.e capacity will be reached the end if we add a element
func (list *List) growBy(n int) {
	currentCapacity := cap(list.element)
	if list.size+n >= currentCapacity {
		newCapacity := int(growthFactor * float32(currentCapacity+n))
		list.resize(newCapacity)
	}
}

//Remove removes the element  at the given index from the list
func (list *List) Remove(index int) {
	if index > list.size {
		return
	}
	list.element[index] = nil
	copy(list.element[index:], list.element[index+1:list.size])
	list.size--
	list.shrink()
}

//Shrink the array if neccessary,when size is shrinkFactor percent of current capacity
func (list *List) shrink() {
	if shrinkthFactor == 0.0 {
		return
	}
	currentCapacity := cap(list.element)
	// Shrink when size is at shrinkFactor * capacity
	if list.size <= int(float32(currentCapacity)*shrinkthFactor) {
		list.resize(list.size)
	}
}

// Size return the size of array
func (list *List) Size() int {
	return list.size
}

// Clear remove all elements from the array
func (list *List) Clear() {
	list.size = 0
	list.element = []interface{}{}
}

type sortable struct {
	values    []interface{}
	comprator Comprator
}

func (a sortable) Len() int           { return len(a.values) }
func (a sortable) Swap(i, j int)      { a.values[i], a.values[j] = a.values[j], a.values[i] }
func (a sortable) Less(i, j int) bool { return a.comprator(a.values[i], a.values[j]) < 0 }

//Sort sorts values (in-place) using
func Sort(values []interface{}, comprator Comprator) {
	sort.Sort(sortable{values, comprator})
}

func main() {
	list := New(3, 2, 1)
	// fmt.Println(list.element, list.size)
	Sort(list.element[:list.size], mycomprator)
	fmt.Println(list.element)
}
