#pragma once
#include <iostream>
#include <time.h>
using namespace std;

//红黑树
enum Color { RED, BLACK };

template <class v>
struct RBTNode
{
	RBTNode(const  v& data =  v())
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _color(RED)
	{}
	RBTNode<v>* _left; // 节点的左孩子
	RBTNode<v>* _right; // 节点的右孩子
	RBTNode<v>* _parent; // 节点的父亲
	v _data; // 节点的值
	Color _color; // 节点的颜色
};


template <class v>
class _RBTreeIterator
{
public:
	typedef RBTNode<v>  Node;
	typedef Node*  pNode;
	typedef _RBTreeIterator<v>  self;
	_RBTreeIterator(pNode node)
		:_node(node)
	{}
	v& operator *()
	{
		return _node->_data;
	}
	v* operator ->()
	{
		return &_node->_data;
	}
	bool operator!=(const self& it)
	{
		return _node != it._node;
	}
	bool operator==(const self& it)
	{
		return _node == it._node;
	}
	self& operator++()
	{
		pNode parent = _node->parent;
		if (_node->_right)
		{
			_node = _node->_right;
			while (_node->_left)
			{
				_node = _node->_left;
			}
		}
		else
		{
			while (_node == parent->_right)
			{
				_node = parent;
				parent = parent->parent;
			}
			if (_node->_right != parent)
				_node = parent;
		}
		return *this;
	}
	self& operator--()
	{
		pNode parent = _node->parent;
		if (_node->_left)
		{
			_node = _node->_left;
			while (_node->_right)
			{
				_node = _node->_right;
			}
		}
		else
		{
			while (_node != parent->_right)
			{
				_node = parent;
				parent = parent->parent;
			}
			if (_node->_left != parent)
				_node = parent;
		}
		return *this;
	}
private:
	pNode _node;
};

template <class k,class v,class kov>
class RBTree
{
public:
	typedef  RBTNode<v>  Node;
	typedef  Node* pNode;
	typedef _RBTreeIterator<v> iterator;

	iterator begin()
	{
		return iterator(_header->_left);
	}
	iterator end()
	{
		return iterator(_header);
	}

	RBTree(const v& data = v())
	{
		_header = new Node(data);
		_header->_left = _header;
		_header->_right = _header;
		_header->_parent = nullptr;
	}

	pair<iterator,bool> Insert(const v& data);
	pNode LeftMost();
	pNode RightMost();
	void RotateLeft(pNode parent);
	void RotateRight(pNode parent);
	void Inorder();
	void _Inorder(pNode root);
	bool isRBTree();
	bool _isRBTree(pNode root, int count, int curcount);
private:
	pNode _header;
};


template<class k, class v, class kov>
inline pair<typename RBTree<k, v, kov>::iterator, bool> RBTree<k, v, kov>::Insert(const v& data)
{
	if (_header->_parent == nullptr)
	{
		pNode root = new Node(data);
		root->_color = BLACK;
		root->_parent = _header;
		_header->_parent = root;
		_header->_left = root;
		_header->_right = root;
		return make_pair(iterator(root), true);
	}
	pNode cur = _header->_parent;
	pNode parent = nullptr;
	kov kov1;
	while (cur)
	{
		parent = cur;
		if (kov1(data) > kov1(cur->_data))
			cur = cur->_right;
		else if (kov1(data) < kov1(cur->_data))
			cur = cur->_left;
		else
			return make_pair(iterator(cur), false);
	}
	cur = new Node(data);
	pNode newNode = cur;
	if (kov1(data) > kov1(parent->_data))
		parent->_right = cur;
	else
		parent->_left = cur;
	cur->_parent = parent;
	while (cur != _header->_parent && cur->_parent->_color == RED)
	{
		pNode parent = cur->_parent;
		pNode gparent = parent->_parent;
		if (parent == gparent->_left)
		{
			pNode unclue = gparent->_right;
			if (unclue && unclue->_color == RED)
			{
				parent->_color = unclue->_color = BLACK;
				gparent->_color = RED;
				cur = gparent;
			}
			else
			{
				if (parent->_right == cur)
				{
					RotateLeft(parent);
					swap(parent, cur);
				}
				RotateRight(gparent);
				gparent->_color = RED;
				parent->_color = BLACK;
				break;
			}
		}
		else
		{
			pNode unclue = gparent->_left;
			if (unclue && unclue->_color == RED)
			{
				parent->_color = unclue->_color = BLACK;
				gparent->_color = RED;
				cur = gparent;
			}
			else
			{
				if (parent->_left == cur)
				{
					RotateRight(parent);
					swap(parent, cur);
				}
				RotateLeft(gparent);
				gparent->_color = RED;
				parent->_color = BLACK;
				break;
			}
		}
	}
	_header->_parent->_color = BLACK;
	_header->_left = LeftMost();
	_header->_right = RightMost();
	return make_pair(iterator(newNode), true);
}



