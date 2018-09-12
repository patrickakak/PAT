int Isomorphic(Tree T1, Tree T2)
{
	if ((T1 == NULL) && (T2 == NULL))	/* Both empty */
		return 1;
	if (((T1 == NULL) && (T2 != NULL)) || ((T2 == NULL) && (T1 != NULL)))
		return 0;	/* One of them is empty */
	if (T1->Element != T2->Element)
		return 0;	/* Roots are different */
	if ((T1->Left == NULL) && (T2->Left == NULL))
		return Isomorphic(T1->Right, T2->Right);	/* Both have no left subtree */
	if (((T1->Left != NULL) && (T2->Left != NULL))
			&& (T1->Left->Element == T2->Left->Element))	/* No need to swap the left and the right */
		return (Isomorphic(T1->Left, T2->Left)
				&& Isomorphic(T1->Right, T2->Right));
	else	/* Need to swap the left and the right */
		return (Isomorphic(T1->Left, T2->Right)
				&& Isomorphic(T1->Right, T2->Left));
}

