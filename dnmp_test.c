#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 1000

//����������
int k = 0;
//��ҵ������
int w = 0;

//������
struct free_area
{
    int id;
    int start;
    int end;
    int length;
    int state; 
}free_area[N];


//��ҵ��
struct job_area
{
    int id;
    int end;
    int length;
}job_area[N];




int n1;//���з����ĸ���

int n2;//��ҵ���ĸ���

struct kongxian
{
	int start;  //��ַ
	int end;    //����
	int length;  //����
}kongxian[N];

struct zuoye
{
	int start;  //��ַ
	int end;   //����
	int length;  //����
}zuoye[N];


//����
int cmp1(const void *a, const void *b)
{
	return (*(struct kongxian *)a).start - (*(struct kongxian *)b).start;
}

//����
int cmp2(const void *a, const void *b)
{
	return (*(struct zuoye *)a).start - (*(struct zuoye *)b).start;
}


void init()
{
	n1 = 1;  //��ʼʱֻ��һ��������

	n2 = 0;  //��ʼû����ҵ

	kongxian[0].start = 0;
	kongxian[0].end = 511;
	kongxian[0].length = 512;
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

int main()
{
	int i, j, t, len, flag, id;
	int front, middle, behind;
	int t1, t2;
	init();
	print1();
	printf("����1װ������ҵ,����0������ҵ,����-1����\n");

	while (scanf("%d", &t) != EOF)
	{
		if (t == 1)  //װ������ҵ
		{
			printf("��������ҵ��ռ�ÿռ�ĳ���: ");
			scanf("%d", &len);
			flag = 0;
			for (i = 0; i<n1; i++)
			{
				if (kongxian[i].length >= len)  //�״���Ӧ�㷨
				{
					flag = 1;
					break;
				}
			}
            
			if (!flag)
			{
				printf("�ڴ����ʧ��\n");
			}

			else
			{
				//������ҵ������ҵ����
				zuoye[n2].start = kongxian[i].start;
				zuoye[n2].end = zuoye[n2].start + len;
				zuoye[n2].length = len;
				n2++;  

				//��ҵ����1
				if (kongxian[i].length == len) //�÷���ȫ�����ڷ��䣬ɾ���ÿ��з���
				{
					for (j = i; j<n1 - 1; j++)
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






		else if (t == 0)
		{
			printf("����Ҫ���յ���ҵID ");

			scanf("%d", &id);

			front = middle = behind = 0;

			for (i = 0; i<n1; i++)
			{
				if (kongxian[i].start>zuoye[id].end)
					break;

				if (kongxian[i].end == zuoye[id].start)  //�����յ���ҵ�����п��з���
				{
					front = 1;
					t1 = i;
				}

				if (kongxian[i].start == zuoye[id].end)  //�����յ���ҵ�����п��з���
				{
					behind = 1;
					t2 = i;
				}
			}

			if (!front&&!behind)  //�����յ���ҵ���¾�û�п��з���
			{
				kongxian[n1].start = zuoye[id].start;
				kongxian[n1].end = zuoye[id].end;
				kongxian[n1].length = zuoye[id].length;
				n1++;  //���з�������һ��

				qsort(kongxian, n1, sizeof(struct kongxian), cmp1); //������з���������

				for (j = id; j<n2 - 1; j++)  //����ҵ������ɾ������ҵ
				{
					zuoye[j].start = zuoye[j + 1].start;
					zuoye[j].end = zuoye[j + 1].end;
					zuoye[j].length = zuoye[j + 1].length;
				}
				n2--;
			}

			if (front &&behind)  //�����յ���ҵ���¾��п��з���
				middle = 1;
            

			if (front&&!middle)  //�ϲ������յ���ҵ������Ŀ��з���
			{
				kongxian[t1].end += zuoye[id].length;
				kongxian[t1].length += zuoye[id].length;
				for (j = id; j<n2 - 1; j++)  //����ҵ������ɾ������ҵ
				{
					zuoye[j].start = zuoye[j + 1].start;
					zuoye[j].end = zuoye[j + 1].end;
					zuoye[j].length = zuoye[j + 1].length;
				}
				n2--;
			}



			if (middle)  //�ϲ������յ���ҵ�����µĿ��з���
			{
				kongxian[t1].end = kongxian[t2].end;
				kongxian[t1].length += (zuoye[id].length + kongxian[t2].length);
				//ɾ�����з���t2
				for (j = t2; j<n1 - 1; j++)
				{
					kongxian[j].start = kongxian[j + 1].start;
					kongxian[j].end = kongxian[j + 1].end;
					kongxian[j].length = kongxian[j + 1].length;
				}
				n1--;
				for (j = id; j<n2 - 1; j++)  //����ҵ������ɾ������ҵ
				{
					zuoye[j].start = zuoye[j + 1].start;
					zuoye[j].end = zuoye[j + 1].end;
					zuoye[j].length = zuoye[j + 1].length;
				}
				n2--;
			}
			if (behind &&!middle) //�ϲ������յ���ҵ������ķ���
			{
				kongxian[t2].start -= zuoye[id].length;
				kongxian[t2].length += zuoye[id].length;
				for (j = id; j<n2 - 1; j++)  //����ҵ������ɾ������ҵ
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
			printf("��������\n");
			break;
		}

		print1();
		print2();

	}


	return 0;
}




//����������
int fa_num = 0;
//��ҵ������
int jb_num = 0;

//������
struct free_area
{
    int start;
    int end;
    int length;
    int state; 
    
}free_area_arr[N];

//��ҵ��
struct job_area
{
	int start;
    int end;
    int length;

}job_area_arr[N];

//����
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

//��ʼ��

void init()
{
	fa_num = 1;   //��ʼ��һ��������
	jb_num = 0;	 
	free_area_arr[0].start = 0;
	free_area_arr[0].end = 1000;
	free_area_arr[0].length = 1000;

}

void print_free() //��ӡ���з���
{
	int i;
	for (i = 0; i<fa_num; i++)
		printf("���з���ID:%d ��ֹ:%d ����:%d ����:%d\n", i, free_area_arr[i].start, free_area_arr[i].end, free_area_arr[i].length);
}

void print_job() //��ӡ��ҵ����
{
	int i;
	for (i = 0; i<jb_num; i++)
		printf("��ҵ����ID:%d ��ֹ:%d ����:%d ����:%d\n", i, job_area_arr[i].start, job_area_arr[i].end, job_area_arr[i].length);
}



//�״���Ӧ�㷨
void first_fit()
{
	int flag = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	init();
	print_free();
	printf("��������ҵ��ռ�ÿռ�ĳ���: ");
	scanf("%d", &len);
	for (i = 0; i<fa_num; i++)
	{
		if (free_area_arr[i].length >= len)  //�״���Ӧ�㷨
		{
			flag = 1;
			break;
		}
	}    
	if (!flag)
	{
		printf("�ڴ����ʧ��\n");
	}

	else
	{
		//������ҵ������ҵ����
		job_area_arr[jb_num].start = free_area_arr[i].start;
		job_area_arr[jb_num].end = job_area_arr[jb_num].start + len;
		job_area_arr[jb_num].length = len;
		jb_num++;  
		//��ҵ����1
		if (free_area_arr[i].length == len) //�÷���ȫ�����ڷ��䣬ɾ���ÿ��з���
		{
			for (j = i; j<fa_num - 1; j++)
			{
				free_area_arr[j].start = free_area_arr[j + 1].start;
				free_area_arr[j].end = free_area_arr[j + 1].end;
				free_area_arr[j].length = free_area_arr[j + 1].length;
			}
			fa_num--;
		}
		else  //�ÿ��з����������ڷ��䣬ʣ������ڿ��з�����
		{
			free_area_arr[i].start += len;
			free_area_arr[i].length -= len;
		}

	}
}


//�����Ӧ�㷨
void best_fit()
{
	int flag = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	printf("��������ҵ��ռ�ÿռ�ĳ���: ");
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
		printf("�ڴ����ʧ��\n");
	}

	else
	{
		//������ҵ������ҵ����
		job_area_arr[jb_num].start = free_area_arr[i].start;
		job_area_arr[jb_num].end = job_area_arr[jb_num].start + len;
		job_area_arr[jb_num].length = len;
		jb_num++;  
		//��ҵ����1
		if (free_area_arr[i].length == len) //�÷���ȫ�����ڷ��䣬ɾ���ÿ��з���
		{
			for (j = i; j<fa_num - 1; j++)
			{
				free_area_arr[j].start = free_area_arr[j + 1].start;
				free_area_arr[j].end = free_area_arr[j + 1].end;
				free_area_arr[j].length = free_area_arr[j + 1].length;
			}
			fa_num--;
		}

		else  //�ÿ��з����������ڷ��䣬ʣ������ڿ��з�����
		{
			free_area_arr[i].start += len;
			free_area_arr[i].length -= len;
		}




	}
	//���п�������---��С����
	qsort(free_area_arr,fa_num,sizeof(struct free_area),cmp_sort_worst);
}



//�ʵ���㷨
void worst_fit()
{
	int flag = 0;
	int len = 0;
	int i = 0;
	int j = 0;
	printf("��������ҵ��ռ�ÿռ�ĳ���: ");
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
		printf("�ڴ����ʧ��\n");
	}

	else
	{
		//������ҵ������ҵ����
		job_area_arr[jb_num].start = free_area_arr[i].start;
		job_area_arr[jb_num].end = job_area_arr[jb_num].start + len;
		job_area_arr[jb_num].length = len;
		jb_num++;  
		//��ҵ����1
		if (free_area_arr[i].length == len) //�÷���ȫ�����ڷ��䣬ɾ���ÿ��з���
		{
			for (j = i; j<fa_num - 1; j++)
			{
				free_area_arr[j].start = free_area_arr[j + 1].start;
				free_area_arr[j].end = free_area_arr[j + 1].end;
				free_area_arr[j].length = free_area_arr[j + 1].length;
			}
			fa_num--;
		}

		else  //�ÿ��з����������ڷ��䣬ʣ������ڿ��з�����
		{
			free_area_arr[i].start += len;
			free_area_arr[i].length -= len;
		}
	}
	//���п�������---�Ӵ�С
	qsort(free_area_arr,fa_num,sizeof(struct free_area),cmp_sort_best);
}



//�����㷨
void recycle()
{
    int i, j, t, len, flag, id;
	int front, middle, behind;
	int t1, t2;
    printf("����Ҫ���յ���ҵID");
	scanf("%d", &id);
	front = middle = behind = 0;
	for (i = 0; i< fa_num; i++)
	{
		if (free_area_arr[i].start>job_area_arr[id].end)
			break;
		if (free_area_arr[i].end == job_area_arr[id].start)  //�����յ���ҵ�����п��з���
		{
			front = 1;
			t1 = i;
		}

		if (free_area_arr[i].start == job_area_arr[id].end)  //�����յ���ҵ�����п��з���
		{
			behind = 1;

			t2 = i;
		}
	}

	if (!front&&!behind)  //�����յ���ҵ���¾�û�п��з���
	{
		free_area_arr[fa_num].start = job_area_arr[id].start;
		free_area_arr[fa_num].end = job_area_arr[id].end;
		free_area_arr[fa_num].length = job_area_arr[id].length;
		fa_num++;  //���з�������һ��

		qsort(free_area_arr, fa_num,sizeof(struct free_area),cmp_free); //������з���������

		for (j = id; j<jb_num - 1; j++)  //����ҵ������ɾ������ҵ
		{
			job_area_arr[j].start = job_area_arr[j + 1].start;
			job_area_arr[j].end = job_area_arr[j + 1].end;
			job_area_arr[j].length = job_area_arr[j + 1].length;
		}
		jb_num--;
	}

	if (front&&behind)  //�����յ���ҵ���¾��п��з���
		middle = 1;


	if (front&&!middle)  //�ϲ������յ���ҵ������Ŀ��з���
	{
		free_area_arr[t1].end += job_area_arr[id].length;
		free_area_arr[t1].length += job_area_arr[id].length;
		for (j = id; j<jb_num - 1; j++)  //����ҵ������ɾ������ҵ
		{
			job_area_arr[j].start = job_area_arr[j + 1].start;
			job_area_arr[j].end = job_area_arr[j + 1].end;
			job_area_arr[j].length = job_area_arr[j + 1].length;
		}
		jb_num--;
	}

	if (middle)  //�ϲ������յ���ҵ�����µĿ��з���
	{
		free_area_arr[t1].end = free_area_arr[t2].end;
		free_area_arr[t1].length += (job_area_arr[id].length + free_area_arr[t2].length);

		//ɾ�����з���t2
		for (j = t2; j<fa_num - 1; j++)
		{
			free_area_arr[j].start = free_area_arr[j + 1].start;
			free_area_arr[j].end = free_area_arr[j + 1].end;
			free_area_arr[j].length = free_area_arr[j + 1].length;
		}
		fa_num--;
		for (j = id; j<jb_num - 1; j++)  //����ҵ������ɾ������ҵ
		{
			job_area_arr[j].start = job_area_arr[j + 1].start;
			job_area_arr[j].end = job_area_arr[j + 1].end;
			job_area_arr[j].length = job_area_arr[j + 1].length;
		}
			jb_num--;
	}
	if (behind &&!middle) //�ϲ������յ���ҵ������ķ���
	{
		free_area_arr[t2].start -= job_area_arr[id].length;
		free_area_arr[t2].length += job_area_arr[id].length;
		for (j = id; j<jb_num - 1; j++)  //����ҵ������ɾ������ҵ
		{
			job_area_arr[j].start = job_area_arr[j + 1].start;
			job_area_arr[j].end = job_area_arr[j + 1].end;
			job_area_arr[j].length = job_area_arr[j + 1].length;
		}
		jb_num--;

	}

}

//������
void manger()
{
	
	while(1)
	{
		
		printf("��ѡ��̬�����㷨");
		printf("***1:�״���Ӧ�㷨,2:�����Ӧ�㷨,3:���Ӧ�����㷨,4��������***:");
		int chose = 0;
		scanf("%d",&chose);
		switch (chose)
		{
			case1:first_fit();
			print("�Ƿ������ҵ:1����,0������");
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
			print("�Ƿ������ҵ:1����,0������");
			scanf("%d",&chosse2);
			if(chosse2){
				recycle();
			}
			print_free();
			print_job();
			break;

			case3:worst_fit();
			int chosse3 = 0;
			print("�Ƿ������ҵ:1����,0������");
			scanf("%d",&chosse3);
			if(chosse3){
				recycle();
			}
			print_free();
			print_job();
			break;

			default:
			printf("����!");
			
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

