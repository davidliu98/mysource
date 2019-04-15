#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

struct Arr
{
    int *pBase; //保存数组的首地址
    int len;    //数组长度
    int cnt;    //元素个数
};

void init_arr(struct Arr *pArr, int length);           //初始化
bool append_arr(struct Arr *pArr, int val);            //追加
bool insert_arr(struct Arr *pArr, int pos, int val);   //插入 pos从1开始
bool delete_arr(struct Arr *pArr, int pos, int *pVal); //删除
bool is_empty(struct Arr *pArr);                       //是否为空
bool is_full(struct Arr *pArr);                        //是否占满
void sort_arr(struct Arr *pArr);                       //Ascending sort
void show_arr(struct Arr *pArr);                       //Print Array
void inversion_arr(struct Arr *pArr);                  //Inverted array

int main(void)
{

    struct Arr arr;
    int val;
    init_arr(&arr, 6);
    //show_arr(&arr);
    append_arr(&arr, 100);
    append_arr(&arr, 20);
    append_arr(&arr, 500);
    append_arr(&arr, -10);
    append_arr(&arr, 700);

    printf("TheArray Is\n");
    printf("=======================\n");
    show_arr(&arr);
    printf("=======================\n");
    // // append_arr(&arr, 6);
    // insert_arr(&arr, 2, 100);
    // // append_arr(&arr, 6);
    // // append_arr(&arr, 7);
    // // append_arr(&arr, 8);
    if (delete_arr(&arr, 3, &val))
    {
        printf("=======================\n");
        printf("Delete successfully:)\n");
        printf("The element you deleted is = %d\n", val);
        printf("=======================\n");
    }
    else
    {
       printf("=======================\n");
        printf("Delete failed! \n");
       printf("=======================\n");
    }

    inversion_arr(&arr);
    printf("=======================\n");
    printf("Inverted array\n");
    printf("=======================\n");
    show_arr(&arr);
    printf("=======================\n");
    printf("Sort array\n");
    printf("=======================\n");
    sort_arr(&arr);
    show_arr(&arr);

    getchar();
    return 0;
}

//初始化
void init_arr(struct Arr *pArr, int length)
{
    pArr->pBase = (int *)malloc(sizeof(int) * length);
    if (pArr->pBase == NULL)
    {
        exit(-1); //stop program
    }
    else
    {

        pArr->len = length;
        pArr->cnt = 0;
    }
    return;
}

//是否为空
bool is_empty(struct Arr *pArr)
{
    if (pArr->cnt == 0)
        return true;
    else
        return false;
}

//是否为满
bool is_full(struct Arr *pArr)
{
    if (pArr->cnt == pArr->len)
        return true;
    else
        return false;
}
//显示arrayList
void show_arr(struct Arr *pArr)
{
    if (is_empty(pArr))
    {
        printf("Array is empty\n");
    }
    else
    {
        for (int i = 0; i < pArr->cnt; i++)
        {
            printf("%d", pArr->pBase[i]);
            printf("\n");
        }
    }
}

//追加元素
bool append_arr(struct Arr *pArr, int val)
{
    if (is_full(pArr))
    {
        return false;
    }
    else
    {
        pArr->pBase[pArr->cnt] = val;
        (pArr->cnt)++;
        return true;
    }
}

//指定位置插入元素
bool insert_arr(struct Arr *pArr, int pos, int val)
{
    if (is_full(pArr))
    {
        printf("array is full\n");
        return false;
    }
    else if (pos > pArr->cnt)
    {
        printf("pos is too big\n");
        return false;
    }
    // else if (pos == pArr->cnt + 1)
    // {
    //     if (pArr->cnt + 1 <= pArr->len)
    //     {
    //         pArr->pBase[pos - 1] = val;
    //         return true;
    //     }
    //     else
    //     {
    //         printf("pos is too big\n");
    //         return false;
    //     }
    // }
    else if (pos < 1)
    {
        printf("pos must >=1\n");
        return false;
    }
    else
    {
        int i; //i=数组下标 pos 插入元素位置 pos = i+1
        for (i = (pArr->cnt) - 1; i >= pos - 1; i--)
        {
            pArr->pBase[i + 1] = pArr->pBase[i];
        }
        pArr->pBase[pos - 1] = val;
        (pArr->cnt)++;
        return true;
    }
}

//删除元素
bool delete_arr(struct Arr *pArr, int pos, int *pVal)
{
    int i;
    if (is_empty(pArr))
    {
        return false;
    }
    if (pos < 1 || pos > pArr->cnt)
    {
        return false;
    }
    *pVal = pArr->pBase[pos - 1];
    for (i = pos; i < pArr->cnt; i++)
    {
        pArr->pBase[i - 1] = pArr->pBase[i];
    }
    pArr->cnt--;
    return true;
}
//Inverted array
void inversion_arr(struct Arr *pArr)
{
    int i = 0;
    int j = pArr->cnt - 1;
    int k;
    while (i < j)
    {
        k = pArr->pBase[i];              // k = i;
        pArr->pBase[i] = pArr->pBase[j]; // i = j;
        pArr->pBase[j] = k;              // j = k;
        ++i;
        --j;
    }
}

//Ascending soft排序
void sort_arr(struct Arr *pArr)
{
    int i, j, k;
    for (i = 0; i < pArr->cnt; i++)
    {
        for (j = i + 1; j < pArr->cnt; j++)
        {
            //大于小于号决定了升降序。The greater than less sign determines the lifting order.
            if (pArr->pBase[i] > pArr->pBase[j])
            {
                k = pArr->pBase[i];              // k = i;
                pArr->pBase[i] = pArr->pBase[j]; // i = j;
                pArr->pBase[j] = k;              // j = k;
            }
        }
    }
}