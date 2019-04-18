#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 这是一个关于栈的练习
 * 
*/

//栈中的元素类型
typedef struct Node
{
    int date;
    struct Node *pNext;
} NODE, *PNODE;

//栈结构
typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK;

void init(PSTACK pStack);          //初始化
void push(PSTACK pStack, int val); //压栈
bool pop(PSTACK pStack, int *val); //出栈
void traverse(PSTACK pStack);      //遍历
bool isempty(PSTACK pStack);       //栈是否为空
void clear(PSTACK pStack);         //清空栈

/**
 * 栈是否为空
*/
bool isempty(PSTACK pStack)
{
    if (pStack->pTop == pStack->pBottom)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * 初始化栈
*/
void init(PSTACK pStack)
{
    pStack->pTop = (PNODE)malloc(sizeof(NODE));
    if (pStack == NULL)
    {
        printf("create stack field!\n");
    }
    else
    {
        pStack->pBottom = pStack->pTop; //栈顶，和栈尾指针指向同一个节点
        pStack->pTop->pNext = NULL;     //清空NODE的指针域，作为首节点
    }
}

/**
 * 压栈
 * pStack 栈地址
 * val 压入栈的数据
*/
void push(PSTACK pStack, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (pNew == NULL)
    {
        printf("push stack field!\n");
    }
    else
    {
        pNew->date = val;           //给NODE数据域赋值
        pNew->pNext = pStack->pTop; //给NODE指针域赋值，让其指向上一个节点
        pStack->pTop = pNew;        //将栈首节点指向新压栈NODE的地址
    }
}

/**
 * 遍历
 * pStack 栈地址
*/
void traverse(PSTACK pStack)
{
    if (isempty(pStack))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        PNODE p = pStack->pTop;
        while (p != pStack->pBottom)
        {
            printf("the statck val is = %d \n", p->date);
            p = p->pNext;
        }
        //printf("\n");
        return;
    }
}

/**
 * 出栈
 * pStack 栈地址
 * *val 出栈的数据
 * 出栈失败返回FALSE 成功返回TRUE
*/
bool pop(PSTACK pStack, int *val)
{
    if (isempty(pStack))
    {
        return false;
    }
    else
    {
        PNODE r = pStack->pTop;    //创建临时指向栈顶的指针
        *val = pStack->pTop->date; //取得栈顶数据
        pStack->pTop = r->pNext;
        free(r);
        r = NULL;
        return true;
    }
}

/**
 * 清空栈
*/
void clear(PSTACK pStack)
{
    if (isempty(pStack))
    {
        return;
    }
    else
    {
        PNODE q = pStack->pTop;
        PNODE r = NULL;
        while (q != pStack->pBottom)
        {
            r = q->pNext;
            free(q);
            q = r;
        }
        r = NULL;
        pStack->pTop = pStack->pBottom;
    }
    return;
}

int main(void)
{
    int val;
    STACK S;
    init(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    traverse(&S);
    pop(&S, &val);
    printf("val = %d \n", val);
    traverse(&S);
    clear(&S);
    traverse(&S);
    system("pause");
    return 0;
}
