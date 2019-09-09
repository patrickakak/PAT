/**
 * 6-7: Two trees, T1 and T2, are isomorphic if T1 can be transformed into 
 * T2 by swapping left and right children of (some of the) nodes in T1.
 *        A          A                A          A
 *       / \        / \              / \        / \
 *      B   C      C   B            B   C      B   C
 *     / \  /     /   / \          / \  /     /   / \
 *    D  E  G    G   E   D        D  E  G    G   D   E
 *      /  /      \ /               /   /     \  /
 *     F   H      H F              F    H     H F
 *          Figure 1                   Figure 2
 * ----------------------------------------------------
 * Sample Output1 (for the trees shown in Figure 1):
 * 1
 * ----------------------------------------------------
 * Sample Output2 (for the trees shown in Figure 2):
 * 0
 */
int Isomorphic(Tree T1, Tree T2)
{
	/*********************************/
	/* About the root node jugement: */
	/*********************************/
	
	if ((T1 == NULL) && (T2 == NULL))	/* Both empty */
		return 1;
	if (((T1 == NULL) && (T2 != NULL)) || ((T2 == NULL) && (T1 != NULL)))
		return 0;	/* One of them is empty */
	if (T1->Element != T2->Element)
		return 0;	/* Roots are different */
	
	/***********************************/
	/* About the child nodes jugement: */
	/***********************************/
	
	/* Both have no left subtree */
	if ((T1->Left == NULL) && (T2->Left == NULL))
		return Isomorphic(T1->Right, T2->Right);
	/* No need to swap the left and the right */
	if (((T1->Left != NULL) && (T2->Left != NULL))
			&& (T1->Left->Element == T2->Left->Element))
		return (Isomorphic(T1->Left, T2->Left)
				&& Isomorphic(T1->Right, T2->Right));
	else	/* Need to swap the left and the right */
		return (Isomorphic(T1->Left, T2->Right) 
				&& Isomorphic(T1->Right, T2->Left));
}

/*
int Isomorphic(Tree T1, Tree T2)
{
	if (!T1 && !T2)
		return 1;
	if ((!T1 && T2) || (T1 && !T2))
		return 0;
	// T1 and T2 are both not empty
	if (T1->Element != T2->Element)
		return 0;
	// T1 and T2 are both not empty and root element is same
	if (!T1->Left && !T2->Left && !T1->Right && !T2->Right)
		return 1;
	else if (!T1->Left && !T2->Left)
		return Isomorphic(T1->Right, T2->Right);
	else if (!T1->Left && !T2->Right)
		return Isomorphic(T1->Right, T2->Left);
	else if (!T1->Right && !T2->Left)
		return Isomorphic(T1->Left, T2->Right);
	else if (!T1->Right && !T2->Right)
		return Isomorphic(T1->Left, T2->Left);
	else if (T1->Left && T1->Right && T2->Left && T2->Right)
		return ((Isomorphic(T1->Left, T2->Left) 
					&& Isomorphic(T1->Right, T2->Right))
				|| (Isomorphic(T1->Left, T2->Right) 
					&& Isomorphic(T1->Right, T2->Left)));
	else
		return 0;
}
*/

