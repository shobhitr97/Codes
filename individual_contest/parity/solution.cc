/*
 * Parity problem sample solution by Jelani Nelson
 *
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define MAXN 64
#define MAXR 50
#define MAXK 10
typedef long long LL;
int n, k, r, at, vals[MAXN];
long long xors[MAXR], mark;
string s[MAXN];
vector<int> rec;
map<long long, long long> M;

inline vector<int> decode(LL x) {
  vector<int> v = vector<int>(x&7);
  x >>= 3;
  for (int i = 0; i < v.size(); ++i, x >>= 6)
    v[i] = x&63;
  return v;
}

inline LL encode(const vector<int> &v, int t) {
  LL ret = t; // 0 <= t <= 5 (3 bits)
  // 6 bits to encode an index 0,...,50
  for (int i = 0; i < t; ++i)
    ret |= ((0LL+v[i])<<(6*i + 3));
  return ret;
}

void go(int x, int maxk, LL xo, bool build) {
  if (x == r) {
    if (build)
      M[xo] = encode(rec, at);
    else if (M.count(xo)) {
      set<int> ret;
      vector<int> v = decode(M[xo]);
      for (int i = 0; i < at; ++i)
        ret.insert(rec[i]);
      for (int i = 0; i < v.size(); ++i)
        if (ret.find(v[i]) != ret.end())
          ret.erase(v[i]);
        else
          ret.insert(v[i]);
      cout << ret.size() << endl;
      if (ret.size()) {
        bool flag = false;
	set<int>::iterator iter = ret.begin();
	while (iter != ret.end()) {
          if (flag)
            cout << " ";
          flag = true;
          cout << *(iter++);
	}
        cout << endl;
      }
      exit(0);
    }
  } else {
    go(x + 1, maxk, xo, build);
    if (at < maxk) {
      rec[at++] = x, xo ^= xors[x];
      go(x + 1, maxk, xo, build);
      --at, xo ^= xors[x];
    }
  }
}

int main() {
  rec = vector<int>(MAXK);
  cin >> n >> k;
  mark = 0;
  memset(xors, 0, sizeof(xors));
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> vals[i];
    if (vals[i])
      mark |= (1LL<<i);
  }
  r = s[0].size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < r; ++j)
      if (s[i][j] == '1')
        xors[j] |= (1LL<<i);
  at = 0;
  M.clear();
  go(0, k/2, 0, 1);
  go(0, k - k/2, mark, 0);
  cout << -1 << endl;
  return 0;
}
