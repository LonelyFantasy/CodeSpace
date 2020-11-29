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
	//请在此处填写代码， 完成二叉树和创建，返回值是二叉树的根结点指针
	/********** Begin **********/
	DataType ch;
	cin >> ch;
	BiTree Tree;
	if (ch == '#')
		Tree = NULL;
	else
	{
		Tree = (BiTree)malloc(sizeof(struct node));
		Tree->info = ch;
		Tree->lchild = createBiTree();
		Tree->rchild = createBiTree();
	}
	return Tree;
	/********** End *********/
}

void visit(BiTree T) //输出结点T的数据
{
	cout << T->info;
}

/****** 周游算法 ******/
void inOrder(BiTree root) //对称周游周游递归算法
{
	if (root == NULL)
		return;
	inOrder(root->lchild);
	visit(root);
	inOrder(root->rchild);
}

void linOrder(BiTree root) //先根次序周游算法
{
	if (root == NULL)
		return;
	visit(root);
	linOrder(root->lchild);
	linOrder(root->rchild);
}

void rinOrder(BiTree root) //后根次序周游递归算法
{
	if (root == NULL)
		return;
	rinOrder(root->lchild);
	rinOrder(root->rchild);
	visit(root);
}

int main(void)
{
	BiTree root = createBiTree();
	inOrder(root);
}
