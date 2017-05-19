#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

typedef long long int ll;
typedef vector<int> vec;
typedef vector<ll> vecl;
typedef vector<string> vecp;

#define num 100005
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define pb push_back

ll n, u, one, a;
int q, H, h, len;
string s;
vecl ans;

void find_answer(int index, string str){

	while( index < len ){

	// cout<<a<<":"<<str[index]<<":";

		switch(str[index]){
			case 'L':
			if( h > 1 ){
			
				a = a - (one<<(h-2));
				h--;

			}
			break;
			case 'R':
			if( h > 1 ){

				a = a + (one<<(h-2));
				h--;

			}
			break;
			case 'U':
			if( h < H ){

				ll d, beg;
				d = (one<<h);
				beg = (d>>1);
				if( ( ( a-beg )/d )%2 == 0 ){
					a = a + beg;
				}
				else{
					a = a - beg;
				}
				h++;

			}
			break;
		}

		// cout<<a<<"\n";
		index++;

	}

}

int main(){

	cin>>n>>q;

	one = 1;

	ll temp;

	temp = n+1;
	H = 0;

	while( temp/2 ){
		H++;
		temp = temp/2;
	}
	// cout<<H<<"\n";

	ans.clear();

	fori(0, q){
		// cout<<q<<":\n";
		cin>>u;
		cin>>s;

		len = s.length();

		// cout<<s<<":"<<len<<"\n";

		temp = u;
		h = 1;
		while(temp%2 == 0 ){
			temp = temp/2;
			h++;
		}

		// cout<<"\n"<<u<<" "<<h<<"\n";

		a = u;
		find_answer(0, s);
		if( h==1 && a%2 != 1 ){
			cout<<"ERROR\n";
		}
		ans.pb( a );

	}

	for( vecl::iterator it = ans.begin() ; it != ans.end() ; it++ ){
		cout<<(*it)<<"\n";
	}

	return 0;
}