#include <iostream>
using namespace std;

#include <stdlib.h>

typedef char DataType;

//二叉树结点定义
struct node
{
    DataType info;
    struct node *lchild, *rchild;
};

typedef struct node *BiTree;

void print(DataType d)
{
    cout << d << " ";
}

//初始化二叉树的结点序列
char treeData[] = "ABC##D##E#F#G##";

int i;//全局变量i用于将序列依次写入二叉树
/*
函数名：createBiTree
函数功能：读取treeData 数组中的字符序列进行二叉树创建二叉树，并返回二叉树的根结点指针 
参数：无 
返回值：二叉树的根结点指针 
*/
BiTree createBiTree()
{
    //请在此处填写代码，完成创建二叉树并返回二叉树根结点指针的功能
    BiTree tree;
    DataType ch;
    ch = treeData[i];
    if (ch == '#')
    {
        tree = NULL;
    }
    else
    {
        tree = (BiTree)malloc(sizeof(struct node));
        if (tree == NULL)
            return tree;
        tree->info = ch;
        i++;
        tree->lchild = createBiTree(); //构造左子树
        i++;
        tree->rchild = createBiTree(); //构造右子树
    }
    return tree;
}

void Sibling(BiTree T)
{
    //在此处填入代码,输出结点T的所有兄弟姐妹 
    if (T == NULL)
        return;
    print(T->info);
    Sibling(T->lchild);
    Sibling(T->rchild);
}

/*
函数名：preOrder
函数功能：先根遍历二叉树 ，并找到值为ch的结点指针
参数：根结点指针 BiTree *T  ,需查找的结点值 ch 
返回值：无 
*/
void preOrder(BiTree T, DataType ch) //找到结点值ch后调用函数sibling输出该结点的所有兄弟姐妹，以空格分界
{
    if (T == NULL)
        return;
    if (T->info == ch)
    {
        //Sibling(T->lchild);
        Sibling(T->rchild);
    }
    else
    {
        preOrder(T->lchild, ch);
        preOrder(T->rchild, ch);
    }
}

int main(void)
{
    BiTree T;
    T = createBiTree(); //创建二叉树
    char ch;
    cin >> ch;       //输入某人的代号 E F G 
    preOrder(T, ch); //调用函数输出ch的所有兄弟姐妹
    return 1;
}