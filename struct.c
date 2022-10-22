#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int sid;
    char name[200];
    int age;
};

void setStudent(struct Student *pstl);
void getStudent(struct Student *stl);

int main(void)
{
    //第一种给结构体赋值方式
    struct Student st = {1000, "LiuJiang", 40};
    getStudent(&st);

    st.sid = 1001;
    strcpy(st.name, "wangwu");
    st.age = 30;
    getStudent(&st);

    //通过指针给机构体赋值，结构体不能加减乘除，但可以相互赋值。
    struct Student *pst;
    pst = &st;
    pst->sid = 100;    strcpy(pst->name, "lihong");
    pst->age = 25;
    getStudent(&st);

    //通过函数给结构体赋值，和取值
    setStudent(&st);
    getStudent(&st);
    getchar();

    return 0;
}

void getStudent(struct Student *stl)
{
    printf("%d %s %d \n", stl->age, stl->name, stl->age);
}

void setStudent(struct Student *pstl)
{

    (*pstl).sid = 1003;
    strcpy(pstl->name, "lisi");
    pstl->age = 33;
}