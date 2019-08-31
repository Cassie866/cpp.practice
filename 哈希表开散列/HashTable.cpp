#include <iostream>
#include <vector>
using namespace std;

//开散列
template<class V>
struct HashNode
{
	HashNode(const V& data = V())
		:_data(data)
		, _next(nullptr)
	{}
	V _data;
	HashNode<V>* _next;
};

template <class K, class V, class KeyOfValue, class HFun>
class HashTable;

//迭代器
template <class K, class V, class KeyOfValue, class HFun>
class HashIterator
{
	typedef HashNode<V> Node;
	typedef Node* pNode;
	typedef HashIterator<K, V, KeyOfValue, HFun> Self;
	typedef HashTable<K, V, KeyOfValue, HFun> HTable;

	template <class K, class V, class KeyOfValue, class HFun>
	friend class HashTable;

	HashIterator(pNode node, HTable* p)
		:_node(node)
		, _phs(p)
	{}

	V& operator*()
	{
		return _node->_data;
	}

	V* operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		if (_node->_next)
			_node = _node->_next;
		else
		{
			KeyOfValue kov;
			size_t id = kov(_node->_data) % _phs->_hs.size();
			++id;
			while (id < _phs->_hs.size())
			{
				if (_phs->_hs[id])
				{
					_node = _phs->_hs[id];
					break;
				}
				++id;
			}
			if (id == _phs->_hs.size())
				_node = nullptr;
		}
		return *this;
	}

private:
	pNode _node;
	HTable* _phs;
};

template <class K, class V, class KeyOfValue, class HFun>
class HashTable
{
public:
	typedef HashNode<V>Node;
	typedef Node* pNode;
	typedef HashIterator<K, V, KeyOfValue, HFun>iterator;

	HashTable(size_t N = 10)
	{
		_hs.resize(N);
		_size = 0;
	}

	iterator begin()
	{
		for (size_t i = 0; i < _hs.size(); i++)
		{
			if (_hs[i])
				return iterator(_hs[i], this);
		}
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	size_t HashId(const K& key, size_t sz)
	{
		HFun hf;
		return hf(key) % sz;
	}

	pair<iterator, bool>Insert(const V& data);
	size_t GetPrime(size_t sz);
	void CheckCapacity();
	pNode find(const K& key);
	bool Erase(const K& key);

private:
	vector<pNode> _hs;//指针数组
	size_t _size;
};

template<class K, class V, class KeyOfValue, class HFun>
pair<typename HashTable<K, V, KeyOfValue, HFun>::iterator, bool>  HashTable<K, V, KeyOfValue, HFun>::Insert(const V& data)
{
	CheckCapacity();
	KeyOfValue kov;
	int id = HashId(kov(data), _hs.size());
	pNode cur = _hs[id];
	while (cur)
	{
		if (kov(cur->_data) == kov(data))
			return make_pair(iterator(cur, this), false);
		cur = cur->_next;
	}
	cur = new Node(data);
	cur->_next = _hs[id];
	_hs[id] = cur;
	++_size;
	return make_pair(iterator(cur, this), true);
}

template<class K, class V, class KeyOfValue, class HFun>
size_t HashTable<K, V, KeyOfValue, HFun>::GetPrime(size_t sz)
{
	const int PRIMECOUNT = 28;
	const static size_t primeList[PRIMECOUNT] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	for (int i = 0; i < PRIMECOUNT; i++)
	{
		if (primeList[i] > sz)
			return primeList[i];
	}
	return primeList[PRIMECOUNT - 1];
}

template<class K, class V, class KeyOfValue, class HFun>
void HashTable<K, V, KeyOfValue, HFun>::CheckCapacity()
{
	if (_size == _hs.size())
	{
		size_t newcapacity = GetPrime(_hs.size());
		vector<pNode>newhs;
		newhs.resize(newcapacity);
		KeyOfValue kov;
		for (int i = 0; i < _hs.size(); i++)
		{
			pNode cur = _hs[i];
			while (cur)
			{
				pNode next = cur->_next;
				int id = HashId(kov(cur->_data), newhs.size());
				cur->_next = newhs[id];
				newhs[id] = cur;
				cur = next;
			}
			_hs[i] = nullptr;
		}
		swap(_hs, newhs);
	}
}

template<class K, class V, class KeyOfValue, class HFun>
typename HashTable<K, V, KeyOfValue, HFun>::pNode HashTable<K, V, KeyOfValue, HFun>::find(const K& key)
{
	int id = key % _hs.size();
	pNode cur = _hs[id];
	KeyOfValue kov;
	while (cur)
	{
		if (kov(cur->_data) == key)
			return cur;
		cur = cur->_next;
	}
	return nullptr;
}

template<class K, class V, class KeyOfValue, class HFun>
bool HashTable<K, V, KeyOfValue, HFun>::Erase(const K& key)
{
	int id = HashId(key, _hs.size());
	pNode cur = _hs[id];
	pNode prev = nullptr;
	KeyOfValue kov;
	while (cur)
	{
		if (kov(cur->_data) == key)
		{
			if (prev == nullptr)
				_hs[id] = cur->_next;
			else
				prev->_next = cur->_next;
			delete cur;
			--size;
			return true;
		}
		prev = cur;
		cur = cur->_next;
	}
	return false;
}


int main()
{
	return 0;
}