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
#define num 52

int main(){
	ll sum[num][num], product[num][num], arr[num];
	int t, n, cnt;
	cin>>t;
	while(t--){
		cin>>n;
		fori(0, n)	cin>>arr[i];
		forn(i, 0, n){
			forn(j, 0, n){
				sum[i][j]=0;
				product[i][j]=1;
			}
		}
		forn(i, 0, n){
			sum[i][i]=arr[i];
			product[i][i]=arr[i];
		}
		forn(i, 0, n){
			forn(j, i+1, n){
				sum[i][j]=sum[i][j-1]+arr[j];
				product[i][j]=product[i][j-1]*arr[j];
			}
		}
		cnt=0;
		forn(i, 0, n){
			forn(j, i, n){
				if(sum[i][j]==product[i][j])	cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}