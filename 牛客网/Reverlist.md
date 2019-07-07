# 反转链表

后面补更讲解一下，这道题有点麻烦

```C++
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};*/
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
