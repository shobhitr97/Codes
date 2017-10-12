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
#define num 1005

int main(){
	int a[num], b[num], p[num], posa1, posb1, posa2, posb2, mis1, mis2, n, cnt[num], t1, t2;
	cin>>n;
	fori(0, 1001)	cnt[i]=0;
	fori(0, n)	cin>>a[i];
	fori(0, n)	cin>>b[i];
	fori(0, n)	cnt[ a[i] ]++;
	fori(1, n+1){
		if(cnt[i]==0)	mis1=i;
		if(cnt[i]==2)	t1=i;
	}
	int k=0;
	fori(0, n){
		if(a[i]==t1){
			if(k){
				posa2=i;
			}
			else{
				posa1=i;
				k++;
			}
		}
	}
	fori(0, n){
		p[i]=a[i];
	}
	fori(1, n+1)	cnt[i]=0;
	fori(0, n)	cnt[ b[i] ]++;
	fori(1, n+1){
		if(cnt[i]==0)	mis2=i;
		if(cnt[i]==2)	t2=i;
	}
	k=0;
	fori(0, n){
		if(b[i]==t2){
			if(k){
				posb2=i;
			}
			else{
				posb1=i;
				k++;
			}
		}
	}
	if(mis1==mis2){
		if(posa1==posb1)	p[posa1]=mis1;
		else{
			if(posa1==posb2)	p[posa1]=mis1;
			else{
				if(posa2==posb1)	p[posa2]=mis1;
				else{
					if(posa2==posb2)	p[posa2]=mis1;
				}
			}
		}
	}
	else{
		if(posa1==posb1&&posa2==posb2&&mis1==t2)	p[posa1]=t2;
		else{
			if(posa1!=posb1&&posa1!=posb2){
				if(a[posa1]==b[posa1]){
					p[posa2]=mis1;
				}
				else{
					p[posa1]=mis1;
				}
			}
			else{
				if(posa2!=posb1&&posa2!=posb2){
					if(a[posa2]==b[posa2]){
						p[posa1]=mis1;
					}
					else{
						p[posa2]=mis1;
					}
				}
			}
		}
	}
	fori(0, n)	cout<<p[i]<<" ";
	cout<<"\n";
	return 0;
}