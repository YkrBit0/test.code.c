
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
    printf("��ǰϵͳ������Դʣ�ࣺ");
    for(i = 0; i < 4 ;i++)
    {
        printf("%d ",Available[i]);
    }
    printf("\n");
    printf("��ǰϵͳ��Դ�����\n");
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
    printf("Need����:\n");
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


    printf("'胜多负少�?'");

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

int n1;//���з����ĸ���

int n2;//��ҵ���ĸ���

struct kongxian
{
	int start;  //��ַ
	int end;    //����
	int length;  //����
}kongxian[Num];

struct zuoye
{
	int start;  //��ַ
	int end;   //����
	int length;  //����
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
	n1 = 1;  //��ʼʱֻ��һ��������

	n2 = 0;  //��ʼû����ҵ

	kongxian[0].start = 0;
	kongxian[0].end = 1000;
	kongxian[0].length = 1000;
}
void print1() //��ӡ���з���
{
	int i;
	for (i = 0; i<n1; i++)
		printf("���з���ID:%d ��ֹ:%d ����:%d ����:%d\n", i, kongxian[i].start, kongxian[i].end, kongxian[i].length);
}

void print2() //��ӡ��ҵ����
{
	int i;
	for (i = 0; i<n2; i++)
		printf("��ҵ����ID:%d ��ֹ:%d ����:%d ����:%d\n", i, zuoye[i].start, zuoye[i].end, zuoye[i].length);
}


