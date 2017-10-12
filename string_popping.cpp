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

bool isReducible(string s){
	if(s.empty()==1)	return true;
	int len=s.length();
	// if(len==0)	return true;
	bool val=false;
	for(int i=0, j;i<len;i++){
		for(j=i; j<len&&s[j]==s[i]; j++){
			if(j-i>=1)	val|=isReducible(s.substr(0, i)+s.substr(j+1));
		}
		i=j-1;
		if(val==true)	break;
	}
	return val;
}

int main(){
	int t;
	bool flag;
	string s;
	cin>>t;
	fori(0, t){
		cin>>s;
		// cout<<s.substr(s.length())<<"\n";
		flag=isReducible(s);
		if(flag==true)	cout<<"1\n";
		else	cout<<"0\n";
	}
	return 0;
}