/*
 * Boy Scouts problem sample solution by Zoran Dzunic
 *
 */

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

struct Point
{
  double x, y;
};

bool operator<(Point a, Point b)
{
  return (a.x < b.x) || (a.x==b.x && (a.y < b.y));
}

int N, Nsol;
vector<Point> point;
vector<vector<int> > upper, lower;

void input()
{
  cin>> N;
  point.resize(N);
  upper.resize(N);
  lower.resize(N);
  for (int i = 0; i < N; i++)
    {
      cin >> point[i].x >> point[i].y;
      upper[i].resize(N);
      lower[i].resize(N);
    }
  
  
}

bool concave(int a, int b, int c)
{
  return (point[b].x - point[a].x) * (point[c].y - point[b].y) < (point[b].y - point[a].y) * (point[c].x - point[b].x);
}

void solve()
{
  Nsol = 3;
  int up, lo;
  sort(point.begin(), point.end());
  for (int beg = 0; beg < N - 1; beg++)
    {
      for (int i = beg + 1; i < N; i++)
	{
	  upper[beg][i] = 1;
	  lower[beg][i] = 1;
	  up = 1;
	  lo = 1;
	  for (int prev = beg + 1; prev < i; prev++)
	    {
	      upper[prev][i] = 0;
	      lower[prev][i] = 0;
	      for (int prevprev = beg; prevprev < prev; prevprev++)
		{
		  if (concave(prevprev, prev, i))
		    {
		      if (upper[prevprev][prev] > 0)
			if (upper[prevprev][prev] + 1 > upper[prev][i])
			  upper[prev][i] = upper[prevprev][prev] + 1;
		    }
		  else
		    {
		      if (lower[prevprev][prev] > 0)
			if (lower[prevprev][prev] + 1 > lower[prev][i])
			  lower[prev][i] = lower[prevprev][prev] + 1;
		    }
		}
	      if (upper[prev][i] > up)
		up = upper[prev][i];
	      if (lower[prev][i] > lo)
		lo = lower[prev][i];
	    }
	  if (up + lo > Nsol)
	    Nsol = up + lo;
	}
    }
}

void output()
{
  cout << Nsol << endl;
}

int main()
{
  input();
  solve();
  output();
  return 0;
}
