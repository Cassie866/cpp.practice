/*
1.实现一个函数，可以左旋字符串中的k个字符。
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB
*/


//左旋k字符
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
	printf("请输入要旋转的字符串：\n");
	scanf("%s", str);
	printf("请输入要旋转的字符个数：\n");
	scanf("%d", &k);
	ZuoXuan(str, k);
	printf("%s\n", str);
	return 0;
}
