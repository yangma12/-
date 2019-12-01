#include<stdio.h>
//交换排序

//1.直接交换排序（冒泡）
void directSlesct(int *num, int n) {
	int i, j, temp;
	//{ 0,6,9,2,4,7,1,3,4,8 }
	for (i = 1; i < n; i++) {
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
