#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1); //���캯��
	Date(const Date& d); //�������캯��
	int GetDay(int month, int year); //��ȡĳ��ĳ�·ݵ�����
	Date& operator = (const Date& d);//��ֵ��������غ���
	Date& operator += (int days);
	Date& operator -= (int days);
	Date operator + (int days);
	Date operator - (int days);
	int operator - (const Date& d);//����������������
	Date& operator ++ ();//ǰ��++       
	Date operator ++ (int);//����++      
	Date& operator -- ();//ǰ��--
	Date operator -- (int);//����--
	bool operator > (const Date& d)const; //�ж��������ڵĴ�С
	bool operator >= (const Date& d)const;
	bool operator < (const Date& d)const;
	bool operator <= (const Date& d)const;
	bool operator == (const Date& d)const;
	bool operator != (const Date& d)const;
	void DisPlay();
private:
	int _year;
	int _month;
	int _day;
};

int Date::GetDay(int month, int year)
{
	static int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = days[month - 1];
	//���������Ķ��£���һ��
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			++day;
		}
	}
	return day;
}

Date::Date(int year, int month, int day)
{
	if (year < 0 || month < 0 || month > 12 || day < 1 || day > GetDay(month, year))
	{
		cout << "���벻�Ϸ���������ΪĬ��ֵ: 2000-1-1" << endl;
		_year = 2000;
		_month = 1;
		_day = 1;
	}
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator = (const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

Date& Date:: operator += (int days)
{
	if (days < 0)
	{
		return *this -= -days;
	}
	_day += days;
	while (_day > GetDay(_month, _year))
	{
		_day -= GetDay(_month, _year);
		++_month;
		if (_month == 13)
		{
			_month = 1;
			++_year;
		}
	}
	return *this;
}

Date& Date::operator -= (int days)
{
	if (days < 0)
	{
		return *this += -days;
	}
	_day -= days;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetDay(_month, _year);
	}
	return *this;
}

Date Date::operator + (int days)
{
	Date d(*this);
	d += days;
	return d;
}


Date Date::operator - (int days)
{
	Date d(*this);
	d -= days;
	return d;
}

int Date::operator - (const Date& d)
{
	int count = 0;
	Date D(*this);
	if (D < d)
	{
		while (D < d)
		{
			++D;
			count++;
		}
		return count;
	}
	else
	{
		while (D > d)
		{
			D--;
			count++;
		}
		return -count;
	}
}

//ǰ��++
Date& Date::operator ++ ()
{
	return *this += 1;
}

//����++
Date Date:: operator ++ (int)
{
	Date  d(*this);
	++* this;
	return d;
}

//ǰ��--
Date& Date::operator -- ()
{
	return *this -= 1;
}

//����--
Date Date::operator -- (int)
{
	Date  d(*this);
	--* this;
	return d;
}

bool Date::operator > (const Date& d)const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator >= (const Date& d)const
{
	return (*this > d) || (*this == d);
}

bool Date::operator < (const Date& d)const
{
	return !(*this >= d);
}

bool Date::operator <= (const Date& d)const
{
	return !(*this > d);
}

bool Date::operator == (const Date& d)const
{
	return (_year == d._year && _month == d._month && _day == d._day);
}

bool Date::operator != (const Date& d)const
{
	return !(*this == d);
}

void Date::DisPlay()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}


void test()
{
	Date d1(2018, 5, 5);
	Date d2(2019, 3, 14);
	Date d3(d1);
	d3.DisPlay();

	d1 += 60;
	cout << "d1(2018, 5, 5) += 60: " << endl;
	d1.DisPlay();

	d2 -= 364;
	cout << "d2(2019, 3, 14) -= 364:" << endl;
	d2.DisPlay();

	cout << "(d1(2018, 5, 5) += 60)  -  (d2(2019, 3, 14) -= 364)" << endl;
	cout << (d1 - d2) << endl;

	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 <= d2) << endl;

	d2 = d1;
	d2.DisPlay();
}

int main()
{
	test();
	return 0;
}