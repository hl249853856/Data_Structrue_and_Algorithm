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

//生成空链表
List MakeEmpty(List L);
//判断链表是否为空
int IsEmpty(List L);
//判断给定位置是否是链表表尾
int IsLast(Position P, List L);
//按值查找
Position Find(ElementType X, List L);
//按值删除
void Delete(ElementType X, List L);
//返回给定值前一个结点
Position FindPrevious(ElementType X, List L);
//插入
void Insert(ElementType X, List L, Position P);
//删除链表
void DeleteList(List L);
//返回头结点
Position Header(List L);
//返回第一个结点
Position First(List L);
//
Position Advance(Position P);

//按位置插入
void InsertByPos(ElementType X, List L, int N);

//打印链表
void PrintList(List L);