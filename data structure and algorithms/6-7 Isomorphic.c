int Isomorphic(Tree T1, Tree T2) {
	if ((T1 == NULL) && (T2 == NULL)) return 1;
	if (((T1 == NULL) && (T2 != NULL)) || ((T2 == NULL) && (T1 != NULL))) return 0;
	if (T1->Element != T2->Element) return 0;
	if ((T1->Left == NULL) && (T2->Left == NULL)) return Isomorphic(T1->Right, T2->Right);
	if (((T1->Left != NULL) && (T2->Left != NULL)) && (T1->Left->Element == T2->Left->Element))
		return (Isomorphic(T1->Left, T2->Left) && Isomorphic(T1->Right, T2->Right));
	else
		return (Isomorphic(T1->Left, T2->Right) && Isomorphic(T1->Right, T2->Left));
}
