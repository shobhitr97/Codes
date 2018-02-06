#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef set<int> si;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007

vector <vi> graph;
vi ts, deg;

void fillDeg(int n){
	fori(0, n)	deg[i] = 0;
	fori(0, n){
		int siz = graph[i].size();
		forn(j, 0, siz)	deg[graph[i][j]]++;
	}
}

bool topSort(int n){
	bool isCycle = false;
	queue <int> q;
	fillDeg(n);
	fori(0, n){
		if(deg[i] == 0)	q.push(i);
	}
	while(!q.empty()){
		n--;
		int t = q.front();
		ts.pb(t);
		q.pop();
		fori(0, graph[t].size()){
			deg[graph[t][j]]--;
			if(deg[graph[t][j]] == 0)	q.push(graph[t][j]);
		}
	}

	if(n > 0)	return true;
	else	return false;
}


int main(){
	return 0;
}