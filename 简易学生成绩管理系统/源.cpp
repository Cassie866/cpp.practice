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
	cout << "ѧ��:";
	scin >> s1.num;
	cout << "����:";
	scin >> s1.name;
	cout << "����:";
	scin >> s1.score[0];
	cout << "Ӣ��:";
	scin >> s1.score[1];
	cout << "��ѧ:";
	scin >> s1.score[2];
	cout << "����:";
	scin >> s1.score[3];
	cout << "��ѧ:";
	scin >> s1.score[4];
	cout << "����:";
	scin >> s1.score[5];
	cout << "ƽ���ɼ�:";
	scin >> s1.score[6];
	s1.average = (s1.score[0] + s1.score[1] + s1.score[2] + s1.score[3] + s1.score[4] + s1.score[5]) / 6;
	s1.last = (int)(s1.score[6] * 0.3 + s1.average * 0.7);
	return scin;
}

int Menu()
{
	cout << endl;
	cout << endl;
	cout << "                     ��ѧ���ɼ�����ϵͳ��" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "                      1.¼��ѧ���ɼ�" << endl;
	cout << "                      2.��ѯѧ���ɼ�" << endl;
	cout << "                      3.�޸�ѧ���ɼ�" << endl;
	cout << "                      4.ɾ��ѧ���ɼ�" << endl;
	cout << "                      5.��ӡȫ��ѧ���ɼ�" << endl;
	cout << "                      6.�ļ���������" << endl;
	cout << "                      7.�ļ���������" << endl;
	cout << "                      0.�˳�ϵͳ" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "��������Ҫ���еĲ����ı�ţ�";
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
			cout << "�����������������룺 ";
		}
	}
}

void Student::Add()
{
	if (size > SIZE)
	{
		cout << "ϵͳ���������ʧ�ܣ�" << endl;
	}
	cout << "������ѧ����ѧ�š����������Ƴɼ���" << endl;
	cout << "ע�⣺ѧ��Ϊ9λ������ѧ���+�ڶ��꼶+�ڶ��༶+���ڱ�ţ�" << endl;
	cin >> stu[size];
	size++;
	cout << "��ӳɹ���" << endl;
	return;
}

void Student::Find()
{
	char n[20];
	cout << "������Ҫ���ҵ�ѧ������: ";
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
		cout << "     ѧ��     ����     ����    Ӣ��    ��ѧ    ����    ��ѧ    ����    ƽʱ�ɼ�    ����" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		cout << setw(10) << stu[i].num << setw(8) << stu[i].name << setw(8) << stu[i].score[0]
			<< setw(8) << stu[i].score[1] << setw(8) << stu[i].score[2] << setw(8) << stu[i].score[3]
			<< setw(8) << stu[i].score[4] << setw(8) << stu[i].score[5] << setw(10) << stu[i].score[6]
			<< setw(10) << stu[i].last << endl;
	}
	else
	{
		cout << "û��Ҫ���ҵ�ѧ����" << endl;
	}
	return;
}

void Student::Modify()
{
	char n[20];
	cout << "������Ҫ�޸ĵ�ѧ������:";
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
		cout << "�������޸ĺ��ѧ����Ϣ: " << endl;
		cin >> stu[i];
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "û��Ҫ�޸ĵ�ѧ����" << endl;
	}
	return;
}

void Student::Delete()
{
	char n[20];
	cout << "������Ҫ�h����ѧ��������";
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
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "û��Ҫɾ����ѧ����" << endl;
	}
	return;
}

void Student::Show()
{
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "     ѧ��     ����     ����    Ӣ��    ��ѧ    ����    ��ѧ    ����    ƽʱ�ɼ�    ����" << endl;
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
	cout << "�������ļ�����";
	cin >> filename;
	ofstream fout(filename, ios::app);
	if (!fout)
	{
		cout << "�ļ��򲻿���" << endl;
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
		cout << "����ɹ���" << endl;
	}
	fout.close();
	return;
}

void Student::Load()
{
	char filename[20];
	cout << "������Ҫ��ȡ���ļ�����";
	cin >> filename;
	ifstream fin(filename, ios::in);
	if (!fin)
	{
		cout << "�ļ��򲻿���" << endl;
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
		cout << "�ļ���ȡ�ɹ���" << endl;
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
			cout << "ϵͳ���˳�!" << endl;
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