#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
���ز����������� 1 �ĸ�����
���磺
15
0000 1111
4 �� 1
*/

//���ز�����������1�ĸ���
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
	printf("������һ�����֣�\n");
	int value = 0;
	scanf("%d", &value);
	printf("��������1�ĸ���: %d\n", count_one_bits(value));
}

/*��ȡһ�������������������е�ż��λ������λ���ֱ�������������С�*/
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
	printf("������һ�����֣�\n");
	int value = 0;
	scanf("%d", &value);
	Print(value);
}

/*
����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ����������:1999 2299�������:7
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
	printf("�������������֣�\n");
	int m = 0, n = 0;
	scanf("%d %d", &m, &n);
	printf("��ͬ��bitλ��Ϊ��%d\n", differ1(m, n));
}

/*
��д������
unsigned int reverse_bit(unsigned int value);
��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
�磺
��32λ������25���ֵ�������и�λ��
00000000000000000000000000011001
��ת�󣺣�2550136832��
10011000000000000000000000000000
���������أ�
2550136832
*/

unsigned int Reverse1(unsigned int n)
{
	unsigned int ret = 0;
	for (int i = 0; i < 32; i++)
	{
		//������һλ�Ľ��
		ret <<= 1;
		//�ѵ�ǰλ�Ľ��������ret�ĵ�һλ��
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
	printf("������һ����������\n");
	scanf("%d", &n);
	printf("%u\n", Reverse1(n));
	printf("%u\n", Reverse2(n));
}

/*
��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��
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
	printf("��������������");
	scanf("%d %d", &m, &n);
	printf("ƽ����Ϊ��%d\n", average1(m, n));
	printf("ƽ����Ϊ��%d\n", average2(m, n));
	printf("ƽ����Ϊ��%d\n", average3(m, n));
}

/*
һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ����ҳ�������֡���ʹ��λ���㣩
*/

void test6()
{
	int a[9] = { 1, 2, 3, 4, 6, 4, 3, 2, 1 };
	int ret = 0;
	for (int i = 0; i < 9; i++)
	{
		ret ^= a[i];
	}
	printf("�������ֵ�����Ϊ��%d\n", ret);
}

/*
һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Σ��ҳ����������֡�
*/

void test7()
{
	int a[10] = { 1,1,2,2,4,4,4,4,5,6 };
	int ret = 0, divide = 0, x = 0, y = 0;
	for (int i = 0; i < 10; i++)
	{
		ret ^= a[i];    //ret��ֵ�ǳ�����һ�ε����������Ľ��
	}
	for (int i = 0; i < 32; i++)
	{
		if (((ret << i) & 1) == 1)
		{
			//��ret�Ķ�����λ���ҵ�һ��Ϊ 1 ��λ����¼�������λ��
			divide = i;
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		//���ݵ� divide λ�Ĳ�ͬ���������Ϊ����
		if (((a[i] << divide) & 1) == 1)
		{
			x ^= a[i];
			//x��ֵ���������е������ֵ��Ǹ���
		}
		else
		{
			y ^= a[i];
			//y��ֵ���������е������ֵ��Ǹ���
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