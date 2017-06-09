#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<utility>

using namespace std;

typedef long long int ll;
typedef vector<int> vec;
typedef vector< vector<int> > vvec;
typedef vector<ll> vecl;
typedef vector< vector<ll> > vvecl;

vecl b, a, h;
map <ll,ll> mp1, mp2;
map<ll,int> mp;

ll min( ll a, ll b){
	if( a < b ){
		return a;
	}
	return b;
}

int main(){

	int n, i, j, index[100005];
	ll s, l, prev, temp_a, hl, H;
	vecl new_b, arr;
	cin>>n;

	for( i=0 ; i<n ; i++ ){

		cin>>s>>l>>hl;

		b.push_back(l);

		mp1.insert(make_pair(l,s));
		mp2.insert(make_pair(l,h));

	}

	a.clear();
	h.clear();

	b.sort(b.begin(), b.end() );

	vecl::iterator it;

	prev = b[0];
	temp_a = mp1[prev];
	H = 0;
	// i=0;
	for( it = b.begin() ; it != b.end() ; it++ ){

		if( prev == *it ){
			temp_a = min( temp_a, mp1[ *it ] );
			H += mp2[ *it ];
			continue;
		}

		a.push_back( temp_a );
		new_b.push_back( prev );
		h.push_back(H);
		// mp.push_back(temp_a, i);
		arr.push_back( temp_a );
		arr.push_back( prev );
		// i++;

		prev = *it;
		temp_a = mp1[ *it ];
		H = mp2[*it];
	
	}

	b.clear();
	arr.sort(arr.begin(), arr.end() );


	return 0;
}