#include<stdio.h>
#include<stdlib.h>


struct ELectric
{
	int id;
	char name[10];
	int num;

};
typedef struct ELectric ELectricdemo;
struct Node
{
	ELectricdemo info;
	struct Node *link;
};
typedef struct Node * LinkList;/*����������*/

//ͷ�巨����������  
LinkList createNullList() {
	int x;

	LinkList _list = (LinkList)malloc(sizeof(struct Node));/*��ͷ�ڵ�ռ�*/



	if (_list != NULL)//����ڴ治�㣬��null
		_list->link = NULL;//����Ϊ������

	while (scanf_s("%d", &x) != EOF)//while(scanf("%d",&x) != EOF) (str = getchar()) != '\n'���߿��������
	{
		//LinkList llist = (LinkList)malloc(sizeof(Pnode));
		LinkList llist = (LinkList)malloc(sizeof(struct Node));
		printf("�������Ʒ���");
		scanf_s("%d", llist->info.id);
		printf("�������Ʒ����");
		scanf_s("%d", llist->info.name);
		printf("�������Ʒ����");
		scanf_s("%d", llist->info.num);
		llist->link = _list->link;
		_list->link = llist;
	}

	return _list;
}
//β�巨����������(l�������½ڵ��������)
LinkList createNullList2() {
	int x;

	LinkList _list = (LinkList)malloc(sizeof(struct Node));/*��ͷ�ڵ�ռ�*/
	_list->link = NULL;
	LinkList l;
	l = _list;

	while (scanf_s("%d", &x) != EOF)
	{
		LinkList llist = (LinkList)malloc(sizeof(struct Node));
		printf("�������Ʒ���");
		scanf_s("%d", llist->info.id);
		printf("�������Ʒ����");
		scanf_s("%d", llist->info.name);
		printf("�������Ʒ����");
		scanf_s("%d", llist->info.num);
		l->link = llist;
		l = llist;
	}
	l->link = NULL;
	return _list;
}

//���������ɾ�Ĳ����
LinkList Insert(LinkList L, int i) {
	//���ҵ�Ҫ����Ľڵ��ǰ���ڵ�
	int z;
	LinkList p;
	p = L;

	for (z = 1; z < i; z++) {
		p = p->link;
	}


	//�ٴ����½ڵ㣬��һ��ָ����
	LinkList n = (LinkList)malloc(sizeof(struct Node));
	printf("�������Ʒ���");
	scanf_s("%d", n->info.id);
	printf("�������Ʒ����");
	scanf_s("%d", n->info.name);
	printf("�������Ʒ����");
	scanf_s("%d", n->info.num);
	n->link = p->link;
	p->link = n;

	return L;
}

LinkList LinkedListDelete(LinkList L, int x)
{
	int z;
	LinkList p, q;
	q = L;
	//preΪǰ����㣬pΪ���ҵĽ�㡣   
	p = L->link;
	while (p->info.id != x)              //����ֵΪx��Ԫ��   
	{
		q = p;
		p = p->link;
	}
	q->link = p->link;//ɾ������������ǰ��nextָ�����̡�   
	p->link = NULL;
	free(p);
	return L;
}
//���Ա�L�в���e������Ԫ�أ��ɹ���������Ԫ�ص�λ����ţ�ʧ�ܷ���0
int inquiry(LinkList L, int e) {
	LinkList p;
	int j = 0;
	p = L;
	while (p->info.id != e) {
		p = p->link;
		++j;
	}
	if (p) {
		return j;  //�ɹ��Ĳ��ҷ���Ԫ�ص�λ��
	}
	else {
		return 0; //ʧ�ܣ�����0
	}
}
//LinkList Delet(LinkList L, int i,int x) {
//	//ɾ��ֵΪx�Ľڵ�,���ߵڼ����ڵ�
//	//���ҵ�Ҫɾ���Ľڵ��ǰ���ڵ�
//	int z;
//	Pnode p,q;
//	p = L;
//	q = L;
//	if (i != NULL) {
//		for (z = 1; z < i; z++) {
//			q = p;
//			p = p->link;
//		}
//		q->link = p->link;
//		free(p);
//	}
//	if (x != NULL) {
//		while (p->info!=x)
//		{
//			q = p;
//			p = p->link;
//		}
//		q->link = p->link;
//		free(p);
//	}
//	return L;
//}
void main() {
	LinkList ll = createNullList();

	//�������
	printf_s("��Ҫ����Ϊ��");
	int x;
	scanf_s("%d", x);
	ll = Insert(ll, x);
	//ll = Delet(ll,NULL,2);
	//����ɾ��
	printf_s("��Ҫ����Ϊ��");
	int y;
	scanf_s("%d", y);
	ll = Insert(ll, y);
	ll = LinkedListDelete(ll, y);
	for (ll = ll->link; ll != NULL; ll = ll->link) {
		printf("%d", ll->info.name);
	}
	//��ѯ����
	printf_s("��Ҫ����Ϊ��");
	int e;
	scanf_s("%d", e);

	int loaction = inquiry(ll, e);
}
