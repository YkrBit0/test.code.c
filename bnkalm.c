#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
// 初始化当前的系统资源
int Max[5][4] = {0,0,1,2,1,7,5,0,2,3,5,6,0,6,5,2,0,6,5,6};
int Allocation[5][4]={0,0,1,2,1,0,0,0,1,3,5,4,0,6,3,2,0,0,1,4};
int Need[5][4] = {0,0,0,0,0,7,5,0,1,0,0,2,0,0,2,0,0,6,4,2};
int Available[4] = {1,5,2,0};
bool Finsh[5];   
int Request[4];     //进程发出的资源请求
int List[5];       //进程的安全序列 
int Work[4];
// 判断系统是否安全
bool or_safe()
{
    int i,j;
    int ps = 0;
    bool t = false;
    // 把Available赋值给Work
    for(i = 0;i < 4; i++)
    {
        Work[i] = Available[i];

    }
    // 初始化所有进程为未完成 
    for(i = 0;i < 5; i++)
    {
        Finsh[i] = false;
    }
    while (1)
    {
        for(i = 0;i < 5;i++)
        {
            if(Finsh[i]) continue;  //判断进程是否完成
            t = true;
            for(j = 0;j < 4; j++)
            {
                if(Need[i][j] <= Work[j]) continue;
                
                else{
                    t = false;
                    break;
                }
            }
            if(t) break;    //判断第i个进程是否满足Need小于等于Work
        }

        if(t && (Finsh[i] == false)) //是否找到Need小于等于Work的进程并且进程未完成 
        {
            for(j = 0; j < 4;j++)
            {
                Work[j] = Work[j]+Allocation[i][j];
            }

            Finsh[i] = true;   //进程完成
            List[ps] = i;
            ps++;
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

//输出原来系统资源
void print()
{
    int i = 0;
    int j = 0;
    printf("当前系统各类资源剩余：");
    for(i = 0; i < 4 ;i++)
    {
        printf("%d ",Available[i]);
    }
    printf("\n");
    printf("当前系统资源情况：\n");
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

void request_problem(int num)   //资源的请求选择 
{
    int i;
    bool t = true;

    for(i = 0; i < 4; i++)  //判断Requesti是否小于等于Needi 
    {
        if(Request[i] <= Need[num][i]) continue;
        else
        {
            printf("请求错误! \n");
            t = false;
            break;
        }
    }

    if(t)
    {
        for(i = 0;i < 4; i++) //判断Requesti是否小于等于Availablei 
        {
            if(Request[i] <= Available[i]) continue;

            else
            {
                printf("请求错误！\n");
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
        if(or_safe())
        {
            printf("系统能满足该资源请求...\n"); 
            print_Arry();
        }
        else
        {
            printf("系统不能满足该资源请求\n");
        }
    }
}

// 打印安全序列
void print_Arry()
{
    int i;
    printf("安全序列: ");
    for(i = 0;i < 4; i++)
    {
        printf("P%d->",List[i]);
    }
    printf("P%d\n",List[4]);
    
}

void request_safe()
{
    int num,i;
    printf("请输入资源请求的进程(0:P0  1:P1  2:P2  3:P3  4:P4):");
    scanf("%d",&num);
    printf("输入请求A,B,C,D资源的数目:");
    for(i = 0; i<4 ;i++)
    {
        scanf("%d",&Request[i]);
    }
    request_problem(num);

}

//判断系统是否处于安全状态
void is_safe()
{
    if(or_safe())
    {
        printf("T0系统处于安全状态\n");
        print_Arry();
    }
    else
    {
        printf("T0系统处于不安全状态\n");
    }
}

int main()
{
    print();
    is_safe();
    request_safe();

}



