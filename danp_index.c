#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 10000

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





int main()
{
	int i, j, t, len, flag, id;
	int front, middle, behind;
	int t1, t2;
	int chose = 0;
	init();
	print1();
	printf("��ѡ��̬�����㷨");
	printf("***1:�״���Ӧ�㷨,2:�����Ӧ�㷨,3:���Ӧ�����㷨***:");
	scanf("%d",&chose);
	printf("����1װ������ҵ,����0������ҵ,����-1����:");
	printf("\n");
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
				n2++;  //��ҵ����1
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