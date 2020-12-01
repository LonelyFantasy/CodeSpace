#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
typedef int DataType;

struct HtTree //结构定义
{
    DataType weight, value;
    DataType parent, llink, rlink;
};
typedef struct HtTree *PHtTree;

void Huffmantree_Coding(PHtTree ptr, DataType size)
{
    DataType current = size;
    DataType i, j, x1, x2, m1, m2;
    for (i = 0; i < size - 1; i++)
    {
        DataType max_weight = ptr[0].weight;
        for (int j = 0; j < current; j++) //寻找权值最大的点
            if (ptr[j].weight > max_weight)
                max_weight = ptr[j].weight;
        m1 = max_weight + 1, m2 = max_weight + 1; //保存此时节点的权值
        x1 = -1, x2 = -1;                         //最小权值节点的下表
        for (j = 0; j < current; j++)
        {
            if (ptr[j].weight < m1 && ptr[j].parent == -1)
            {
                m2 = m1;
                x2 = x1;
                m1 = ptr[j].weight;
                x1 = j;
            }
            else if (ptr[j].weight < m2 && ptr[j].parent == -1)
            {
                m2 = ptr[j].weight;
                x2 = j;
            }
        }
        //已寻找完成
        ptr[current].llink = x1;       //权值最小结点
        ptr[current].rlink = x2;       //权值第二小结点
        ptr[current].weight = m1 + m2; //新节点权值
        ptr[x1].parent = current;
        ptr[x2].parent = current;
        current = current + 1;
    }
}

PHtTree creatrTree(int m)
{
    PHtTree ptr = (PHtTree)malloc(sizeof(struct HtTree) * (2 * m - 1));
    DataType i;
    for (i = 0; i < m * 2 - 1; i++)
    {
        //初始化
        ptr[i].llink = -1;
        ptr[i].rlink = -1;
        ptr[i].parent = -1;
        ptr[i].weight = 0;
        ptr[i].value = 0;
    }
    for (i = 0; i < m; i++)
    {
        cin >> ptr[i].weight;
        ptr[i].value = ptr[i].weight;
    }
    Huffmantree_Coding(ptr, m);
    return ptr;
}

void print_Coding(PHtTree ptr, int key, vector<char> &result)
{
    //中序遍历输出
    //利用vector将编码逆置存放
    if (ptr[key].llink != -1 && ptr[key].rlink != -1)
    { //非根节点
        //左遍历
        result.push_back('0');
        print_Coding(ptr, ptr[key].llink, result);
        //右遍历
        result.push_back('1');
        print_Coding(ptr, ptr[key].rlink, result);
        result.erase(result.end() - 1);
    }
    else
    {
        //根节点输出
        cout << ptr[key].weight << " ";
        for (DataType i = 0; i < result.size(); i++)
        {
            cout << result[i];
        }
        cout << endl;
        result.erase(result.end() - 1);
    }
}

void out(PHtTree ptr, int m)
{
    vector<char> result;
    print_Coding(ptr, m * 2 - 2, result);
    result.clear();
}
int main() //5 2 7 4 5 19
{
    DataType m;
    cin >> m;
    PHtTree ptr = creatrTree(m);
    out(ptr, m);
    return 0;
}