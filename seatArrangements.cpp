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
#define NUM 2005

int main(){

	int cnt, sum;
	string a[NUM];

	int n, m, k;

	cin>>n>>m>>k;

	fori(0, n){
		cin>>a[i];
	}

	cnt = 0;

	if(m >= k){
		fori(0, n){
			sum = 0;
			forn(j, 0, k)	sum+=1*(a[i][j] == '.');
			if(sum == k)	cnt++;
			forn(j, k, m){
				sum = sum + 1*(a[i][j] == '.') - 1*(a[i][j-k] == '.');
				if(sum == k)	cnt++;
			}
		}
	}
	if(n >= k){
		fori(0, m){
			sum = 0;
			forn(j, 0, k)	sum += 1*(a[j][i] == '.');
			if(sum == k)	cnt++;
			forn(j, k, n){
				sum = sum + 1*(a[j][i] == '.') - 1*(a[j-k][i] == '.');
				if(sum == k)	cnt++;
			}
		}
	}

	if(k == 1)	cout<<(cnt/2)<<"\n";
	else	cout<<cnt<<"\n";

	return 0;
}