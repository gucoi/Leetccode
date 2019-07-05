# 输出链表的倒数第k个值

这道题我用的是比较经典的算法是声明两个指针p.q，然后p和q之间相差k个节点，p指向头节点，q指向p后的k个节点（前提是该节点存在否则直接返回空指针）然后p，q同步向后遍历，每次都想后面走一个节点，直到q节点到达终点，那p节点指向的就是倒数第k个节点

```C++
    void FindKthToTail(ListNode* l,unsigned int k){
        ListNode *p=l,*q=p;
        while(k>0){
            k--;
            q=q->next;
        }
        //如果链表长度小于k时直接返回
        if(k>0){
            return nullptr;
        }
        while(q){
            q=q->next;
            p=p->next;
        }
        return p;
    }
```

试着写一下go版本的
看这个之前可以先看一下我之前写的go的链表的结构体 [go的结构体](https://github.com/PICKQUE/Leetccode/blob/master/Leetcode/AddNode.md) 看下来不需要两分钟


```go
    func (list *List)FindKthToTail(k int)*List{
        lastPtr:=list.first
        prePtr:=list.first
        for k>0 {
            k--;
            prePtr=prePtr.next;
        }
        if k>0{
            return nil
        }
        for prePtr!=nil{
            prePtr=prePtr.next
            lastPtr=lastPtr.next
        }
    }
```

总结：go里面没有while真是不方便呢 不过for的大法真好（吹爆go）还有从来不担心释放内存以及变量名称问题真是炒鸡舒服呢 nil也是非常棒呢



