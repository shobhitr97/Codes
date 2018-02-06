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
	string s, t;
	int T, i, j, slen, tlen, a, b;
	bool flag;

	cin>>T;

	forn(pp, 0, T){
		cin>>s>>t;
		flag=true;
		slen=s.length();
		tlen=t.length();

		i=0, j=0;
		while(i<slen&&j<tlen){
			if(s[i]!=t[j]){
				flag = false;
				break;
			}
			a=i+1;
			while(a+1<slen){
				if(s[a+1]!=s[a])	break;
				a++;	
			}
			b=j+1;
			while(b+1<tlen){
				if(t[b+1]!=t[b])	break;
				b++;
			}
			if(b-j<a-i){
				flag=false;
				break;
			}
			j=b, i=a;
		}
		if(i<slen||j<tlen)	flag=false;
		if(flag==true)	cout<<"Yes\n";
		else	cout<<"No\n";
	}
	return 0;
}