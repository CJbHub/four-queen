#include<iostream>
#include<math.h>
using namespace std;
struct graph {
	int x;
	int y;
	int num;//用来记录这是第几个皇后
};
bool constraint(graph child,graph father);//约束函数，由隐约束判断是否能够得到可行解
void output(graph *x);
void backtrack(int dep,graph *x,graph father);//dep表示当前深度
int main() {
	graph *x = new graph[4];//用来装皇后的位置，保存解
	graph father;
	int dep;
	for (int i = 1; i < 4; i++) {
		father.x = i;           //确定第一行皇后的位置
		father.y = 1;
		father.num = 1;
		x[0] = father;
		backtrack(1, x, father);
	}
	return 0;
}

void backtrack(int dep, graph *x, graph father)
{
	graph child;                                 //孩子节点
	int num = dep;
	if (dep >= 4)                               //当搜索的成熟大于解空间树的深度时，说明搜索到了叶子结点，找到了一个解
		output(x);
	else {
		for (int i = 1; i < 5; i++) {           //遍历父节点的每一个孩子  
			child.x = i;
			child.y = father.y + 1;             //显约束，不同行
			child.num = child.y;
			x[num] = child;                     //将分支上的 数据保存
			if (constraint(child, father)) {    //判断该分支上的孩子是否满足隐约束
				backtrack(dep + 1, x, child);   //如果满足，则进入dep+1层的孩子节点继续搜索
			}
		}

	}
}

bool constraint(graph child,graph father)
{
	if (abs(father.num - child.num) != abs(father.x - child.x)&&(child.x!=father.x))//隐约束 不同斜线和显条件不同列
		return true;
	else
		return false;
}

void output(graph * x)
{
	for (int i = 0; i < 4; i++) {
		cout << "(" << x[i].x << "," << x[i].y << ")" << endl;
	}
	cout << endl;
}
