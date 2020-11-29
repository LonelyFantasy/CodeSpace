#include <iostream>
using namespace std;

typedef char DataType;

//二叉树数据结构
struct node
{
	DataType info;				  //存放结点数据
	struct node *lchild, *rchild; //指向左右孩子的指针
};

typedef struct node *BiTree;

/*创建二叉树
  函数名：createBiTree
  参数：无
  返回值：二叉树根结点指针
  */
BiTree createBiTree(void)
{
	char ch;
	BiTree root;
	cin >> ch;
	if (ch == '#')
		root = NULL;
	else
	{
		root = new struct node;
		root->info = ch;
		root->lchild = createBiTree();
		root->rchild = createBiTree();
	}
	return root;
}

void visit(BiTree T)
{
	cout << T->info;
}

int countLeaf(BiTree root)
{
	//请在此处填写代码， 计算二叉树中树叶的个数
	/********** Begin **********/
	if(root == NULL)//节点数据为空
		return 0;
	if(root->lchild == NULL &&root->rchild == NULL)//节点左右link空
		return 1;
	return countLeaf(root->lchild) + countLeaf(root->rchild);
	/********** End **********/
}

int main(void)
{
	BiTree root = createBiTree();
	cout << countLeaf(root);
}
