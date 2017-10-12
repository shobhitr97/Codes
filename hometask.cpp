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
	string s;
	int n, blocked[27], ans=0, cnt, cnt2;
	char c1, c2, ch;
	cin>>s>>n;
	fori(0, 26)	blocked[i]=-1;
	fori(0, n){
		cin>>c1>>c2;
		blocked[c1-'a']=c2-'a';
		blocked[c2-'a']=c1-'a';
	}
	// fori(0, 26)	cout<<(char)('a'+i)<<" "<<(char)('a'+blocked[i])<<"\n";
	int i=0, len=s.length();
	while(i<len){
		cnt=0, cnt2=0;
		ch=s[i];
		if(blocked[ch-'a']==-1){
			// cout<<"No removed from : "<<i+1<<"\n";
			i++;
			continue;
		}
		// cout<<i<<" - ";
		while(i<len&&(s[i]==ch||s[i]-'a'==blocked[ch-'a'])){
			if(s[i]-'a'==blocked[ch-'a'])	cnt2++;
			cnt++;
			i++;
		}
		// cout<<i-1<<"\n";
		ans+=min(cnt2, cnt-cnt2);
	}
	cout<<ans<<"\n";
	return 0;
}