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
#define num 105

double dp[num][num][num];
int R, S, P;

int main(){
	cin>>R>>S>>P;
	int r, s, p, cnt[num][num][num];
	double a1, a2, a3;
	forn(i, 0, R+1)	forn(j, 0, S+1)	forn(k, 0, P+1)	dp[i][j][k]=0.000000, cnt[i][j][k]=0;
	dp[R][S][P]=1.0000000;
	cnt[R][S][P]=1;
	queue<pair<int, ii> >q;
	q.push(mp(R, mp(S, P)));
	while(!q.empty()){
		r=q.front().fi;
		s=q.front().se.fi;
		p=q.front().se.se;
		q.pop();
		if(cnt[r][s][p]>1){
			cnt[r][s][p]--;
			continue;
		}
		cnt[r][s][p]--;
		// cout<<r<<" "<<s<<" "<<p<<"\n";
		if(!(r*s||r*p||p*s))	continue;
		double den=(double)(r*s+s*p+r*p);
		if(r>=1){
			dp[r-1][s][p]+=(dp[r][s][p]*(double)(((double)(r*p))/den));
			q.push(mp(r-1, mp(s, p)));
			cnt[r-1][s][p]++;
		}
		if(s>=1){
			dp[r][s-1][p]+=(dp[r][s][p]*(double)(((double)(s*r))/den));
			q.push(mp(r, mp(s-1, p)));
			cnt[r][s-1][p]++;
		}
		if(p>=1){
			dp[r][s][p-1]+=(dp[r][s][p]*(double)(((double)(p*s))/den));
			q.push(mp(r, mp(s, p-1)));
			cnt[r][s][p-1]++;
		}
	}

	a1=0.0, a2=0.0, a3=0.0;
	fori(1, R+1)	a1+=dp[i][0][0];
	fori(1, S+1)	a2+=dp[0][i][0];
	fori(1, P+1)	a3+=dp[0][0][i];
	printf("%.12f %.12f %.12f\n", a1, a2, a3);
	return 0;
}