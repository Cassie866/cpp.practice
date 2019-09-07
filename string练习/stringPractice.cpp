/*
���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�
ע�⣺
    num1 ��num2 �ĳ��ȶ�С�� 5100.
	num1 ��num2 ��ֻ�������� 0-9.
	num1 ��num2 ���������κ�ǰ���㡣
	�㲻��ʹ���κ΃Ƚ� BigInteger �⣬ Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��
*/
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
	string addStrings(string num1, string num2)
	{
		int len1 = num1.size() - 1;
		int len2 = num2.size() - 1;
		string ret;
		int capacity = (len1 > len2 ? len1 + 1 : len2 + 1);
		ret.reserve(capacity);
		int step = 0;
		while (len1 >= 0 || len2 >= 0)
		{
			int curSum = 0;
			curSum += step;
			if (len1 >= 0)
			{
				curSum += num1[len1] - '0';
			}
			if (len2 >= 0)
			{
				curSum += num2[len2] - '0';
			}
			if (curSum > 9)
			{
				curSum -= 10;
				step = 1;
			}
			else
			{
				step = 0;
			}
			ret += curSum + '0';
			len1--;
			len2--;
		}
		if (step == 1)
		{
			ret += '1';
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

/*
��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������
��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ���
*/

#include <vector>
class Solution
{
public:
	void reverseString(vector<char>& s)
	{
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			swap(s[begin], s[end]);
			++begin;
			--end;
		}
	}
};

/*
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
*/

class Solution
{
public:
	int firstUniqChar(string s)
	{
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i < size; ++i)
		{
			count[s[i]] += 1;
		}
		for (int i = 0; i < size; ++i)
		{
			if (count[s[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};

/*
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:
����: "A man, a plan, a canal: Panama"
���: true

ʾ�� 2:
����: "race a car"
���: false
*/

class Solution
{
public:
	bool isNumberLetter(char c)
	{
		return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}
	bool isPalindrome(string s)
	{
		int begin = 0;
		int end = s.size() - 1;
		for (auto& e : s)
		{
			if (e >= 'a')
			{
				e -= 32;
			}
		}
		while (begin < end)
		{
			while (begin < end)
			{
				if (isNumberLetter(s[begin]))
					break;
				begin++;
			}
			while (begin < end)
			{
				if (isNumberLetter(s[end]))
					break;
				end--;
			}
			if (s[begin] != s[end])
			{
				return false;
			}
			begin++;
			end--;
		}
		return true;
	}
};

