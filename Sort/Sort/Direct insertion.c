#include<stdio.h>

void Print(int *A, int N)
{
	int i;
	for (i = 1; i < N; i++)
	{
		printf(" %d ", A[i]);
		
	}
	printf("\n");
}
//插入排序的所有算法

//直接插入排序算法
void directinsertion(int *num,int n) {
	int i, j;
	for (i = 2; i < n; i++) {
		num[0] = num[i];//设置哨兵，减少一次j的判断结束比较
		//在有序组中直接插入
		for (j = i - 1; num[j] > num[0]; j--) {
			//如果num[j] > num[0],将num[j]往后移
			num[j + 1] = num[j];
		}
		//当num[j]<=num[0]，跳出
		num[j+1] = num[0];
	}
}
//二分法插入排序
void halfinsertion(int *num, int n) {
	int i, j;
	for (i = 2; i < n; i++) {
		num[0] = num[i];
		//高位低位
		int high = i - 1;
		int low = 1;
		//while (high != low)   有high-1后小于
			while (high >= low) {
			int mid = (high + low) / 2;
			if (num[mid] > num[0]) {
				high = mid-1;
			}
			else
				low = mid+1;
		}
		//high+1为插入位置
		for (j = i - 1; j>=high+1; j--) {
			num[j + 1] = num[j];
		}
		
		num[high+1] = num[0];
	}
}
//希尔排序()
/*d是步长增量
希尔排序的基本思想是：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，
待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。*/

void shell_sort(int *arr, int length)
{
	int temp;
	int j;
	for (int d = (length / 3) + 1; d >= 1; d = d / 2)
	{
		for (int i = d; i < length; ++i)
		{
			temp = arr[i];
			for (j = i - d; j >= 0 && temp < arr[j]; j = j - d)
			{
				arr[j + d] = arr[j];
			}
			arr[j + d] = temp;
		}

	}

}
//
//void main() {
//	int exam1[10] = { 0,6,9,2,4,7,1,3,4,8 };
//	//directinsertion(exam1, 10);
//	//halfinsertion(exam1, 10);
//	shell_sort(exam1, 10);
//	Print(exam1, 10);
//	system("pause");
//}

	