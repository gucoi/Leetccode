package main

type element struct {
	value interface{}
	pre   *element
	next  *element
}

type List struct {
	first *element
	last  *element
	size  int
}

//New instantiates a new list and adds the passed values if any to the list
func New(values ...interface{}) *List {
	var list = &List{}
	if len(values) > 0 {
		list.Add(values...)
	}
	return list
}

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

func main() {
	list := New()
	list.Add(1, 2, 3, 4)

}
