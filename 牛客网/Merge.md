# 链表的经典题目合并两个有序链表

**必读**
*今天刚学会用markdown语法，写的有点遭，多担待*

题目：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

***值得注意的是***
*尽管这道题做了很多遍了，但是我乍一写还是出问题*

对于这种链表题，我只想说的是一定要注意指针的取值问题，在这个指针作为左值时，一定要对这个指针进行非空判断，另外对这个指针操作后，一定要记得对他进行销毁，然后将其置为NULL，这样是最安全的了。

例如这样肯定是不对的

```C++
ListNode* ptr;
ptr->val=1;
//改后
ListNode* ptr;
if(ptr)
    ptr->val=1;
```

回归题目，这道题主要是要求合并两个有序链表，并且要求合并后单调递增，这个要求还是蛮简单的，只要对两个链表进行遍历，那么这个链表当前节点值小就作为合并链表的下一个节点，然后这个链表就移向下一节点。

```C++
clss solution{
    public:
        ListNode* Merge(ListNodee* l1,ListNode* l2){
            //新建返回节点
            ListNode* res=new ListNode(-1);
            ListNode* root=res;
            while(l1&&l2){
                if(l1->val>l2->val){
                    res->next=l2;
                    l2=l2->next;
                    res=res->next;
                }
                else{
                    res->next=l1;
                    l1=l1->next;
                    res=res->next;
                }
            }
            if(l1&&!l2){
                res->next=l1;
            }
            if(l2&&!l1){
                res->next=l2;
            }
            return root->next;
        }
};
```
