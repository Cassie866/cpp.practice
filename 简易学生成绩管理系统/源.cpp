#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;
#define SIZE 1000

class Student
{
private:
	int num;
	char name[20];
	int score[7];
	int average;
	int last;
public:
	Student();
	void Add();
	void Find();
	void Modify();
	void Delete();
	void Show();
	void Save();
	void Load();
	Student& operator = (Student& T);
	friend istream& operator >> (istream& scin, Student& s1);
	friend ostream& operator  << (ostream& scout, Student& s2);
};

Student stu[SIZE];
int size = 0;

Student::Student()
{
	strcpy(name, " ");
	num = 0;
	for (int i = 0; i < 7; i++)
	{
		score[i] = 0;
	}
	average = 0;
	last = 0;
}

Student& Student :: operator = (Student& T)
{
	strcpy(name, T.name);
	num = T.num;
	for (int i = 0; i < 7; i++)
	{
		score[i] = T.score[i];
	}
	average = T.average;
	last = T.last;
	return(*this);
}

ostream& operator  << (ostream& scout, Student& s2)
{
	cout << setw(10) << s2.num << setw(8) << s2.name << setw(8) << s2.score[0]
		<< setw(8) << s2.score[1] << setw(8) << s2.score[2] << setw(8) << s2.score[3]
		<< setw(8) << s2.score[4] << setw(8) << s2.score[5] << setw(10) << s2.score[6]
		<< setw(10) << s2.last << endl;
	return scout;
}

istream& operator >> (istream& scin, Student& s1)
{
	cout << "学号:";
	scin >> s1.num;
	cout << "姓名:";
	scin >> s1.name;
	cout << "语文:";
	scin >> s1.score[0];
	cout << "英语:";
	scin >> s1.score[1];
	cout << "数学:";
	scin >> s1.score[2];
	cout << "物理:";
	scin >> s1.score[3];
	cout << "化学:";
	scin >> s1.score[4];
	cout << "生物:";
	scin >> s1.score[5];
	cout << "平吋成绩:";
	scin >> s1.score[6];
	s1.average = (s1.score[0] + s1.score[1] + s1.score[2] + s1.score[3] + s1.score[4] + s1.score[5]) / 6;
	s1.last = (int)(s1.score[6] * 0.3 + s1.average * 0.7);
	return scin;
}

int Menu()
{
	cout << endl;
	cout << endl;
	cout << "                     【学生成绩管理系统】" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "                      1.录入学生成绩" << endl;
	cout << "                      2.查询学生成绩" << endl;
	cout << "                      3.修改学生成绩" << endl;
	cout << "                      4.删除学生成绩" << endl;
	cout << "                      5.打印全部学生成绩" << endl;
	cout << "                      6.文件存入数据" << endl;
	cout << "                      7.文件读出数据" << endl;
	cout << "                      0.退出系统" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "请输入您要进行的操作的编号：";
	while (1)
	{
		int choice = -1;
		cin >> choice;
		if (choice == 0 || choice == 1 || choice == 2
			|| choice == 3 || choice == 4 || choice == 5
			|| choice == 6 || choice == 7)
		{
			return choice;
		}
		else
		{
			cout << "输入有误，请重新输入： ";
		}
	}
}

void Student::Add()
{
	if (size > SIZE)
	{
		cout << "系统已满，添加失败！" << endl;
	}
	cout << "请输入学生的学号、姓名、各科成绩：" << endl;
	cout << "注意：学号为9位数（入学年份+在读年级+在读班级+班内编号）" << endl;
	cin >> stu[size];
	size++;
	cout << "添加成功！" << endl;
	return;
}

void Student::Find()
{
	char n[20];
	cout << "请输入要査找的学生姓名: ";
	cin >> n;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (strcmp(stu[i].name, n) == 0)
		{
			break;
		}
	}
	if (i < size)
	{

		cout << "--------------------------------------------------------------------------------------------------" << endl;
		cout << "     学号     姓名     语文    英语    数学    物理    化学    生物    平时成绩    总评" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		cout << setw(10) << stu[i].num << setw(8) << stu[i].name << setw(8) << stu[i].score[0]
			<< setw(8) << stu[i].score[1] << setw(8) << stu[i].score[2] << setw(8) << stu[i].score[3]
			<< setw(8) << stu[i].score[4] << setw(8) << stu[i].score[5] << setw(10) << stu[i].score[6]
			<< setw(10) << stu[i].last << endl;
	}
	else
	{
		cout << "没有要査找的学生！" << endl;
	}
	return;
}

void Student::Modify()
{
	char n[20];
	cout << "请输入要修改的学生姓名:";
	cin >> n;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (strcmp(stu[i].name, n) == 0)
		{
			break;
		}
	}
	if (i < size)
	{
		cout << "请输入修改后的学生信息: " << endl;
		cin >> stu[i];
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "没有要修改的学生！" << endl;
	}
	return;
}

void Student::Delete()
{
	char n[20];
	cout << "请输入要刪除的学生姓名：";
	cin >> n;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (strcmp(stu[i].name, n) == 0)
		{
			break;
		}
	}
	if (i < size)
	{
		for (int j = i; j < size; j++)
		{
			stu[j] = stu[j + 1];
			j++;
		}
		size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "没有要删除的学生！" << endl;
	}
	return;
}

void Student::Show()
{
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "     学号     姓名     语文    英语    数学    物理    化学    生物    平时成绩    总评" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << stu[i];
	}
	return;
}

void Student::Save()
{
	char filename[20];
	cout << "请输入文件名：";
	cin >> filename;
	ofstream fout(filename, ios::app);
	if (!fout)
	{
		cout << "文件打不开！" << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			fout << stu[i].num << "  " << stu[i].name << "  " << stu[i].score[0] << "  "
				<< stu[i].score[1] << "  " << stu[i].score[2] << "  " << stu[i].score[3] << "  "
				<< stu[i].score[4] << "  " << stu[i].score[5] << "  " << stu[i].score[6] << "  "
				<< stu[i].average << "  " << stu[i].last << endl;
		}
		cout << "保存成功！" << endl;
	}
	fout.close();
	return;
}

void Student::Load()
{
	char filename[20];
	cout << "请输入要读取的文件名：";
	cin >> filename;
	ifstream fin(filename, ios::in);
	if (!fin)
	{
		cout << "文件打不开！" << endl;
	}
	else
	{
		for (int i = 0;; i++, size = i - 1)
		{
			if (fin.eof())
			{
				break;
			}
			fin >> stu[i].num >> stu[i].name >> stu[i].score[0]
				>> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3]
				>> stu[i].score[4] >> stu[i].score[5] >> stu[i].score[6]
				>> stu[i].average >> stu[i].last;
		}
		cout << "文件读取成功！" << endl;
	}
	fin.close();
}

int main()
{
	Student s;
	while (1)
	{
		int choice = Menu();
		if (choice == 0)
		{
			cout << "系统已退出!" << endl;
			break;
		}
		switch (choice)
		{
		case 1:
			s.Add();
			break;
		case 2:
			s.Find();
			break;
		case 3:
			s.Modify();
			break;
		case 4:
			s.Delete();
			break;
		case 5:
			s.Show();
			break;
		case 6:
			s.Save();
			break;
		case 7:
			s.Load();
			break;
		}
	}
	return 0;
}