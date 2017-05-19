#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<stdio.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, int> li;
typedef set<li> sli;
typedef vector<int> vi;
typedef vector<sli> vsli;
typedef vector<ll> vl;

#define pb push_back
#define mp make_pair
#define INF 1000000007
#define fori(a, b) for(int i=a ; i<b ; i++ )

vsli front;
vsli back;
vl prices;
vi frontColor, backColor;

int main(){

	int n, a, b, m;
	ll x;
	vi input;

	cin>>n;

	fori(0, n){
		cin>>x;
		prices.pb(x);
	}

	front.resize(5);
	back.resize(5);

	fori(0, n){
		cin>>a;
		// cout<<".."
		frontColor.pb(a);
		front[a].insert( mp(prices[i], i) );
		// cout<<".";
	}

	fori(0, n){
		cin>>b;
		backColor.pb(b);
		back[b].insert( mp(prices[i], i) );
	}

	// fori(0, n){
	// 	cout<<frontColor[i]<<" "<<backColor[i]<<"\n";
	// }

	cin>>m;

	fori(0, m){
		cin>>a;
		input.pb(a);
	}

	ll minm;
	int j;
	fori(0, m){
		// cout<<input[i]<<"\n";
		minm =INF;
		if( front[ input[i] ].empty() == 0 ){
			minm = min(minm, ( *( front[ input[i] ].begin() ) ).first );
		}
		if( back[ input[i] ].empty() == 0 ){
			minm =	 min(minm, ( *( back[ input[i] ].begin() ) ).first );
		}

		if( minm == INF ){
			cout<<"-1 ";
			continue;
		}
		cout<<minm<<" ";
		if( minm == ( *( front[ input[i] ].begin() ) ).first ){
			j = ( *( front[ input[i] ].begin() ) ).second;
			// cout<<( *( front[ input[i] ].begin() ) ).first<<"\n";
			// cout<<( *( front[ input[i] ].begin() ) ).second<<"\n";
			front[ frontColor[j] ].erase( mp(minm, j) );
			back[ backColor[j] ].erase( mp(minm, j) );
			// cout<<( *( front[ input[i] ].begin() ) ).second<<"\n";
		}
		else{
			j = ( *( back[ input[i] ].begin() ) ).second;
			// cout<<( *( back[ input[i] ].begin() ) ).first<<"\n";
			// cout<<( *( back[ input[i] ].begin() ) ).second<<"\n";
			front[ frontColor[j] ].erase( mp(minm, j) );
			back[ backColor[j] ].erase( mp(minm, j) );
			// cout<<( *( back[ input[i] ].begin() ) ).second<<"\n";
		}
	}

	cout<<"\n";

	return 0;
}