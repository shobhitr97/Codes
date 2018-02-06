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
	int cnt=0, i, len;
	bool flag=false;
	string s;
	cin>>s;
	len=s.length();
	i=len-1;
	while(i>=0){
		if(s[i]=='0')	cnt++;
		if(cnt==6)	break;
		i--;
	}
	if(i<0)	cout<<"no\n";
	else{
		while(i>=0){
			if(s[i]=='1'){
				flag=true;
				break;
			}
			i--;
		}
		if(flag==true&&s[i]=='1')	cout<<"yes\n";
		else	cout<<"no\n";
	}
	return 0;
}