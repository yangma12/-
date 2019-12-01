#include<stdio.h>
#include<stdlib.h>
//顺序栈（与顺序表极其相似）
/*
栈的后进先出思想与递归十分相似
最后解迷宫问题
*/
struct mazedemo
{
	//迷宫坐标
	int x;
	int y;
	//方向
	int d;//1,2,3,4--东南西北
};
typedef struct mazedemo DataType;
//typedef struct mazedemo
//{
//	//迷宫坐标
//	int x;
//	int y;
//	//方向
//	int d;//1,2,3,4--东南西北
//}DataType;//所存数据类型
typedef struct SeqStack {
	int Maxnum;//最多存元素个数
	int top;//栈顶位置
	
	DataType *s;
}* PseqStack;

//创建空栈
PseqStack createEmptyStack(int x) {
	PseqStack ps = (PseqStack)malloc(sizeof(struct SeqStack));
	if (ps != NULL) {
		ps->Maxnum = x;
		ps->top = -1;
		ps->s = (DataType *)malloc(sizeof(DataType)*x);
		
		return ps;
	}
}
//进栈
void push_seq(PseqStack pstack, DataType x) {
	if (pstack->top >= pstack->Maxnum - 1) {
		printf("Overflow\n");
	}
	else
	{
		pstack->top = pstack->top + 1;
		pstack->s[pstack->top] = x;
	}
}
//出栈(取栈顶元素)
void pop_seq(PseqStack pstack) {
	if (pstack->top == -1) {
		printf("underflower\n");
	}
	else
	{
		pstack->top = pstack->top - 1;
	}
}
//迷宫问题(1为入口，2为出口),地图道路标记为1，其余标记为0
void mazePath(int (*m)[4], int x1, int y1, int x2, int y2, PseqStack pstack) {
	int i, j, k,g,h;//承载坐标和方向
	int dx[] = { 1,-1,0,0 };//x轴方向
	int dy[] = { 0,0,-1,1 };//y轴方向
	//给出口做标记
	
	m[x1][y1] = 2;
	DataType maze;
	maze.x = x1;
	maze.y = y1;
	maze.d = -1;
	push_seq(pstack,maze);//入口进栈
	while (pstack!=NULL)
	{
		DataType element = pstack->s[pstack->top];//取栈顶元素
		pop_seq(pstack);//出栈
		i = element.x;
		j = element.y;
		/*if (element.d == 4) {
			k = 1;
		}
		else
			k = element.d + 1;*/
		k = element.d + 1;
		//依次判别方向
		/*
		想法1：(当遇到走不通时，需要原路返回，因此上一个路径的反方向必须是方向循环中的最后一个，所以d+1)
		但并不用这么麻烦，如果走不通了就跳出方向循环，出栈删除，一直删除到有新的方向且=1
		*/
		while (k<4)
		{

			g = i + dx[k];
			h = j + dy[k];
			if (g == x2 && h == y2 && m[g][h] == 1) {//走到了出口
				//打印路径
				printf("路径为：");
				while (pstack!=NULL)
				{
					DataType ele = pstack->s[pstack->top];
					pop_seq(pstack);
					printf("%d,%d\n", ele.x, ele.y);
				}
				return;
			}
			else if (m[g][h] == 1) {//有没走过的点了
				m[g][h] = 2;
				element.x = i;
				element.y = j;
				
				element.d = k;
				push_seq(pstack,element);//进入路径栈
				i = g;
				j = h;
				k = -1;
				break;
			}
			
			k++;
		}

	}

}

void main() {
	//测试迷宫
	int a[5][5] = { 0,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,0,0 };
	int i,j;
	/*printf("Input ：\n");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			scanf_s("%d", &a[j][i],20);
		}
	}*/
	

	PseqStack ps = createEmptyStack(25);
	int (*maze)[] = a;
	mazePath(maze, 1, 1, 4, 4,ps);
	for (j = 0; j < ps->top; j++) {
		printf("%d,%d", ps->s[j].x, ps->s[j].y);
	}
	system("pause");//暂停
}
