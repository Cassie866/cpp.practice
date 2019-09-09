#include <stdio.h>
#include <assert.h>
//1.实现strcpy
char* Mystrcpy(char* dest, const char* sour)
{
	assert(dest != NULL);    //assert(dest);
	assert(sour != NULL);    //assert(sour);
	char* temp = dest;
	while (*sour != '\0')
	{
		*dest = *sour;
		dest++;
		sour++;
	}
	*dest = '\0';   //较容易遗漏
	return temp;
}

//2.实现strcat
char* Mystrcat(char* dest, char* sour)
{
	assert(dest != NULL);
	assert(sour != NULL);
	char* temp = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*sour != '\0')
	{
		*dest = *sour;
		dest++;
		sour++;
	}
	*dest = '\0';
	return temp;
}

//3.实现strstr

char* Mystrstr(char* str1, char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	char* cp = (char*)str1;
	char* substr = (char*)str2;
	char* s1 = NULL;
	if (*str2 == '\0')
	{
		return NULL;
	}
	while (*cp != '\0')
	{
		s1 = cp;
		substr = str2;
		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		if (*substr == '\0')
		{
			return cp;
			cp++;
		}
	}
}

//4.实现strcmp
int Mystrcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 > * str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		else
		{
			str1++;
			str2++;
		}
	}
	if (*str1 > * str2)
	{
		return 1;
	}
	else if (*str1 < *str2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//5.实现memcpy
void* Mymemcpy(void* dest, const* src, size_t count)
{
	void* ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

//6.实现memmove
void* Mymemmove(void* dest, const* src, size_t count)
{
	void* ret = dest;
	if (dest <= src || (char*)dest >= ((char*)src + count))
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		dest = (char*)dest + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}