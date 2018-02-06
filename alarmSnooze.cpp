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

bool check(int x){
	if(x%10 == 7 || x/10 == 7)	return true;
	else	return false;
}	

int main(){

	int x, h, m, t0, t1, t2;
	char ch[2], cm[2];

	cin>>x;
	cin>>ch[0]>>ch[1];
	cin>>cm[0]>>cm[1];

	h = (ch[0]-'0')*10+(ch[1] - '0');
	m = (cm[0]-'0')*10+(cm[1] - '0');

	t0 = h*60+m;

	fori(0, (24*60/x + 10)){
		h = t0/60;
		m = t0%60;
		if(check(h) == true || check(m) == true){
			cout<<i<<"\n";
			break;
		}
		if(t0 < x){
			t0 = 24*60 + t0-x;
		}
		else	t0 -= x;
	}

	return 0;
}