
/*
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
*/

/*
int Max[5][4] = {0,0,1,2,1,7,5,0,2,3,5,6,0,6,5,2,0,6,5,6};
int Allocation[5][4]={0,0,1,2,1,0,0,0,1,3,5,4,0,6,3,2,0,0,1,4};
int Need[5][4] = {0};
int Available[4] = {1,5,2,0};
*/
/*
void print_resources()
{
    int i = 0;
    int j = 0;
    printf("----------------------------------------\n");
    printf("当前系统各类资源剩余：");
    for(i = 0; i < 4 ;i++)
    {
        printf("%d ",Available[i]);
    }
    printf("\n");
    printf("当前系统资源情况：\n");
    printf("PID     ");
    printf(" MAx");
    printf("      Allocation");
    printf("      Need\n");
    
    for(i = 0;i < 5;i++)
    {
        printf("p%d     ",i);
        for(j = 0;j < 4;j++)
        {
            printf("%d ",Max[i][j]);
        }

        
        printf("   ");
        for(j = 0;j < 4;j++)
        {
            printf(" %d",Allocation[i][j]);
        }

        printf("     ");

        for(j = 0;j < 4;j++)
        {
            printf(" %d",Need[i][j]);
        }

        printf("\n");

    }

    printf("----------------------------------------\n");
}

*/
/*
int find_need()
{   
    int i = 0;
    int j = 0;
    printf("Need矩阵:\n");
    for(i = 0;i<5;i++)
    {
        for(j =0;j<4;j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
            printf("%d",Need[i][j]);
        }
        printf("\n");

    }

    //return need[5][4];
}

*/

/*
int cmp(const void* a,const void* b)
{
    int* n1 = (int*)a;
    int* n2 = (int*)b;
    return *n1 - *n2;

}

int main()
{
    //print_resources();

    int arr[8] = {1,5,8,6,9,2,5,8};
    qsort(arr,8,sizeof(int),cmp);
    int i = 0;
    for(i = 0;i< 8 ;i++)
    {
        printf("%d ",arr[i]);
    }

    


    find_need();
    return 0;

}
*/

/*
int main()
{
    bool t = false;
    int i,j;

    for(i = 0;i<5;i++)
    {
        if(i==3) continue;
        t = true;
        for(j = 0;j<4;j++)
        {
            if(j == 2) continue;

            else{
                t = false;
                break;
                
            }
        }

        if(t) break;
    }

    printf("i=%d,j=%d \n",i,j);

    int f = boo();

    printf("%d",f);


    printf("'鑳滃璐熷皯鐨?'");

    return 0;
}


int boo()
{
    int k = 0;
    for(k = 0; k < 8; k++)
    {
        if (k >7) continue;

        else return false;
    }

    return true;
}



bool tf()
{
    return true;
}

*/

