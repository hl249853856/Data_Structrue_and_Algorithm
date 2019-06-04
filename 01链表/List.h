#pragma once
#include<stdio.h>
#include<stdlib.h>

#define ElementType int
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node {
	ElementType Element;
	Position Next;
};

//���ɿ�����
List MakeEmpty(List L);
//�ж������Ƿ�Ϊ��
int IsEmpty(List L);
//�жϸ���λ���Ƿ��������β
int IsLast(Position P, List L);
//��ֵ����
Position Find(ElementType X, List L);
//��ֵɾ��
void Delete(ElementType X, List L);
//���ظ���ֵǰһ�����
Position FindPrevious(ElementType X, List L);
//����
void Insert(ElementType X, List L, Position P);
//ɾ������
void DeleteList(List L);
//����ͷ���
Position Header(List L);
//���ص�һ�����
Position First(List L);
//
Position Advance(Position P);

//��λ�ò���
void InsertByPos(ElementType X, List L, int N);

//��ӡ����
void PrintList(List L);