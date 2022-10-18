#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
// ��ʼ������
int Max[5][4] = {0,0,1,2,1,7,5,0,2,3,5,6,0,6,5,2,0,6,5,6};

int Allocation[5][4]={0,0,1,2,1,0,0,0,1,3,5,4,0,6,3,2,0,0,1,4};

int Need[5][4] = {0};

int Available[4] = {1,5,2,0};

int Work[4];

bool Finsh[5];

int Request[4];

int Sequence[5];

//�ҳ�need����
int find_need()
{   
    int i = 0;
    int j = 0;
    printf("���Need����:\n");
    for(i = 0;i<5;i++)
    {
        for(j =0;j<4;j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
            printf("%d",Need[i][j]);
        }
        printf("\n");

    }
}

//�����ǰϵͳ����Դ���
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
    printf(" Max");
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
// �жϰ�ȫ��
bool is_safe()
{
    int i,j;
    int p = 0;

    bool t = false;

    // ��Available��ֵ��Work
    for(i = 0;i < 4; i++)
    {
        Work[i] = Available[i];

    }
    // ��ʼ�����н���Ϊδ��� 
    for(i = 0;i < 5; i++)
    {
        Finsh[i] = false;
    }

    while (1)
    {
        for(i = 0;i < 5;i++)
        {
            if(Finsh[i]) continue;  //�жϽ����Ƿ����
            t = true;
            for(j = 0;j < 4; j++)
            {
                if(Need[i][j] <= Work[j]) continue;
                else{
                    t = false;
                    break;
                }
            }
            if(t) break;    //�жϵ�i�������Ƿ�����NeedС�ڵ���Work
        }

        if(t && (Finsh[i] == false)) //�Ƿ��ҵ�NeedС�ڵ���Work�Ľ��̲��ҽ���δ��� 
        {
            for(j = 0; j < 4;j++)
            {
                Work[j] = Work[j]+Allocation[i][j];

            }
            Finsh[i] = true;   //�������
            Sequence[p] = i;
            p++;
        }

        else
        {
            for(j = 0; j < 5; j++)
            {
                if(Finsh[j]) continue;

                else return false;
            }
            return true;
        }

    }
    return true;
}
//��Դ������ѡ�� 
void request_problem(int num)   
{
    int i;
    bool t = true;
    for(i = 0; i < 4; i++)  //�ж�Request�Ƿ�С�ڵ���Need
    {
        if(Request[i] <= Need[num][i]) continue;
        else
        {
            printf("�������! \n");
            t = false;
            break;
        }
    }
    if(t)
    {
        for(i = 0;i < 4; i++) //�ж�Requesti�Ƿ�С�ڵ���Availablei 
        {
            if(Request[i] <= Available[i]) continue;
            else
            {
                printf("�������\n");
                t = false;
                break;
            }
        }
    }
    if(t)
    {
        for(i = 0;i< 4;i++)
        {
            Available[i] = Available[i] - Request[i];
            Allocation[num][i] = Allocation[num][i] + Request[i];
            Need[num][i] = Need[num][i] - Request[i];
        }
        print_resources();   //�������������Դ���
        if(is_safe())
        {
            printf("ϵͳ���������Դ����\n"); 
            print_Sequence();
        }
        else
        {
            printf("ϵͳ�����������Դ����\n");
        }
    }
}
// ��ӡ��ȫ����
void print_Sequence()
{
    int i = 0;
    printf("��ȫ����: ");
    for(i = 0;i < 4; i++)
    {
        printf("P%d->",Sequence[i]);
    }
    printf("P%d\n",Sequence[4]);
}

// �ж������Ƿ���ȷ
void request_is_safe()
{
    int num,i;
    printf("��������Դ����Ľ���(0:P0  1:P1  2:P2  3:P3  4:P4):");
    scanf("%d",&num);
    printf("��������A,B,C,D��Դ����Ŀ:");
    for(i = 0; i<4 ;i++)
    {
        scanf("%d",&Request[i]);
    }
    request_problem(num);
}

//�ж�ϵͳ�Ƿ�ȫ
void orl_is_safe()
{
    if(is_safe())
    {
        printf("T0ϵͳ���ڰ�ȫ״̬\n");
        print_Sequence();
    }
    else
    {
        printf("T0ϵͳ���ڲ���ȫ״̬\n");
    }
}

//������
int main()
{
    find_need();
    print_resources();
    orl_is_safe();
    request_is_safe();
}