/*

#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define Num 10000

int n1;//空闲分区的个数

int n2;//作业区的个数

struct kongxian
{
	int start;  //起址
	int end;    //结束
	int length;  //长度
}kongxian[Num];

struct zuoye
{
	int start;  //起址
	int end;   //结束
	int length;  //长度
}zuoye[Num];

int cmp1(const void *a, const void *b)
{
	return (*(struct kongxian *)a).start - (*(struct kongxian *)b).start;
}

int cmp2(const void *a, const void *b)
{
	return (*(struct zuoye *)a).start - (*(struct zuoye *)b).start;
}

void init()
{
	n1 = 1;  //初始时只有一个空闲区

	n2 = 0;  //初始没有作业

	kongxian[0].start = 0;
	kongxian[0].end = 1000;
	kongxian[0].length = 1000;
}
void print1() //打印空闲分区
{
	int i;
	for (i = 0; i<n1; i++)
		printf("空闲分区ID:%d 起止:%d 结束:%d 长度:%d\n", i, kongxian[i].start, kongxian[i].end, kongxian[i].length);
}

void print2() //打印作业分区
{
	int i;
	for (i = 0; i<n2; i++)
		printf("作业分区ID:%d 起止:%d 结束:%d 长度:%d\n", i, zuoye[i].start, zuoye[i].end, zuoye[i].length);
}


void arr()
{
    int t = 0;
    int fg = 0;
    int len = 0;
    int i = 0;
	
		printf("请输入作业的占用空间的长度: ");
		scanf("%d", &len);
	fg = 0;
		for (int i = 0; i<n1; i++)
		{
			if (kongxian[i].length >= len)  //首次适应算法
			{
			fg = 1;
				break;
			}
		}
            
			if ( fg)
			{
				printf("内存分配失败\n");
			}

			else
			{
				//将该作业加入作业区里
				zuoye[n2].start = kongxian[i].start;
				zuoye[n2].end = zuoye[n2].start + len;
				zuoye[n2].length = len;
				n2++;  //作业数加1
				if (kongxian[i].length == len) //该分区全部用于分配，删除该空闲分区
				{
					for (int j = i; j<n1 - 1; j++)
					{
						kongxian[j].start = kongxian[j + 1].start;
						kongxian[j].end = kongxian[j + 1].end;
						kongxian[j].length = kongxian[j + 1].length;
					}
					n1--;
				}

				else  //该空闲分区部分用于分配，剩余的留在空闲分区中
				{
					kongxian[i].start += len;
					kongxian[i].length -= len;
				}

		    }
	
}



int main()
{
    init();
    print1();
    int a = 0;
    while (1)
    {
        printf("输入1装入新作业,输入0回收作业,输入-1结束:");
        scanf("%d",&a);
        if(a == 1)
        {
            arr();
            print1();
            print2();
        }
        else
        break;
        
    }
    
    
}

*/

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define Num 1000
//内存大小
#define size_num 1500
//空闲区个数
int empty_num = 0;
//作业区个数
int task_num = 0;
//空闲区
struct empty_area
{
    int start;
    int end;
    int length;
    int state; 
}empty_area_array[Num];
//作业区
struct task_area
{
	int start;
    int end;
    int length;
}task_area_array[Num];
//排序
int cmp_free(const void* a,const void* b)
{
	struct empty_area* f = (struct empty_area*)a;
	struct empty_area* t = (struct empty_area*)b;
	int num1 = f->start;
	int num2 = t->start;
	return num1 - num2;

}
int cmp_job(const void* a,const void* b)
{
	struct task_area* f = (struct task_area*)a;
	struct task_area* t = (struct task_area*)b;
	int num1 = f->start;
	int num2 = t->start;
	return num1 - num2;
}
int cmp_sort_best(const void* a,const void* b)
{
	struct empty_area* f = (struct empty_area*)a;
	struct empty_area* t = (struct empty_area*)b;
	int num1 = f->length;
	int num2 = t->length;
	return num1 - num2;
}
int cmp_sort_worst(const void* a,const void* b)
{
	struct empty_area* f = (struct empty_area*)a;
	struct empty_area* t = (struct empty_area*)b;
	int num1 = f->length;
	int num2 = t->length;
	return num2 - num1;
}
//初始化
void init()
{
	empty_num = 1;   //初始化一个空闲区
	task_num = 0;	 
	empty_area_array[0].start = 0;
	empty_area_array[0].end = size_num;
	empty_area_array[0].length = size_num;
}
void print_empty() //打印空闲分区
{
	int i;
	for (i = 0; i<empty_num; i++)
	printf("空闲分区ID:%d 起止:%d 结束:%d 长度:%d\n", i, empty_area_array[i].start, empty_area_array[i].end, empty_area_array[i].length);
}
void print_task() //打印作业分区
{
	int i;
	for (i = 0; i<task_num; i++)
	printf("作业分区ID:%d 起止:%d 结束:%d 长度:%d\n", i, task_area_array[i].start, task_area_array[i].end, task_area_array[i].length);
}
//首次适应算法
void first_fit()
{
	int fg = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	printf("请输入作业的占用空间的长度: ");
	scanf("%d", &len);
	for (i = 0; i<empty_num; i++)
	{
		if (empty_area_array[i].length >= len)  //首次适应算法
		{
		fg = 1;
			break;
		}
	}  
	if ( fg)
	{
		printf("内存分配失败\n");
	}
	else
	{
		//将该作业加入作业区里
		task_area_array[task_num].start = empty_area_array[i].start;
		task_area_array[task_num].end = task_area_array[task_num].start + len;
		task_area_array[task_num].length = len;
		task_num++;  
		//作业数加1
		if (empty_area_array[i].length == len) //该分区全部用于分配，删除该空闲分区
		{
			for (j = i; j<empty_num - 1; j++)
			{
				empty_area_array[j].start = empty_area_array[j + 1].start;
				empty_area_array[j].end = empty_area_array[j + 1].end;
				empty_area_array[j].length = empty_area_array[j + 1].length;
			}
			empty_num--;
		}
		else  //该空闲分区部分用于分配，剩余的留在空闲分区中
		{
			empty_area_array[i].start += len;
			empty_area_array[i].length -= len;
		}
	}
}
//最佳适应算法
void best_fit()
{
	int fg = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	printf("请输入作业的占用空间的长度: ");
	scanf("%d", &len);
	for (i = 0; i<empty_num; i++)
	{
		if (empty_area_array[i].length >= len)
		{
		fg = 1;
			break;
		}
	}
	if ( fg)
	{
		printf("内存分配失败\n");
	}
	else
	{
		//将该作业加入作业区里
		task_area_array[task_num].start = empty_area_array[i].start;
		task_area_array[task_num].end = task_area_array[task_num].start + len;
		task_area_array[task_num].length = len;
		task_num++;  
		//作业数加1
		if (empty_area_array[i].length == len) //该分区全部用于分配，删除该空闲分区
		{
			for (j = i; j<empty_num - 1; j++)
			{
				empty_area_array[j].start = empty_area_array[j + 1].start;
				empty_area_array[j].end = empty_area_array[j + 1].end;
				empty_area_array[j].length = empty_area_array[j + 1].length;
			}
			empty_num--;
		}
		else  //该空闲分区部分用于分配，剩余的留在空闲分区中
		{
			empty_area_array[i].start += len;
			empty_area_array[i].length -= len;
		}
	}
}
//最坏实验算法
void worst_fit()
{
	int fg = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	printf("请输入作业的占用空间的长度: ");
	scanf("%d", &len);
	for (i = 0; i<empty_num; i++)
	{
		if (empty_area_array[i].length >= len)
		{
		fg = 1;
			break;
		}
	}    
	if ( fg)
	{
		printf("内存分配失败\n");
	}
	else
	{
		//将该作业加入作业区里
		task_area_array[task_num].start = empty_area_array[i].start;
		task_area_array[task_num].end = task_area_array[task_num].start + len;
		task_area_array[task_num].length = len;
		task_num++;  
		//作业数加1
		if (empty_area_array[i].length == len) //该分区全部用于分配，删除该空闲分区
		{
			for (j = i; j<empty_num - 1; j++)
			{
				empty_area_array[j].start = empty_area_array[j + 1].start;
				empty_area_array[j].end = empty_area_array[j + 1].end;
				empty_area_array[j].length = empty_area_array[j + 1].length;
			}
			empty_num--;
		}
		else  //该空闲分区部分用于分配，剩余的留在空闲分区中
		{
			empty_area_array[i].start += len;
			empty_area_array[i].length -= len;
		}
	}
	//排列空闲区域---从大到小
}
//回收算法
void release(int sign)
{
    int i, j, t, len, fg, id;
	int front, middle, behind;
	int t1, t2;
    printf("输入要回收的作业ID:");
	scanf("%d", &id);
	front = middle = behind = 0;
	for (i = 0; i< empty_num; i++)
	{
		if (empty_area_array[i].start>task_area_array[id].end)
			break;
		if (empty_area_array[i].end == task_area_array[id].start)  //待回收的作业上面有空闲分区
		{
			front = 1;
			t1 = i;
		}
		if (empty_area_array[i].start == task_area_array[id].end)  //待回收的作业下面有空闲分区
		{
			behind = 1;
			t2 = i;
		}
	}
	if (!front&&!behind)  //待回收的作业上下均没有空闲分区
	{
		empty_area_array[empty_num].start = task_area_array[id].start;
		empty_area_array[empty_num].end = task_area_array[id].end;
		empty_area_array[empty_num].length = task_area_array[id].length;
		empty_num++;  //空闲分区增加一个
		qsort(empty_area_array, empty_num,sizeof(struct empty_area),cmp_free); //插入空闲分区后排序
		for (j = id; j<task_num - 1; j++)  //在作业分区中删除该作业
		{
			task_area_array[j].start = task_area_array[j + 1].start;
			task_area_array[j].end = task_area_array[j + 1].end;
			task_area_array[j].length = task_area_array[j + 1].length;
		}
		task_num--;
	}
	if (front&&behind)  //待回收的作业上下均有空闲分区
		middle = 1;


	if (front&&!middle)  //合并待回收的作业和上面的空闲分区
	{
		empty_area_array[t1].end += task_area_array[id].length;
		empty_area_array[t1].length += task_area_array[id].length;
		for (j = id; j<task_num - 1; j++)  //在作业分区中删除该作业
		{
			task_area_array[j].start = task_area_array[j + 1].start;
			task_area_array[j].end = task_area_array[j + 1].end;
			task_area_array[j].length = task_area_array[j + 1].length;
		}
		task_num--;
	}
	if (middle)  //合并待回收的作业和上下的空闲分区
	{
		empty_area_array[t1].end = empty_area_array[t2].end;
		empty_area_array[t1].length += (task_area_array[id].length + empty_area_array[t2].length);
		//删除空闲分区t2
		for (j = t2; j<empty_num - 1; j++)
		{
			empty_area_array[j].start = empty_area_array[j + 1].start;
			empty_area_array[j].end = empty_area_array[j + 1].end;
			empty_area_array[j].length = empty_area_array[j + 1].length;
		}
		empty_num--;
		for (j = id; j<task_num - 1; j++)  //在作业分区中删除该作业
		{
			task_area_array[j].start = task_area_array[j + 1].start;
			task_area_array[j].end = task_area_array[j + 1].end;
			task_area_array[j].length = task_area_array[j + 1].length;
		}
		task_num--;
	}
	if (behind &&!middle) //合并待回收的作业和下面的分区
	{
		empty_area_array[t2].start -= task_area_array[id].length;
		empty_area_array[t2].length += task_area_array[id].length;
		for (j = id; j<task_num - 1; j++)  //在作业分区中删除该作业
		{
			task_area_array[j].start = task_area_array[j + 1].start;
			task_area_array[j].end = task_area_array[j + 1].end;
			task_area_array[j].length = task_area_array[j + 1].length;
		}
		task_num--;
	}
	//判断算法来确定空闲区的排列方式
	if(sign == 2)
	{
		qsort(empty_area_array,empty_num,sizeof(struct empty_area),cmp_sort_best);
	}
	if(sign == 3)
	{
		qsort(empty_area_array,empty_num,sizeof(struct empty_area),cmp_sort_worst);
	}
}

