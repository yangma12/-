#include<stdio.h>
#include<stdlib.h>


typedef int DataType;
struct SeqList
{
	int MAX;//������
	int n;//ʵ�ʴ���
	//DataType element[];����ָ��
	DataType *element;
};
typedef struct SeqList *Pseq;

//����m���Ŀձ�
Pseq creatseqList(int m){
	Pseq plist = (Pseq)malloc(sizeof(struct SeqList));
	if (plist != NULL) {
		//element��һ��ָ��int[]��ָ��
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
//�ڵ�x������ǰ����
void insertseqList(Pseq pseq, int x, DataType i) {
	Pseq p1 = pseq;

	int a;
	//�Ⱥ����ٲ���
	/*for (a; a +1< p1->MAX; a++) {
		p1->element[a] = p1->element[a + 1];
	}*///�϶�Ҫ������밡
	for (a = pseq->n ; a >= x; a--) {
		pseq->element[a ] = pseq->element[a-1];
	}
	p1->element[a] = i;
	p1->n += 1;

}
//ɾ������i
void deleteseqList(Pseq pseq, DataType i) {
	//�Ƚ���ɾ��Ԫ�غ������ȫ��ǰ��
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

	}//�ҵ���ɾ����Ԫ���±�
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
//	printf("�����������Сm");
//	scanf("%d", &m);
//	Pseq pseq = creatseqList(m);
//	//��ֵ
//	for (i = 0; i < m-1; i++) {
//		
//		printf("��%dλ",i+1);
//		scanf_s("%d",& pseq->element[i]);
//		pseq->n++;   //���˼���ֵ�������±�
//	}
//	
//	//����
//	//insertseqList(pseq, 2, 9);
//	//ɾ��(���һλ���������룬ԭ��δ�ҵ�)
//	deleteseqList(pseq, 2);
//	for (i = 0; i < m; i++) {
//		printf("%d", pseq->element[i]);
//	}
//	system("pause");//��ͣ
//}