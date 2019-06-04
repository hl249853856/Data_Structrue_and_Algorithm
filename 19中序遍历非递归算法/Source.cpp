void InOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreateStack(MaxSize);
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S))
		{
			T = Pop(S);
			printf("%5d", T->Data);
			T = T->Right;
		}
	}
}