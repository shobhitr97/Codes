#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>

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
#define fi first
#define se second

int main(){
	int b, r, left, right , maxLeft, maxRight, maxNice, s;
	vi nice;
	cin>>b;
	forn(z, 1, b+1){
		cin>>r;
		fori(0, r-1){
			cin>>s;
			nice.pb(s);
		}
		maxNice=0;
		maxLeft=0;
		maxRight=-1;
		s=0;
		left=0;
		right=-1;
		fori(0, r-1){
			if(s+nice[i]<0){
				s=0;
				left=i+1;
				right=i;
				continue;
			}
			right++;
			s+=nice[i];
			if(s>maxNice||(s==maxNice&&(right-left)>(maxRight-maxLeft)))	maxRight=right, maxLeft=left, maxNice=s;
		}
		if(maxRight==-1)	printf("Route %d has no nice parts\n", z);
		else	printf("The nicest part of route %d is between stops %d and %d\n", z, maxLeft+1, maxRight+2);
		nice.clear();
	}


	return 0;
}