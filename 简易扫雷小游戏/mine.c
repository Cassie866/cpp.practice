#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 10   //定义地图行数
#define COL 10   //定义地图的列数
#define MINE 20  //定义雷的个数

char mine_map[ROW + 2][COL + 2];   //表示实际的地图（含地雷）
char show_map[ROW + 2][COL + 2];   //表示用户看到的地图

//菜单页面，供用户选择是否开始游戏
int Menu()
{
	int choice = 0;
	printf("             1.开始游戏\n");
	printf("             0.退出游戏\n");
	printf("请输入你的选择：\n");
	scanf("%d", &choice);
	return choice;
}

//两个地图的初始化
void InIt(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2])
{
	memset(mine_map, '0', (ROW + 2) * (COL + 2));  //无雷的地图
	memset(show_map, '*', (ROW + 2) * (COL + 2));  //用户看到的地图
	srand(time(0));  //用当前的系统时间作为随机种子
	int mine_count = MINE;
	while (mine_count > 0)
	{
		int row = rand() % 10 + 1;   //随机产生地图的某行
		int col = rand() % 10 + 1;   //随机产生地图的某列
		if (mine_map[row][col] == '0')
		{
			mine_map[row][col] = '1';  //在随机产生的位置处布雷
			mine_count--;
		}
	}
}

//打印地图
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

//更新地图，将翻开的无雷位置设置为周围雷的个数

void UpdateMap(char show_map[ROW + 2][COL + 2], char mine_map[ROW + 2][COL + 2], int row, int col)
{
	int mine_count = 0;
	mine_count = (mine_map[row - 1][col - 1] - '0') + (mine_map[row - 1][col] - '0')
		+ (mine_map[row - 1][col + 1] - '0') + (mine_map[row][col - 1] - '0')
		+ (mine_map[row][col + 1] - '0') + (mine_map[row + 1][col - 1] - '0')
		+ (mine_map[row + 1][col] - '0') + (mine_map[row + 1][col + 1] - '0');
	show_map[row][col] = '0' + mine_count;
}

//游戏函数
void Game()
{
	int not_mine = 0;
	InIt(mine_map, show_map);
	DisPlay(show_map);
	while (1)
	{
		int row = 0, col = 0;
		printf("请输入要翻开的坐标：\n");  //提示用户翻开地图
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > ROW || col <= 0 || col > COL)  //对用户输入的坐标进行检测
		{
			printf("您输入的坐标不合法，请重新输入！");  //坐标超出地图的范围，重新输入
			continue;
		}
		if (mine_map[row][col] == '1')  //翻到地雷，游戏结束
		{
			printf("游戏结束！\n");
			DisPlay(mine_map);
			break;
		}
		not_mine++;
		if (not_mine == ROW * COL - MINE)  //翻开全部无地雷的坐标，扫雷成功，游戏结束
		{
			printf("扫雷成功！\n");
			DisPlay(mine_map);
			break;
		}
		UpdateMap(show_map, mine_map, row, col); //打印地图
		DisPlay(show_map);
	}
}

//游戏开始函数
void Start()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 0)
		{
			printf("游戏结束！\n");
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
