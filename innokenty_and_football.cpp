#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<stdio.h>
#include<utility>
#include<map>

using namespace std;

typedef long long int ll;
typedef vector<string> vs;
typedef set<string> ss;
typedef multiset<string> ms;
typedef pair<string, int> si;
typedef map<si> msi;

#define fori(a, b) for( int i=a ; i<b ; i++ )
#define pb push_back
#define mp make_pair
#define num 1003

int n;
ms first;
ss names;
vs firstOpt, secondOpt;
msi indices;

int main(){

	string a, b, x, y;
	int counter;

	cin>>n;

	fori(0, n){
		cin>>a>>b;
		x = a.substr(0, 3);
		firstOpt.pb(x);
		first.insert(x);
		y = a.substr(0, 2);
		y += b.substr(0, 1);
		secondOpt.pb(y);
		indices.insert( mp(x, i) );
	}

	ms::iterator it;

	for( it = first.begin() ; it != first.end() ; it++ ){
		counter = first.count( (*it) );
		cout<<(*it)<<"\n";
		if( counter > 1 ){
			fori(0, counter){
				y = secondOpt[ indices[(*it)] ];   // wrong
				cout<<"\t y\n";
				if( names.find(y) != names.end() ){
					cout<<"No\n";
					return 0;
				}
				names.insert(y);
				first.erase( first.find( (*it) ) );
			}
		}
	}

	for( it =first.begin() ; it != first.end() ; it++ ){
		cout<<(*it)<<"\n";
	}

	ss::iterator tt;

	for( tt = names.begin() ; tt != names.end() ; tt++ ){
		if( first.find( (*tt) ) == first.end() ){
			continue;
		}
		y = secondOpt[ indices[(*tt)] ];          //wrong
		if( names.find(y) != names.end() ){
			cout<<"No\n";
			return 0;
		}
		names.insert(y);
		first.erase( (*tt) );
	}

	for( it = first.begin() ; it != first.end() ; it++ ){
		if( names.find( (*it) ) != names.end() ){
			cout<<"No\n";
			return 0;
		}
		names.insert( (*it) );
	}

	return 0;
}