#include<stdio.h>
//��������

//1.ֱ�ӽ�������ð�ݣ�
void directSlesct(int *num, int n) {
	int i, j, temp;
	//{ 0,6,9,2,4,7,1,3,4,8 }
	for (i = 1; i < n; i++) {
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
