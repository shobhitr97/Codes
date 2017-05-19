#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

typedef long long int ll;

#define INF 1000000007
#define fori(a, b) for( int i=a ; i<b ; i++ )

int main(){

	int t, n, r, u, v, s, d, p;
	ll adjMat[103][103], ans;

	cin>>t;

	p=1;
	while(t--){	
		cin>>n;

		fori(0, n){
			for(int j=0 ; j<n ; j++ ){
				adjMat[i][j] = INF;
				if( i==j ){
					adjMat[i][j] = 0;
				}
			}
		}

		cin>>r;
		fori(0, r){
			cin>>u>>v;
			adjMat[u][v] = 1;
			adjMat[v][u] = 1;
		}
		cin>>s>>d;

		fori(0, n){
			for(int j=0 ; j<n ; j++ ){
				for(int k=0 ; k<n ; k++ ){
					adjMat[j][k] = min(adjMat[j][k], adjMat[j][i] + adjMat[i][k] );
				}
			}
		}

		ans = 0;
		fori(0, n){
			ans = max(ans, adjMat[s][i] + adjMat[i][d] );
		}

		cout<<"Case "<<p<<": "<<ans<<"\n";
		p++;

	}

	return 0;
}