# 关卡描述

## 第一关

### 本关任务

        完成二叉树的创建及遍历输出。

### 相关知识

#### 扩充二叉树

![img](https://www.educoder.net/api/attachments/414775)

#### 遍历二叉树（二叉树的周游）

![img](https://www.educoder.net/api/attachments/414776)

- 假设有二叉树如下图所示：
![img](https://www.educoder.net/api/attachments/414777)

  - 则先根遍历得到的结点序列是: `ABDCEGFHI`
  - 中根遍历得到的结点序列是: `DBAEGCHFI`
  - 后根遍历得到的结点序列是: `DBGEHIFCA`

#### 存储一棵二叉树

- 顺序存储法
![img](https://www.educoder.net/api/attachments/414782)
- 链式存储法
  - 除了存储结点本身的数据外，再设置两个指针字段：lchild 和 rchild，分别存放结点的左孩子结点和右孩子结点的位置。
  - 数据结构可定义如下:

    ``` cpp
    typedef struct node
    {
    char data; //存储结点的数据
    struct node *lchild,*lchild ;
    }BiTreeNode,   *BiTree;
    ```

### 编程要求

- 在Begin-End处补充代码，完成创建一棵二叉树，并输出该二叉树的先根、中根、后根遍历结果。

### 测试样例

![img](https://www.educoder.net/api/attachments/414811)

- 测试输入: `ABD###CE#G##FH##I##`
- 预期输出
  
    ``` cpp
    A B D C E G F H I
    D B A E G C H F J
    D B G E H I F C A
    ```

![img](https://www.educoder.net/api/attachments/414817)

- 测试输入：AB##CE#G###；
- 预期输出

    ``` cpp
    A B C E G
    B A E G C
    B G E C A
    ```

## 第二关

### 任务描述

- 假设我们用一棵二叉树存储你的家族族谱：对于任意一个结点来说，左孩子代表长子或长女，右孩子代表兄弟或姐妹。结点存储的是每个人的代号。
- 程序要求：输入某人的代号，输出此人的所有兄弟姐妹。

### 测试样例

- 输入`ABC##D##E#F#G##`来创建一棵家谱二叉树
- 测试输入: `B`
- 预期输出: `D`

- 测试输入: `A`
- 预期输出: `E F G`
