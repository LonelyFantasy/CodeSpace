#include <stdio.h>
#include <stdlib.h>

/*哈希结构*/
struct hashTable
{
    int* element; //存放键值的连续空间起始地址
    int maxNum;   // 哈希表长度
    int curNum;   //当前哈希表已有数据元素
};

struct node
{
    int data;
    struct node* next;
};

struct hashTable_link
{
    struct node* element;
    int maxNum; // 哈希表长度
};            //哈希表基本区域长度
int insertKey(struct hashTable* h, int key);
int findPos(struct hashTable* h, int key);
int hashFun(int key);
void printHashTable(struct hashTable* h);
/*第一关*/
//初始化一个哈希表，能满足线性探测再散列处理冲突法使用，初始化哈希表元素均为-1，表示该位置为空，可插入
struct hashTable* initHashTable_linear()
{ //Create
    struct hashTable* value = (struct hashTable*)malloc(sizeof(struct hashTable));
    if (value != NULL)
    {
        value->maxNum = 10; //依照题目要求设置10个长度
        value->element = (int*)malloc(sizeof(int) * value->maxNum);
        if (value->element)
        {
            for (int i = 0; i < value->maxNum; i++)
                value->element[i] = -1;
        }
    } //Creat End
    int key;
    for (int i = 0; i < 7; i++) {
        scanf_s("%d", &key);
        insertKey(value, key);
    }
    return value;
}

//初始化一个哈希表，能满足拉链法处理冲突法使用。初始化哈希表元素为0，用于计算该条链中数据个数，在插入时增加
struct hashTable_link* initHashTable_link()
{
    struct hashTable_link* head = (struct hashTable_link*)malloc(sizeof(struct hashTable_link));
    if (head != NULL)
    {
        head->maxNum = 10; //依照题目要求设置10个长度
        head->element = (struct node*)malloc(sizeof(struct node) * head->maxNum);
        if (head->element)
        {
            head->maxNum = head->maxNum;
            for (int i = 0; i < head->maxNum; i++)
            {
                head->element[i].data = 0;
            }
            return head;
        }
    }
    else
        free(head);
    return NULL;
}

/*第二关*/
//输出线性探测再散列法构建的哈希表,从下标为0的元素开始输出，每输出一个数据空一格
void printHashTable(struct hashTable* h)
{
    for (int i = 0; i < h->maxNum; i++)
    {
        printf("%d ", h->element[i]);
    }
}

/*第三关*/
//哈希函数，h(key) = (key*3) %  7
int hashFun(int key)
{
    return (key * 3) % 7;
}

//函数功能：计算key的哈希地址，若发生冲突，则使用线性探测再散列的方法查找合适的插入位置下标，并返回该下标
int findPos(struct hashTable* h, int key)
{
    int d, inc;
    d = hashFun(key);
    for (inc = 0; inc < h->maxNum; inc++)
    {
        if (h->element[d] == -1)
        {
            return d;
        }
        else if (h->element[d] != -1)
            d = (d + 1) % h->maxNum;
    }
    return -1; //for完后溢出
}

//插入键值函数,若哈希表空间已满，则返回-1，否则返回插入位置下标
int insertKey(struct hashTable* h, int key)
{
    int position;
    position = findPos(h, key);
    if (position != -1)
    {
        h->element[position] = key;
        return position;
    }
    else
        return -1;
}

int main()
{
    struct hashTable* h = initHashTable_linear();
    //printf("%d\n",h->maxNum);
    printHashTable(h);
}