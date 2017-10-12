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
	int k, len;
	cin>>s;
	cin>>k;
	int arr[26], cnt;
	len=s.length();
	if(k>len){
		cout<<"impossible\n";
		return 0;
	}
	fori(0, 26)	arr[i]=0;
	fori(0, len){
		arr[s[i]-'a']++;
	}
	cnt=0;
	fori(0, 26){
		if(arr[i])	cnt++;
	}
	if(cnt>=k)	cout<<"0\n";
	else	cout<<(k-cnt)<<"\n";
	return 0;
}