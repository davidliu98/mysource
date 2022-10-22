#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct Node
{
    int date;           //数据域
    struct Node *pNext; //指针域
} NODE, *PNODE;         //NODE等价于sturct Node , PNODE等价于 struct Node *

/**
 * 函数声明
*/
PNODE create_list(void);                         //创建链表
void traverse_list(PNODE pHead);                 //输出链表
bool is_empty(PNODE pHead);                      //判断链表是否为空
int length_list(PNODE pHead);                    //获取链表长度
bool insert_list(PNODE pHead, int pos, int val); //插入节点 pos插入节点的位置，val插入节点的数据
bool delete_list(PNODE pHead, int pos, int *val); //删除节点 pos删除节点的位置，val保存删除节点的数据
void sort_list(PNODE pHead); //排序

/**
 * 入口main
*/

int main(void)
{
    int val;
    PNODE pHead = NULL;    //等价于struct Node * pHead = NULL;
    pHead = create_list(); //创建一个非循环单链表，并将该链表的头节点地址赋给phead
    printf("linklist len is: %d \n", length_list(pHead));
    traverse_list(pHead);      //输出链表
    sort_list(pHead);          //排序
    insert_list(pHead, 5, 33); //插入元素
    if(delete_list(pHead,4,&val)){
        printf("delete is ok val= %d\n",val); 
    }else{
        printf("Field delete");
    }
    traverse_list(pHead);
    system("pause");
    return 0;
}

/**
 * 创建单向链表
*/
PNODE create_list(void)
{
    int len; //存放有效节点的个数
    int i;   //临时变量
    int val; //临时存放链表某个节点的值

    //分配头节点，不存放有效数据
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (pHead == NULL)
    {
        printf("Allocation failure");
        exit(-1);
    }

    PNODE pTail = pHead; //构造临时节点
    pTail->pNext = NULL;

    printf("Please enter the length of the linked list:");
    scanf("%d", &len);
    for (i = 0; i < len; i++)
    {
        printf("Please enter the value of the Nth=%d node:", i + 1);
        scanf("%d", &val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (pNew == NULL)
        {
            printf("Allocation failure");
            exit(-1);
        }
        pNew->date = val;

        //临时ptail指针永远指向尾节点，当循环进入第下一次时pTail依然指向前一个节点
        //换句话说pTail->pNext是上一个节点的指针域，而pNew是当前新创建节点的地址，赋给了上一个节点的指针域
        //这是将新生成的节点与上一个节点进行连接的操作
        pTail->pNext = pNew;

        //将新生成的节点的指针域清空，使其变为尾节点
        pNew->pNext = NULL;

        //将pTail继续指向新生成的尾节点，等待循环的下一步操作
        pTail = pNew;
    }

    //free(pTail);

    if (is_empty(pHead))
    {
        printf("linklist is empty!\n");
    }
    else
    {
        printf("linklist not empty!\n");
    }
    return pHead;
}

/**
 * 输出链表
*/  
void traverse_list(PNODE pHead)
{
    if (is_empty(pHead) == false)
    {
        printf("linklist node is:\n");
    }

    PNODE p = pHead->pNext; //通过首指针获得首节点指向下一个节点的地址
    while (p != NULL)
    {
        printf(" %d ", p->date);
        p = p->pNext; //此语句将P指向下一个节点
    }
    printf("\n");
    return;
}

/**
 * 判断链表是否为空 为空返回TRUE 不为空返回FALSE
*/
bool is_empty(PNODE pHead)
{
    if (pHead->pNext == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * 返回链表的长度
*/
int length_list(PNODE pHead)
{
    int lens = 0; //临时变量存放链表长度

    PNODE p = pHead->pNext; //为了不改变phead的结构，建立一个新的临时指向PNODE的指针

    while (p != NULL)
    {
        lens++;
        p = p->pNext;
    }
    return lens;
}

/**
 * 对链表进行排序
*/
void sort_list(PNODE pHead)
{
    int i, j, t;
    PNODE p, q;
    int lens = length_list(pHead);

    for (i = 0, p = pHead->pNext; i < lens - 1; i++, p = p->pNext)
    {
        for (j = i + 1, q = p->pNext; j < lens; j++, q = q->pNext)
        {
            if (p->date > q->date)
            {
                t = p->date;
                p->date = q->date;
                q->date = t;
            }
        }
    }
    return;
}

/**
 * 向链表插入一条数据
 * 在PHADE链表，第pos个节点前面插入一个新的节点，该节点的数值为VAL
 * pos从1开始
 * */
bool insert_list(PNODE pHead, int pos, int val)
{
    int i = 0;
    PNODE p = pHead;

    while (p != NULL && i < pos - 1)
    {
        p = p->pNext;
        i++;
    }

    if (i > pos - 1 || p == NULL)
    {
        return false;
    }

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (pNew == NULL)
    {
        printf("Failed to allocate memory");
        exit(-1);
    }

    pNew->date = val;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;

    return true;
}

/**
 * 删除链表中的数据
 * 
*/
bool delete_list(PNODE pHead, int pos, int *val){
    
    int i = 0;
    PNODE p = pHead;

    while (p->pNext != NULL && i < pos - 1)
    {
        p = p->pNext;
        i++;
    }

    if (i > pos - 1 || p->pNext == NULL)
    {
        return false;
    }

    PNODE q =p->pNext;
    *val = q->date;

    p->pNext = p->pNext->pNext;
    return true;
}
