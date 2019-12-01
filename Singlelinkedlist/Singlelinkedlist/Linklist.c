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
typedef struct Node * LinkList;/*单链表类型*/

//头插法建立单链表  
LinkList createNullList() {
	int x;

	LinkList _list = (LinkList)malloc(sizeof(struct Node));/*表头节点空间*/



	if (_list != NULL)//如果内存不足，将null
		_list->link = NULL;//设置为空链表

	while (scanf_s("%d", &x) != EOF)//while(scanf("%d",&x) != EOF) (str = getchar()) != '\n'或者可以用这个
	{
		//LinkList llist = (LinkList)malloc(sizeof(Pnode));
		LinkList llist = (LinkList)malloc(sizeof(struct Node));
		printf("请输入产品编号");
		scanf_s("%d", llist->info.id);
		printf("请输入产品名称");
		scanf_s("%d", llist->info.name);
		printf("请输入产品数量");
		scanf_s("%d", llist->info.num);
		llist->link = _list->link;
		_list->link = llist;
	}

	return _list;
}
//尾插法建立单链表(l会随着新节点产生下移)
LinkList createNullList2() {
	int x;

	LinkList _list = (LinkList)malloc(sizeof(struct Node));/*表头节点空间*/
	_list->link = NULL;
	LinkList l;
	l = _list;

	while (scanf_s("%d", &x) != EOF)
	{
		LinkList llist = (LinkList)malloc(sizeof(struct Node));
		printf("请输入产品编号");
		scanf_s("%d", llist->info.id);
		printf("请输入产品名称");
		scanf_s("%d", llist->info.name);
		printf("请输入产品数量");
		scanf_s("%d", llist->info.num);
		l->link = llist;
		l = llist;
	}
	l->link = NULL;
	return _list;
}

//单链表的增删改查操作
LinkList Insert(LinkList L, int i) {
	//先找到要加入的节点的前驱节点
	int z;
	LinkList p;
	p = L;

	for (z = 1; z < i; z++) {
		p = p->link;
	}


	//再创建新节点，换一下指针域
	LinkList n = (LinkList)malloc(sizeof(struct Node));
	printf("请输入产品编号");
	scanf_s("%d", n->info.id);
	printf("请输入产品名称");
	scanf_s("%d", n->info.name);
	printf("请输入产品数量");
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
	//pre为前驱结点，p为查找的结点。   
	p = L->link;
	while (p->info.id != x)              //查找值为x的元素   
	{
		q = p;
		p = p->link;
	}
	q->link = p->link;//删除操作，将其前驱next指向其后继。   
	p->link = NULL;
	free(p);
	return L;
}
//线性表L中查找e的数据元素，成功返回数据元素的位置序号，失败返回0
int inquiry(LinkList L, int e) {
	LinkList p;
	int j = 0;
	p = L;
	while (p->info.id != e) {
		p = p->link;
		++j;
	}
	if (p) {
		return j;  //成功的查找返回元素的位置
	}
	else {
		return 0; //失败，返回0
	}
}
//LinkList Delet(LinkList L, int i,int x) {
//	//删除值为x的节点,或者第几个节点
//	//先找到要删除的节点和前驱节点
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

	//测试添加
	printf_s("你要查编号为几");
	int x;
	scanf_s("%d", x);
	ll = Insert(ll, x);
	//ll = Delet(ll,NULL,2);
	//测试删除
	printf_s("你要查编号为几");
	int y;
	scanf_s("%d", y);
	ll = Insert(ll, y);
	ll = LinkedListDelete(ll, y);
	for (ll = ll->link; ll != NULL; ll = ll->link) {
		printf("%d", ll->info.name);
	}
	//查询操作
	printf_s("你要查编号为几");
	int e;
	scanf_s("%d", e);

	int loaction = inquiry(ll, e);
}
