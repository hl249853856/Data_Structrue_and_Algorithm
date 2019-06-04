#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MaxTree 10
#define Tree int
#define Null -1

struct TreeNode {
	char Element;
	Tree Left;
	Tree Right;
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
	char cl, cr;
	int N;//N个结点
	int Root = Null;//根结点
	int i;
	int check[MaxTree];

	scanf("%d\n", &N);
	getchar();
	if (N) {
		for (i = 0; i < N; i++)
			check[i] = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
			getchar();
			//对cl处理
			if (cl != '-') {
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = Null;

			//对cr处理
			if (cr != '-') {
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
				T[i].Right = Null;
		}
		for (i = 0; i < N; i++)
			if (check[i] == 0)
				break;
		Root = i;
	}
	return Root;
}

int Isomorphic(Tree R1, Tree R2)
{
	//R1和R2都为空
	if ((R1 == Null) && (R2 == Null))
		return 1;

	//一个空，一个不空
	if (((R1 == Null) && R2 != Null) || ((R1 != Null) && (R2 == Null)))
		return 0;

	//两结点的值不等
	if (T1[R1].Element != T2[R2].Element)
		return 0;

	//都没左结点
	if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
		return Isomorphic(T1[R1].Right, T2[R2].Right);

	if (((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	else
		return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
}

int main()
{
	Tree R1, R2;

	R1 = BuildTree(T1);
	R2 = BuildTree(T2);

	if (Isomorphic(R1, R2))
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}