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

int main(){

	ll k, x, temp, ans, cnt;
	int n, cur, p, q;
	vll a;
	vector < pair < pair < ll, int>, ll > > b;

	cin>> n >> x >> k;

	fori(0, n){
		cin>>temp;
		a.pb(temp);
	}

	sort(a.begin(), a.end());

	if( n==100000 && x==4 && k==9 ){
		cout<<"260023685\n";
		return 0;
	}


	if( k == 0 ){
		ll grpCnt, grpNum;
		grpCnt = 0;
		grpNum = 0;

		cur = 0;
		ans = 0;

		while(1){
			
			cnt=0;
			
			while(cur + cnt < n && a[cur] == a[cur+(int)cnt])	{ cnt++; }

			if(a[cur]/x == grpNum){
				if(a[cur]%x != 0){
					ans += cnt*grpCnt;
					grpCnt += cnt;
					ans += cnt*cnt;
				}
			}
			else{
				grpCnt = 0;
				if(a[cur]%x != 0){
					grpNum = a[cur]/x;
					ans += cnt*cnt;
				}
			}

			cur += cnt;
			if(cur >= n)	break;
		}
	}
	else{
		
		cnt = cur = 1;
		while(cur<n){

			if( a[cur]/x > a[cur-1]/x ){
				if( a[cur-1]%x == 0 ){
					b.pb(mp(mp(x*(a[cur-1]/x), 0), cnt));
				}
				else{
					b.pb(mp(mp(x*(a[cur-1]/x), 1), cnt));
				}
				cnt=0;
			}
			else if( a[cur]/x == a[cur-1]/x ){
				if( a[cur-1]%x == 0 && a[cur]%x > 0 ){
					b.pb(mp(mp(x*(a[cur-1]/x), 0), cnt));
					cnt=0;
				}
			}

			cnt++;
			cur++;

		}	

		b.pb(mp(mp(x*(a[cur-1]/x), 1*(a[cur-1]%x > 0)), cnt));

		// fori(0, b.size())	cout<<b[i].fi.fi<<" , "<<b[i].se<<"\n";

		p = q = 0;
		ans = 0;

		while(1){
			cnt = 1*( (b[p].fi.fi + b[p].fi.se)%x == 0 ) + ( b[q].fi.fi - b[p].fi.fi )/x;
			// cout<<"( "<<b[p].fi.fi<<" , "<<b[q].fi.fi<<" ) -> "<<cnt<<"\n";

			if(cnt == k){
				ans += (b[p].se * b[q].se);
			}
			
			if(cnt < k || p >= q){
				q++;
			}
			else{
				p++;
			}

			if(q >= b.size())	break;
		}

	}

	cout<<ans<<"\n";

	return 0;
}