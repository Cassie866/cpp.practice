/*
2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1，给定s1=abcd和s2=ACBD，返回0.
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC
*/


//判断一个字符串是否为一个字符串旋转之后的值

#define  _CRT_SECURE_NO_WARNINGS
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

int Judje(char* dest, char* sour)
{
	if (strlen(dest) != strlen(sour))
	{
		return 0;
	}
	if (strcmp(dest, sour) == 0)
	{
		return 1;
	}
	int k = strlen(dest);
	k--;
	while (k != 0)
	{
		ZuoXuan(sour, 1);
		if (strcmp(dest, sour) == 0)
		{
			return 1;
		}
		k--;
	}
	return 0;
}

int main()
{
	char dest[100] = { 0 };
	char sour[100] = { 0 };
	scanf("%s", dest);
	scanf("%s", sour);
	printf("%d\n", Judje(dest, sour));
	return 0;
}
