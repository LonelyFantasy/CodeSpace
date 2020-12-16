#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 6
/*----------邻接矩阵结构----------*/
typedef struct
{
    int vcount;     //顶点数
    int type;       //0 无向图，1 有向图
    char vexs[N];   // 顶点信息
    int arcs[N][N]; //关系矩阵
} GraphMatrix;
/*----------END----------*/

/*----------邻接表数据结构----------*/
struct EdgeNode
{                              //边表中的结点
    int endvex;                //相邻顶点在顶点表中下标
    int weight;                //边的权
    struct EdgeNode *nextedge; //链字段
};
typedef struct EdgeNode *EdgeList;

typedef struct
{
    char vertex;       //记录顶点信息
    int degree;        //用于记录顶点的入度，在拓扑排序时需使用
    EdgeList edgelist; //指向边表的指针
} VexNode;

typedef struct
{
    VexNode vexs[N]; //N个顶点
    int type;        //0 无向图，1 有向图
    int vcount;      //顶点数
} GraphList;
/*----------END----------*/

void printGraph(GraphMatrix *G)
{ //本函数输出图的邻接矩阵
    int i, j;
    for (i = 0; i < G->vcount; i++)
    {
        //  printf("%c ",G->vexs[i]);
        for (j = 0; j < G->vcount; j++)
            printf("%d ", G->arcs[i][j]);
        printf("\n");
    }
}

/*第一关 完成图初始化-邻接矩阵*/
GraphMatrix *initGraphMatrix()
{ /*第一行输入图的类型、图的顶点数和边数，第二行输入各条边的两顶点的编号，按顶点编号从小到大的顺序输入。
    输出邻接矩阵，不需要考虑输入的数字非法情况，不输入顶点的信息*/
    int column, i, j, m, n;
    GraphMatrix *current = (GraphMatrix *)malloc(sizeof(GraphMatrix));
    scanf("%d %d %d", &current->type, &current->vcount, &column);
    if (current->vcount <= 0 || column <= 0)
        return NULL;
    if (current->type == 0) //无向图
        for (i = 0; i < column; i++)
        {
            scanf("%d %d", &m, &n);
            current->arcs[m][n] = 1;
            current->arcs[n][m] = 1;
        }
    else //有向图
        for (i = 0; i < column; i++)
        {
            scanf("%d %d", &m, &n);
            current->arcs[m][n] = 1;
        }
    return current;
}
/*第二关 完成图初始化-邻接表,并完成输出图的邻接表函数*/
GraphList *initGraphList()
{
    /*第一行输入图的类型、图的顶点数和边数，第二行输入各条边的两顶点的编号，按顶点编号从小到大的顺序输入。
输出邻接表。不需考虑输入的数字非法情况，输入顶点的信息*/
    int line, i, j, count, m, n, tmp;
    char in, out;
    GraphList *current = (GraphList *)malloc(sizeof(GraphList));
    scanf("%d%d%d", &current->type, &current->vcount, &line);
    getchar();
    for (i = 0; i < current->vcount; i++) //编号输入
    {
        scanf("%c", &current->vexs[i].vertex);
        current->vexs[i].edgelist = NULL;
    }
    for (i = 0; i < line; i++)
    { //点与点信息录入
        getchar();
        scanf("%c", &in);
        getchar();
        scanf("%c", &out);
        count = 0;
        for (j = 0;; j++)
        { //标记起点终点位置
            if (current->vexs[j].vertex == in)
            {
                m = j;
                count++;
            }
            if (current->vexs[j].vertex == out)
            {
                n = j;
                count++;
            }
            if (count == 2)
                break;
        }
        //始点的节点创建和联系
        if (!current->type) //无向图
        {
            for (int k = 0; k < 2; k++)
            {
                if (current->vexs[m].edgelist == NULL) //判断顶点是否已有链
                {
                    current->vexs[m].edgelist = (EdgeList)malloc(sizeof(struct EdgeNode));
                    current->vexs[m].edgelist->nextedge = NULL;
                    current->vexs[m].edgelist->endvex = n;
                    current->vexs[m].edgelist->weight = 0; //默认权为0
                }
                else
                {
                    EdgeList node = (EdgeList)malloc(sizeof(struct EdgeNode));
                    node->nextedge = current->vexs[m].edgelist;
                    node->endvex = n;
                    node->weight = 0; //默认权为0
                    current->vexs[m].edgelist = node;
                }
                tmp = m, m = n, n = tmp;
            }
        }
        else //有向图
        {
            if (current->vexs[m].edgelist == NULL) //判断顶点是否已有链
            {
                current->vexs[m].edgelist = (EdgeList)malloc(sizeof(struct EdgeNode));
                current->vexs[m].edgelist->nextedge = NULL;
                current->vexs[m].edgelist->endvex = n;
                current->vexs[m].edgelist->weight = 0; //默认权为0
            }
            else
            {
                EdgeList node = (EdgeList)malloc(sizeof(struct EdgeNode));
                node->nextedge = current->vexs[m].edgelist;
                node->endvex = n;
                node->weight = 0; //默认权为0
                current->vexs[m].edgelist = node;
            }
        }
    }
    return current;
}

