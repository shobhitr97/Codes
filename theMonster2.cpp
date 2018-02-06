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

	string s;

	cin>>s;

	int ans = 0;
	int canTurn, openBrackets, len = s.length();
	fori(0, len){
		openBrackets=0;
		canTurn=0;
		forn(j, i, len){
			if( s[j] == '(' )	openBrackets++;
			else if(s[j] == ')'){
				if(openBrackets)	openBrackets--;
				else if(canTurn){
					canTurn--;
					openBrackets++;
				}
				else	break;
			}
			else{
				if(openBrackets){
					openBrackets--;
					canTurn++;
				}
				else	openBrackets++;
			}
			if(openBrackets == 0)	ans++;
		}
	}

	cout<<ans<<"\n";

	return 0;
}