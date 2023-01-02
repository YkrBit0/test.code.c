#include "damol.h"

//
void SeqListPrint(SL* ps)
{
    for(int i = 0;i< ps->size;++i)
    {
        printf("%d ",ps->a[i]);
    }
    printf("\n");
}


//
void SeqListCheckCapacity(SL* ps)
{
    //扩容
    if(ps->size == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity*2;
        SLDateType* tmp = (SLDateType*)realloc(ps->a,newcapacity*sizeof(SLDateType));
        if(tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newcapacity;
    }

}

void SeqListInit(SL* ps)
{
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}


//尾锟斤拷
void SeqListPushBack(SL* ps,SLDateType x)
{
    // SeqListCheckCapacity(ps);
    // ps->a[ps->size] = x;
    // ps->size++;
    SeqListInsert(ps,ps->size,x);
}



void SeqListDestory(SL* ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->size =0;
}


//尾删
void SeqListPopBack(SL* ps)
{
    if(ps->size>0)
    {  
        ps->size--;
    }

    // assert(ps->size > 0);
    // ps->size--;
    
}


//头插
void SeqListPushFront(SL* ps,SLDateType x)
{
    // SeqListCheckCapacity(ps);
    // int end = ps->size-1;
    // while (end>=0)
    // {
    //     ps->a[end+1] = ps->a[end];
    //     --end;
    // }
    // ps->a[0] = x;
    // ps->size++;
    SeqListInsert(ps,0,x);
}

//头删
void SeqListPopFront(SL* ps){
    if(ps->size>0)
    {
        int begin = 1;
        while (begin < ps->size)
        {
            ps->a[begin-1] = ps->a[begin];
            ++begin;
        }
        ps->size--;
    }
}

//尾删
int SeqListFind(SL* ps,SLDateType x)
{
    int i = 0;
    while (i<ps->size)
    {
        if(ps->a[i]==x)
        {
            return i;
        }
        else if (ps->a[i]!=x)
        {
            return -1;
        }
        i++;
    }
    
}

//指定位置插入数据
void SeqListInsert(SL* ps,int pos,SLDateType x)
{
    // if(pos > ps->size || pos < 0)
    // {
    //     printf("pos invaid\n");
    // }
    
    assert(pos <= ps->size && pos >= 0);
    SeqListCheckCapacity(ps);

    int end = ps->size-1;
    while (end>=pos)
    {
        ps->a[end+1] = ps->a[end];
        --end;
    }
    ps->a[pos] = x;
    ps->size++;
    

}

//删锟斤拷锟斤拷锟斤拷位锟矫碉拷锟斤拷锟斤拷
void SeqListErase(SL* ps,int pos)
{
    assert(pos >= 0 && pos < ps->size);    //锟斤拷锟斤拷
    int begin = pos + 1;
    while (begin < ps->size)
    {
        ps->a[begin-1] = ps->a[begin];
        ++begin;
    }
    ps->size--;
}




