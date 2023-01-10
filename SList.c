#include "SList.h"
//打印链表
void SListPrint(SLTNode* phead)
{
    SLTNode* cur = phead;
    while (cur != NULL)
    {
        printf("%d->",cur->data);
        cur = cur->next;
    }
    
}

//生成一节点
SLTNode* BuySListNode(SLTDateType x)
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    if(newnode == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

//尾插
void SListPushBack(SLTNode** pphead,SLTDateType x)
{
    // SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    // newnode->data = x;
    // newnode->next = NULL;
    assert(pphead);
    SLTNode* newnode = BuySListNode(x);
    if(*pphead == NULL)
    {
        *pphead = newnode;
    }
    else{
        SLTNode* tail = *pphead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

//头插
void SListPushFront(SLTNode** pphead,SLTDateType x)
{
    assert(pphead);
    SLTNode* newnode = BuySListNode(x);
    newnode->next = *pphead;
    *pphead = newnode;
}

//尾删
void SListPopBack(SLTNode** pphead)
{
    assert(pphead);
    if(*pphead == NULL)
    {
        return;
    }

    //assert(*pphead != NULL);
    if((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }
    else
    {
        SLTNode* prev = NULL;
        SLTNode* tail = *pphead;
        //while (tail->next !=NULL)
        while (tail->next)
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        tail = NULL;
        prev->next = NULL;

        // SLTNode* tail = *pphead;
        // while (tail->next->next)
        // {
        //     tail = tail->next;
        // }
        // free(tail->next);
        // tail->next = NULL;
    }
    
}


 //头删
void SListPopFront(SLTNode** pphead)
{
    assert(pphead);
    if(*pphead == NULL)
    {
        return;
    }
    SLTNode* next = (*pphead)->next;
    free(*pphead);
    *pphead = next;
    
}
//查找
SLTNode* SListFind(SLTNode* phead,SLTDateType x)
{
    assert(phead);
    SLTNode* cur = phead;
    while (cur)
    {
        if(cur->data == x)
        {
            return cur;
        }
        else{
            cur = cur->next;
        }
    }
    return NULL;
}

//在pos位置之前去插入一个节点
void SListInsert(SLTNode** pphead,SLTNode* pos,SLTDateType x)
{
    assert(pphead);
    SLTNode* newnode = BuySListNode(x);
    if(*pphead == pos)
    {
        newnode->next = *pphead;
        *pphead = newnode;
    }
    else{
        SLTNode* posPrev = *pphead;
        while(posPrev->next != pos)
        {
            posPrev = posPrev->next;
        }
        posPrev->next = newnode;
        newnode->next = pos;
    }
}

//在pos位置之后面去插入一个节点---简单，效率较高
void SListInsertAfter(SLTNode* pos,SLTDateType x)
{
    SLTNode* newnode = BuySListNode(x);
    newnode->next = pos->next;
    pos->next = newnode;

}

//删除pos节点的数据
void SListEase(SLTNode** pphead,SLTNode* pos)
{
    assert(pphead);
    //删除第一个节点
    if(*pphead == pos)
    {
        *pphead = pos->next;
        free(pos);
    }
    else{
        SLTNode* prev = *pphead;
        while (prev->next != pos)
        {
            prev = prev->next;
            /* code */
        }
        prev->next = pos->next;
        free(pos);
    }

}

//删除pos后节点的数据
void SListEaseAfter(SLTNode* pos)
{
    assert(pos->next != NULL);
    SLTNode* next = pos->next->next;
    free(pos->next);
    pos->next = next;
}


//销毁链表
void SListDestroy(SLTNode** pphead)
{
    SLTNode* cur = *pphead;
    while (cur)
    {
        SLTNode* next = cur->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
    
} 




//反转链表
struct SLTNode* reverseList(SLTNode* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    
    SLTNode* n1,*n2,*n3;
    n1 = NULL;
    n2 = head;
    n3 = head->next;
    while(n2)
    {
        //反转
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if(n3)
            n3 = n3->next;
    }
    return n1;

    

}


//头插
struct SLTNode* reverseList2(SLTNode* head)
{
    SLTNode* cur = head;
    SLTNode* newhead = NULL;
    while (cur)
    {
        SLTNode* next = cur->next;
        cur->next = newhead;
        newhead = cur;

        //迭代
        cur = next;
    }
    return newhead;
    
}


//返回中间值
struct SLTNode* middeSlist(SLTNode* head)
{
    SLTNode* slow = head;
    SLTNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
    
}


//返回倒数第k个值
struct SLTNode* middeSlist2(SLTNode* head,int k)
{
    SLTNode* slow = head;
    SLTNode* fast = head;
    while (k--)
    {
        if(fast == NULL)
        {
            return NULL;
        }
        fast = fast->next;
    }
    
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;

}

//

void SLTNode* mergeTwoList(SLTNode* l1,SLTNode* l2)
{
    if(l1 == NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }

    SLTNode* head = NULL;
    SLTNode* tail = NULL;
    while (l1 && l2)
    {
        if(l1->next < l2->next)
        {
            
        }
        
    }
    

    
}
