/*
 * Edit problem sample solution by Jelani Nelson
 *
 */

#include <iostream>
#include <vector>
using namespace std;
#define MAXN 60
#define MAXM 60
int dp[MAXN][MAXN][MAXM][MAXM];
int n, labelF[MAXN], postorderF[MAXN], smallestF[MAXN];
int m, labelG[MAXM], postorderG[MAXM], smallestG[MAXM];
vector<int> childrenF[MAXN], childrenG[MAXN];

int dfs(int x, int c, const vector<int> *child, int *po, int *smallest) {
  smallest[x] = c;
  for (int i = 0; i < child[x].size(); ++i)
    c = dfs(child[x][i], c, child, po, smallest);
  po[c] = x;
  return c + 1;
}

void read_input(int N, int *label, int *postorder, int *smallest,
		vector<int> *children) {
  char is_root[N];
  memset(is_root, 1, sizeof(is_root));
  for (int i = 0; i < N; ++i) {
    int d;
    children[i] = vector<int>();
    cin >> label[i] >> d;
    for (int j = 0; j < d; ++j) {
      int x;
      cin >> x;
      children[i].push_back(x);
      is_root[x] = 0;
    }
  }
  int root = -1;
  for (int i = 0; i < N; ++i)
    if (is_root[i])
      root = i;
  dfs(root, 0, children, postorder, smallest);
}

int go(int x1, int x2, int y1, int y2) {
  if (x1 > x2)
    return y2 - y1 + 1;
  if (y1 > y2)
    return x2 - x1 + 1;
  int &ret = dp[x1][x2][y1][y2];
  if (ret != -1)
    return ret;
  int a = postorderF[x2], b = postorderG[y2];
  ret = 1 + go(x1, x2, y1, y2 - 1);
  ret <?= 1 + go(x1, x2 - 1, y1, y2);
  ret <?= (labelF[a] != labelG[b]) + 
    go(smallestF[a], x2 - 1, smallestG[b], y2 - 1) +
    go(x1, smallestF[a] - 1, y1, smallestG[b] - 1);
  return ret;
}

int main() {
  cin >> n >> m;
  read_input(n, labelF, postorderF, smallestF, childrenF);
  read_input(m, labelG, postorderG, smallestG, childrenG);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", (labelF[postorderF[n-1]]!=labelG[postorderG[m-1]]) + 
	 go(0, n - 2, 0, m - 2));
  return 0;
}
