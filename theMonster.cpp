#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>

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
#define NUM 5005

int main(){
	int val[NUM];
	bool flag[NUM];
	string s;
	int len, cnt;

	cin>>s;

	memset(val, -1, sizeof(val));
	memset(flag, false, sizeof(flag));
	len = s.length();

	cnt = 0;
	fori(1, len){
		if( s[i] == '(' ){
			continue;
		}
		fornn(j, i-1, 0)	flag[j] = false;
		fornn(j, i-1, 0){
			if(s[j] == '(' || s[j] == '?'){
				if(j == (i-1)){
					cnt++;
					flag[j] = true;
				}
				else{
					if(s[j+1] == '(' && val[j+1] == (i-1)){
						cnt++;
						flag[j] = true;
					}
					if(val[j] != (-1) && (val[j] + 1) < i && flag[val[j]+1] == true){
						cnt++;
						// cout<<(j+1)<<","<<(i+1)<<"\n";
						flag[j] = true;
					}
				}
			}
		}
		fornn(j, i-1, 0){
			if(flag[j] == true)	val[j] = i;
		}
	}

	cout<<cnt<<"\n";


	return 0;
}