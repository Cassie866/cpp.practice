/*
1.ʵ��һ�����������������ַ����е�k���ַ���
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB
*/


//����k�ַ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ZuoXuan(char* str, int k)
{
	int len = strlen(str);
	k = k % len;
	char temp = 0;
	char* cur = str;
	while (k != 0)
	{
		temp = *str;
		cur = str;
		while (*(cur + 1) != '\0')
		{
			*cur = *(cur + 1);
			cur++;
		}
		*cur = temp;
		k--;
	}
}

int main()
{
	char str[100];
	int k = 0;
	printf("������Ҫ��ת���ַ�����\n");
	scanf("%s", str);
	printf("������Ҫ��ת���ַ�������\n");
	scanf("%d", &k);
	ZuoXuan(str, k);
	printf("%s\n", str);
	return 0;
}