void arr()
{
    int t = 0;
    int fg = 0;
    int len = 0;
    int i = 0;
	
		printf("��������ҵ��ռ�ÿռ�ĳ���: ");
		scanf("%d", &len);
	fg = 0;
		for (int i = 0; i<n1; i++)
		{
			if (kongxian[i].length >= len)  //�״���Ӧ�㷨
			{
			fg = 1;
				break;
			}
		}
            
			if ( fg)
			{
				printf("�ڴ����ʧ��\n");
			}

			else
			{
				//������ҵ������ҵ����
				zuoye[n2].start = kongxian[i].start;
				zuoye[n2].end = zuoye[n2].start + len;
				zuoye[n2].length = len;
				n2++;  //��ҵ����1
				if (kongxian[i].length == len) //�÷���ȫ�����ڷ��䣬ɾ���ÿ��з���
				{
					for (int j = i; j<n1 - 1; j++)
					{
						kongxian[j].start = kongxian[j + 1].start;
						kongxian[j].end = kongxian[j + 1].end;
						kongxian[j].length = kongxian[j + 1].length;
					}
					n1--;
				}

				else  //�ÿ��з����������ڷ��䣬ʣ������ڿ��з�����
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
        printf("����1װ������ҵ,����0������ҵ,����-1����:");
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
//�ڴ��С
#define size_num 1500
//����������
int empty_num = 0;
//��ҵ������
int task_num = 0;
//������
struct empty_area
{
    int start;
    int end;
    int length;
    int state; 
}empty_area_array[Num];
//��ҵ��
struct task_area
{
	int start;
    int end;
    int length;
}task_area_array[Num];
//����
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
//��ʼ��
void init()
{
	empty_num = 1;   //��ʼ��һ��������
	task_num = 0;	 
	empty_area_array[0].start = 0;
	empty_area_array[0].end = size_num;
	empty_area_array[0].length = size_num;
}
void print_empty() //��ӡ���з���
{
	int i;
	for (i = 0; i<empty_num; i++)
	printf("���з���ID:%d ��ֹ:%d ����:%d ����:%d\n", i, empty_area_array[i].start, empty_area_array[i].end, empty_area_array[i].length);
}
void print_task() //��ӡ��ҵ����
{
	int i;
	for (i = 0; i<task_num; i++)
	printf("��ҵ����ID:%d ��ֹ:%d ����:%d ����:%d\n", i, task_area_array[i].start, task_area_array[i].end, task_area_array[i].length);
}
//�״���Ӧ�㷨
void first_fit()
{
	int fg = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	printf("��������ҵ��ռ�ÿռ�ĳ���: ");
	scanf("%d", &len);
	for (i = 0; i<empty_num; i++)
	{
		if (empty_area_array[i].length >= len)  //�״���Ӧ�㷨
		{
		fg = 1;
			break;
		}
	}  
	if ( fg)
	{
		printf("�ڴ����ʧ��\n");
	}
	else
	{
		//������ҵ������ҵ����
		task_area_array[task_num].start = empty_area_array[i].start;
		task_area_array[task_num].end = task_area_array[task_num].start + len;
		task_area_array[task_num].length = len;
		task_num++;  
		//��ҵ����1
		if (empty_area_array[i].length == len) //�÷���ȫ�����ڷ��䣬ɾ���ÿ��з���
		{
			for (j = i; j<empty_num - 1; j++)
			{
				empty_area_array[j].start = empty_area_array[j + 1].start;
				empty_area_array[j].end = empty_area_array[j + 1].end;
				empty_area_array[j].length = empty_area_array[j + 1].length;
			}
			empty_num--;
		}
		else  //�ÿ��з����������ڷ��䣬ʣ������ڿ��з�����
		{
			empty_area_array[i].start += len;
			empty_area_array[i].length -= len;
		}
	}
}
//�����Ӧ�㷨
void best_fit()
{
	int fg = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	printf("��������ҵ��ռ�ÿռ�ĳ���: ");
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
		printf("�ڴ����ʧ��\n");
	}
	else
	{
		//������ҵ������ҵ����
		task_area_array[task_num].start = empty_area_array[i].start;
		task_area_array[task_num].end = task_area_array[task_num].start + len;
		task_area_array[task_num].length = len;
		task_num++;  
		//��ҵ����1
		if (empty_area_array[i].length == len) //�÷���ȫ�����ڷ��䣬ɾ���ÿ��з���
		{
			for (j = i; j<empty_num - 1; j++)
			{
				empty_area_array[j].start = empty_area_array[j + 1].start;
				empty_area_array[j].end = empty_area_array[j + 1].end;
				empty_area_array[j].length = empty_area_array[j + 1].length;
			}
			empty_num--;
		}
		else  //�ÿ��з����������ڷ��䣬ʣ������ڿ��з�����
		{
			empty_area_array[i].start += len;
			empty_area_array[i].length -= len;
		}
	}
}
//�ʵ���㷨
void worst_fit()
{
	int fg = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	printf("��������ҵ��ռ�ÿռ�ĳ���: ");
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
		printf("�ڴ����ʧ��\n");
	}
	else
	{
		//������ҵ������ҵ����
		task_area_array[task_num].start = empty_area_array[i].start;
		task_area_array[task_num].end = task_area_array[task_num].start + len;
		task_area_array[task_num].length = len;
		task_num++;  
		//��ҵ����1
		if (empty_area_array[i].length == len) //�÷���ȫ�����ڷ��䣬ɾ���ÿ��з���
		{
			for (j = i; j<empty_num - 1; j++)
			{
				empty_area_array[j].start = empty_area_array[j + 1].start;
				empty_area_array[j].end = empty_area_array[j + 1].end;
				empty_area_array[j].length = empty_area_array[j + 1].length;
			}
			empty_num--;
		}
		else  //�ÿ��з����������ڷ��䣬ʣ������ڿ��з�����
		{
			empty_area_array[i].start += len;
			empty_area_array[i].length -= len;
		}
	}
	//���п�������---�Ӵ�С
}
//�����㷨
void release(int sign)
{
    int i, j, t, len, fg, id;
	int front, middle, behind;
	int t1, t2;
    printf("����Ҫ���յ���ҵID:");
	scanf("%d", &id);
	front = middle = behind = 0;
	for (i = 0; i< empty_num; i++)
	{
		if (empty_area_array[i].start>task_area_array[id].end)
			break;
		if (empty_area_array[i].end == task_area_array[id].start)  //�����յ���ҵ�����п��з���
		{
			front = 1;
			t1 = i;
		}
		if (empty_area_array[i].start == task_area_array[id].end)  //�����յ���ҵ�����п��з���
		{
			behind = 1;
			t2 = i;
		}
	}
	if (!front&&!behind)  //�����յ���ҵ���¾�û�п��з���
	{
		empty_area_array[empty_num].start = task_area_array[id].start;
		empty_area_array[empty_num].end = task_area_array[id].end;
		empty_area_array[empty_num].length = task_area_array[id].length;
		empty_num++;  //���з�������һ��
		qsort(empty_area_array, empty_num,sizeof(struct empty_area),cmp_free); //������з���������
		for (j = id; j<task_num - 1; j++)  //����ҵ������ɾ������ҵ
		{
			task_area_array[j].start = task_area_array[j + 1].start;
			task_area_array[j].end = task_area_array[j + 1].end;
			task_area_array[j].length = task_area_array[j + 1].length;
		}
		task_num--;
	}
	if (front&&behind)  //�����յ���ҵ���¾��п��з���
		middle = 1;


	if (front&&!middle)  //�ϲ������յ���ҵ������Ŀ��з���
	{
		empty_area_array[t1].end += task_area_array[id].length;
		empty_area_array[t1].length += task_area_array[id].length;
		for (j = id; j<task_num - 1; j++)  //����ҵ������ɾ������ҵ
		{
			task_area_array[j].start = task_area_array[j + 1].start;
			task_area_array[j].end = task_area_array[j + 1].end;
			task_area_array[j].length = task_area_array[j + 1].length;
		}
		task_num--;
	}
	if (middle)  //�ϲ������յ���ҵ�����µĿ��з���
	{
		empty_area_array[t1].end = empty_area_array[t2].end;
		empty_area_array[t1].length += (task_area_array[id].length + empty_area_array[t2].length);
		//ɾ�����з���t2
		for (j = t2; j<empty_num - 1; j++)
		{
			empty_area_array[j].start = empty_area_array[j + 1].start;
			empty_area_array[j].end = empty_area_array[j + 1].end;
			empty_area_array[j].length = empty_area_array[j + 1].length;
		}
		empty_num--;
		for (j = id; j<task_num - 1; j++)  //����ҵ������ɾ������ҵ
		{
			task_area_array[j].start = task_area_array[j + 1].start;
			task_area_array[j].end = task_area_array[j + 1].end;
			task_area_array[j].length = task_area_array[j + 1].length;
		}
		task_num--;
	}
	if (behind &&!middle) //�ϲ������յ���ҵ������ķ���
	{
		empty_area_array[t2].start -= task_area_array[id].length;
		empty_area_array[t2].length += task_area_array[id].length;
		for (j = id; j<task_num - 1; j++)  //����ҵ������ɾ������ҵ
		{
			task_area_array[j].start = task_area_array[j + 1].start;
			task_area_array[j].end = task_area_array[j + 1].end;
			task_area_array[j].length = task_area_array[j + 1].length;
		}
		task_num--;
	}
	//�ж��㷨��ȷ�������������з�ʽ
	if(sign == 2)
	{
		qsort(empty_area_array,empty_num,sizeof(struct empty_area),cmp_sort_best);
	}
	if(sign == 3)
	{
		qsort(empty_area_array,empty_num,sizeof(struct empty_area),cmp_sort_worst);
	}
}

