#include<stdio.h>

typedef int ZHANGSAN;//为int取一个名字

typedef struct Student
{
    int sid;
    char name[100];
    char sex;
}* PST,STU;


int main(void){

    int i = 10 ; //等价于ZHANGSAN i = 10;
    ZHANGSAN j = 20;

    STU st;
    PST pst = &st;
    pst->sid = 99;
    printf("%d",pst->sid);


    
    getchar();
    return 0 ;
}