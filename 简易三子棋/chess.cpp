#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROW 3
#define COL 3

char chess[ROW][COL];

void InIt()
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			chess[row][col] = ' ';
		}
	}
}

void Print()
{
	printf(" \n");
	printf("     |---|---|---|\n");
	for (int row = 0; row < ROW; row++)
	{
		printf("     | %c | %c | %c |\n",chess[row][0], chess[row][1], chess[row][2]);
		if (row != ROW - 1)
		{
			printf("     |---|---|---|\n");
		}
	}
	printf("     |---|---|---|\n");
	printf(" \n");
}

void PlayerTime()
{
	while (1)
	{
		//1.��ʾ�������
		printf("��������ӣ�����һ�����꣩��\n");
		int row = 0, col = 0;
		scanf("%d %d", &row, &col);
		//2.�ж�����������Ƿ�Ϸ���������ȷ��ʾ
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("�����������������룡\n");
			continue;
		}
		if (chess[row][col] != ' ')
		{
			printf("��λ�������ӣ����������룡\n");
			continue;
		}
		//3.�Ϸ��󽫶�Ӧλ�����Ϊx
		chess[row][col] = 'x';
		break;
	}
}

void ComputerTime()
{
	printf("�������ӣ�\n");
	int row = 0, col = 0;
	//1.�������һ���к���
	while (1)
	{
		row = rand() % ROW;  //[0,row)
		col = rand() % COL;  //[0,col)
		//2.�ж�λ���Ƿ���ȷ
		if (chess[row][col] == ' ')
		{
			//3.����Ӧλ�����Ϊo
			chess[row][col] = 'o';
			break;
		}
	}
}

int IsFull()
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (chess[row][col] == ' ')
				return 0;
		}
	}
	return 1;
}

char CheckOver()
{
	//����Ƿ�����3����
	for (int row = 0; row < ROW; row++)
	{
		if (chess[row][0] == chess[row][1] && chess[row][0] == chess[row][2]
			&& chess[row][2] != ' ')
		{
			return chess[row][0];
		}
	}
	for (int col = 0; col < COL; col++)
	{
		if (chess[0][col] == chess[1][col] && chess[0][col] == chess[2][col] && chess[0][col] != ' ')
		{
			return chess[0][col];
		}
	}
	if (chess[0][0] == chess[1][1] && chess[0][0] == chess[2][2] && chess[0][0] != ' ')
	{
		return chess[0][0];
	}
	if (chess[0][2] == chess[1][1] && chess[0][2] == chess[2][0] && chess[0][2] != ' ')
	{
		return chess[0][2];
	}
	if (IsFull())
	{
		return 'q';
	}
	return ' ';
}

int main()
{
	char winner = ' ';
	InIt();
	while (1)
	{
		Print();
		PlayerTime();
		winner = CheckOver();
		if (winner != ' ')
		{
			Print();
			break;
		}
		ComputerTime();
		winner = CheckOver();
		if (winner != ' ')
		{
			Print();
			break;
		}
	}
	if (winner == 'o')
	{
		printf("���Ի�ʤ������\n");
	}
	else if (winner == 'x')
	{
		printf("��һ�ʤ������\n");
	}
	else if (winner == 'q')
	{
		printf("���壡����\n");
	}
	system("pause");
	return 0;
}
