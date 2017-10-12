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
	string qu;
	int n, k;
	map<int, int> ent, ext;
	map<int, int>::iterator it;
	cin>>n>>k;
	cin>>qu;
	int entry[27], exit[27];
	fori(0, 26)	entry[i]=n, exit[i]=-1;
	fori(0, n){
		entry[qu[i]-'A']=min(i, entry[qu[i]-'A']);
		exit[qu[i]-'A']=max(i, exit[qu[i]-'A']);
	}
	fori(0, 26){
		if(entry[i]<n){
			// cout<<entry[i]<<" "<<exit[i]<<"\n";
			ent[entry[i]]=1;
			ext[exit[i]]=1;
		}
	}
	int cnt=0;
	bool flag=false;
	fori(0, n){
		it=ent.find(i);
		if(it!=ent.end())	cnt++;
		if(cnt>k)	flag=true;
		it=ext.find(i);
		if(it!=ext.end())	cnt--;
		// cout<<cnt<<"\n";
	}
	if(flag==true)	cout<<"YES\n";
	else	cout<<"NO\n";
	return 0;
}