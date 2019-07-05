# 删除单向链表的节点

这个是递归版的，调了半天才发现原来是我创建链表时出了问题，应该将最后一位置为null的，马虎加大意

```C++
    void DeleteListNode(ListNode*& l1,int x){
        //结束条件
        if(!l1)
            return;
        if(l1->val==x){
            ListNode* p=l1;
            l1=l1->next;
            free(p);
            //注意参数是引用部分
            DeleteListNode(l1,x);
        }
        else
            DeleteListNode(l1->next,x);
    }
```

这个是非递归普通版本的

```C++
   void DeleteListNode(ListNode*& l1,int x){
       //单链表删除节点需要两个节点 一个是所删除节点的前节点，另一个是删除节点
       ListNode *p=l1,*q=p->next;
       while(q){
           if(q->val==x){
               p->next=q->next;
               free(q);
           }
           p=p->next;
           q=p->next;
       }
    }
```
