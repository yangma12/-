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
//��������������㷨

//ֱ�Ӳ��������㷨
void directinsertion(int *num,int n) {
	int i, j;
	for (i = 2; i < n; i++) {
		num[0] = num[i];//�����ڱ�������һ��j���жϽ����Ƚ�
		//����������ֱ�Ӳ���
		for (j = i - 1; num[j] > num[0]; j--) {
			//���num[j] > num[0],��num[j]������
			num[j + 1] = num[j];
		}
		//��num[j]<=num[0]������
		num[j+1] = num[0];
	}
}
//���ַ���������
void halfinsertion(int *num, int n) {
	int i, j;
	for (i = 2; i < n; i++) {
		num[0] = num[i];
		//��λ��λ
		int high = i - 1;
		int low = 1;
		//while (high != low)   ��high-1��С��
			while (high >= low) {
			int mid = (high + low) / 2;
			if (num[mid] > num[0]) {
				high = mid-1;
			}
			else
				low = mid+1;
		}
		//high+1Ϊ����λ��
		for (j = i - 1; j>=high+1; j--) {
			num[j + 1] = num[j];
		}
		
		num[high+1] = num[0];
	}
}
//ϣ������()
/*d�ǲ�������
ϣ������Ļ���˼���ǣ��Ƚ�����������ļ�¼���зָ��Ϊ���������зֱ����ֱ�Ӳ�������
�����������еļ�¼����������ʱ���ٶ�ȫ���¼��������ֱ�Ӳ�������*/

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

	