//主函数
int main()
{
	bool ft = false;
	int sign = 0;
	init();
	print_empty();
	while(1)
	{
		if (ft)
		break;
		printf("请选择动态分配算法");
		printf("***1:首次适应算法,2:最佳适应算法,3:最坏适应分配算法***:");
		int chose = 0;
		scanf("%d",&chose);
		switch (chose)
		{
			case 1:
			while (1)
			{
				printf("是否回收作业:1装入作业,0回收作业,-1结束操作!:");
				sign = 1;
				int chosse1 = 0;
				scanf("%d",&chosse1);
				if(chosse1 == 1)
				{

					first_fit();
					print_empty();
			print_task();
				printf("------------------------------------\n");
				}
				if(chosse1 == 0){
					release(sign);
					print_empty();
			print_task();
					printf("------------------------------------\n");
				}
				if(chosse1 == -1)
				{
					printf("结束操作!");
					ft = true;
					break;
				}
			}
			break;
			case 2:
			while (1)
			{
				printf("是否回收作业:1装入作业,0回收作业,-1结束操作!");
				sign = 2;
				int chosse2 = 0;
				scanf("%d",&chosse2);
				if(chosse2 == 1)
				{
					best_fit();
					print_empty();
			print_task();
					printf("------------------------------------\n");
				}
				if(chosse2 == 0){
					release(sign);
					print_empty();
			print_task();
					printf("------------------------------------\n");
				}
				if(chosse2 == -1)
				{
					printf("结束操作!");
					ft = true;
					break;
				}
			}
			break;
			case 3:
			while (1)
			{
				printf("是否回收作业:1装入作业,0回收作业,-1结束操作!:");
				sign = 3;
				int chosse3 = 0;
				scanf("%d",&chosse3);
				if(chosse3 == 1)
				{
					worst_fit();
					print_empty();
			        print_task();
					printf("------------------------------------\n");
				}
				if(chosse3 == 0){
					release(sign);
					print_empty();
			        print_task();
					printf("------------------------------------\n");
				}
				if(chosse3 == -1)
				{
					printf("结束操作!\n");
					ft = true;
					break;
				}	
			}
			break;
		}
	}
	return 0;
}

