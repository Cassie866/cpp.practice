/*
输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。

函数change的功能：
从数组的左端查找偶数，同时从数组右端查找奇数，交换奇偶数的位置，使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。

*/

#include <stdio.h>
#include <stdlib.h>

void change(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		while ((left < right) && (a[left] % 2 != 0))
		{
			left++;
		}
		while ((left < right) && (a[right] % 2 == 0))
		{
			right--;
		}
		if (left < right)
		{
			int tmp = a[left];
			a[left] = a[right];
			a[right] = tmp;
		}
	}
}

int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	change(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
