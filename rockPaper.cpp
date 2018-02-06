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

	vector<vi> rel;

	rel.resize(5);

	rel[2].pb(1);
	rel[1].pb(0);
	rel[0].pb(4);
	rel[4].pb(3);
	rel[3].pb(2);
	rel[2].pb(4);
	rel[4].pb(1);
	rel[1].pb(3);
	rel[3].pb(0);
	rel[0].pb(2);

	int t;
	string s1, s2;
	string s[]= {"rock", "paper", "scissors", "sun", "moon" };

	cin>>t;

	forn(k, 0, t){
		
		cin>>s1>>s2;

		int siz, winner = (-1), i1 =0,  i2 = 0;
		while(i1<5 && s[i1] != s1)	i1++;
		while(i2<5 && s[i2] != s2)	i2++;

		// cout<<(i1+1)<<" "<<(i2+1)<<"\n";

		siz = rel[i1].size();

		fori(0, siz){
			if( rel[i1][i] == i2){
				winner = 0;
				break;
			}
		}

		if(winner == -1){
			siz = rel[i2].size();

			fori(0, siz){
				if(rel[i2][i] == i1){
					winner = 1;
					break;
				}
			}
		}

		switch(winner){
			case 0:cout<<"akira\n";break;
			case 1:cout<<"hideki\n";break;
			default:cout<<"drew\n";break;
		}
	}

	return 0;
}