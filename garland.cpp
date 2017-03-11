#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

typedef vector < vector <int> > vvec;
typedef vector < int  > vec;

#define N 1000007

vvec rel;
int n,a[N],t[N],s[N];

bool vis[N];

int val

void dfs(int index){
	if(vis[index]){
		return ;
	}
	vis[index] =1 ;
	s[index] = t[index];
	vec::iterator it;
	for( it = rel[index].begin() ; it != rel[index].end() ; it++ ){
		if(vis[*it]){
			continue;
		}
		dfs(*it);
		s[index] += s[*it]
	}

}

int main(){

	int i,root,sum,sum1,sum2;

	cin>>n;

	rel.resize(n+2);

	sum = 0;

	for( i=1 ; i<=n ; i++ ){
		cin>>a[i]>>t[i];

		sum += t[i];

		if( a[i] ){
			rel[ a[i] ].push_back(i);
		}
		else{
			root = i;
		}
		vis[i] = 0;
	}

	if(sum%3){
		cout << "-1\n";
		return 0;
	}

	sum1 = sum/3;
	sum2 = 2*sum1;

	dfs(root);

	return 0;
}