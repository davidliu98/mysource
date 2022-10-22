#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int age;
    int sid;
};

struct Student *createStudent();

void showStudent(struct Student *pst);

int main(void)
{
    struct Student *ps;
    ps = createStudent();
    showStudent(ps);
    free(ps);
    // printf("i= %d\n", i);
   // system("pause");
    return 0;
}

struct Student *createStudent()
{
    struct Student *p = (struct Student *)malloc(sizeof(struct Student));
    p->age = 99;
    p->sid = 88;
    return p;
}

void showStudent(struct Student *pst)
{
    printf("%d %d\n",pst->age,pst->sid);
}
