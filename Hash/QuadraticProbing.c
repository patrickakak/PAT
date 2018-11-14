Position Find(HashTable H, ElementType Key)
{
	Position CurrentPos, NewPos;
	int CNum = 0; 	/* To record the collision time */

	NewPos = CurrentPos = Hash(Key, H->TableSize); 	/* The initial hash position */
	/* When collision happens: */
	while (H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key) {
		/* If the keyword is a string type, use strcmp function instead */
		/* One collision occured, and to decide the parity of this time */
		if (++CNum%2) { 	/* An odd time collision */
			NewPos = CurrentPos + (CNum+1)*(CNum+1)/4; 	/* Increment: +[(CNum+1)/2]^2 */
			if (NewPos >= H->TableSize)
				NewPos = NewPos % H->TableSize; 	/* Adjust to legitimate address */
		} else { 	/* An even time collision */
			NewPos = CurrentPos - CNum*CNum/4; 	/* Increment: -(CNum/2)^2 */
			while (NewPos < 0)
				NewPos += H->TableSize; 	/* Adjust to legitimate address */
		}
	}
	return NewPos; 	/* The position of Key, or an empty ceil */
}

bool Insert(HashTable H, ElementType Key)
{
	Position Pos = Find(H, Key); 	/* Check the exsistency of Key first */

	/* If the ceil hasn't been taken, Key can be inserted here */
	if (H->Cells[Pos].Info != Legitimate) {
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		/* Use strcpy function if the type of keyword is string */
		return true;
	} else {
		printf("The key value already exists!\n");
		return false;
	}
}

