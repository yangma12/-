#include<stdio.h>

/*�������Ĵ洢��ʽ�����֣�
   1.˳��洢�Ļ������ڷ���ȫ����������ȱ��λ����Ҫ�������ַ������
   2,��ʽ�洢����ͨ����ֻ��Ҫ��������ָ��
               ��ͨ˫����Ҫ�������ҼӸ�ָ��
			   ����������,����ԭ���Ŀ�������ָ�룬ָ������������㡣����ָ���Ϊ����
			              һ�����1�����ptr->lchildΪ�գ�����ָ��������������иý���ǰ����㡣�������Ϊptr������ǰ����
                                  ��2�����ptr->rchildΪ�գ�����ָ��������������иý��ĺ�̽�㡣�������Ϊptr�������̣�
								       ��������һ����־�������ж�ָ������Ӻ��ӻ���ǰ����̽ڵ�

*/
struct Treenode;
typedef struct Treenode *Ptreenode;
typedef int DataType;
typedef struct Treenode {
	//��־��
	int tag;//1-l,r�����Ӻ��ӡ�2-l��r��̡�3-lǰ��r�ӡ�4-����
	//ָ����
	Ptreenode llink, rlink;
	//������
	DataType *s;
}*Trenode;
typedef Trenode *Ptrenode;
DataType x = 0;
//�����������������Trenode tre=(Trenode)__vcrt_malloc_normal(sizeof(struct Treenode))
void CreatTree(Trenode tre) {
	int ch;
	scanf_s("%d", &ch);//�����ַ�
	if (ch == 9)//.���������
		tre = NULL;
	else
	{
		tre = (Trenode *)malloc(sizeof(struct Treenode));
		if (!tre)
		{
			printf("�����ڴ�ʧ��\n");
			exit(1);
		}
		(tre)->s = ch;//��T��ֵ
		CreatTree(&(tre)->llink);//����������ֵ
		CreatTree(&(tre)->rlink);//����������ֵ
	}

    
}
//�������
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

	printf("�����ɹ�\n");
	TraverTree(tre);
	
}