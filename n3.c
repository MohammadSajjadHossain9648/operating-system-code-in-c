#include<pthread.h>
#include<stdio.h>
#include<string.h>

int input1(int i)
{
    int x[i];
    scanf("%d",&x[i]);
    return x[i];
}


int input2()
{
    printf("1 for addition and 2 for substraction operation : \n");
    int o;
    scanf("%d",&o);
}

int output(int i)
{
    int x[3],a[3];
    a[i]=x[i];
    printf("a[%d]=%d\n",i,a[i]);

    int result;

    if(a[2] == 1)
    {
        result = a[0]+a[1];
        printf("r1=%d\n",result);
    }
    else if(a[2] == 2)
    {
        result = a[0]-a[1];
        printf("r2=%d\n",result);
    }
    return result;
}

int main()
{
    pthread_t thread1,thread2,thread3;

    int i,x[2],a1,a2,a3,t[3];
    for(i=0; i<2; i++)
    {
        printf("enter number %d: \n",i+1);
        pthread_create(&thread1, NULL, input1, i);

        pthread_join(thread1,&a1);
        t[i]=a1;
    }

    pthread_create(&thread2, NULL, input2, NULL);
    pthread_join(thread2,&a2);
    t[2]=a2;

    for(i=0; i<3; i++)
    {
        printf("t[%d] = %d\n",i,t[i]);
        pthread_create(&thread3, NULL, output, i);
    }

    pthread_join(thread3,&a3);
    printf("result is %d\n",a3);
}