void printGraphLit(GraphList *G)
{
    /*输出邻接表，输出格式：顶点->邻接顶点编号->...*/
    for (int i = 0; i < G->vcount; i++)
    {
        printf("%c", G->vexs[i].vertex);
        printf("->");
        EdgeList temp = G->vexs[i].edgelist;
        while (temp != NULL)
        {
            printf("%c", G->vexs[temp->endvex].vertex);
            if (temp->nextedge != NULL)
                printf("->");
            temp = temp->nextedge;
        }
        printf("\n");
    }
}

/*第三关 完成图的广度遍历（周游），可根据需要添加自定义函数*/

/*----------Queue File----------*/
typedef struct Node
{
    int data;
    struct Node *next;
} LinkQueueNode;
typedef struct
{
    LinkQueueNode *front;
    LinkQueueNode *rear;
} LinkQueue;

int InitQueue(LinkQueue *Q)
{
    Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (Q->front != NULL)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
        return 1;
    }
    else
        return 0;
}

int EnterQueue(LinkQueue *Q, int x)
{
    LinkQueueNode *NewNode;
    NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (NewNode != NULL)
    {
        NewNode->data = x;
        NewNode->next = NULL;
        Q->rear->next = NewNode;
        Q->rear = NewNode;
        return 1;
    }
    else
        return 0;
}

int DeleteQueue(LinkQueue *Q, int *x)
{
    LinkQueueNode *p;
    if (Q->front == Q->rear)
        return 0;
    p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    *x = p->data;
    free(p);
    return 0;
}
/*----------END----------*/

void BFS_list(GraphList *G)
{
    int i, j, node_read[N];
    for (i = 0; i < N; i++)
        node_read[i] = 0;
    LinkQueue Q;
    InitQueue(&Q);                  //队列初始化
    for (i = 0; i < G->vcount; i++) //每顶点遍历访问
    {
        if (node_read[i] == 0) //未访问此顶点
        {
            EdgeList p;
            node_read[i] = 1; //该顶点已读
            printf("%c ", G->vexs[i].vertex);
            EnterQueue(&Q, i);
            while (Q.front != Q.rear)
            {
                DeleteQueue(&Q, &i);
                p = G->vexs[i].edgelist; //此时p指向当前出队顶点的邻接表
                while (p)                //读取当前顶点的所有数据
                {
                    if (node_read[p->endvex] == 0)
                    {
                        printf("%c ", G->vexs[p->endvex].vertex);
                        node_read[p->endvex] = 1;
                        EnterQueue(&Q, p->endvex);
                    }
                    p = p->nextedge;
                }
            }
        }
    }
}

/*第四关 完成图的深度遍历（周游），可根据需要添加自定义函数*/
void DFS_list(GraphList *G)
{
    int node_read[N] = {0};
    struct EdgeNode *p;
    for (int i = 0; i < G->vcount; i++)
    {
        if (node_read[i] == 0)
        {
            printf("%d ", i);
            node_read[i] = 1;
            p = G->vexs[i].edgelist;
            do
            {
                while (p)
                {
                    if (node_read[p->endvex] == 0)
                    {
                        node_read[p->endvex] = 1;
                        printf("%d ", p->endvex);
                        break;
                    }
                    p = p->nextedge;
                }
                if (p == NULL)
                    break;
                p = G->vexs[p->endvex].edgelist;
            } while (1);
        }
    }
}
/*第五关 生成图的拓扑排序，可根据需要添加自定义函数*/

void Top_list(GraphList *G)
{
}

/*第六关 prim算法生成最小生成树*/

void Prim_list(GraphList *G)
{
    int read_node[N] = {0}, i, j, enter_node[N] = {0};

}
/*第七关 Kruskal算法生成最小生成树*/

void Kruskal_list(GraphList *G)
{
}

/*第八关 Dijistra算法求最短路径*/

void Dijkstra_list(GraphList *G)
{
}
