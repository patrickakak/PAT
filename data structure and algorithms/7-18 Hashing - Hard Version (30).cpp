#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 0x2fffffff;
int n, key[1010], ind[1010], e[1010][1010];
struct cmp {
	bool operator () (int a, int b) {
		return key[a] > key[b];
	}
};
int main() {
	fill(e[0], e[0] + 1010 * 1010, inf);
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &key[i]);
		if (key[i] < 0) continue;
		int pos = key[i] % n;
		if (pos != i)
			for (int j = pos; j != i; j = (j+1)%n)
				e[j][i] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (e[i][j] == 1) ind[j]++;
	priority_queue<int, vector<int>, cmp> q;
	for (int i = 0; i < n; i++)
		if (key[i] >= 0 && ind[i] == 0) q.push(i);
	vector<int> ans;
	while (!q.empty()) {
		int t = q.top();
		ans.push_back(key[t]);
		q.pop();
		for (int i = 0; i < n; i++)
			if (e[t][i] == 1) {
				if (--ind[i] == 0) q.push(i);
			}
	}
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}0) continue;
		Pos = Hash(A[i], N);
		if (Pos == i) {
			pair.Value = A[i]; pair.V = i;
			InsertMinHeap(H, pair);
		} else {
			if (Pos > i) ActualPos = i + N;
			else ActualPos = i;
			E = (Edge) malloc(sizeof(*E));	/* Insert an edge */
			for (j = Pos; j < ActualPos; j++) {
				E->V1 = j%N; E->V2 = i;
				InsertEdge(LG, E);
				Indegree[i]++;
			}
			free(E);
		}
	}
	return LG;
}

int TopSort(LGraph LG, MinHeap H, int Indeg[], KeyType A[], KeyType TopOrder[])
{
	Vertex V;
	PtrToAdjVNode W;
	Pair Out, In;
	int cnt = 0;

	while (!IsEmptyHeap(H)) {
		Out = DeleteMin(H);
		V = Out.V;
		TopOrder[cnt++] = Out.Value;
		for (W = LG->G[V].FirstEdge; W; W = W->Next)
			if (--Indeg[W->AdjV] == 0) {
				In.V = W->AdjV;
				In.Value = A[W->AdjV];
				InsertMinHeap(H, In);
			}
	}
	return cnt;
}

void Output(KeyType TopOrder[], int N)
{
	int i;

	printf("%d", TopOrder[0]);
	for (i = 1; i < N; i++)
		printf(" %d", TopOrder[i]);
	putchar('\n');
}

Index Hash(KeyType Key, int N)
{
	return Key % N;
}

LGraph CreateGraph(int VertexNum)
{
	LGraph LG;
	Vertex V;

	LG = (LGraph) malloc(sizeof(*LG));
	LG->Nv = VertexNum;
	LG->Ne = 0;
	for (V = 0; V < LG->Nv; V++)
		LG->G[V].FirstEdge = NULL;
	return LG;
}

void DestroyGraph(LGraph LG)
{
	Vertex V;
	PtrToAdjVNode T, t;

	for (V = 0; V < LG->Nv; V++) {
		T = LG->G[V].FirstEdge;
		while (T) {
			t = T->Next;
			free(T);
			T = t;
		}
	}
	free(LG);
}

void InsertEdge(LGraph LG, Edge E)
{
	PtrToAdjVNode NewNode;

	NewNode = (PtrToAdjVNode) malloc(sizeof(*NewNode));
	NewNode->AdjV = E->V2;
	NewNode->Next = LG->G[E->V1].FirstEdge;
	LG->G[E->V1].FirstEdge = NewNode;
}

MinHeap CreateHeap()
{
	MinHeap H;
	Pair pair;

	H = (MinHeap) malloc(sizeof(*H));
	H->Size = 0;

	pair.V = -1;
	pair.Value = MinData;
	H->Elems[0] = pair;

	return H;
}

void DestroyHeap(MinHeap H)
{
	free(H);
}

void InsertMinHeap(MinHeap H, ElementType X)
{
	int p;

	p = ++H->Size;
	H->Elems[p] = X;
	PercUp(H, p);
}

ElementType DeleteMin(MinHeap H)
{
	ElementType MinItem;

	MinItem = H->Elems[1];
	H->Elems[1] = H->Elems[H->Size--];
	PercDown(H, 1);

	return MinItem;
}

void PercUp(MinHeap H, int p)
{
	int i;
	ElementType X;

	for (i=p, X=H->Elems[p]; H->Elems[i/2].Value > X.Value; i /= 2)
		H->Elems[i] = H->Elems[i/2];
	H->Elems[i] = X;
}

void PercDown(MinHeap H, int p)
{
	int Parent, Child;
	ElementType Tmp = H->Elems[p];

	for (Parent = p; Parent*2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && 
				(H->Elems[Child].Value > H->Elems[Child+1].Value))
			Child++;
		if (Tmp.Value <= H->Elems[Child].Value) break;
		else H->Elems[Parent] = H->Elems[Child];
	}
	H->Elems[Parent] = Tmp;
}

bool IsEmptyHeap(MinHeap H)
{
	return H->Size == 0;
}
