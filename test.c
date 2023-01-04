#include "SList.h"
#include "SList.c"

void Test1()
{
    SLTNode* plist = NULL;
    SListPushBack(&plist,1);
    SListPushBack(&plist,2);
    SListPushBack(&plist,3);
    SListPushBack(&plist,4);

    SListPrint(plist);
    printf("\n");
    SListPushFront(&plist,1);
    SListPushFront(&plist,2);
    SListPushFront(&plist,3);
    SListPushFront(&plist,4);
    SListPrint(plist);
    printf("\n");

    SListPopBack(&plist);
    SListPopBack(&plist);
    SListPopBack(&plist);
    SListPrint(plist);
    printf("\n");

    SListPopFront(&plist);
    SListPrint(plist);
    printf("\n");
    SListPopFront(&plist);
    SListPrint(plist);
    printf("\n");
}


void Test2()
{
    SLTNode* plist = NULL;
    SListPushBack(&plist,1);
    SListPushBack(&plist,2);
    SListPushBack(&plist,2);
    SListPushBack(&plist,2);
    SListPushBack(&plist,3);
    SListPushBack(&plist,3);
    SListPushBack(&plist,4);
    SListPrint(plist);
    printf("\n");
    SLTNode* pos = SListFind(plist,2);
    int i = 1;
    while (pos)
    {
        printf("第%d个pos节点:%p->%d\n",i++,pos,pos->data);
        pos = SListFind(pos->next,2);
    }

    //修改数据
    pos = SListFind(plist,3);
    while(pos)
    {
        pos->data = 30;
        pos = SListFind(pos->next,3);
    }
    SListPrint(plist);

}

void Test3()
{
    SLTNode* plist = NULL;
    SListPushBack(&plist,1);
    SListPushBack(&plist,2);
    SListPushBack(&plist,2);
    SListPushBack(&plist,2);
    SListPushBack(&plist,3);
    SListPushBack(&plist,3);
    SListPushBack(&plist,4);
    SListPrint(plist);
    printf("\n");
    SLTNode* pos = SListFind(plist,3);
    if(pos)
    {
        SListInsert(&plist,pos,30);
    }
    SListPrint(plist);
    printf("\n");
    pos = SListFind(plist,1);
    if(pos)
    {
        SListInsert(&plist,pos,10);
    }
    SListPrint(plist);
    printf("\n");
    pos = SListFind(plist,4);
    if(pos)
    {
        SListInsertAfter(pos,40);
    }
    SListPrint(plist);
    printf("\n");


    pos = SListFind(plist,40);
    if(pos)
    {
        SListEase(&plist,pos);
    }
    SListPrint(plist);
    printf("\n");

    pos = SListFind(plist,1);
    if(pos)
    {
        SListEaseAfter(pos);
    }
    SListPrint(plist);
    printf("\n");
    

}

int main()
{
    //Test1();
    Test3();
    return 0;
}