template<class k, class v, class kov>
typename RBTree<k,v,kov>::pNode RBTree<k, v, kov>::LeftMost()
{
	pNode cur = _header->_parent;
	while (cur && cur->_left)
	{
		cur = cur->_left;
	}
	return cur;
}

template<class k, class v, class kov>
typename RBTree<k, v, kov>::pNode RBTree<k, v, kov>::RightMost()
{
	pNode cur = _header->_parent;
	while (cur && cur->_right)
	{
		cur = cur->_right;
	}
	return cur;
}

template<class k, class v, class kov>
void RBTree<k, v, kov>::RotateLeft(pNode parent)
{
	pNode subR = parent->_right;
	pNode subRL = subR->_left;
	subR->_left = parent;
	parent->_right = subRL;
	if (subRL)
		subRL->_parent = parent;
	if (parent != _header->_parent)
	{
		if (parent->_parent->_left == parent)
			parent->_parent->_left = subR;
		else
			parent->_parent->_right = subR;
		subR->_parent = parent->_parent;
	}
	else
	{
		_header->_parent = subR;
		subR->_parent = _header;
	}
	parent->_parent = subR;
}

template<class k, class v, class kov>
void RBTree<k, v, kov>::RotateRight(pNode parent)
{
	pNode subL = parent->_left;
	pNode subLR = subL->_right;
	subL->_right = parent;
	parent->_left = subLR;
	if (subLR)
		subLR->_parent = parent;
	if (parent != _header->_parent)
	{
		if (parent->_parent->_left == parent)
		{
			parent->_parent->_left = subL;
		}
		else
		{
			parent->_parent->_right = subL;
		}
		subL->_parent = parent->_parent;
	}
	else
	{
		_header->_parent = subL;
		subL->_parent = _header;
	}
	parent->_parent = subL;
}

template<class k, class v, class kov>
void RBTree<k, v, kov>::Inorder()
{
	_Inorder(_header->_parent);
	cout << endl;
}

template<class k, class v, class kov>
void RBTree<k, v, kov>::_Inorder(pNode root)
{
	if (root)
	{
		_Inorder(root->_left);
		cout << root->_data.first << " ";
		_Inorder(root->_right);
	}
}

template<class k, class v, class kov>
bool RBTree<k, v, kov>::isRBTree()
{
	if (_header->_parent == nullptr)
		return true;
	if (_header->_parent->_color == RED)
		return false;
	int count = 0;
	pNode cur = _header->_parent;
	while (cur)
	{
		if (cur->_color == BLACK)
			++count;
		cur = cur->_left;
	}
	return _isRBTree(_header->_parent, count, 0);
}

template<class k, class v, class kov>
bool RBTree<k, v, kov>::_isRBTree(pNode root, int count, int curcount)
{
	if (root == nullptr)
	{
		if (curcount != count)
			return false;
		return true;
	}
	if (root->_color == BLACK)
		++curcount;
	if (root->_parent->_color == RED && root->_color == RED)
		return false;
	return _isRBTree(root->_left, count, curcount)
		&& _isRBTree(root->_right, count, curcount);
}

