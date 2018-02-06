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

int h, a[num], n;
vector<vi> rel1, rel2;
vi par1, par2;
vector<bool> vis;

int main(){

	bool flag = true;

	cin>>h;
	fori(0, h+1)	cin>>a[i];

	fori(0, h+1){
		if(a[i] > 1 ){
			if(i>0 && a[i-1] > 1){
				flag = false;
				break;
			}
		}
	}

	if(flag == true){
		cout<<"perfect\n";
		return 0;
	}
	else	cout<<"ambiguous\n";

	n=0;
	fori(0, h+1)	n+=a[i];

	// rel1.resize(n);
	// rel2.resize(n);
	par1.resize(n);
	par2.resize(n);

	bool done = false;
	int cur, par, nextCur;

	// 0 is the root
	// par = 0;
	// cur = 0;
	cur = a[0];
	fori(1, h+1){
		par = cur - a[i-1];
		if(done == false){
			if(a[i] == 1 || a[i-1] == 1){
				forn(j, 0, a[i]){
					par1[cur + j ] = par;
					par2[cur + j ] = par;
				}
			}
			else{
				forn(j, 0, a[i]){
					par1[cur + j ] = par;
				}
				// cout<<"\t"<<cur<<" "<<par<<" "<<a[i]<<"\n";
				forn(j, 0, a[i]/2){
					par2[cur + j ] = par;
				}
				forn(j, a[i]/2, a[i]){
					par2[cur + j ] = par+1;
				}
				// forn(j, 0, n)	cout<<par2[j]<<" ";
				// cout<<"\n";
				done = true;
			}
		}
		else{
			forn(j, 0, a[i]){
				par1[cur + j] = par;
				par2[cur + j] = par;
			}
		}
		cur = cur + a[i];
	}

	cout<<"0";
	fori(1, n){
		cout<<" "<<(par1[i] + 1);
	}
	cout<<"\n";

	cout<<"0";
	fori(1, n){
		cout<<" "<<(par2[i] + 1);
	}
	cout<<"\n";

	return 0;
}