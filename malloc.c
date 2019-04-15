#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    int len, i;

    printf("��ȷ������������ĳ��� len = ");

    scanf("%d", &len);

    int *pArr = (int *)malloc(sizeof(int) * len);
   
    for (i = 0; i < len; i++)
    {
        scanf("%d", &pArr[i]);
    }

    for (i = 0; i < len; i++)
    {
        printf("%d\n", *(pArr + i));
    }

    free(pArr);
    system("pause");
    //getchar();
    return 0;
}