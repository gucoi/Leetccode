# 既然来到这里 那就认真的读下去吧 放下浮躁 放下心 去认真读

请谨记
 **没有立即的成功 只有不懈的努力 少点功利心 多点奋斗（More interest Less interests）  勿骄勿燥**
**这里有go的数据结构和一些常用的算法题**

## Leetcode/剑指offer/一些算法题目集锦

| 题目            | 所使用语言 | 所属网站 | 文件位置                                 |
| :-------------- | :--------: | :-------- | --------------------------------------- |
| 二维数组查找    | C++        | 牛客网   | [二维数组查找](/牛客网/PrintMatrix.cpp)  |
| 二叉树的坡度    | C++        | Leetcode | [计算二叉树坡度](/Leetcode/findTilt.cpp) |
| 替换空格        | C++        | 牛客网   | [替换空格](/Leetcode/replaceSpace.cpp)   |
| 二进制中1的个数 | C++        | 牛客网   | [二进制中1的个数](/牛客网/Numberof1.cpp) |
| 调整数组顺序    | C++        | 牛客网   | [调整数组顺序](/牛客网/reOrderArray.cpp) |
|合并两个链表     |C++          |牛客网    |[合并两个链表](/牛客网/Merge.md)        |
|删除单向链表的节点|C++         |Leetcode  |[删除单向链表的节点](https://github.com/PICKQUE/Leetccode/blob/master/Leetcode/DeleteListNode.md)|
|链表中的倒数第k个节点|go&&C++|牛客网|[链表中的倒数第k个节点](https://github.com/PICKQUE/Leetccode/blob/master/牛客网/FindKthToTail.md)|
|二叉树镜像|C++|牛客网|[二叉树镜像](https://github.com/PICKQUE/Leetccode/blob/master/牛客网/Mirror.md)|

## go的一些常用的数据结构

|**Data**|**Structure**|**Implementation**|
|:---:|:---:|:----:|
|lists|
|   |[UseSingleList](#SingleLists)|[SinglLists](Go/SingleList.md)|

### SingleLists

```go
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
```
