#include<stdio.h>
//ѡ������

//1.ֱ��ѡ������
void directSlesct(int *num,int n) {
	int i, j,temp;
	//{ 0,6,9,2,4,7,1,3,4,8 }
	for ( i = 1; i < n; i++) {
		//��һ����Сֵ
		int min = 0;
		for (j = i + 1; j < n; j++) {
			if (num[j] < num[min]) {
				min = j;
			}

		}
		//����С���õ�ǰ����
		if (min != i) {// �����������λ�ý���
			temp = num[min];
			num[min] = num[i];
			num[i] = temp;

		}
	}
}

//������
void heapsort() {

}
void Print(int *A, int N)
{
	int i;
	for (i = 1; i < N; i++)
	{
		printf(" %d ", A[i]);

	}
	printf("\n");
}
void main() {
	int exam1[10] = { 0,6,9,2,4,7,1,3,4,8 };
	
	directSlesct(exam1, 10);
	Print(exam1, 10);
	system("pause");
}

