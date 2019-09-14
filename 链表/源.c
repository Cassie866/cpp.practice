#include <stdio.h>
#include <assert.h>
#include <malloc.h>




//��ͷ�����ѭ������
typedef struct SListNode
{
	int data;
	struct SListNode* next;
}SListNode;

typedef struct SList
{
	SListNode* head;
}SList;

//��ʼ��
void Init(SList* p)
{
	assert(p);
	p->head = NULL;
}

//����
void Destory(SList* p)
{
	SListNode* p1;
	SListNode* cur;
	for (cur = p->head; cur != NULL; cur = p1)
	{
		p1 = cur->next;
		free(cur);
	}
	p->head = NULL;
}

//�����½��
SListNode* Buy(int x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	node->data = x;
	node->next = NULL;
	return node;
}

//ͷ��
void PushFront(SList* p, int x)
{
	assert(p);
	SListNode* node = Buy(x);
	node->next = p->head;
	p->head = node;
}

//ͷɾ
void PopFront(SList* p)
{
	assert(p);
	assert(p->head);
	SListNode* old_head = p->head;
	p->head = p->head->next;
	free(old_head);
}

//β��
void PushBack(SList* p, int x)
{
	assert(p);
	if (p->head == NULL)
	{
		PushFront(p, x);
		return;
	}
	SListNode* last = p->head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	SListNode* node = Buy(x);
	last->next = node;
}

//βɾ
void PopBack(SList* p)
{
	assert(p);
	assert(p->head);
	if (p->head->next == NULL)
	{
		PopFront(p);
		return;
	}
	SListNode* cur = p->head;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

//����
SListNode* Find(SList* p, int x)
{
	SListNode* cur = p->head;
	for (; cur != NULL; cur = cur->next)
	{
		if (cur->data = x)
		{
			return cur;
		}
	}
	return NULL;
}

//��pos�������
void InsertAfter(SListNode* pos, int x)
{
	SListNode* node = Buy(x);
	node->next = pos->next;
	pos->next = node;
}

//��pos����ɾ��
void EraseAfter(SListNode* pos)
{
	SListNode* next = pos->next->next;
	free(pos->next);
	pos->next = next;
}

//��ӡ
void Print(SList* p)
{
	SListNode* cur = p->head;
	for (; cur != NULL; cur = cur->next)
	{
		printf("%d-->", cur->data);
	}
	printf("NULL\n");
}


int main()
{
	return 0;
}