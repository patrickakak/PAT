/**
 * IMPLIMENTATION OF UNION-FIND-SET
 */
#define MAXN 1000 			/* Maxmum number of set */
typedef int ElementType;	/* Non-negative integer to present normal element */
typedef int SetName;		/* Use index of root as the name of set */
typedef ElementType SetType[MAXN];	/* Indices begin with 0 */

/* Root1 and Root2 are root of different set by assumption */
void Union(SetType S, SetName Root1, SetName Root2)
{
	/* To promise merge the smaller one into the larger one */
	if (S[Root2] < S[Root1]) {		/* Set two is larger */
		S[Root2] += S[Root1];		/* Merge set one into set two */
		S[Root1] = Root2;
	} else {						/* Set one is larger */
		S[Root1] += S[Root2];		/* Merge set two into set one */
		S[Root2] = Root1;
	}
}

/* Set all elements in the set as -1 */
SetName Find(SetType S, ElementType X)
{
	if (S[X] < 0) return X; 		/* Find the root of set */
	else return S[X] = Find(S, S[X]); 	/* Path compression */
}

