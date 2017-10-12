#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include <fstream>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

ifstream inFile;
ifstream studentFile;
ifstream outFile;

void solve()
{
  static int caseno = 0;
  int N, M;
  {
    string line;
    getline(inFile, line);
    istringstream ss(line);
    ss >> N >> M;
  }
  assert(!!inFile);
  if (N == 0 && M == 0)
    {
      cout << "OK\n";
      exit(0);
    }

  int V = M;
  VVI caps(V, VI(V, 0));
  for(int i = 0; i < M; i++)
    {
      string line;
      getline(inFile, line);
      istringstream ss(line);
      while(true)
	{
	  int j;
	  ss >> j;
	  if (!ss)
	    break;
	  j--;
	  caps[i][j] = 1;
	}
    }

  int possible;
  outFile >> possible;

  string line;
  getline(studentFile, line);
  ostringstream ss;
  ss << "Case " << ++caseno << ":";
  if (line != ss.str()) {
    cout << "Bad caseno line on case " << caseno << '\n';
    exit(1);
  }

  if (!possible) {
    getline(studentFile, line);
    if (line != "Impossible") {
      cerr << "Expected impossible; got " << line << " on case " << caseno << "; will continue anyway\n";
      goto keeptrying;
    }
    getline(studentFile, line);
    if (line.size() > 1) {
      cout << "Missing blank line\n";
      exit(1);
    }
    return;  // All done here.
  }

 keeptrying:

  VI used(M, 0);
  for(int i = 0; i < N; i++)
    {
      if (i != 0 || possible)
	getline(studentFile, line);
      istringstream ss(line);
      int here = 0;
      int next;
      ss >> next;
      if (!ss || next != 1) {
	cout << "Bad first index on case " << caseno << "\n";
	exit(1);
      }

      while(true)
	{
	  ss >> next;
	  if (!ss) {
	    if (here != 1) {
	      cout << "Bad last index on case " << caseno << "\n";
	      exit(1);
	    }
	    
	    break; // next line.
	  }
	  if (here == 1) {
	    cout << "Didn't stop at 2\n";
	    exit(1);
	  }
	  next--;
	  if (next < 0 || next >= M) {
	    cout << "Out of bounds: " << line << "\n";
	    exit(1);
	  }
	  if (!caps[here][next]) {
	    cout << "Bad edge " << here+1 << "->" << next+1 << " on case " << caseno << "\n";
	    exit(1);
	  }
	  if (used[next]) {
	    cout << "Reused node\n";
	    exit(1);
	  }
	  if (next != 1)
	    used[next] = 1;
	  here = next;
	  if (here == 0) {
	    cout << "Repeated 1\n";
	    exit(1);
	  }
	}
    }

    getline(studentFile, line);
    if (line.size() > 1) {
      cout << "Missing blank line\n";
      exit(1);
    }      
}

int main(int argc, char **argv)
{
  inFile.open(argv[1]);
  studentFile.open(argv[2]);
  outFile.open(argv[3]);

  while(true)
    solve();
}
