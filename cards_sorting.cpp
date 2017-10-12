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
#define num 100005

int binSearch(vi vec, int ele){
	int siz, l, r, mid, ans;
	siz=vec.size();
	l=0, r=siz-1;
	while(l<=r){
		mid=(l+r)/2;
		if(vec[mid]<ele)	l=mid+1;
		else	r=mid-1;
	}
	return l;
}

int main(){
	int n, arr[num], coef, siz, last, tmp;
	ll ans;
	vector<vi>pos;
	pos.resize(num-4);
	
	cin>>n;
	fori(0, n)	cin>>arr[i];

	fori(0, n)	pos[arr[i]].pb(i);
	// fori(0, 100001){
	// 	if(pos[i].empty())	continue;
	// 	// sort(pos[i].begin(), pos[i].end());
	// 	cout<<i<<":"<<pos[i].size()<<" ";
	// }
	// cout<<"\n";
	coef=1, siz=0, last=-1, ans=0;
	fori(0, 100001){
		if(pos[i].empty())	continue;
		tmp=pos[i].size();
		if(pos[i][0]>last){
			siz+=tmp;
			last=max(last, pos[i][tmp-1]);
			// cout<<i<<":"<<tmp<<"\n";
		}
		else{
			int cur=binSearch(pos[i], last);
			// cout<<i<<" "<<cur<<"\n";
			siz+=(tmp-cur);
			// cout<<i<<":"<<(tmp-cur)<<" -> ";
			ans+=(coef*siz);
			// cout<<coef<<","<<siz<<"\n";
			coef++;
			siz=cur;
			// cout<<i<<":"<<tmp<<"\n";
			if(siz>0)	last=pos[i][siz-1];
			else	last=-1;
		}
	}
	ans+=(coef*siz);
	cout<<ans<<"\n";
	return 0;
}