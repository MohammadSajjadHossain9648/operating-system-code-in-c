#include<pthread.h>
#include<stdio.h>
#include<string.h>

int number1()
{
    int x;
    scanf("%d",&x);
}

int number2()
{
    int y;
    scanf("%d",&y);
}

int input1()
{
    inta,b;
    printf("enter 2 number : \n");
    a=number1();
    b=number2();
    printf("number1() = %d\n",a);
    printf("number2() = %d\n",b);
}

int operation()
{
    char o;
    scanf("%s",&o);
}

int input2()
{
    printf("enter the sub/add operation : \n");
    operation();
    printf("operation() = %s\n",operation);
}

int output()
{
    int a=number1();
    printf("a=%d\n",a);
    int b=number2();
    printf("b=%d\n",b);
    char o=operation();
    printf("o=%d\n",o);
    int result;

    if(o == "+")
    {
        result = a+b;
        printf("r1=%d\n",result);
    }
    else if(o == "-")
    {
        result = a-b;
        printf("r2=%d\n",result);
    }
    return result;
}

int main()
{
    pthread_t thread1,thread2,thread3;

    pthread_create(&thread1, NULL, input1, NULL);
    pthread_create(&thread2, NULL, input2, NULL);
    ///pthread_create(&thread3, NULL, output, NULL);

    int a;
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    ///pthread_join(thread3,&a);
    printf("result is %d\n",a);
}
