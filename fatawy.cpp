#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>

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

vector<string> fatwa;
int parent[504];

int lcs(int i1, int i2, int len1, int len2){
	// if(len1==0||len2==0)	return 0;
	// if(fatwa[i1][len1-1]==fatwa[i2][len2-1])	return (1+lcs(i1, i2, len1-1, len2-1));
	// return max(lcs(i1, i2, len1, len2-1), lcs(i1, i2, len1-1, len2));
	int match[12][12];
	// forn(i, 0, len1){
	// 	forn(j, 0, len2)	match[i][j]=0;
	// }
	match[0][0]=(fatwa[i1][0]==fatwa[i2][0]);
	fori(1, len1){
		match[i][0]=match[i-1][0];
		if(fatwa[i1][i]==fatwa[i2][0])	match[i][0]=1;
	}
	fori(1, len2){
		match[0][i]=match[0][i-1];
		if(fatwa[i2][i]==fatwa[i1][0])	match[0][i]=1;
	}
	forn(i, 1, len1){
		forn(j, 1, len2){
			if(fatwa[i1][i]==fatwa[i2][j])	match[i][j]=match[i-1][j-1]+1;
			else	match[i][j]=max(match[i-1][j], match[i][j-1]);
		}
	}
	return match[len1-1][len2-1];
}

int findParent(int x){
	if(parent[x]!=x)	parent[x]=findParent(parent[x]);
	return parent[x];
}

int main(){
	int t, n, len, u, v, sz[504], cnt;
	double th, x1, x2;
	string str;
	cin>>t;
	forn(z, 1, t+1){
		cin>>n>>th;
		fori(0, n){
			cin>>str;
			fatwa.pb(str);
		}
		fori(0, n)	parent[i]=i;
		fori(0, n)	sz[i]=1;
		forn(i, 0, n){
			forn(j, i+1, n){
				len=lcs(i, j, fatwa[i].length(), fatwa[j].length());
				x1=((double)len/fatwa[i].length());
				x2=((double)len/fatwa[j].length());
				// cout<<i<<","<<j<<" :"<<len<<" - "<<x1<<" "<<x2<<"\n";
				x1*=100.0;
				x2*=100.0;
				if(x1>=th&&x2>=th){
					// cout<<i<<","<<j<<" :"<<len<<" - "<<x1<<" "<<x2<<"\n";
					u=findParent(i);
					v=findParent(j);
					if(u!=v){
						sz[v]+=sz[u];
						sz[u]=0;
						parent[u]=v;
					}
				}
			}
		}
		// fori(0, n)	cout<<sz[i]<<" ";
		// cout<<"\n";
		cnt=0;
		fori(0, n){
			if(sz[i])	cnt++;
		}
		printf("Case #%d:\n", z);
		cout<<cnt<<"\n";
		fatwa.clear();
	}
	return 0;
}