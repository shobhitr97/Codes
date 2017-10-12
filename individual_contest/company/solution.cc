/*
 * Company problem sample solution by Zoran Dzunic
 *
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, M_soln = 0;
vector<vector<int> > edge;
vector<vector<int> > back_edge;
vector<vector<int> > soln_edge;
vector<vector<int> > in_list;
vector<int> outdeg;
queue<int> trav;

void input()
{
  int a, b;
  cin >> N >> M;
  
  // init
  edge.resize(N);
  back_edge.resize(N);
  soln_edge.resize(N);
  in_list.resize(N);
  for (int i = 0; i < N; i++)
    {
      in_list[i].resize(N);
      fill(in_list[i].begin(), in_list[i].end(), 0);
    }
  outdeg.resize(N);
  fill(outdeg.begin(), outdeg.end(), 0);
  
  for (int i = 0; i < M; i++)
    {
      cin >> a >> b;
      edge[a - 1].push_back(b - 1);
      back_edge[b - 1].push_back(a - 1);
      outdeg[a - 1]++;
    }
}

void solve()
{
  for (int i = 0; i < N; i++)
    if (outdeg[i] == 0)
      trav.push(i);
  
  int a, b;
  while (!trav.empty())
    {
      a = trav.front();
      
      for (int i = 0; i < edge[a].size(); i++)
	{
	  b = edge[a][i];
	  if (!in_list[a][b])
	    {
	      soln_edge[a].push_back(b);
	      M_soln++;
	    }
	}

      for (int i = 0; i < edge[a].size(); i++)
	in_list[a][edge[a][i]] = 1;
      
      for (int j = 0; j < back_edge[a].size(); j++)
	{
	  b = back_edge[a][j];
	  for (int i = 0; i < N; i++)
	    if (in_list[a][i])
	      in_list[b][i] = 1;
	  
	  outdeg[b]--;
	  if (outdeg[b] == 0)
	    trav.push(b);
	}
      
      trav.pop();
    }
}

void output()
{
  cout << M_soln << endl;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < soln_edge[i].size(); j++)
      cout << i + 1 << " " << soln_edge[i][j] + 1 << endl;
}

int main()
{
  input();
  solve();
  output();
  return 0;
}
