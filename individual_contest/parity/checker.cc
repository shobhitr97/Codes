#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <cmath>
#include <set>

using namespace std;

#define assert2(cond, reason) \
  if(!(cond)) { cout << __STRING(cond) << " failed because:  " << reason << endl; exit(1); }

int main(int argc, char* argv[]) {
  assert(argc > 3);
  const char *infile = argv[1];
  const char *outfile = argv[2]; // student answer
  const char *ansfile = argv[3]; // correct answer

  ifstream in(infile), ans(ansfile), out(outfile);

  int n, k, k1, k2;

  in >> n >> k;

  string nums[n];
  int xors[n], si;
  for (int i = 0; i < n; ++i)
    in >> nums[i] >> xors[i];

  si = nums[0].size();

  ans >> k1;
  out >> k2;

  if (k1==-1 && k2==-1) {
    cout << "OK" << endl;
    exit(0);
  }

  assert2(k2 != -1, "didn't find valid solution but one exists");
  assert2(k2>=0 && k2<=k, "invalid set size");

  vector<int> inds;
  for (int i = 0; i < k2; ++i) {
    int x;
    out >> x;
    inds.push_back(x);
  }

  sort(inds.begin(), inds.end());
  for (int i = 1; i < inds.size(); ++i) {
    assert2(inds[i] != inds[i-1], "duplicate indices");
    assert2(inds[i]>=0 && inds[i]<si, "index out of range");
  }

  int vals[n];
  memset(vals, 0, sizeof(vals));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k2; ++j)
      if (nums[i][inds[j]] == '1')
	vals[i] = !vals[i];
    assert2(vals[i] == xors[i], "indices don't give the right xor");
  }

  if (k1==-1 && k2!=-1)
    cout << "test data is buggy -- check it" << endl;

  cout << "OK" << endl;
  exit(0);
}
