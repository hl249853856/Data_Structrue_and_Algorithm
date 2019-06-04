#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode *SearchTree;

struct TreeNode
{
	int val;
	TreeNode* Left;
	TreeNode* Right;
};

SearchTree MakeEmpty(SearchTree T);
SearchTree Find(SearchTree T, int X);
SearchTree FindMin(SearchTree T);
SearchTree FindMax(SearchTree T);
SearchTree Insert(SearchTree T, int X);
SearchTree Delete(SearchTree T, int X);