/**
 *       3
 *      / \
 *     5   6
 *    / \   \
 *   1   8  10
 *      /
 *     9
 * ---------------------------
 * Sample Output:
 * Level-order: 3 5 6 1 8 10 9
 */
void Level_order(Tree T, void (*visit)(Tree ThisNode))
{
	Tree TArr[32];
	int Front = 0, Rear = 0;
	if (!T) return;

	TArr[Rear++] = T;
	while (Front < Rear) {
		if (TArr[Front]->Left)
			TArr[Rear++] = TArr[Front]->Left;
		if (TArr[Front]->Right)
			TArr[Rear++] = TArr[Front]->Right;
		(*visit)(TArr[Front++]);
	}
}

