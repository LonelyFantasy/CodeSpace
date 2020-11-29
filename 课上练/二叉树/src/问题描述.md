# 关卡内容

## 第一关

### 任务描述

- 实现二叉树的创建函数及二叉树的遍历函数。

### 相关知识

- 二叉树可用顺序方式存储，也可使用链式存储，本关使用二叉树的链式存储方式。结点数据结构定义为：

    ```cpp
    struct node
    {
        DataType info ;
        struct node *lchild , *rchild ;
    };
    ```

- 二叉树的链式存储结构举例如下图所示：
    ![img](https://www.educoder.net/api/attachments/439015)

- 创建二叉树时，可采用递归算法，其中一种方法是，将二叉树先扩充为扩二叉树，然后按先序遍历的结点顺序输入，如：

    ![img](https://www.educoder.net/api/attachments/439016)
上图中，#结点为扩充的外部结点，输入该二叉树时输入结点顺序为：AB#DF###CE#G###

### 编程要求

- 请仔细阅读右侧编辑器中的框架代码，在Begin-End之间补充代码，完成BiTree createBiTree(void)函数创建二叉树。

### 测试说明

- 测试输入：`AB#DF###CE#G###`
- 预期输出：`BFDAEGC`
