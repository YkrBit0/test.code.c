#include "damol.h"
#include "damol.c"
void TestSeqlist1()
{
    SL sl;
    SeqListInit(&sl);
    SeqListPushBack(&sl,1);
    SeqListPushBack(&sl,2);
    SeqListPushBack(&sl,3);
    SeqListPushBack(&sl,4);
    SeqListPushBack(&sl,5);
    SeqListPrint(&sl);
    SeqListDestory(&sl);
}

void TestSeqlist2()
{
    SL sl;
    SeqListInit(&sl);
    SeqListPushBack(&sl,1);
    SeqListPushBack(&sl,2);
    SeqListPushBack(&sl,3);
    SeqListPushBack(&sl,4);
    SeqListPushBack(&sl,5);
    SeqListPrint(&sl);


    SeqListPushFront(&sl,10);
    SeqListPushFront(&sl,20);
    SeqListPushFront(&sl,30);
    SeqListPushFront(&sl,40);
    SeqListPrint(&sl);

    SeqListPopFront(&sl);
    SeqListPopFront(&sl);
    SeqListPrint(&sl);


    int cont = SeqListFind(&sl,100);
    printf("%d\n",cont);

    SeqListDestory(&sl);

}

int main()
{
    printf("hello word\n");
    TestSeqlist2();
    
    return 0; 
}