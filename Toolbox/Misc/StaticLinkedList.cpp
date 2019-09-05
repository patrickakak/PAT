/**
 * Static Lined List
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100010
struct Node {
	int addr;		// address
	typename data;
	int next;		// pointer: -1 to end usually
	typename XXX;	// property/flag
} node[maxn];
int count = 0;		// # of valid nodes

void init()
{
	for (int i = 0; i < maxn; i++)
		node[i].XXX = -1;	// less than any resonable num (to help sort())
}

void traverse(int begin)
{
	int p = begin;
	while (p != -1) {
		node[p].XXX = 1;
		count++;
		p = node[p]->next;
	}
}

bool cmp(Node a, Node b)
{
	if (a.XXX == -1 || b.XXX == -1)		// degrade invalid nodes
		return a.XXX > b.XXX;
	else {
		// sort valid nodes as you want
	}
}

int main()
{
	init();

	return 0;
}


