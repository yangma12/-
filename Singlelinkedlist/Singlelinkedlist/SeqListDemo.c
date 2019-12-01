#include<stdio.h>
#include<stdlib.h>


typedef int DataType;
struct SeqList
{
	int MAX;//最大存量
	int n;//实际存量
	//DataType element[];不如指针
	DataType *element;
};
typedef struct SeqList *Pseq;

//创建m长的空表
Pseq creatseqList(int m){
	Pseq plist = (Pseq)malloc(sizeof(struct SeqList));
	if (plist != NULL) {
		//element是一个指向int[]的指针
		plist->element = (DataType *)malloc(sizeof(DataType)*m);
		if (plist->element != NULL) {
			plist->MAX = m;
			plist->n = 0;


			return plist;
		}
		else
		{
			free(plist);
		}
		printf("out of space");
		return NULL;
	}
}
//在第x个数据前插入
void insertseqList(Pseq pseq, int x, DataType i) {
	Pseq p1 = pseq;

	int a;
	//先后移再插入
	/*for (a; a +1< p1->MAX; a++) {
		p1->element[a] = p1->element[a + 1];
	}*///肯定要倒叙插入啊
	for (a = pseq->n ; a >= x; a--) {
		pseq->element[a ] = pseq->element[a-1];
	}
	p1->element[a] = i;
	p1->n += 1;

}
//删除数据i
void deleteseqList(Pseq pseq, DataType i) {
	//先将被删除元素后的数据全部前移
	int a;
	int x = 0;
	while (i!=NULL) {
		if (pseq->element[x] == i) {
			break;
		}
		else
		{
			x++;
		}

	}//找到被删除的元素下标
	for (a =x; a < pseq->n-1; a++) {
		if (pseq->element[a + 1] == NULL)
			break;
		pseq->element[a] = pseq->element[a + 1];
	}
	pseq->n--;
}
//void main() {
//	int m;
//	int i;
//	printf("创建，输入大小m");
//	scanf("%d", &m);
//	Pseq pseq = creatseqList(m);
//	//赋值
//	for (i = 0; i < m-1; i++) {
//		
//		printf("第%d位",i+1);
//		scanf_s("%d",& pseq->element[i]);
//		pseq->n++;   //赋了几个值，不是下标
//	}
//	
//	//插入
//	//insertseqList(pseq, 2, 9);
//	//删除(最后一位数总是乱码，原因未找到)
//	deleteseqList(pseq, 2);
//	for (i = 0; i < m; i++) {
//		printf("%d", pseq->element[i]);
//	}
//	system("pause");//暂停
//}