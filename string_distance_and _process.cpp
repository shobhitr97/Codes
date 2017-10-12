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

int dp[81][81], dir[81][81];

int calC(string s, string t){
	int s_len, t_len, opt[3];
	s_len=s.length();
	t_len=t.length();
	cout<<s_len<<" "<<t_len<<"\n";
	dp[0][0]=0;
	dir[0][0]=-1;
	fori(1, t_len){
		dp[0][i]=i;
		dir[0][i]=1;
	}
	fori(1, s_len){
		dp[i][0]=i;
		dir[i][0]=2;
	}
	forn(i, 1, s_len){
		forn(j, 1, t_len){
			opt[0]=dp[i-1][j-1]+ (s[i]==t[j] ? 0: 1);
			opt[1]=dp[i][j-1]+1;
			opt[2]=dp[i-1][j]+1;

			dp[i][j]=opt[0];
			dir[i][j]=0;
			forn(k, 0, 3){
				if(opt[k]<dp[i][j]){
					dp[i][j]=opt[k];
					dir[i][j]=k;
				}
			}
		}
	}
	forn(z, 0, s_len){
		forn(nn, 0, t_len)	cout<<dp[z][nn]<<" ";
		cout<<"\n";
	}
	return dp[s_len-1][t_len-1];
}
// int string_compare(char *s, char *t){ 
// 	int i, j, k; 
// 	int opt[3]; // cost of the tree option
// 	int s_len, t_len; 
// 	s_len = strlen(s); 
// 	t_len = strlen(t); // length boundary
// 	m[0][0] = 0; 
// 	p[0][0] = -1; 
// 	for(i=1; i<MAXLEN; ++i){ 
// 		m[0][i] = i; // source is empty, insert i times
// 		p[0][i] = 1; // mark insert operation
// 		m[i][0] = i; // target is empty, delete i times
// 		p[i][0] = 2; // mark delete operation
// 	}
 
// 	for(i=1; i<s_len; i++) {
// 		for(j=1; j<t_len; j++){ 
// 			opt[0] = m[i-1][j-1] + (s[i]==t[j] ? 0: 1); // match or substitute 
// 			opt[1] = m[i][j-1] + 1; // insert 
// 			opt[2] = m[i-1][j] + 1; // delete
 
// 			//m[i][j] = min(opt[0..2]) 
// 			m[i][j] = opt[0]; 
// 			p[i][j] = 0; 
// 			for(k=0; k<3; ++k){
// 				if(opt[k]<m[i][j]){ 
// 					m[i][j] = opt[k];
// 					p[i][j] = k; 
// 				} 
// 			}
// 		} 
// 	}
// 	return m[s_len-1][t_len-1]; 
// }

void backtracking(string s, string t){
	int i, j, k, len, u, v;
	char p[162];
	i=s.length()-1;
	j=t.length()-1;
	k=0;
	while(dir[i][j]!=-1){
		switch(dir[i][j]){
			case 0:	p[k++]=(s[i]==t[j])?'M':'S';	
					i--, j--;	
					break;
			case 1:	p[k++]='I';
					j--;
					break;
			case 2:	p[k++]='D';
					i--;
					break;
		}
	}
	fori(0, k)	cout<<p[i]<<" ";
	cout<<"\n";
	i=0; j=0;
	len=k, u=1, v=0;
	for(int l=k-1;l>=0;l--){
		switch(p[l]){
			case 'M':	i++, v++;
						break;
			case 'S':	printf("%d Replace %d,%c\n", u++, i+1, t[v]);
						i++, v++;
						break;
			case 'I':	printf("%d Insert %d,%c\n", u++, i+1, t[v]);
						i++, v++;	
						break;
			case 'D':	printf("%d Delete %d\n", u++, i+1);
						break;
		}
	}
}

int main(){
	string a, b;
	int t=0;
	while(cin>>a){
		if(t>0)	cout<<"\n";
		else	t++;
		cin>>b;
		cout<<calC(a, b)<<"\n";
		backtracking(a, b);
	}
	return 0;
}