#include<stdio.h>
//选择排序

//1.直接选择排序
void directSlesct(int *num,int n) {
	int i, j,temp;
	//{ 0,6,9,2,4,7,1,3,4,8 }
	for ( i = 1; i < n; i++) {
		//设一个最小值
		int min = 0;
		for (j = i + 1; j < n; j++) {
			if (num[j] < num[min]) {
				min = j;
			}

		}
		//把最小的拿到前面来
		if (min != i) {// 避免无意义的位置交换
			temp = num[min];
			num[min] = num[i];
			num[i] = temp;

		}
	}
}

//堆排序
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

