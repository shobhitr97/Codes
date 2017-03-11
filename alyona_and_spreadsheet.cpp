#include<iostream>
#include<vector>

using namespace std;

typedef long long int ll;
typedef vector< ll > vecl;
typedef vector< int > vec;
typedef vector <vector <ll> > vvecl;
typedef vector <vector <int> > vvec;

int max(int a, int b){
	if( a>b ){
		return a;
	}
	return b;
}

int main(){

	vvecl data;
	vvec bin_data;
	int n,m,i,j,p,q,l,r;
	vec fin_data;

	cin>>n>>m;

	bin_data.resize(n+2);
	data.resize(n+2);
	fin_data.resize(n+2);

	for( i=0 ; i<n ; i++ ){
		data[i].resize(m+2);
		bin_data[i].resize(m+2);

		for( j=0 ; j<m ; j++ ){
			cin>>data[i][j];
			// cout<<data[]
		}
	}

	for( i=0 ; i<m ; i++ ){
		
		p=0;
		for( j=0 ; j < n ; j++ ){

			p++;
			bin_data[j][i] = p;

			if( j<(n-1) && data[j][i] > data[j+1][i] ){
				p=0;
			}
		}
	}

	int Max;

	for( i=0 ; i<n ; i++ ){
		Max = 0;
		for( j=0 ; j<m ; j++ ){
			Max = max(Max, bin_data[i][j]);
		}
		fin_data[i] = Max;
		// cout<<fin_data[i]<<"\n";
	}



	int k;
	cin>>k;

	for( i=0 ; i<k ; i++ ){
		cin>>l>>r;
		if(fin_data[r-1] >= (r-l+1) ){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}

	return 0;
}