# 反转链表

题目：**将给的链表翻转过来**

```C++
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

```

这道题思路先进行判断如果根节点为空或者链表只有一个节点都返回自己本身（不用反转），否则声明三个节点，一个指向当前的节点和当前节点的反转前一个节点，一个指向没反转前的下一个节点，两个节点互（前后）互相交换，直到遍历到原来链表的最后一个节点

```C++
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead||!pHead->next)return pHead;
        ListNode *pre=nullptr;
        ListNode *nxt=nullptr;
        ListNode *cur=pHead;
        while(cur){
            nxt=cur->next;
            cur->next=pre;
            if(!nxt)
                break;
            pre=cur;
            cur=nxt;
        }
        return cur;
    }
};
```
