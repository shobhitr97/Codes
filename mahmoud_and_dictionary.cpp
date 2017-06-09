#include<iostream>
#include<map>
#include<vector>
#include<utility>
#include<stdio.h>
#include<cstdlib>
#include<algorithm>
#include<string>

using namespace std;

typedef vector< int> vec;
typedef vector< vector<int> > vvec;
typedef map<string,  int> mps;
typedef pair<int, int> pp;

#define ii insert
#define mp make_pair
#define pb push_back
#define for(a,b) for( int i=a ; i<b ; i++ )
#define num 100005

int n, m, q, par[num], val[num];
mps index;

//iterative function takes almost the same amount of time but does not evaluate the vlues and parents for those in paths
// pp find_in( int ind ){

// 	int i, x;

// 	i = ind;
// 	x = 0;
// 	while( par[i] != i ){
// 		x = (x + val[i])%2;
// 		i = par[i];
// 	}
// 	// val[ind] = x;
// 	// par[ind] =  
// 	return mp(i, x);
// }

int find_in(int ind){
	
	if( par[ind] == ind ){
		return val[ind];
	}

	val[ind] = (val[ind] + find_in(par[ind]))%2;
	par[ind] = par[ par[ind] ];
	return val[ind];

}

int main(){

	cin >> n >> m >> q;

	int i, x, ind1, ind2;
	string r, s;
	pp temp1, temp2;

	for(0,n){
		cin>> r;
		index.ii(mp(r,i));
		par[i] = i;
		val[i] = 0;
	}

	for(0,m){
		cin >> x >> r >> s;

		x = (x==2);

		ind1 = index[r];
		ind2 = index[s];

		temp1 = mp(0,0);
		temp2 = mp(0,0);

		temp1.second = find_in(ind1);
		temp2.second = find_in(ind2);
		temp1.first = par[ind1];
		temp2.first = par[ind2];

		// cout<<"\n";
		// cout<<r<<"---par1:"<<temp1.first<<" ;"<<"val1:"<<temp1.second<<"\n";
		// cout<<s<<"---par2:"<<temp2.first<<" ;"<<"val2:"<<temp2.second<<"\n";

		if( temp1.first != temp2.first ){
			cout<<"YES\n";
			// Observation : the value of val[temp_.first] must be 0 !
			if( temp2.second != val[temp2.first] ){
				val[temp2.first] = ( val[temp2.first] + temp1.second + x + 1)%2;
			}
			else{
				val[temp2.first] = ( val[temp2.first] + temp1.second + x)%2;
			}
			
			par[temp2.first] = temp1.first;
			
			par[ind1] = temp1.first;
			val[ind1] = temp1.second;

			par[ind2] = temp1.first;
			val[ind2] = (temp2.second + val[temp2.first])%2;

		}
		else{
			if( (temp2.second)^(temp1.second) == x ){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
		// temp1 = find_in(index[r]);
		// temp2 = find_in(index[s]);
		// cout<<"\n";
		// cout<<r<<"---par1:"<<temp1.first<<" ;"<<"val1:"<<temp1.second<<"\n";
		// cout<<s<<"---par2:"<<temp2.first<<" ;"<<"val2:"<<temp2.second<<"\n";

	}

	for(0,q){
		cin>>r>>s;
		
		ind1 = index[r];
		ind2 = index[s];

		temp1.second = find_in(ind1);
		temp2.second = find_in(ind2);
		temp1.first = par[ind1];
		temp2.first = par[ind2];

		if( temp1.first != temp2.first ){
			cout<<"3\n";
		}
		else{
			if( temp2.second^temp1.second ){
				cout<<"2\n";
			}
			else{
				cout<<"1\n";
			}
		}

	}

	

	return 0;
}
