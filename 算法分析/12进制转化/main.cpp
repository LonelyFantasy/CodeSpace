#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 36
typedef char DataType;
struct seqList
{
    int MAXNUM;        //结果存储大小
    int jinzhi;        //待转化进制
    int num;           //十进制数
    DataType *element; //char存储
};
typedef struct seqList *PseqList;
PseqList createNullList_seq(int m) //创表
{
    struct seqList *palist;
    palist = (struct seqList *)malloc(sizeof(struct seqList));
    palist->MAXNUM = m;
    palist->element = (DataType *)malloc(sizeof(DataType) * m);
    if (m <= 0)
        return NULL;
    else
        return palist;
}
void translate(PseqList L) //进制转化函数
{
    int yushu;
    char *node = L->element;
    while (L->num > 0)
    {
        yushu = L->num % L->jinzhi; //求余数
        if (yushu < 10)             //余数判断
            *node = yushu + 48;     //小于10直接余数
        else
            *node = yushu + 55; //大于10转字母
        L->num = L->num / L->jinzhi;
        node++;
    }
    *node = '\0';
}
void printList_seq(PseqList L) //输出表
{
    for (int i = strlen(L->element); i >= 0; i--)
    {
        printf("%c", *(L->element + i));
    }
    putchar('\n');
}
void destroyList_seq(PseqList L) //销毁表
{
    free(L->element);
    free(L);
}
int main()
{
    srand((unsigned int)time(NULL));
    PseqList head = createNullList_seq(MAX);
    if (head == NULL)
        return 0;
    scanf("%d", &head->jinzhi);
    while (head->jinzhi > 1 && head->jinzhi < 17)
    {
        head->num = rand() % 1000000 + 1; //随机生成转化数字
        printf("将十进制%d转化为%d进制：", head->num, head->jinzhi);
        translate(head);
        printList_seq(head);
        scanf("%d", &head->jinzhi);
    }
    destroyList_seq(head); //销毁表
    return 0;
}