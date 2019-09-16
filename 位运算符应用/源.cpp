#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
返回参数二进制中 1 的个数。
比如：
15
0000 1111
4 个 1
*/

//返回参数二进制中1的个数
int count_one_bits(int value)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((value >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}

void test1()
{
	printf("请输入一个数字：\n");
	int value = 0;
	scanf("%d", &value);
	printf("二进制中1的个数: %d\n", count_one_bits(value));
}

/*获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。*/
void Print(int n)
{
	int i = 0;
	for (i = 31; i > 0; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
}


void test2()
{
	printf("请输入一个数字：\n");
	int value = 0;
	scanf("%d", &value);
	Print(value);
}

/*
两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？输入例子:1999 2299输出例子:7
*/
int differ1(int m, int n)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((m >> i) & 1) != ((n >> i) & 1))
		{
			count++;
		}
	}
	return count;
}

void test3()
{
	printf("请输入两个数字：\n");
	int m = 0, n = 0;
	scanf("%d %d", &m, &n);
	printf("不同的bit位数为：%d\n", differ1(m, n));
}

/*
编写函数：
unsigned int reverse_bit(unsigned int value);
这个函数的返回值value的二进制位模式从左到右翻转后的值。
如：
在32位机器上25这个值包含下列各位：
00000000000000000000000000011001
翻转后：（2550136832）
10011000000000000000000000000000
程序结果返回：
2550136832
*/

unsigned int Reverse1(unsigned int n)
{
	unsigned int ret = 0;
	for (int i = 0; i < 32; i++)
	{
		//保存上一位的结果
		ret <<= 1;
		//把当前位的结果保存在ret的第一位；
		ret |= (n >> i) & 1;
	}
	return ret;
}

unsigned int Reverse2(unsigned int n)
{
	unsigned int sum = 0;
	for (int i = 0; i < 32; i++)
	{
		sum += ((n >> i) & 1) * pow(2, 31 - i);
	}
	return sum;
}

void test4()
{
	unsigned int n = 0;
	printf("请输入一个正整数：\n");
	scanf("%d", &n);
	printf("%u\n", Reverse1(n));
	printf("%u\n", Reverse2(n));
}

/*
不使用（a+b）/2这种方式，求两个数的平均值。
*/

int average1(int m, int n)
{
	return (m + n) >> 1;
}

int average2(int m, int n)
{
	return (m & n) + ((m ^ n) >> 1);
}

int average3(int m, int n)
{
	return m + ((n - m) >> 1);
}

void test5()
{
	int m = 0, n = 0;
	printf("请输入两个数：");
	scanf("%d %d", &m, &n);
	printf("平均数为：%d\n", average1(m, n));
	printf("平均数为：%d\n", average2(m, n));
	printf("平均数为：%d\n", average3(m, n));
}

/*
一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。请找出这个数字。（使用位运算）
*/

void test6()
{
	int a[9] = { 1, 2, 3, 4, 6, 4, 3, 2, 1 };
	int ret = 0;
	for (int i = 0; i < 9; i++)
	{
		ret ^= a[i];
	}
	printf("单独出现的数字为：%d\n", ret);
}

/*
一个数组中只有两个数字是出现一次，其他所有数字都出现了两次，找出这两个数字。
*/

void test7()
{
	int a[10] = { 1,1,2,2,4,4,4,4,5,6 };
	int ret = 0, divide = 0, x = 0, y = 0;
	for (int i = 0; i < 10; i++)
	{
		ret ^= a[i];    //ret的值是出现了一次的两个数异或的结果
	}
	for (int i = 0; i < 32; i++)
	{
		if (((ret << i) & 1) == 1)
		{
			//在ret的二进制位中找到一个为 1 的位，记录下来这个位置
			divide = i;
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		//根据第 divide 位的不同，将数组分为两组
		if (((a[i] << divide) & 1) == 1)
		{
			x ^= a[i];
			//x的值是这组数中单独出现的那个数
		}
		else
		{
			y ^= a[i];
			//y的值是这组数中单独出现的那个数
		}
	}
	printf("%d\n", x);
	printf("%d\n", y);
}

int main()
{
	test1();
	/*
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	*/
	return 0;
}