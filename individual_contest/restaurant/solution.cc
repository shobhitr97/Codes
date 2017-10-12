/*
 * Restaurant problem sample solution by Andy Lutomirski
 *
 * This is a greedy solution.
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct Infeasible {};

enum Coin
  {
    C1, C5, C10, C25, C50, C100, C500, C1000, C2000, C5000, C10000, NCOINS
  };

int cvals[] = {1, 5, 10, 25, 50, 100, 500, 1000, 2000, 5000, 10000};

typedef vector<int> VI;
VI x;  // Pot's debt to a person
VI pot;
int N;

void assign(int c, int towhom, int howmany)
{
  if (pot[c] < howmany)
    throw Infeasible();
  if (x[towhom] < cvals[c] * howmany)
    throw Infeasible();
  pot[c] -= howmany;
  x[towhom] -= cvals[c] * howmany;
}

void greedy(int c)
{
  int ratio;
  if (c != C10000) {
    ratio = cvals[c+1] / cvals[c];
    assert(cvals[c+1] == cvals[c] * ratio);
  }
  for(int i = 0; i < N; i++)
    {
      assert(x[i] % cvals[c] == 0);
      int amt = x[i] / cvals[c];
      if (c != C10000)
	amt %= ratio;
      assign(c, i, amt);
    }

  if (c != C10000)
    for(int i = 0; i < NCOINS; i++)
      {
	pot[c+1] += pot[c] / ratio;
	pot[c] %= ratio;
	assert(pot[c] == 0);
      }
}

void magic(int c)
{
  int base = cvals[c];
  assert(cvals[c+1] == 2*cvals[c]);
  assert(cvals[c+2] == 5*cvals[c]);
  assert(cvals[c+3] == 10*cvals[c]);

#define ASSIGN_ONE(cond, type) \
  for (int i = 0; i < N; i++) \
    { \
      int r = (x[i] / base) % 10; \
      if (pot[c+type] && (cond)) \
	assign(c+type, i, 1); \
    }

#define ASSIGN_5_1(cond) \
  for (int i = 0; i < N; i++) \
    { \
      int r = (x[i] / base) % 10; \
      if (pot[c+2] && pot[c] && (cond)) { \
	assign(c, i, 1); \
	assign(c+2, i, 1); \
      } \
    }

  // Make all x even.
  ASSIGN_ONE(r == 5 || r == 7 || r == 9, 2);       // 5
  ASSIGN_ONE(r == 5 || r == 7 || r == 9, 0);       // 1 -- no choice
  ASSIGN_ONE((r == 1 || r == 3) && x[i] < 10, 0);  // 1
  ASSIGN_ONE(r == 1 || r == 3, 0);                 // 1
  ASSIGN_ONE(r == 1 || r == 3, 2);                 // 5 -- no choice

  // Now everyone is owed an even number (or infeasible).

  // 6 or 8 can take 5+1 safely.
  ASSIGN_5_1(r == 6 || r == 8);

  // Note that 5+1+5+1 = 5+5+1+1, so we can assign 2 and 1+1 all around.
  for (int i = 0; i < N; i++)
    {
      int r = (x[i] / base) % 10;
      while(r >= 2) {
	if (pot[c+1])
	  assign(c+1, i, 1);
	else if (pot[c] >= 2)
	  assign(c, i, 2);
	else
	  throw Infeasible();
	r = (x[i] / base) % 10;
      }
      if (r)
	throw Infeasible();
    }

  // At this point, (if feasible), everyone is owed a
  // multiple of 10, so the pot contains a multiple of
  // 10.  All remaining coins are a multiple of 10*base,
  // so we can convert the pot into 10s.

  int potsize = pot[c] + pot[c+1]*2 + pot[c+2]*5;
  assert(potsize % 10 == 0);
  pot[c+3] += potsize / 10;
  pot[c] = pot[c+1] = pot[c+2] = 0;
}

void solve()
{
  static int caseno = 0;
  caseno++;
  cin >> N;
  assert(!!cin);
  if (N == 0)
    exit(0);
  pot = VI(NCOINS, 0);
  x.resize(N);
  int totaldebt = 0;
  for(int i = 0; i < N; i++)
    {
      int debt;
      cin >> debt;
      totaldebt += debt;
      for(int j = 0; j < NCOINS; j++)
	{
	  int z;
	  if (j == C50)
	    z = 0;
	  else
	    cin >> z;
	  debt -= cvals[j] * z;
	  pot[j] += z;
	  //  cout << cvals[j] << ':' << z << ' ';
	}
      //      cout << endl;
      assert(debt <= 0);
      x[i] = -debt;
    }
  x.push_back(totaldebt);
  N++;

  cout << "Case " << caseno << ": ";

  try {
    greedy(C1);
    magic(C5);
    greedy(C50);
    greedy(C100);
    greedy(C500);
    magic(C1000);

    // All remaining "coins" are $100 bills.
    for(int i = 0; i < N; i++)
      {
	assign(C10000, i, x[i]/10000);
	assert(x[i] == 0);
      }
    assert(pot[C10000] == 0);
    cout << "YES\n";
  } catch(Infeasible &) {
    cout << "NO\n";
  }
}

int main()
{
  while(true)
    solve();
}
