/**
 * Sample input:
 * 3 4 5 2
 * 1 1 1 1
 * 1 1 1 1
 * 1 1 1 1
 * 0 0 1 1
 * 0 0 1 1
 * 0 0 1 1
 * 1 0 1 1
 * 0 1 0 0
 * 0 0 0 0
 * 1 0 1 1
 * 0 0 0 0
 * 0 0 0 0
 * 0 0 0 1
 * 0 0 0 1
 * 1 0 0 0
 * --------------
 * Sample output:
 * 26
 */
#include <cstdio>
#include <queue>
using namespace std;

struct Node {
	int x, y, z;
} node;

int m, n, slice, T;
int pixel[1290][130][61];
bool inQ[1290][130][61] = {false};
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool judge(int x, int y, int z)
{
	if (x >= m || x < 0 || y >= n || y < 0 || z >= slice || z < 0) return false;
	if (pixel[x][y][z] == 0 || inQ[x][y][z] == true) return false;
	return true;
}

// get volume of the current block
int BFS(int x, int y, int z)
{
	int tot = 0;
	queue<Node> Q;
	node.x = x, node.y = y, node.z = z;
	Q.push(node);
	inQ[x][y][z] = true;
	while (!Q.empty()) {
		Node top = Q.front();
		Q.pop();
		tot++;
		for (int i = 0; i < 6; i++) {
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if (judge(newX, newY, newZ)) {
				node.x = newX, node.y = newY, node.z = newZ;
				Q.push(node);
				inQ[newX][newY][newZ] = true;
			}
		}
	}
	if (tot >= T) return tot;
	else return 0;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	scanf("%d%d%d%d", &m, &n, &slice, &T);
	for (int z = 0; z < slice; z++)
		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++)
				scanf("%d", &pixel[x][y][z]);
	int ans = 0;
	for (int z = 0; z < slice; z++)
		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++)
				if (pixel[x][y][z] == 1 && inQ[x][y][z] == false)
					ans += BFS(x, y, z);
	printf("%d\n", ans);

	return 0;
}


