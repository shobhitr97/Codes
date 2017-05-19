#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

#define num 200003
#define fori(a, b) for( int i=a ; i<b ; i++ )
#define mod 1000000007

typedef long long int ll;

int main(){

	int temp, x, y, len, j, t;
	ll comx, comy, ans;

	string str;

	cin>>str;

	len = str.length();

	x = 0;
	y = 0;
	fori(0, len ){

		if( str[i] == ')' ){
			y++;
		}

	}

	
	// initialize to the first opening bracket

	// y represents the number of closing brackets ahead
	// x represents the number of opening brackets behind that opening bracket

	j = 0;

	while( str[j] == ')' ){
		j++;
		y--;
	}
	// x++;                          to not count the first (

	t = 1;
	comx = 1;
	comy = y;
	j++;									   // to ignore the first (

	ans = y;

	cout<<x<<" "<<y<<"\n";

	int x1, y1;

	while( j < len ){

		cout<<"\n";

		cout<<j+1<<":"<<str[j]<<"\n";

		// x1 = x;
		// y1 = y;

		if( str[j] == ')' ){
			if( y > 1 )
			comy = ( comy*(y-t) )/y;
			y--;
		}
		else{
			comx = ( comx*(x+1) )/( x+1 - (t-1) );
			x++;
		}

		cout<<x<<"C"<<(t-1)<<":"<<comx<<" "<<y<<"C"<<t<<":"<<comy<<"\n";

		temp = min( x+1, y );

		// cout<<x<<" "<<y<<"\n";
		cout<<t<<"->"<<temp<<"\n";

		if( temp > t ){

			while( t != temp ){
				comy = ( comy*(y-t) )/( t+1 );
				comx = ( comx*( x-(t-1) ) )/t;
				t++;
			}

		}

		if( temp < t ){

			while( t != temp ){	
				if( t > 1 ){
					comy = ( comy*t )/( y-t+1 );
					comx = ( comx*(t-1) )/( x+1-(t-1) );
				}
				else{

				}
				t--;
			}

		}
		// x = x1;
		// y = y1;
		
		cout<<x<<"C"<<(t-1)<<":"<<comx<<" "<<y<<"C"<<t<<":"<<comy<<"\n";

		cout<<ans<<"->";

		if( str[j] == '(' ){
			// 
			
			ans = ( ans + ( (comx%mod)*(comy%mod) )%mod )%mod;
		}
		cout<<ans<<"\n";
		// cout<<x<<" "<<y<<"\n";

		j++;
	}

	cout<<ans<<"\n";

	return 0;
}