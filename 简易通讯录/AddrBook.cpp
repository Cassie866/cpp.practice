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
	printf("         1.�����ϵ��\n");
	printf("         2.ɾ����ϵ��\n");
	printf("         3.������ϵ��\n");
	printf("         4.�޸���ϵ��\n");
	printf("         5.��ʾ������ϵ��\n");
	printf("         6.���������ϵ��\n");
	printf("         0.�˳�ͨѶ¼\n");
	printf("__________________________________\n");
	printf("��������Ҫ���в����ı�ţ� ");
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
			printf("�����������������룺 ");
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
		printf("��ϵ�����������ʧ�ܣ�\n");
	}
	printf("��������ϵ��������");
	scanf("%s", addrbook.personifm[addrbook.size].name);
	printf("��������ϵ�˵绰��");
	scanf("%s", addrbook.personifm[addrbook.size].phone);
	addrbook.size++;
	printf("��ӳɹ���\n");
	return;
}

void Del()
{
	printf("������Ҫɾ������ϵ��������");
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
		printf("ɾ���ɹ�!\n");
	}
	else
	{
		printf("û��Ҫɾ������ϵ��!\n");
	}
}

void Find()
{
	printf("������Ҫ���ҵ���ϵ��������");
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
			printf("û��Ҫ���ҵ���ϵ��!\n");
		}
	}
	else
	{
		printf("û��Ҫ���ҵ���ϵ��!\n");
	}
}

void Modify()
{
	printf("������Ҫ�޸ĵ���ϵ��������");
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
		printf("�������޸ĺ����ϵ��������");
		scanf("%s", addrbook.personifm[i].name);
		printf("�������޸ĺ����ϵ�˵绰��");
		scanf("%s", addrbook.personifm[i].phone);
	}
	else
	{
		printf("û��Ҫ�޸ĵ���ϵ��!\n");
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
	printf("��ϵ������գ�\n");
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
			//�����ϵ��
			Add();
			break;
		case 2:
			//ɾ����ϵ��
			Del();
			break;
		case 3:
			//������ϵ��
			Find();
			break;
		case 4:
			//�޸���ϵ����Ϣ
			Modify();
			break;
		case 5:
			//��ʾ������ϵ��
			Print();
			break;
		case 6:
			Clear();
			//���������ϵ��
			break;
		case 0:
			printf("ͨѶ¼���˳���\n");
			break;
		}
		if (choice == 0)
		{
			break;
		}
	}
	return 0;
}
