#include<stdio.h>

/*二叉树的存储方式有两种：
   1.顺序存储的话，对于非完全二叉树，空缺的位置需要用特殊字符坐填充
   2,链式存储，普通单向，只需要设置左右指针
               普通双向，需要设置左右加父指针
			   线索二叉树,利用原来的空链域存放指针，指向树中其他结点。这种指针称为线索
			              一般规则：1）如果ptr->lchild为空，则存放指向中序遍历序列中该结点的前驱结点。这个结点称为ptr的中序前驱；
                                  （2）如果ptr->rchild为空，则存放指向中序遍历序列中该结点的后继结点。这个结点称为ptr的中序后继；
								       其中另设一个标志域用于判断指向的是子孩子还是前驱后继节点

*/
struct Treenode;
typedef struct Treenode *Ptreenode;
typedef int DataType;
typedef struct Treenode {
	//标志域
	int tag;//1-l,r都是子孩子。2-l子r后继。3-l前驱r子。4-都继
	//指针域
	Ptreenode llink, rlink;
	//数据域
	DataType *s;
}*Trenode;
typedef Trenode *Ptrenode;
DataType x = 0;
//先序遍历创建二叉树Trenode tre=(Trenode)__vcrt_malloc_normal(sizeof(struct Treenode))
void CreatTree(Trenode tre) {
	int ch;
	scanf_s("%d", &ch);//读入字符
	if (ch == 9)//.代表空子树
		tre = NULL;
	else
	{
		tre = (Trenode *)malloc(sizeof(struct Treenode));
		if (!tre)
		{
			printf("开辟内存失败\n");
			exit(1);
		}
		(tre)->s = ch;//给T赋值
		CreatTree(&(tre)->llink);//给左子树赋值
		CreatTree(&(tre)->rlink);//给右子树赋值
	}

    
}
//先序遍历
void TraverTree(Trenode T)
{
	if (T == NULL)
		return;
	printf("%d ", T->s);
	TraverTree(T->llink);
	TraverTree(T->rlink);
}
static void main() {
	Trenode tre = NULL;
	CreatTree(tre);

	printf("建树成功\n");
	TraverTree(tre);
	
}