#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


// int main()
// {
    // int a[] = {1,2,3,4,5};
    // int b[] = {2,5,6,8,4};
    // int c[] = {3,5,4,8,9};
    // int* arr[] = {a,b,c};
    // int i = 0;
    // for(i = 0; i<3;i++)
    // {
    //     int j = 0;
    //     for(j = 0; j<5;j++)
    //     {
    //         //printf("%d ",*(arr[i]+j));
    //         printf("%d ",arr[i][j]);
    //     }
    //     printf("\n");
    // }
    // int a = 10;
    // int*pa = &a;
    // char ch = 'as';
    // char*pc = &ch;
    // int arr[10] = {1,2,3,4,5,6};
    // int (*parr)[10] = &arr;
    // double* d[5];
    // double* (*pd)[5] = &d;   //数组指针
    // int arr[10] ={1,2,3,4,5,6,7,8,9,10};
    // int (*pa)[10] = &arr;
    // int i = 0;
    // for(i = 0;i<10;i++)
    // {
    //     printf("%d ",(*pa)[i]);
    //     printf("----");
    //     printf("%d ",*((*pa)+i));
    // }
    //int arr1[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
    //print1(arr1,3,5);
//     return 0;
// }



// int main()
// {
//     int a = 0;
//     int n = 0;
//     printf("输入:");
//     scanf("%d %d",&a,&n);
//     int i = 0;
//     int sum = 0;
//     int ret = 0;
//     for(i = 0; i < n ;i++)
//     {
//         ret = ret * 10 + a;
//         sum = sum + ret;

//     }
//     printf("sum = %d",sum);
//     return 0;
// }



// int main()
// {
//     int i = 0;

//     for(i = 0; i < 100000 ; i++)
//     {
//         int n = 1;
//         int tmp = i;
//         while(tmp / 10)
//         {
//             n++;

//             tmp = tmp / 10;
//         }

//         tmp = i;
//         int sum = 0;
//         while(tmp)
//         {
//             sum += pow(tmp % 10,n);
//             tmp = tmp / 10;
//         }

//         if(sum == i)
//         {
//             printf("%d ",i);
//         }

//     }

//     return 0;

// }

/*
void reverse(char * str)
{
    assert(str);
    int len = strlen(str);
    char * left = str;
    char * right =  str + len - 1;
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;

    }

}
*/


// int main()
// {
//     char arr[] = "aszcfsadf";
//     reverse(arr);
//     printf("%s",arr);
//     return 0;
// }




//数组指针    
/*
void print1(int(*p)[5],int r,int c)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d ",*(*(p+i)+j));

        }
    }
}
*/

// int main()
// {
//     char arr = 'sdfug';

//     int lens = strlen(arr);

//     printf("%d",lens);

// }



//数组指针

// int arr[5]; 整型数组

// int *parr[10];   整型指针数组

// int (*parr2)[10];   数组指针，改指针能够指向一个数组，数组10元素，每个元素的类型是int

// int (*parr3[10])[5]; parr3是一个存储数组指针的数组该数组能够存放10个数组指针每个数组指针能够指向一个数组，数组5个元素，每个元素是int类型

/*
int main()
{
    int line = 0;
    printf("输入:");
    scanf("%d",&line);
    int i = 0;
    for(i = 0; i<line;i++)
    {
        int j = 0;
        for(j = 0;j< line -1-i; j++)
        {
            printf(" ");
        }
        for(j = 0; j < 2*i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i = 0; i < line - 1; i++)
    {
        int j = 0;

        for(j = 0;j <=i ;j++)
        {
            printf(" ");
        }

        for(j = 0; j <2*(line-i-1)-1;j++)
        {
            printf("*");

        }
        printf("\n");
    }
    return 0;
}

*/

// 喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，20元可以喝多少汽水


/*
int main()
{
    int mony = 0;
    printf("输入:");
    scanf("%d",&mony);
    int num = mony;
    int empty = mony;
    while (empty >= 2)
    {
        num += empty / 2;
        empty = (empty/2) + (empty % 2);

    }
    printf("%d",num);
    return 0;
}

*/


// char 0~255
//0010 0101 0101

/*
int main()
{
    
    unsigned char a = 100;
    //0001 0000 0000
    unsigned char b = 200;
    //0010 0000 0000
    unsigned char c = 0;
    c = a + b;

    printf("%d %d",a + b,c);
    
    return 0;
}

*/



/*
int main()
{
    int arr[10][10] = {0};
    int i = 0;
    int j = 0;
    for(i = 0; i < 10 ; i++)
    {
        for(j = 0; j <= i ; j++)
        {
            if(j == 0)
            {
                arr[i][j] = 1;
            }

            if(i == j)
            {
                arr[i][j] = 1;
            }

            if(i >= 2 && j >= 1)
            {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }

        }
    }

    for(i = 0;i<10;i++)
    {
        for(j = 0;j<=i ;j++)
        {
            printf("%d",arr[i][j]);

        }
        printf("\n");

    }

    return 0;

}
*/


/*
int main()
{
    char killer = 0;
    for(killer = 'A'; killer <= 'D'; killer++)
    {
        if((killer !='A') + (killer == 'C') + (killer == 'd') + (killer != 'D') == 3)
        {
            printf("%c",killer);
        }

    }

    return 0;
}

*/

/*
int main()
{
    srand((unsigned)time(NULL));   //srand( (unsigned)time( NULL ) );          //初始化随机数
    int num = 36;
    int run = 6;
    int i = 0;
    int j = 0;
    int k = 0;

    int cn = 0;

    for(i = 0; i < 6 ; i++)
    {
        for(j = 0; j < 6; j++)
        {
            k = random(6);
        }
        
    }

    return 0;
    


}
*/


/*
int add(int a, int b)
{
    return a+b;
}
int main()
{

    int (*pt)(int,int) = &add;
    //int (*pt)(int,int) = &add; == int (*pt)(int,int) = add;

    int ret = (*pt)(3,5);
    int rt = pt(3,5);
    printf("%p\n",add);   //输出函数的地址
    printf("%d",ret);
    printf("%d",rt);

    return 0;
}

*/


int add(int x,int y)
{
    return x + y;
}

int sub(int x,int y)
{
    return x - y;
}

int mul(int x,int y)
{
    return x*y;
}

int del(int x,int y)
{
    return x/y;
}


int Calc(int (*pf)(int,int))
{
    
    int x = 0;
    int y = 0;
    printf("请输入两操作数；");
    scanf("%d %d",&x,&y);
    return pf(x,y);
    
}

void mun()
{
    printf("*************************\n");
    printf("***** 1.add   2.sub *****\n");
    printf("***** 3.mul   4.del *****\n");
    printf("*****    0.exit     *****\n");
}

int main()
{

/*
    int (*pr1)(int, int) = add;
    int (*pr2)(int,int) = sub;
    int (*ppr[2])(int,int) = {add,sub};  //函数指针数组
*/
    int input = 0;
    do
    {
        mun();
        int ret = 0;
        printf("请选择:>");
        scanf("%d",&input);

        switch (input)
        {
        case 1:
            ret = Calc(add);
            printf("ret = %d\n",ret);
            break;
        case 2:
            ret = Calc(sub);
            printf("ret = %d\n",ret);
            break;
        case 3:
            ret = Calc(mul);
            printf("ret = %d\n",ret);
            break;
        case 4:
            ret = Calc(del);
            printf("ret = %d\n",ret);
            break;
        case 0:
            printf("退出\n");
            break;
        default:
            printf("输入错误，重新输入\n");
            break;
        }

    } while (input);
    
    return 0;
}



























