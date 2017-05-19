// i := (s div 50) mod 475
// repeat 25 times:
//     i := (i * 96 + 42) mod 475
//     print (26 + i)

#include<iostream>
#include<set>
#include<stdio.h>
#include<vector>

using namespace std;

typedef long long int ll;
typedef set<int> si;

#define num 200005
#define mod 475
#define fori(a, b) for( int i=a ; i<b ; i++ )

bool check(int s, int p){
	int i, count;
	i = (s/50)%mod;
	count = 25;
	while(count--){
		i = ( (i*96) + 42 )%mod;
		if( (26+i) == p ){
			return 1;
		}
	}
	return 0;
}

int main(){

	int p, x, y, temp, j, ans;

	cin>>p>>x>>y;

	temp = x - ((x-y)/50)*50;

	int flag = 0;
	ans = 0;
	if( check(x, p) == 1 ){
		// cout<<x<<"\n";
		flag = 1;
	}
	else{
		while( temp < x ){
			if( check(temp, p) == 1 ){
				// cout<<temp<<"\n";
				flag = 1;
				break;
			}
			temp += 50;
		}

		temp += 50;
		j = 0;
		if( flag == 0 ){
			while(1){
				j++;
				if(j%2 == 1){
					ans++;
				}
				if( check(temp, p) == 1 ){
					// cout<<temp<<"\n";
					flag = 1;
					break;
				}
				temp += 50;
			}
		}
	}

	cout<<ans<<"\n";

	return 0;
}