#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SIZE 1000
typedef struct PersonIFM
{
	char name[100];
	char phone[100];
}PersonIFM;

typedef struct AddrBook
{
	PersonIFM personifm[SIZE];
	int size;
}AddrBook;

AddrBook addrbook;
int Menu()
{
	printf("__________________________________\n");
	printf("\n");
	printf("         1.添加联系人\n");
	printf("         2.删除联系人\n");
	printf("         3.查找联系人\n");
	printf("         4.修改联系人\n");
	printf("         5.显示所有联系人\n");
	printf("         6.清空所有联系人\n");
	printf("         0.退出通讯录\n");
	printf("__________________________________\n");
	printf("请输入您要进行操作的编号： ");
	while (1)
	{
		int choice = 0;
		scanf("%d", &choice);
		if (choice == 0 || choice == 1 || choice == 2
			|| choice == 3 || choice == 4 || choice == 5
			|| choice == 6 || choice == 7)
		{
			return choice;
		}
		else
		{
			printf("输入有误，请重新输入： ");
		}
	}
}

void Init()
{
	addrbook.size = 0;
	for (int i = 0; i < SIZE; i++)
	{
		strcpy(addrbook.personifm[i].name, "");
		strcpy(addrbook.personifm[i].phone, "");
	}
}

void Add()
{
	if (addrbook.size > SIZE)
	{
		printf("联系人已满，添加失败！\n");
	}
	printf("请输入联系人姓名：");
	scanf("%s", addrbook.personifm[addrbook.size].name);
	printf("请输入联系人电话：");
	scanf("%s", addrbook.personifm[addrbook.size].phone);
	addrbook.size++;
	printf("添加成功！\n");
	return;
}

void Del()
{
	printf("请输入要删除的联系人姓名：");
	char name[10] = { 0 };
	scanf("%s", &name);
	int i = 0;
	for (; i < addrbook.size; i++)
	{
		if (strcmp(name, addrbook.personifm[i].name) == 0)
		{
			addrbook.personifm[i] = addrbook.personifm[i + 1];
			break;
		}
	}
	if (i < addrbook.size)
	{
		addrbook.size--;
		printf("删除成功!\n");
	}
	else
	{
		printf("没有要删除的联系人!\n");
	}
}

void Find()
{
	printf("请输入要查找的联系人姓名：");
	char name[10] = { 0 };
	scanf("%s", &name);
	if (addrbook.size > 0)
	{
		int i = 0;
		for (; i < addrbook.size; i++)
		{
			if (strcmp(name, addrbook.personifm[i].name) == 0)
			{
				break;
			}
		}
		if (i < addrbook.size)
		{
			printf("%s", addrbook.personifm[i].name);
			printf("\t");
			printf("%s\n", addrbook.personifm[i].phone);
		}
		else
		{
			printf("没有要查找的联系人!\n");
		}
	}
	else
	{
		printf("没有要查找的联系人!\n");
	}
}

void Modify()
{
	printf("请输入要修改的联系人姓名：");
	char name[10] = { 0 };
	scanf("%s", &name);
	int i = 0;
	for (; i < addrbook.size; i++)
	{
		if (strcmp(name, addrbook.personifm[i].name) == 0)
		{
			break;
		}
	}
	if (i < addrbook.size)
	{
		printf("请输入修改后的联系人姓名：");
		scanf("%s", addrbook.personifm[i].name);
		printf("请输入修改后的联系人电话：");
		scanf("%s", addrbook.personifm[i].phone);
	}
	else
	{
		printf("没有要修改的联系人!\n");
	}
}

void Print()
{
	for (int i = 0; i < addrbook.size; i++)
	{
		printf("%s   %s\n", addrbook.personifm[i].name, addrbook.personifm[i].phone);
	}
	printf("\n");
}

void Clear()
{
	addrbook.size = 0;
	printf("联系人已清空！\n");
}

int main()
{
	Init();
	while (1)
	{
		int choice = Menu();
		switch (choice)
		{
		case 1:
			//添加联系人
			Add();
			break;
		case 2:
			//删除联系人
			Del();
			break;
		case 3:
			//查找联系人
			Find();
			break;
		case 4:
			//修改联系人信息
			Modify();
			break;
		case 5:
			//显示所有联系人
			Print();
			break;
		case 6:
			Clear();
			//清空所有联系人
			break;
		case 0:
			printf("通讯录已退出！\n");
			break;
		}
		if (choice == 0)
		{
			break;
		}
	}
	return 0;
}