*/


#include<stdio.h>
#define FREE 0                   // 内存空闲状态 
#define FULL 1                   // 内存占满状态 
#define MAX_ALLOC_SIZE 65536     // 假设系统允许最大分配空间的大小 
#define MIN_MEMORY_DIFFER 2      // 防止碎片化太过严重，定义最小差值（空闲区-程序片大小） 

struct Node{                     // 空闲分区链结点 and 已使用分区链结点
	int p_id;                    // 当前空闲分区结点的id，唯一 
	long address, size;
	int status;	 
	struct Node *pre, *next;

};

struct Node *usedLink, *freeLink, *initMemory;
long start_add, end_add, memory_size; // 起始地址，终止地址，内存大小 
int initLink();
char *getStatus(int status);
struct Node *deepCopyNode(struct Node *p1, struct Node *p2);
void insertNode(struct Node *link, struct Node *p);
void sortLink(struct Node *temp);
void memoryRecovery(int p_id);
void bestFitAlloc(long prgSize);
void callAllocAlgorithm();
void callRecoveryAlgorithm();
void userInterface();
void displayLink(struct Node *head);

int initLink(){
	// 空闲分区链 & 已使用分区链 ， 说明：带有头结点，方便后续操作 
	usedLink = (struct Node *)malloc(sizeof(struct Node));
	freeLink = (struct Node *)malloc(sizeof(struct Node));
	initMemory = (struct Node *)malloc(sizeof(struct Node));
	
	if(!freeLink || !usedLink || !initMemory){
		printf("空间申请失败！");
		return 0;
	}
	
	// 初始化已使用分区链表 
	usedLink->p_id = -1;
	usedLink->size = 0;
	usedLink->address = 0;
	usedLink->pre = usedLink->next = NULL;
	usedLink->status = FULL;
	
	// 初始化空闲分区链表 
	freeLink->p_id = -1;
	freeLink->size = 0;
	freeLink->address = 0;
	freeLink->pre = freeLink->next = NULL;
	freeLink->status = FULL;

	// 初始化内存空间 
	initMemory->p_id = -1;
	initMemory->size = 0;
	initMemory->address = 0;
	initMemory->pre = initMemory->next = NULL;
	initMemory->status = FULL;
	
	return 1;
	
}
char *getStatus(int status){
	return status ? "占满" : "空闲";
}
struct Node *deepCopyNode(struct Node *p1, struct Node *p2){  // 对节点进行深拷贝 
	p1->next = p1->pre = NULL;
	p1->address = p2->address;
	p1->p_id = p2->p_id;
	p1->size = p2->size;
	p1->status = p2->status;
	return p1;
}
void insertNode(struct Node *link, struct Node *p){
	link->next = p;
	p->pre = link;
}
void sortLink(struct Node *temp){   // 插入排序构造最优适应的空闲分区链 
	// 带头结点，因此此处 freeLink 一定非空 
	struct Node *p = freeLink->next;
	struct Node *preNode = freeLink;

	// 如果是首次添加结点，无需排序 
	if(!p){
		freeLink->next = temp;
		temp->pre = freeLink;
		return;
	}
	// 按照空闲分区容量从小到大进行插入排序，获取第一个需要插入的位置 
	while(p && temp->size > p->size){
		p = p->next;
		preNode = preNode->next;
	}
	temp->next = p;
	if(p)
		p->pre = temp;
	preNode->next = temp;
	temp->pre = preNode;
//	printf("111\n");
}
void memoryRecovery(int p_id){  // 回收内存 
	// 使用initMemory 以及 freeLink
	// 将从initMemory 回收的内存链结 使用sortLink() 方法插入到空闲分区链 freeLink 中
	
	// 检索整个initMemory，找到p_id 所在的内存，判断与之邻接的上下两块内存的状态
	int find = 0;
	struct Node *p = initMemory->next;
	struct Node *copyNode = (struct Node*)malloc(sizeof(struct Node));
	while(p){
		if(p->p_id == p_id){
			// do something
			find = 1;
			break;
		}
		p = p->next;
	}
	if(!find){
		printf("未找到指定 id 的内存！");
		return;
	}
	// 找到对应id的内存结点，内存指针为 p，获取邻接的两块内存的状态 
	struct Node *freeHead = freeLink->next;
	struct Node *preNode = p->pre, *nextNode = p->next;
	int preNodeStatus = preNode->status, nextNodeStatus = nextNode->status;
	
//	printf("%d\n%\d\n", nextNodeStatus, preNodeStatus);
	
	
	if(preNodeStatus < nextNodeStatus){  // 前空闲后满 
		printf("\n前空闲后满\n");
		// 只修改前一个分区的大小，删除定位到的这个分区 
		preNode->size += p->size;
		preNode->next = nextNode;
		if(nextNode)
			nextNode->pre = preNode;
		free(p);
	}
	else if(preNodeStatus > nextNodeStatus){  // 后空闲前满 
		// 只修改后一个分区的大小，删除定位到的这个分区 
		printf("\n后空闲前满\n");
		preNode->next = nextNode;
		if(nextNode){
			nextNode->size += p->size;
			nextNode->address = p->address;		
			nextNode->pre = preNode;
		}
		if(nextNode==freeLink->next)
			return;
		free(p);
	}
	else if(!nextNodeStatus){  // 前后均不满    
		// 将相邻的三个分区合并 
		printf("\n前后均不满\n");
		preNode->size += p->size;
		if(nextNode)
			preNode->size += nextNode->size;
		preNode->next = NULL;
		free(p);
		free(nextNode);	
	}
	else{  // 前后均满 
		// 为回收区单独建立表项，填写回收区首址及大小，并根据回收区大小插入到空闲分区链的适当位置
		printf("\n前后均满\n");
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		temp->pre = temp->next = NULL;
		temp->address = p->address;
		temp->size = p->size;
		temp->p_id = p->p_id; 
		temp->status = FREE;
		p->status = FREE; 
	}
} 
void bestFitAlloc(long prgSize){  // 最佳适应算法 

	struct Node *p = freeLink->next, *preNode = freeLink; 
	
	// 查找到应当存入的内存块 
	while(p && prgSize > p->size){
		p = p->next;
		preNode = preNode->next;
	}
	if(!p){
		printf("程序大于最大内存片长度，无法装入！");
		return;
	}
	
	p->size = p->size - prgSize;
	if(!p->size || p->size < MIN_MEMORY_DIFFER) // 装满 
	{
		p->status = FULL;
		preNode->next = p->next;
		if(p->next)
			p->next->pre = preNode;
		struct Node *q = usedLink;
		
		p->status = FULL;
		p->next = q->next;
		if(q->next)
			q->next->pre = p;
		q->next = p;
		p->pre = q;
		
	}
	else{
		
		preNode->next = p->next;
		if(p->next)
			p->next->pre = preNode;
		// 若每次都对整个空闲分区链排序，效率势必很低
		// 因此我只将定位到的内存片减去程序片大小后"摘下"，然后重新对这个单个结点进行插入排序
		sortLink(p);
	} 
	printf("freeLink:\n");
	displayLink(freeLink);
	printf("usedLink:\n");
	displayLink(usedLink);	
}
void callAllocAlgorithm(){ // 调用分配算法，此处主要用于用户输入信息 

	int prgNum = 0, i = 0;
	long prgSize = 0, p_id = -1;
	printf("请输入添加的程序数量："); 
	scanf("%d", &prgNum);
	for(;i < prgNum;i++){
		printf("\n请输入第 %d 个程序的 id 及大小：", i + 1);
		scanf("%ld%d", &p_id, &prgSize);
		if(prgSize <= 0 || prgSize >= MAX_ALLOC_SIZE){
			printf("内存申请失败！");
			return;
		}
		
		bestFitAlloc(prgSize);
	} 	

}
void callRecoveryAlgorithm(){
	
	struct Node *mHead = initMemory, *fHead = freeLink;
	int prgNum = 0, i = 0;
	int p_id = -1;
	printf("请输入回收的内存数量："); 
	scanf("%d", &prgNum);
	for(;i < prgNum;i++){
		printf("\n请输入第 %d 块内存的 id:", i + 1);
		scanf("%ld", &p_id);
		if(p_id == -1){
			printf("无此内存可以回收！");
			return;
		}
		memoryRecovery(p_id);
		printf("\ninitMemory after recovery:\n");	
		displayLink(initMemory);
		

	} 	
	while(mHead){
		if(mHead->status == FREE){
			fHead->next = mHead;
			fHead = mHead;
		}
		mHead = mHead->next;
	}
	printf("freeLink:\n");
	displayLink(freeLink);
}
void userInterface(){  // 用户界面 
	
	int i = 0;
	long curAdd = 0;
	int init_success = 0;
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node *lastNode, *preNode;
		
	// 初始化起始地址与终止地址
	start_add = end_add = -1; 
	
	printf("请初始化内存块的首地址及内存大小：");
	scanf("%ld%ld", &start_add, &memory_size);
	if(memory_size > MAX_ALLOC_SIZE){
		printf("申请内存超过内存大小阈值！");
		return;
	}
	
	init_success = initLink();
	if(!init_success){
		printf("内存申请失败！");
		return;
	}
	// 内存申请成功，执行下面代码，最初连续分配内存空间 
	
	temp->p_id = -1;
	temp->address = start_add;
	temp->size = memory_size;
	temp->pre = temp->next = NULL;
	temp->status = FREE;
	
	insertNode(initMemory, temp);
	lastNode = temp;   // lastNode 指向初始内存最后一个结点 
	preNode = temp->pre;
	
	int p_id = -1, p_num = 0;
	long p_size = -1;
	printf("请输入申请资源的进程个数：");
	scanf("%d", &p_num);
	for(i = 0;i < p_num;i++){
		printf("请输入第 %d 个进程调入的分区号及其大小：", i + 1);
		scanf("%d%ld", &p_id, &p_size);
		// 开始划分连续分区 
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		p->address = curAdd;
		p->p_id = p_id;
		p->size = p_size;
		p->status = FULL;
		p->pre = p->next = NULL; 

		curAdd += p_size;
		if(curAdd > start_add + memory_size){
			printf("内存分配超出系统限制！");
			return;
		}
		
		lastNode->address = curAdd;
		lastNode->size -= p_size;
		p->next = lastNode;
		lastNode->pre = p;
		
		p->pre = preNode;
		preNode->next = p;
		preNode = p;
	}
	// 上面代码测试无误，initMemory内存被连续使用 
	printf("initMemory:\n");
	displayLink(initMemory);
	callRecoveryAlgorithm();
	callAllocAlgorithm();	
}

void displayLink(struct Node *head){
	struct Node *p = head->next;
	while(p){
		printf("id:%d 首地址：%ld 大小：%ld 状态：%s\n", p->p_id, p->address, p->size, getStatus(p->status));
		p = p->next;
	}
}

int main()
{
	userInterface();
	return 0;
}







