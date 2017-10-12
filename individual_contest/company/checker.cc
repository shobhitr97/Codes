#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
  int from, to;
};

bool operator<(Edge e1, Edge e2)
{
  return ((e1.from < e2.from) || ((e1.from == e2.from) && (e1.to < e2.to)));
}

int stN, trueN;
vector<Edge> stEdges, trueEdges;


int main(int argc, char **argv)
{
  ifstream inFile(argv[1]);
  ifstream studentFile(argv[2]);
  ifstream outFile(argv[3]);
  
  bool ok = true;
  
  studentFile >> stN;
  outFile >> trueN;
  
  if (stN != trueN)
    ok = false;
  else
    {
      stEdges.resize(trueN);
      trueEdges.resize(trueN);
      for (int i = 0; (i < trueN) && ok; i++)
	{
	  if (studentFile.eof())
	    ok = false;
	  studentFile >> stEdges[i].from >> stEdges[i].to;
	  outFile >> trueEdges[i].from >> trueEdges[i].to;
	}
      
      sort(stEdges.begin(), stEdges.end());
      sort(trueEdges.begin(), trueEdges.end());
      
      for (int i = 0; (i < trueN) && ok; i++)
	if ((stEdges[i].from != trueEdges[i].from) || (stEdges[i].to != trueEdges[i].to))
	  ok = false;
    }
  
  inFile.close();
  studentFile.close();
  outFile.close();
  
  if (ok)
    cout << "OK";
  else
    exit(1);
  
  return 0;
}
