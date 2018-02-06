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
#define MOD 941083987

map < int, int > hsh[2];
ll hb[2], he[2], powA[2][2005], prefix[2][2005];
int lt, lb, le;
string t, sb, se;
vi b, e;
int mod[2];

ll hashS(string &s, int l, int r, int c){
	ll ans = 0;
	forin(r, l){
		ans = ( ans + (powA[c][r-i]*(s[i]-'a'+1))%mod[c] )%mod[c];
	}
	return ans;
}

void fillhshVec(vi &x, int len, ll target[]){
	ll val[2], pw[2];

	fori(0, 2)	pw[i] = powA[i][len-1];
	fori(0, 2)	val[i] = hashS(t, 0, len-1, i);

	int tLen = t.length();

	if(val[0] == target[0] && val[1] == target[1])	x.pb(0);

	fori(1, tLen - len+1){
		forn(j, 0, 2)	val[j] = (((( val[j] - ((t[i-1]-'a'+1)*pw[j])%mod[j] + mod[j] )%mod[j] )*31 )%mod[j] + (t[i+len-1]-'a'+1) )%mod[j];
		if(val[0] == target[0] && val[1] == target[1])	x.pb(i);
	}
}

int binSearch(vi &x, int target){
	int l, r, mid;
	l = 0;
	r = x.size()-1;
	while(l<=r){
		mid = (l+r)/2;
		if(x[mid] >= target)	r = mid-1;
		else	l = mid+1;
	}
	return l;
}

void populate(){
	fori(0, 2)	memset(powA[i], -1, sizeof(powA[i]));

	ll pw[2] = {1, 1};

	forn(j, 0, 2){
		fori(0, 2001){
			powA[j][i] = pw[j];
			pw[j] = (pw[j]*31)%mod[j];
		}
	}

	fori(0, 2)	prefix[i][0] = (t[0]-'a'+1);
	forn(j, 0, 2){
		fori(1, lt){
			prefix[j][i] = ( (prefix[j][i-1]*31)%mod[j] + (t[i]-'a'+1) )%mod[j];
		}
	}
}

void printVec(vi &x){
	int len = x.size();
	fori(0, len)	printf("%d ", x[i]);
	printf("\n");
}

int main(){

	mod[0] = 941083987;
	mod[1] = 982451653;

	int index, cnt;
	ll val[2], tmp[2];
	map<int, int>::iterator it[2];
	bool flag = false;

	cin>>t>>sb>>se;

	lt = t.length();
	lb = sb.length();
	le = se.length();

	populate();

	fori(0, 2){
		hb[i] = hashS(sb, 0, lb-1, i);
		he[i] = hashS(se, 0, le-1, i);
	}

	// cout<<hb<<" "<<he<<"\n";

	fillhshVec(b, lb, hb);
	fillhshVec(e, le, he);

	// printVec(b);
	// printVec(e);

	cnt = 0;
	fori(0, b.size()){
		index = binSearch(e, b[i]);
		if(b[i] > 0){
			forn(j, 0, 2)	val[j] = prefix[j][b[i]-1];
		}
		else{
			forn(j, 0, 2)	val[j] = 0;
		}
		forn(j, index, e.size()){
			if(e[j]+le-1 < b[i]+lb-1)	continue;
			forn(c, 0, 2){
				tmp[c] = (prefix[c][ e[j] + le - 1 ] - (val[c]*powA[c][e[j]-b[i]+le])%mod[c] + mod[c])%mod[c];
				it[c] = hsh[c].find(tmp[c]);
			}
			if(it[0] == hsh[0].end() && it[1] == hsh[1].end()){
				hsh[0].insert(mp(tmp[0], 1));
				hsh[1].insert(mp(tmp[1], 1));
				cnt++;
			}
		}
	}

	cout<<cnt<<"\n";

	return 0;
}