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
#define num 100005

int n, ans;
ll S, a[num];

ll find_ans(int number){
	vector<ll> arr;
	fori(1, n+1)	arr.pb(a[i]+(ll)number*i);
	sort(arr.begin(), arr.end());
	ll cost=0;
	fori(0, number)	cost+=arr[i];
	return cost;
}
	
int main(){
	int l, r, mid;
	bool flag;
	ll temp;
	cin>>n>>S;
	fori(1, n+1)	cin>>a[i];
	if(find_ans(1)>S){
		cout<<"0 0\n";
		return 0;
	}
	if(find_ans(n)<=S){
		cout<<n<<" "<<find_ans(n)<<"\n";
		return 0;
	}
	l=1;
	r=n-1;
	while(l<=r){
		mid=(l+r)/2;
		temp=find_ans(mid);
		flag=(temp<=S);
		if(flag==true)	ans=mid, l=mid+1;
		else	r=mid-1;
	}
	cout<<ans<<" "<<find_ans(ans)<<"\n";
	return 0;
}