//������
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
		printf("��ѡ��̬�����㷨");
		printf("***1:�״���Ӧ�㷨,2:�����Ӧ�㷨,3:���Ӧ�����㷨***:");
		int chose = 0;
		scanf("%d",&chose);
		switch (chose)
		{
			case 1:
			while (1)
			{
				printf("�Ƿ������ҵ:1װ����ҵ,0������ҵ,-1��������!:");
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
					printf("��������!");
					ft = true;
					break;
				}
			}
			break;
			case 2:
			while (1)
			{
				printf("�Ƿ������ҵ:1װ����ҵ,0������ҵ,-1��������!");
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
					printf("��������!");
					ft = true;
					break;
				}
			}
			break;
			case 3:
			while (1)
			{
				printf("�Ƿ������ҵ:1װ����ҵ,0������ҵ,-1��������!:");
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
					printf("��������!\n");
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
#define FREE 0                   // �ڴ����״̬ 
#define FULL 1                   // �ڴ�ռ��״̬ 
#define MAX_ALLOC_SIZE 65536     // ����ϵͳ����������ռ�Ĵ�С 
#define MIN_MEMORY_DIFFER 2      // ��ֹ��Ƭ��̫�����أ�������С��ֵ��������-����Ƭ��С�� 

struct Node{                     // ���з�������� and ��ʹ�÷��������
	int p_id;                    // ��ǰ���з�������id��Ψһ 
	long address, size;
	int status;	 
	struct Node *pre, *next;

};

struct Node *usedLink, *freeLink, *initMemory;
long start_add, end_add, memory_size; // ��ʼ��ַ����ֹ��ַ���ڴ��С 
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
	// ���з����� & ��ʹ�÷����� �� ˵��������ͷ��㣬����������� 
	usedLink = (struct Node *)malloc(sizeof(struct Node));
	freeLink = (struct Node *)malloc(sizeof(struct Node));
	initMemory = (struct Node *)malloc(sizeof(struct Node));
	
	if(!freeLink || !usedLink || !initMemory){
		printf("�ռ�����ʧ�ܣ�");
		return 0;
	}
	
	// ��ʼ����ʹ�÷������� 
	usedLink->p_id = -1;
	usedLink->size = 0;
	usedLink->address = 0;
	usedLink->pre = usedLink->next = NULL;
	usedLink->status = FULL;
	
	// ��ʼ�����з������� 
	freeLink->p_id = -1;
	freeLink->size = 0;
	freeLink->address = 0;
	freeLink->pre = freeLink->next = NULL;
	freeLink->status = FULL;

	// ��ʼ���ڴ�ռ� 
	initMemory->p_id = -1;
	initMemory->size = 0;
	initMemory->address = 0;
	initMemory->pre = initMemory->next = NULL;
	initMemory->status = FULL;
	
	return 1;
	
}
char *getStatus(int status){
	return status ? "ռ��" : "����";
}
struct Node *deepCopyNode(struct Node *p1, struct Node *p2){  // �Խڵ������� 
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
void sortLink(struct Node *temp){   // ����������������Ӧ�Ŀ��з����� 
	// ��ͷ��㣬��˴˴� freeLink һ���ǿ� 
	struct Node *p = freeLink->next;
	struct Node *preNode = freeLink;

	// ������״���ӽ�㣬�������� 
	if(!p){
		freeLink->next = temp;
		temp->pre = freeLink;
		return;
	}
	// ���տ��з���������С������в������򣬻�ȡ��һ����Ҫ�����λ�� 
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
void memoryRecovery(int p_id){  // �����ڴ� 
	// ʹ��initMemory �Լ� freeLink
	// ����initMemory ���յ��ڴ����� ʹ��sortLink() �������뵽���з����� freeLink ��
	
	// ��������initMemory���ҵ�p_id ���ڵ��ڴ棬�ж���֮�ڽӵ����������ڴ��״̬
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
		printf("δ�ҵ�ָ�� id ���ڴ棡");
		return;
	}
	// �ҵ���Ӧid���ڴ��㣬�ڴ�ָ��Ϊ p����ȡ�ڽӵ������ڴ��״̬ 
	struct Node *freeHead = freeLink->next;
	struct Node *preNode = p->pre, *nextNode = p->next;
	int preNodeStatus = preNode->status, nextNodeStatus = nextNode->status;
	
//	printf("%d\n%\d\n", nextNodeStatus, preNodeStatus);
	
	
	if(preNodeStatus < nextNodeStatus){  // ǰ���к��� 
		printf("\nǰ���к���\n");
		// ֻ�޸�ǰһ�������Ĵ�С��ɾ����λ����������� 
		preNode->size += p->size;
		preNode->next = nextNode;
		if(nextNode)
			nextNode->pre = preNode;
		free(p);
	}
	else if(preNodeStatus > nextNodeStatus){  // �����ǰ�� 
		// ֻ�޸ĺ�һ�������Ĵ�С��ɾ����λ����������� 
		printf("\n�����ǰ��\n");
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
	else if(!nextNodeStatus){  // ǰ�������    
		// �����ڵ����������ϲ� 
		printf("\nǰ�������\n");
		preNode->size += p->size;
		if(nextNode)
			preNode->size += nextNode->size;
		preNode->next = NULL;
		free(p);
		free(nextNode);	
	}
	else{  // ǰ����� 
		// Ϊ�������������������д��������ַ����С�������ݻ�������С���뵽���з��������ʵ�λ��
		printf("\nǰ�����\n");
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		temp->pre = temp->next = NULL;
		temp->address = p->address;
		temp->size = p->size;
		temp->p_id = p->p_id; 
		temp->status = FREE;
		p->status = FREE; 
	}
} 
void bestFitAlloc(long prgSize){  // �����Ӧ�㷨 

	struct Node *p = freeLink->next, *preNode = freeLink; 
	
	// ���ҵ�Ӧ��������ڴ�� 
	while(p && prgSize > p->size){
		p = p->next;
		preNode = preNode->next;
	}
	if(!p){
		printf("�����������ڴ�Ƭ���ȣ��޷�װ�룡");
		return;
	}
	
	p->size = p->size - prgSize;
	if(!p->size || p->size < MIN_MEMORY_DIFFER) // װ�� 
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
		// ��ÿ�ζ����������з���������Ч���Ʊغܵ�
		// �����ֻ����λ�����ڴ�Ƭ��ȥ����Ƭ��С��"ժ��"��Ȼ�����¶�������������в�������
		sortLink(p);
	} 
	printf("freeLink:\n");
	displayLink(freeLink);
	printf("usedLink:\n");
	displayLink(usedLink);	
}
void callAllocAlgorithm(){ // ���÷����㷨���˴���Ҫ�����û�������Ϣ 

	int prgNum = 0, i = 0;
	long prgSize = 0, p_id = -1;
	printf("��������ӵĳ���������"); 
	scanf("%d", &prgNum);
	for(;i < prgNum;i++){
		printf("\n������� %d ������� id ����С��", i + 1);
		scanf("%ld%d", &p_id, &prgSize);
		if(prgSize <= 0 || prgSize >= MAX_ALLOC_SIZE){
			printf("�ڴ�����ʧ�ܣ�");
			return;
		}
		
		bestFitAlloc(prgSize);
	} 	

}
void callRecoveryAlgorithm(){
	
	struct Node *mHead = initMemory, *fHead = freeLink;
	int prgNum = 0, i = 0;
	int p_id = -1;
	printf("��������յ��ڴ�������"); 
	scanf("%d", &prgNum);
	for(;i < prgNum;i++){
		printf("\n������� %d ���ڴ�� id:", i + 1);
		scanf("%ld", &p_id);
		if(p_id == -1){
			printf("�޴��ڴ���Ի��գ�");
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
void userInterface(){  // �û����� 
	
	int i = 0;
	long curAdd = 0;
	int init_success = 0;
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node *lastNode, *preNode;
		
	// ��ʼ����ʼ��ַ����ֹ��ַ
	start_add = end_add = -1; 
	
	printf("���ʼ���ڴ����׵�ַ���ڴ��С��");
	scanf("%ld%ld", &start_add, &memory_size);
	if(memory_size > MAX_ALLOC_SIZE){
		printf("�����ڴ泬���ڴ��С��ֵ��");
		return;
	}
	
	init_success = initLink();
	if(!init_success){
		printf("�ڴ�����ʧ�ܣ�");
		return;
	}
	// �ڴ�����ɹ���ִ��������룬������������ڴ�ռ� 
	
	temp->p_id = -1;
	temp->address = start_add;
	temp->size = memory_size;
	temp->pre = temp->next = NULL;
	temp->status = FREE;
	
	insertNode(initMemory, temp);
	lastNode = temp;   // lastNode ָ���ʼ�ڴ����һ����� 
	preNode = temp->pre;
	
	int p_id = -1, p_num = 0;
	long p_size = -1;
	printf("������������Դ�Ľ��̸�����");
	scanf("%d", &p_num);
	for(i = 0;i < p_num;i++){
		printf("������� %d �����̵���ķ����ż����С��", i + 1);
		scanf("%d%ld", &p_id, &p_size);
		// ��ʼ������������ 
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		p->address = curAdd;
		p->p_id = p_id;
		p->size = p_size;
		p->status = FULL;
		p->pre = p->next = NULL; 

		curAdd += p_size;
		if(curAdd > start_add + memory_size){
			printf("�ڴ���䳬��ϵͳ���ƣ�");
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
	// ��������������initMemory�ڴ汻����ʹ�� 
	printf("initMemory:\n");
	displayLink(initMemory);
	callRecoveryAlgorithm();
	callAllocAlgorithm();	
}

void displayLink(struct Node *head){
	struct Node *p = head->next;
	while(p){
		printf("id:%d �׵�ַ��%ld ��С��%ld ״̬��%s\n", p->p_id, p->address, p->size, getStatus(p->status));
		p = p->next;
	}
}

int main()
{
	userInterface();
	return 0;
}







