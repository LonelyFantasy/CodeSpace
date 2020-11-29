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
//计算二叉树中满结点的个数
int countFullNode(BiTree root)
{
	int res = 0;
	if (root->lchild && root->rchild)
		return 1 + countFullNode(root->lchild) + countFullNode(root->rchild);
	else if (root->lchild)
		return countFullNode(root->lchild);
	else if (root->rchild)
		return countFullNode(root->rchild);
	else
		return res;
	return res;
}

int main(void)
{
	BiTree root = createBiTree();
	cout << countFullNode(root);
}
