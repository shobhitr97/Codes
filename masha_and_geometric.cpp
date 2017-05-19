#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long int ll;
typedef vector<ll> vecl;
typedef vector<int> vec;
typedef set <ll> sl;

#define num 100005
#define fori(a,b) for( int i=a ; i<b ; i++ )

int main(){

	sl a;
	int m, count ;
	ll b1, q, l, x;

	cin>>b1>>q>>l>>m;

	fori(0,m){
		cin>>x;
		a.insert(x);
	}

	// cout<<"If\n";

	count = 0;

	if( q == 0 ){

		// cout<<"If1\n";

		if( b1 != 0 ){
		 	if( abs(b1) <= l ){
		 		if( a.find(b1) == a.end() ){
		 			count++;
		 		}
		 		if( a.find(0) == a.end() ){
					cout<<"inf\n";
					return 0;
				}
		 	}
		 	
		}
		else{
			if( a.find(0) == a.end() ){
				cout<<"inf\n";
				return 0;
			}
		}
		
		

		// cout<<count<<"\n";

		// return 0;

	}
	else{


		if( b1 == 0 ){

			// cout<<"If2\n";

			if( a.find(0) == a.end() ){
				cout<<"inf\n";
				return 0;
			}

		}
		else{

			if( abs(q) == 1 ){

				// cout<<"If3\n";

				if( q == 1 && abs(b1) <= l && a.find( b1 ) == a.end() ){
					cout<<"inf\n";
					return 0;
				}

				if( q == -1 ){

					if( abs(b1) <= l && ( a.find( b1 ) == a.end() || a.find( -b1 ) == a.end() ) ){
						cout<<"inf\n";
						return 0;
					}

				}

			}
			else{

				// cout<<"If4\n";


				x = b1;
				while( abs(x) <= l ){
					if( a.find(x) == a.end() ){
						count++;
					}
					x = x*q;
				}

			}

		}

	}

	cout<<count<<"\n";

	return 0;
}