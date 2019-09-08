#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 10   //�����ͼ����
#define COL 10   //�����ͼ������
#define MINE 20  //�����׵ĸ���

char mine_map[ROW + 2][COL + 2];   //��ʾʵ�ʵĵ�ͼ�������ף�
char show_map[ROW + 2][COL + 2];   //��ʾ�û������ĵ�ͼ

//�˵�ҳ�棬���û�ѡ���Ƿ�ʼ��Ϸ
int Menu()
{
	int choice = 0;
	printf("             1.��ʼ��Ϸ\n");
	printf("             0.�˳���Ϸ\n");
	printf("���������ѡ��\n");
	scanf("%d", &choice);
	return choice;
}

//������ͼ�ĳ�ʼ��
void InIt(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2])
{
	memset(mine_map, '0', (ROW + 2) * (COL + 2));  //���׵ĵ�ͼ
	memset(show_map, '*', (ROW + 2) * (COL + 2));  //�û������ĵ�ͼ
	srand(time(0));  //�õ�ǰ��ϵͳʱ����Ϊ�������
	int mine_count = MINE;
	while (mine_count > 0)
	{
		int row = rand() % 10 + 1;   //���������ͼ��ĳ��
		int col = rand() % 10 + 1;   //���������ͼ��ĳ��
		if (mine_map[row][col] == '0')
		{
			mine_map[row][col] = '1';  //�����������λ�ô�����
			mine_count--;
		}
	}
}

//��ӡ��ͼ
void DisPlay(char map[ROW + 2][COL + 2])
{
	printf("     ");
	for (int col = 1; col <= COL; col++)
	{
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 1; col <= COL; col++)
	{
		printf("---");
	}
	printf("\n");
	for (int row = 1; row <= ROW; row++)
	{
		printf("%02d | ", row);
		for (int col = 1; col <= COL; col++)
		{
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

//���µ�ͼ��������������λ������Ϊ��Χ�׵ĸ���

void UpdateMap(char show_map[ROW + 2][COL + 2], char mine_map[ROW + 2][COL + 2], int row, int col)
{
	int mine_count = 0;
	mine_count = (mine_map[row - 1][col - 1] - '0') + (mine_map[row - 1][col] - '0')
		+ (mine_map[row - 1][col + 1] - '0') + (mine_map[row][col - 1] - '0')
		+ (mine_map[row][col + 1] - '0') + (mine_map[row + 1][col - 1] - '0')
		+ (mine_map[row + 1][col] - '0') + (mine_map[row + 1][col + 1] - '0');
	show_map[row][col] = '0' + mine_count;
}

//��Ϸ����
void Game()
{
	int not_mine = 0;
	InIt(mine_map, show_map);
	DisPlay(show_map);
	while (1)
	{
		int row = 0, col = 0;
		printf("������Ҫ���������꣺\n");  //��ʾ�û�������ͼ
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > ROW || col <= 0 || col > COL)  //���û������������м��
		{
			printf("����������겻�Ϸ������������룡");  //���곬����ͼ�ķ�Χ����������
			continue;
		}
		if (mine_map[row][col] == '1')  //�������ף���Ϸ����
		{
			printf("��Ϸ������\n");
			DisPlay(mine_map);
			break;
		}
		not_mine++;
		if (not_mine == ROW * COL - MINE)  //����ȫ���޵��׵����꣬ɨ�׳ɹ�����Ϸ����
		{
			printf("ɨ�׳ɹ���\n");
			DisPlay(mine_map);
			break;
		}
		UpdateMap(show_map, mine_map, row, col); //��ӡ��ͼ
		DisPlay(show_map);
	}
}

//��Ϸ��ʼ����
void Start()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 0)
		{
			printf("��Ϸ������\n");
			break;
		}
		if (choice == 1)
		{
			Game();
		}
	}
}

int main()
{
	Start();
	return 0;
}
