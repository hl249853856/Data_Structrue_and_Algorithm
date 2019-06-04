void LevelOrderTraversal(BinTree BT)
{
	Queue Q; BinTree T;
	if (!BT)	return;
	Q = CreateQueue(MaxSize);
	AddQ(Q, BT);
	while (!IsEmptyQ(Q))
	{
		T = DeleteQ(Q);
		printf("%d\n", T->Data);
		if (T->Left)  AddQ(Q, T->Left);
		if (T->Right)  AddQ(Q, T->Right);
	}
}