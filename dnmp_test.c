#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 1000

//空闲区个数
int k = 0;
//作业区个数
int w = 0;

//空闲区
struct free_area
{
    int id;
    int start;
    int end;
    int length;
    int state; 
}free_area[N];


//作业区
struct job_area
{
    int id;
    int end;
    int length;
}job_area[N];




int n1;//空闲分区的个数

int n2;//作业区的个数

struct kongxian
{
	int start;  //起址
	int end;    //结束
	int length;  //长度
}kongxian[N];

struct zuoye
{
	int start;  //起址
	int end;   //结束
	int length;  //长度
}zuoye[N];


//排序
int cmp1(const void *a, const void *b)
{
	return (*(struct kongxian *)a).start - (*(struct kongxian *)b).start;
}

//排序
int cmp2(const void *a, const void *b)
{
	return (*(struct zuoye *)a).start - (*(struct zuoye *)b).start;
}


void init()
{
	n1 = 1;  //初始时只有一个空闲区

	n2 = 0;  //初始没有作业

	kongxian[0].start = 0;
	kongxian[0].end = 511;
	kongxian[0].length = 512;
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

int main()
{
	int i, j, t, len, flag, id;
	int front, middle, behind;
	int t1, t2;
	init();
	print1();
	printf("输入1装入新作业,输入0回收作业,输入-1结束\n");

	while (scanf("%d", &t) != EOF)
	{
		if (t == 1)  //装入新作业
		{
			printf("请输入作业的占用空间的长度: ");
			scanf("%d", &len);
			flag = 0;
			for (i = 0; i<n1; i++)
			{
				if (kongxian[i].length >= len)  //首次适应算法
				{
					flag = 1;
					break;
				}
			}
            
			if (!flag)
			{
				printf("内存分配失败\n");
			}

			else
			{
				//将该作业加入作业区里
				zuoye[n2].start = kongxian[i].start;
				zuoye[n2].end = zuoye[n2].start + len;
				zuoye[n2].length = len;
				n2++;  

				//作业数加1
				if (kongxian[i].length == len) //该分区全部用于分配，删除该空闲分区
				{
					for (j = i; j<n1 - 1; j++)
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






		else if (t == 0)
		{
			printf("输入要回收的作业ID ");

			scanf("%d", &id);

			front = middle = behind = 0;

			for (i = 0; i<n1; i++)
			{
				if (kongxian[i].start>zuoye[id].end)
					break;

				if (kongxian[i].end == zuoye[id].start)  //待回收的作业上面有空闲分区
				{
					front = 1;
					t1 = i;
				}

				if (kongxian[i].start == zuoye[id].end)  //待回收的作业下面有空闲分区
				{
					behind = 1;
					t2 = i;
				}
			}

			if (!front&&!behind)  //待回收的作业上下均没有空闲分区
			{
				kongxian[n1].start = zuoye[id].start;
				kongxian[n1].end = zuoye[id].end;
				kongxian[n1].length = zuoye[id].length;
				n1++;  //空闲分区增加一个

				qsort(kongxian, n1, sizeof(struct kongxian), cmp1); //插入空闲分区后排序

				for (j = id; j<n2 - 1; j++)  //在作业分区中删除该作业
				{
					zuoye[j].start = zuoye[j + 1].start;
					zuoye[j].end = zuoye[j + 1].end;
					zuoye[j].length = zuoye[j + 1].length;
				}
				n2--;
			}

			if (front &&behind)  //待回收的作业上下均有空闲分区
				middle = 1;
            

			if (front&&!middle)  //合并待回收的作业和上面的空闲分区
			{
				kongxian[t1].end += zuoye[id].length;
				kongxian[t1].length += zuoye[id].length;
				for (j = id; j<n2 - 1; j++)  //在作业分区中删除该作业
				{
					zuoye[j].start = zuoye[j + 1].start;
					zuoye[j].end = zuoye[j + 1].end;
					zuoye[j].length = zuoye[j + 1].length;
				}
				n2--;
			}



			if (middle)  //合并待回收的作业和上下的空闲分区
			{
				kongxian[t1].end = kongxian[t2].end;
				kongxian[t1].length += (zuoye[id].length + kongxian[t2].length);
				//删除空闲分区t2
				for (j = t2; j<n1 - 1; j++)
				{
					kongxian[j].start = kongxian[j + 1].start;
					kongxian[j].end = kongxian[j + 1].end;
					kongxian[j].length = kongxian[j + 1].length;
				}
				n1--;
				for (j = id; j<n2 - 1; j++)  //在作业分区中删除该作业
				{
					zuoye[j].start = zuoye[j + 1].start;
					zuoye[j].end = zuoye[j + 1].end;
					zuoye[j].length = zuoye[j + 1].length;
				}
				n2--;
			}
			if (behind &&!middle) //合并待回收的作业和下面的分区
			{
				kongxian[t2].start -= zuoye[id].length;
				kongxian[t2].length += zuoye[id].length;
				for (j = id; j<n2 - 1; j++)  //在作业分区中删除该作业
				{
					zuoye[j].start = zuoye[j + 1].start;
					zuoye[j].end = zuoye[j + 1].end;
					zuoye[j].length = zuoye[j + 1].length;
				}
				n2--;
			}
		}





		else
		{
			printf("操作结束\n");
			break;
		}

		print1();
		print2();

	}


	return 0;
}




//空闲区个数
int fa_num = 0;
//作业区个数
int jb_num = 0;

//空闲区
struct free_area
{
    int start;
    int end;
    int length;
    int state; 
    
}free_area_arr[N];

//作业区
struct job_area
{
	int start;
    int end;
    int length;

}job_area_arr[N];

//排序
int cmp_free(const void* a,const void* b)
{
	struct free_area* f = (struct free_area*)a;
	struct free_area* t = (struct free_area*)b;
	int num1 = f->start;
	int num2 = t->start;
	return num1 - num2;

}

int cmp_sort_best(const void* a,const void* b)
{
	struct free_area* f = (struct free_area*)a;
	struct free_area* t = (struct free_area*)b;
	int num1 = f->length;
	int num2 = t->length;
	return num1 - num2;
}

int cmp_sort_worst(const void* a,const void* b)
{
	struct free_area* f = (struct free_area*)a;
	struct free_area* t = (struct free_area*)b;
	int num1 = f->length;
	int num2 = t->length;
	return num2 - num1;
}


int cmp_job(const void* a,const void* b)
{
	struct job_area* f = (struct job_area*)a;
	struct job_area* t = (struct job_area*)b;
	int num1 = f->start;
	int num2 = t->start;
	return num1 - num2;
}

//初始化

void init()
{
	fa_num = 1;   //初始化一个空闲区
	jb_num = 0;	 
	free_area_arr[0].start = 0;
	free_area_arr[0].end = 1000;
	free_area_arr[0].length = 1000;

}

void print_free() //打印空闲分区
{
	int i;
	for (i = 0; i<fa_num; i++)
		printf("空闲分区ID:%d 起止:%d 结束:%d 长度:%d\n", i, free_area_arr[i].start, free_area_arr[i].end, free_area_arr[i].length);
}

void print_job() //打印作业分区
{
	int i;
	for (i = 0; i<jb_num; i++)
		printf("作业分区ID:%d 起止:%d 结束:%d 长度:%d\n", i, job_area_arr[i].start, job_area_arr[i].end, job_area_arr[i].length);
}



//首次适应算法
void first_fit()
{
	int flag = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	init();
	print_free();
	printf("请输入作业的占用空间的长度: ");
	scanf("%d", &len);
	for (i = 0; i<fa_num; i++)
	{
		if (free_area_arr[i].length >= len)  //首次适应算法
		{
			flag = 1;
			break;
		}
	}    
	if (!flag)
	{
		printf("内存分配失败\n");
	}

	else
	{
		//将该作业加入作业区里
		job_area_arr[jb_num].start = free_area_arr[i].start;
		job_area_arr[jb_num].end = job_area_arr[jb_num].start + len;
		job_area_arr[jb_num].length = len;
		jb_num++;  
		//作业数加1
		if (free_area_arr[i].length == len) //该分区全部用于分配，删除该空闲分区
		{
			for (j = i; j<fa_num - 1; j++)
			{
				free_area_arr[j].start = free_area_arr[j + 1].start;
				free_area_arr[j].end = free_area_arr[j + 1].end;
				free_area_arr[j].length = free_area_arr[j + 1].length;
			}
			fa_num--;
		}
		else  //该空闲分区部分用于分配，剩余的留在空闲分区中
		{
			free_area_arr[i].start += len;
			free_area_arr[i].length -= len;
		}

	}
}


//最佳适应算法
void best_fit()
{
	int flag = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	printf("请输入作业的占用空间的长度: ");
	scanf("%d", &len);
	for (i = 0; i<fa_num; i++)
	{
		if (free_area_arr[i].length >= len)
		{
			flag = 1;
			break;
		}
	}    
	if (!flag)
	{
		printf("内存分配失败\n");
	}

	else
	{
		//将该作业加入作业区里
		job_area_arr[jb_num].start = free_area_arr[i].start;
		job_area_arr[jb_num].end = job_area_arr[jb_num].start + len;
		job_area_arr[jb_num].length = len;
		jb_num++;  
		//作业数加1
		if (free_area_arr[i].length == len) //该分区全部用于分配，删除该空闲分区
		{
			for (j = i; j<fa_num - 1; j++)
			{
				free_area_arr[j].start = free_area_arr[j + 1].start;
				free_area_arr[j].end = free_area_arr[j + 1].end;
				free_area_arr[j].length = free_area_arr[j + 1].length;
			}
			fa_num--;
		}

		else  //该空闲分区部分用于分配，剩余的留在空闲分区中
		{
			free_area_arr[i].start += len;
			free_area_arr[i].length -= len;
		}




	}
	//排列空闲区域---从小到大
	qsort(free_area_arr,fa_num,sizeof(struct free_area),cmp_sort_worst);
}



//最坏实验算法
void worst_fit()
{
	int flag = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	printf("请输入作业的占用空间的长度: ");
	scanf("%d", &len);
	for (i = 0; i<fa_num; i++)
	{
		if (free_area_arr[i].length >= len)
		{
			flag = 1;
			break;
		}
	}    
	if (!flag)
	{
		printf("内存分配失败\n");
	}

	else
	{
		//将该作业加入作业区里
		job_area_arr[jb_num].start = free_area_arr[i].start;
		job_area_arr[jb_num].end = job_area_arr[jb_num].start + len;
		job_area_arr[jb_num].length = len;
		jb_num++;  
		//作业数加1
		if (free_area_arr[i].length == len) //该分区全部用于分配，删除该空闲分区
		{
			for (j = i; j<fa_num - 1; j++)
			{
				free_area_arr[j].start = free_area_arr[j + 1].start;
				free_area_arr[j].end = free_area_arr[j + 1].end;
				free_area_arr[j].length = free_area_arr[j + 1].length;
			}
			fa_num--;
		}

		else  //该空闲分区部分用于分配，剩余的留在空闲分区中
		{
			free_area_arr[i].start += len;
			free_area_arr[i].length -= len;
		}
	}
	//排列空闲区域---从大到小
	qsort(free_area_arr,fa_num,sizeof(struct free_area),cmp_sort_best);
}



//回收算法
void recycle()
{
    int i, j, t, len, flag, id;
	int front, middle, behind;
	int t1, t2;
    printf("输入要回收的作业ID");
	scanf("%d", &id);
	front = middle = behind = 0;
	for (i = 0; i< fa_num; i++)
	{
		if (free_area_arr[i].start>job_area_arr[id].end)
			break;
		if (free_area_arr[i].end == job_area_arr[id].start)  //待回收的作业上面有空闲分区
		{
			front = 1;
			t1 = i;
		}

		if (free_area_arr[i].start == job_area_arr[id].end)  //待回收的作业下面有空闲分区
		{
			behind = 1;

			t2 = i;
		}
	}

	if (!front&&!behind)  //待回收的作业上下均没有空闲分区
	{
		free_area_arr[fa_num].start = job_area_arr[id].start;
		free_area_arr[fa_num].end = job_area_arr[id].end;
		free_area_arr[fa_num].length = job_area_arr[id].length;
		fa_num++;  //空闲分区增加一个

		qsort(free_area_arr, fa_num,sizeof(struct free_area),cmp_free); //插入空闲分区后排序

		for (j = id; j<jb_num - 1; j++)  //在作业分区中删除该作业
		{
			job_area_arr[j].start = job_area_arr[j + 1].start;
			job_area_arr[j].end = job_area_arr[j + 1].end;
			job_area_arr[j].length = job_area_arr[j + 1].length;
		}
		jb_num--;
	}

	if (front&&behind)  //待回收的作业上下均有空闲分区
		middle = 1;


	if (front&&!middle)  //合并待回收的作业和上面的空闲分区
	{
		free_area_arr[t1].end += job_area_arr[id].length;
		free_area_arr[t1].length += job_area_arr[id].length;
		for (j = id; j<jb_num - 1; j++)  //在作业分区中删除该作业
		{
			job_area_arr[j].start = job_area_arr[j + 1].start;
			job_area_arr[j].end = job_area_arr[j + 1].end;
			job_area_arr[j].length = job_area_arr[j + 1].length;
		}
		jb_num--;
	}

	if (middle)  //合并待回收的作业和上下的空闲分区
	{
		free_area_arr[t1].end = free_area_arr[t2].end;
		free_area_arr[t1].length += (job_area_arr[id].length + free_area_arr[t2].length);

		//删除空闲分区t2
		for (j = t2; j<fa_num - 1; j++)
		{
			free_area_arr[j].start = free_area_arr[j + 1].start;
			free_area_arr[j].end = free_area_arr[j + 1].end;
			free_area_arr[j].length = free_area_arr[j + 1].length;
		}
		fa_num--;
		for (j = id; j<jb_num - 1; j++)  //在作业分区中删除该作业
		{
			job_area_arr[j].start = job_area_arr[j + 1].start;
			job_area_arr[j].end = job_area_arr[j + 1].end;
			job_area_arr[j].length = job_area_arr[j + 1].length;
		}
			jb_num--;
	}
	if (behind &&!middle) //合并待回收的作业和下面的分区
	{
		free_area_arr[t2].start -= job_area_arr[id].length;
		free_area_arr[t2].length += job_area_arr[id].length;
		for (j = id; j<jb_num - 1; j++)  //在作业分区中删除该作业
		{
			job_area_arr[j].start = job_area_arr[j + 1].start;
			job_area_arr[j].end = job_area_arr[j + 1].end;
			job_area_arr[j].length = job_area_arr[j + 1].length;
		}
		jb_num--;

	}

}

//管理函数
void manger()
{
	
	while(1)
	{
		
		printf("请选择动态分配算法");
		printf("***1:首次适应算法,2:最佳适应算法,3:最坏适应分配算法,4结束操作***:");
		int chose = 0;
		scanf("%d",&chose);
		switch (chose)
		{
			case1:first_fit();
			print("是否回收作业:1回收,0不回收");
			int chosse1 = 0;
			scanf("%d",&chosse1);
			if(chosse1){
				recycle();
			}
			print_free();
			print_job();
			break;
			
			case2:best_fit();
			int chosse2 = 0;
			print("是否回收作业:1回收,0不回收");
			scanf("%d",&chosse2);
			if(chosse2){
				recycle();
			}
			print_free();
			print_job();
			break;

			case3:worst_fit();
			int chosse3 = 0;
			print("是否回收作业:1回收,0不回收");
			scanf("%d",&chosse3);
			if(chosse3){
				recycle();
			}
			print_free();
			print_job();
			break;

			default:
			printf("错误!");
			
		}

		if(chose == 4)
		{
			break;
		}

	}

}


int main()
{
	manger();

	return 0;
}

