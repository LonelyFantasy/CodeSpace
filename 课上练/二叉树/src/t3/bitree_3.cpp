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

void changeLR(BiTree root)
{
	//请在此处填写代码， 完成二叉树左右子树互换
	/********** Begin **********/
	struct node *temp;
	if(root == NULL)
		return;
	if (root->lchild == NULL && root->rchild == NULL)
		return;
	else
	{
		temp = root->lchild;
		root->lchild = root->rchild;
		root->rchild = temp;
	}
	changeLR(root->lchild);
	changeLR(root->rchild);
	return;
	//节点左右link空
	/********** End **********/
}

void visit(BiTree T) //输出结点T的数据
{
	cout << T->info;
}

void inOrder(BiTree root)
{
	if (root == NULL)
		return;
	inOrder(root->lchild);
	visit(root);
	inOrder(root->rchild);
}

int main(void)
{
	BiTree root = createBiTree();
	changeLR(root);
	inOrder(root);
}
