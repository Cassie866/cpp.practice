#include<iostream>
using namespace std;

int main()
{
	int C, i, j;
	double x;
	double y = 0.0;
	double t = 1.0;
	cout << "请输入已知点对个数：" ;
	cin >> C;
	double(*p)[2] = new double[C][2];
	cout << "输入各个点对的值" << endl;
	for (i = 0; i < C; i++)
	{
		for ( j= 0; j < 2; j++)
		{
			cin >> p[i][j];
		}
	}
	cout << "输入你要估算的x的值：";
	cin >> x;
	for (j = 0; j < C; j++)
	{
		for (i = 0; i < C; i++)
		{
			if (i == j)
			{
				continue;
			}
			t = (x - p[i][0]) / (p[j][0] - p[i][0]) * t;
		}
		y = y + t * p[j][1];
		t = 1;
	}
	cout << "当x=" << x << " 时，估计的结果为：" << y << endl;
	delete[] p;
	return 0;
}
