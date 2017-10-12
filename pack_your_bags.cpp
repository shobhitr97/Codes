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
#define fi first
#define se second
#define INF 1000000007
#define num 200005

int n, x;
vector<vector<pair<int, ll> > >arr;
vector<vector<ll> > minPre, minPost;

int bSearchL(int rightI, int pos){
	int l, r, mid, ans=-1;
	l=0;
	r=arr[pos].size()-1;
	while(l<=r){
		mid=(l+r)/2;
		if(arr[pos][mid].fi>rightI){
			ans=mid;
			r=mid-1;
		}
		else	l=mid+1;
	}
	return ans;
}

int bSearchR(int leftI, int pos){
	int l, r, mid, ans=-1;
	l=0;
	r=arr[pos].size()-1;
	while(l<=r){
		mid=(l+r)/2;
		if(arr[pos][mid].fi+(x-pos)-1<leftI){
			ans=mid;
			l=mid+1;
		}
		else	r=mid-1;
	}
	return ans;
}

void createM(int pos){
	int siz=arr[pos].size();

	minPre[pos].resize(siz+2);
	minPost[pos].resize(siz+2);

	minPre[pos][0]=arr[pos][0].se;
	minPost[pos][siz-1]=arr[pos][siz-1].se;

	fori(1, siz)	minPre[pos][i]=min(arr[pos][i].se, minPre[pos][i-1]);
	forin(siz-2, 0)	minPost[pos][i]=min(arr[pos][i].se, minPost[pos][i+1]);
}

int main(){
	int u, v;
	ll w, minM=1000000000007;
	vi consider;
	cin>>n>>x;
	arr.resize(num+2);
	minPost.resize(num+2);
	minPre.resize(num+2);
	fori(0, n){
		cin>>u>>v>>w;
		arr[v-u+1].pb(mp(u, w));
	}
	fori(0, num){
		if(arr[i].empty())	continue;
		consider.pb(i);
		sort(arr[i].begin(), arr[i].end());
	}
	for(vi::iterator it=consider.begin();it!=consider.end();it++){
		if((double)(*it)>(double)x/2.0)	break;
		int indexL, indexR, p=(*it);
		if(arr[x-p].empty())	continue;
		createM(p);
		createM(x-p);
		fori(0, arr[p].size()){
			ll minm=INF;
			indexL=bSearchL(arr[p][i].fi+p-1, x-p);
			if(indexL!=-1){
				minm=min(minm, minPost[x-p][indexL]);
			}
			indexR=bSearchR(arr[p][i].fi, x-p);
			if(indexR!=-1){
				minm=min(minm, minPre[x-p][indexR]);
			}
			if(minm!=INF)	minM=min(minM, arr[p][i].se+minm);
		}
	}
	if(minM==1000000000007)	cout<<"-1\n";
	else	cout<<minM<<"\n";
	return 0;
}

// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<utility>
// #include<stdio.h>
// #include<set>
// #include<map>
// #include<cmath>
// #include<queue>
// #include<stack>

// using namespace std;

// typedef long long int ll;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef pair<int, int> ii;
// typedef vector<ii> vii;
// typedef pair<int, ii> iii;
// typedef vector<iii> viii;
// typedef set<int> si;

// #define pb push_back
// #define mp make_pair
// #define fori(a, b) for(int i=a ; i<b ; i++ )
// #define forn(i, a, b) for(int i=a ; i<b ; i++ )
// #define forin(a, b) for(int i=a ; i>=b ; i-- )
// #define fi first
// #define se second
// #define INF 1000000007

// int main(){
// 	int n, x, u, v;
// 	vector<pair<pair<int , int>, pair<int , ll> > >consider;
// 	ll w, minCost[200005], ans=2000000002;
// 	cin>>n>>x;
// 	fori(0, n){
// 		cin>>u>>v>>w;
// 		consider.pb(mp(mp(u, 0), mp(v, w)));
// 		consider.pb(mp(mp(v, 1), mp(u, w)));
// 	}
// 	fori(0, x+2)	minCost[i]=2*INF;
// 	sort(consider.begin(), consider.end());
// 	fori(0, consider.size()-1){
// 		int dur, type=consider[i].fi.se;
// 		if(type==0){
// 			dur=consider[i].se.fi - consider[i].fi.fi+1;
// 			if(dur<=x){
// 				ans=min(ans, consider[i].se.se+minCost[x-dur]);
// 			}
// 		}
// 		else{
// 			dur=consider[i].fi.fi-consider[i].se.fi+1;
// 			minCost[dur]=min(minCost[dur], consider[i].se.se);
// 		}
// 	}
// 	if(ans>=2000000002)	cout<<"-1\n";
// 	else	cout<<ans<<"\n";
// 	return 0;
// }