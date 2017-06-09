#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long int ll;

#define fori(a, b) for( int i=a ; i<b ; i++ )
#define pb push_back

int val( char s){
	switch(s){
		case 'C':	return 1;break;
		case 'E': 	return 2;break;
		case 'S': 	return 3;break; 
		default	: 	return 0;break;
	}
}


int main(){

	int t, j, len, x, y, flag;
	string s;

	cin>>t;

	while(t--){
		
		cin>>s;
		len = s.length();
		flag = 1;

		x = val( s[0] );
		fori(1, len){
			y = val( s[i] );
			// cout<<x<<" "<<y<<"\n";
			if( y-x < 0 ){
				flag = 0;
				break;
			}
			x = val( s[i] );
		}

		if( flag ){
			cout<<"yes\n";
		}
		else{
			cout<<"no\n";
		}

	}


	return 0;
}