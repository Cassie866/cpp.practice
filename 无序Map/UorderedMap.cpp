#include "hash.h"
#include <iostream>
#include <string>
using namespace std;

template <class K>
struct HashFun
{
	K& operator()(const K& key)
	{
		return key;
	}
};

//模板特化
template <>
struct HashFun <string>
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto& e : str)
		{
			hash = hash * 131 + e;
		}
		return hash;
	}
};

//哈希函数
struct hashString
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (auto& e : str)
		{
			hash = hash * 131 + e;
		}
		return hash;
	}
};

template <class K,class V,class HFun=HashFun<K>>
class UorderedMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
public:
	typedef typename HashTable<K, pair<K, V>, MapKeyOfValue, HFun>::iterator iterator;

	iterator begin()
	{
		return _hs.begin();
	}

	iterator end()
	{
		return _hs.end();
	} 

	pair<iterator, bool>Insert(const pair<K, V>& data)
	{
		return _hs.Insert(data);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool>ret = _hs.Insert(make_pair(key, V()));
		return ret.first->second;
	}

private:
	HashTable<K, pair<K, V>, MapKeyOfValue, HFun> _hs;
};

template <class K,class HFun>
class UorderedSet
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& data)
		{
			return data;
		}
	};
public:
	typedef typename HashTable<K, K, SetKeyOfValue, HFun>::iterator iterator;

	iterator begin()
	{
		return _hs.begin();
	}

	iterator end()
	{
		return _hs.end();
	}

	pair<K, K>Insert(const K& data)
	{
		return _hs.Insert(data);
	}

private:
	HashTable<K, pair<K, K>, SetKeyOfValue, HFun> _hs;
};

int main()
{
	UorderedMap<int, int,HashFun<int>>umap;
	umap.Insert(make_pair(1, 1));
	umap.Insert(make_pair(5, 5));
	umap.Insert(make_pair(6, 6));
	umap.Insert(make_pair(9, 9));
	umap[9] = 100;
	umap[200] = 200;

	UorderedSet <int,HashFun<int>>uset;
	uset.Insert(1);
	uset.Insert(5);
	uset.Insert(6);
	uset.Insert(9);
	return 0;
}