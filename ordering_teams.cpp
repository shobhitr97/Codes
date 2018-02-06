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
	vector<vi>skills;
	int t, cnt;
	cin>>t;

	skills.resize(3);
	forn(i, 0, 3)	skills[i].resize(3);
	while(t--){
		forn(i, 0, 3){
			forn(j, 0, 3)	cin>>skills[i][j];
		}
		sort(skills.begin(), skills.end());

		bool flag=true;
		forn(i, 0, 2){
			cnt=0;
			forn(j, 0, 3){
				if(skills[i][j]>skills[i+1][j])	flag=false;
				else{
					if(skills[i][j]<skills[i+1][j])	cnt++;
				}
			}
			if(cnt==0)	flag=false;
			if(flag==false)	break;
		}
		if(flag==false)	cout<<"no\n";
		else	cout<<"yes\n";
	}
	return 0;
}