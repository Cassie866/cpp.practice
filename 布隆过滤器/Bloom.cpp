#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Î»Í¼
class BitSet
{
public:
	BitSet(size_t range)
	{
		_bs.resize((range >> 5) + 1, 0);
	}
	//´æ´¢
	void Set(int number)
	{
		int id = number >> 5;
		int bitid = number % 32;
		_bs[id] |= (1 << bitid);
	}
	//ËÑË÷
	int Find(int number)
	{
		int id = number >> 5;
		int bitid = number % 32;
		return (_bs[id] >> bitid )& 1;
	}
	//É¾³ý
	void ReSet(int number)
	{
		int id = number >> 5;
		int bitid = number % 32;
		_bs[id] &= (~(1 << bitid));
	}
private:
	vector<int> _bs;
};

struct Hfun1
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto& ch : str)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

struct Hfun2
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto& ch : str)
		{
			hash = hash * 65599 + ch;
		}
		return hash;
	}
};


struct Hfun3
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		size_t magic = 63689;
		for (auto& ch : str)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
};


template<class T,class Hfun1,class Hfun2,class Hfun3>
class BloomFilter
{
public:
	BloomFilter(size_t number)
	:_bs(5*number)
		,_bitcount(5*number)
	{}

	void Set(const T& data)
	{
		int id1 = Hfun1()(data) % _bitcount;
		int id2 = Hfun2()(data) % _bitcount;
		int id3 = Hfun3()(data) % _bitcount;

		_bs.Set(id1);
		_bs.Set(id2);
		_bs.Set(id3);
	}

	bool Find(const T& data)
	{
		int id1 = Hfun1()(data) % _bitcount;
		if (!_bs.Find(id1))
			return false;
		int id2 = Hfun2()(data) % _bitcount;
		if (!_bs.Find(id2))
			return false;
		int id3 = Hfun3()(data) % _bitcount;
		if (!_bs.Find(id3))
			return false;
		return true;
	}

private:
	BitSet _bs;
	size_t _bitcount;
};

void test()
{
	BitSet bs(64);
	bs.Set(1);
	bs.Set(10);
	bs.Set(32);
	bs.Set(64);
	bs.ReSet(10);
	int ret = bs.Find(1);
	ret = bs.Find(10);
	ret = bs.Find(32);
	ret = bs.Find(64);
	ret = bs.Find(35);
}

void test2()
{
	BloomFilter<string, Hfun1, Hfun2, Hfun3>  bf(1000);
	string str1 = "https://blog.csdn.net/qq_43239560/article/details/100079816";
	string str4 = "https://blog.csdn.net/qq_43239560/article/details/100056387";
	string str2 = "https://blog.csdn.net/qq_43239560/article/details/97282274";
	string str5 = "https://blog.csdn.net/qq_43239560/article/details/99695164";
	string str3 = "https://blog.csdn.net/qq_43239560/article/details/96877659";
	string str6 = "https://blog.csdn.net/qq_43239560/article/details/96572382";
	bf.Set(str1);
	bf.Set(str2);
	bf.Set(str3);

	bool ret = bf.Find(str1);
	ret = bf.Find(str2);
	ret = bf.Find(str3);
	ret = bf.Find(str4);
	ret = bf.Find(str5);
	ret = bf.Find(str6);
}

int main()
{
	return 0;
}