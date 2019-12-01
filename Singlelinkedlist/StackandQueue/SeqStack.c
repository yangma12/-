#include<stdio.h>
#include<stdlib.h>
//˳��ջ����˳��������ƣ�
/*
ջ�ĺ���ȳ�˼����ݹ�ʮ������
�����Թ�����
*/
struct mazedemo
{
	//�Թ�����
	int x;
	int y;
	//����
	int d;//1,2,3,4--��������
};
typedef struct mazedemo DataType;
//typedef struct mazedemo
//{
//	//�Թ�����
//	int x;
//	int y;
//	//����
//	int d;//1,2,3,4--��������
//}DataType;//������������
typedef struct SeqStack {
	int Maxnum;//����Ԫ�ظ���
	int top;//ջ��λ��
	
	DataType *s;
}* PseqStack;

//������ջ
PseqStack createEmptyStack(int x) {
	PseqStack ps = (PseqStack)malloc(sizeof(struct SeqStack));
	if (ps != NULL) {
		ps->Maxnum = x;
		ps->top = -1;
		ps->s = (DataType *)malloc(sizeof(DataType)*x);
		
		return ps;
	}
}
//��ջ
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
//��ջ(ȡջ��Ԫ��)
void pop_seq(PseqStack pstack) {
	if (pstack->top == -1) {
		printf("underflower\n");
	}
	else
	{
		pstack->top = pstack->top - 1;
	}
}
//�Թ�����(1Ϊ��ڣ�2Ϊ����),��ͼ��·���Ϊ1��������Ϊ0
void mazePath(int (*m)[4], int x1, int y1, int x2, int y2, PseqStack pstack) {
	int i, j, k,g,h;//��������ͷ���
	int dx[] = { 1,-1,0,0 };//x�᷽��
	int dy[] = { 0,0,-1,1 };//y�᷽��
	//�����������
	
	m[x1][y1] = 2;
	DataType maze;
	maze.x = x1;
	maze.y = y1;
	maze.d = -1;
	push_seq(pstack,maze);//��ڽ�ջ
	while (pstack!=NULL)
	{
		DataType element = pstack->s[pstack->top];//ȡջ��Ԫ��
		pop_seq(pstack);//��ջ
		i = element.x;
		j = element.y;
		/*if (element.d == 4) {
			k = 1;
		}
		else
			k = element.d + 1;*/
		k = element.d + 1;
		//�����б���
		/*
		�뷨1��(�������߲�ͨʱ����Ҫԭ·���أ������һ��·���ķ���������Ƿ���ѭ���е����һ��������d+1)
		����������ô�鷳������߲�ͨ�˾���������ѭ������ջɾ����һֱɾ�������µķ�����=1
		*/
		while (k<4)
		{

			g = i + dx[k];
			h = j + dy[k];
			if (g == x2 && h == y2 && m[g][h] == 1) {//�ߵ��˳���
				//��ӡ·��
				printf("·��Ϊ��");
				while (pstack!=NULL)
				{
					DataType ele = pstack->s[pstack->top];
					pop_seq(pstack);
					printf("%d,%d\n", ele.x, ele.y);
				}
				return;
			}
			else if (m[g][h] == 1) {//��û�߹��ĵ���
				m[g][h] = 2;
				element.x = i;
				element.y = j;
				
				element.d = k;
				push_seq(pstack,element);//����·��ջ
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
	//�����Թ�
	int a[5][5] = { 0,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,0,0 };
	int i,j;
	/*printf("Input ��\n");
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
	system("pause");//��ͣ
}
