#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>

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

int n;
double dim[1003][5];

bool checkIfObtuse(int i, int j, int k){
	double sum=0;
	forn(l, 0, 5)	sum+=(dim[i][l]-dim[j][l])*(dim[i][l]-dim[k][l]);
	if(sum<=0)	return true;
	return false;
}

int main(){
	cin>>n;
	double a;
	fori(0, n)	forn(j, 0, 5)	cin>>dim[i][j];
	set<int>sol;
	fori(0, n){
		bool flag=true;
		forn(j, 0, n){
			if(j==i)	continue;
			forn(k, 0, n){
				if(k==i||k==j)	continue;
				flag=checkIfObtuse(i, j, k);
				if(flag==false)	break;
			}
			if(flag==false)	break;
		}
		if(flag==true)	sol.insert(i+1);
	}
	set<int>::iterator it;
	cout<<sol.size()<<"\n";
	for(it=sol.begin();it!=sol.end();it++)	cout<<(*it)<<"\n";
	return 0;
}