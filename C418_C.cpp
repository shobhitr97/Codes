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
#define num 1503

int main(){
	int n, q, cnt[27][num], cal[27][num], len, t;
	char ch[num], pp;
	cin>>n;
	fori(1, n+1)	cin>>ch[i];
	fori(0, 26)	forn(j, 0, n+1)	cnt[i][j]=0, cal[i][j]=j;
	fori(1, n+1)	cnt[ch[i]-'a'][i]=1;
	fori(0, 26){
		forn(j, 1, n+1){
			cnt[i][j]+=cnt[i][j-1];
		}
	}
	// fori(0, 26){
	// 	forn(j, 1, n+1)	cout<<cnt[i][j]<<" ";
	// 	cout<<"\n";
	// }
	// cout<<"\n";
	fori(2, n+1){
		forn(j, 0, n-i+1){
			forn(k, 0, 26){
				cal[k][i-(cnt[k][j+i]-cnt[k][j])]=max(cal[k][i-(cnt[k][j+i]-cnt[k][j])], i);
			}
		}
	}
	// fori(0, 26){
	// 	forn(j, 1, n+1)	cout<<cal[i][j]<<" ";
	// 	cout<<"\n";
	// }
	forn(i, 0, 26){
		int maxm=cal[i][0];	
		forn(j, 1, n+1){
			maxm=max(maxm, cal[i][j]);
			cal[i][j]=maxm;
		}
	}
	cin>>q;
	fori(0, q){
		cin>>t>>pp;
		cout<<cal[pp-'a'][t]<<"\n";
	}
	return 0;
}