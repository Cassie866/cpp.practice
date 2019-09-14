#include  <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef struct SeqList
{
	int* array;  //ָ��̬���ٵ�����
	int size;      //��Ч���ݸ���
	int capacity;  //�����ռ��С
}SeqList;

//��ʼ��
void Init(SeqList* p, int capacity)
{
	assert(p);
	p->size = 0;
	p->capacity = capacity;
	p->array = (int*)malloc(capacity * sizeof(int));
	assert(p->array);
}

//�ݻ�
void Destory(SeqList* p)
{
	assert(p);
	free(p->array);
	p->array = NULL;
	p->capacity = p->size = 0;
}

//����
void CheckCapacity(SeqList* p)
{
	if (p->size < p->capacity)
	{
		return;
	}
	int newCapacity = p->capacity * 2;
	int* newArray = (int*)malloc(sizeof(int) * newCapacity);
	assert(newArray);
	for (int i = 0; i < p->size; i++)
	{
		newArray[i] = p->array[i];
	}
	free(p->array);
	p->array = newArray;
	p->capacity = newCapacity;
}

//����
int Find(SeqList* p, int x)
{
	assert(p);
	for (int i = 0; i < p->size; i++)
	{
		if (p->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//ͷ��
void PushFront(SeqList* p, int x)
{
	assert(p);
	CheckCapacity(p);
	for (int i = p->size - 1; i >= 0; i--)
	{
		p->array[i + 1] = p->array[i];
	}
	p->array[0] = x;
	p->size++;
}

//ͷɾ
void PopFront(SeqList* p)
{
	assert(p);
	assert(p->size > 0);
	for (int i = 1; i < p->size; i++)
	{
		p->array[i - 1] = p->array[i];
	}
	p->size--;
}

//β��
void PushBack(SeqList* p, int x)
{
	assert(p);
	CheckCapacity(p);
	p->array[p->size] = x;
	p->size++;
}

//βɾ
void PopBack(SeqList* p)
{
	assert(p);
	assert(p->size > 0);
	p->size--;
}

//��posλ�ò���
void Insert(SeqList* p, int pos, int x)
{
	assert(p);
	CheckCapacity(p);
	assert(pos >= 0 && pos < p->size);
	for (int i = p->size - 1; i >= pos; i--)
	{
		p->array[i + 1] = p->array[i];
	}
	p->array[pos] = x;
	p->size++;
}

//ɾ��pos�����±������
void Erase(SeqList* p, int pos)
{
	assert(p);
	assert(p->size > 0);
	assert(pos >= 0 && pos < p->size);
	for (int i = pos + 1; i < p->size; i++)
	{
		p->array[i - 1] = p->array[i];
	}
	p->size--;
}

//ɾ������x
void Remove(SeqList* p, int x)
{
	assert(p);
	int pos = Find(p, x);
	if (pos != -1)
	{
		Erase(p, pos);
	}
}

//�޸�pos�����±������
void Modify(SeqList* p, int pos, int x)
{
	assert(p);
	assert(pos >= 0 && pos < p->size);
	p->array[pos] = x;
}

//��ӡ
void Print(SeqList* p)
{
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ", p->array[i]);
	}
	printf("\n");
}

int main()
{
	return 0;
}