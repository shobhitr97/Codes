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

vector<pair<ll, ll> > horSnake, verSnake;

int main(){
	int t, currD, m;
	ll n, k, hx, hy, tx, ty, t1, t2, k1, k2, cntH, cntV;
	int currIndex;
	bool flag;
	cin>>t;
	while(t--){
		cin>>n>>k>>m;
		flag=true;
		t1=(n-k)/2+1;
		t2=(n+k)/2;
		k1=0;
		k2=0;
		fori(0, m){
			cin>>hx>>hy>>tx>>ty;
			if(hx==tx){
				if(hy<ty){
					ll temp=hy;
					hy=ty;
					ty=temp;
				}
				if(hx<t1||hx>t2){
					ty=max(ty, t1);
					hy=min(hy, t2);
					if(hy>=ty){
						horSnake.pb(mp(ty, hy-ty+1));
						k1++;
					}
				}
				else{
					verSnake.pb(mp(hx, 1));
					k2++;
				}
			}
			else{
				if(hx<tx){
					ll temp=hx;
					hx=tx;
					tx=temp;
				}
				if(hy<t1||hy>t2){
					tx=max(tx, t1);
					hx=min(hx, t2);
					if(hx>=tx){
						verSnake.pb(mp(tx, hx-tx+1));
						k2++;
					}
				}
				else{
					horSnake.pb(mp(hy, 1));
					k1++;
				}
			}
		}
		sort(horSnake.begin(), horSnake.end());
		sort(verSnake.begin(), verSnake.end());

		// cout<<k1<<" "<<k2<<"\n";

		currIndex=0;
		currD=t1;
		cntH=0;
		while(currIndex<k1&&currD<=t2){
			int temp;
			ll maxm;

			if(horSnake[currIndex].fi>currD){
				flag=false;
				break;
			}
			maxm=horSnake[currIndex].fi+horSnake[currIndex].se;

			temp=currIndex+1;
			while(temp<k1&&horSnake[temp].fi<=currD){
				if(horSnake[temp].fi+horSnake[temp].se>maxm){
					currIndex=temp;
					maxm=horSnake[temp].fi+horSnake[temp].se;
				}
				temp++;
			}
			// cout<<horSnake[currIndex].fi<<": "<<horSnake[currIndex].se<<"\n";
			// currD+=horSnake[currIndex].se;
			currD=maxm;
			currIndex++;
			cntH++;
		}
		// cout<<currD<<"\n";
		if(currD<=t2)	flag=false;

		currIndex=0;
		currD=t1;
		cntV=0;
		if(flag==true){
			while(currIndex<k2&&currD<=t2){
				int temp;
				ll maxm;

				if(verSnake[currIndex].fi>currD){
					flag=false;
					break;
				}
				maxm=verSnake[currIndex].fi+verSnake[currIndex].se;

				temp=currIndex+1;
				while(temp<k2&&verSnake[temp].fi<=currD){
					if(verSnake[temp].fi+verSnake[temp].se>maxm){
						currIndex=temp;
						maxm=verSnake[temp].fi+verSnake[temp].se;
					}
					temp++;
				}
				// cout<<verSnake[currIndex].fi<<": "<<verSnake[currIndex].se<<"\n";
				currD=maxm;
				currIndex++;
				cntV++;
			}
			// cout<<currD<<"\n";
			if(currD<=t2)	flag=false;
		}

		if(flag==true)	cout<<cntV+cntH<<"\n";
		else	cout<<"-1\n";

		horSnake.clear();
		verSnake.clear();
	}


	return 0;
}