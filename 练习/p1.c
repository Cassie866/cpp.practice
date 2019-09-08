/*
����һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

����change�Ĺ��ܣ�
���������˲���ż����ͬʱ�������Ҷ˲���������������ż����λ�ã�ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

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
