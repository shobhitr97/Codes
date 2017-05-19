// #include<iostream>
// #include<sstream>
// #include<cmath>
// #include<vector>
#include<stdio.h>

// using namespace std;

// typedef long long int ll;
// typedef vector<int> vec;

// #define fori(a, b) for( int i=a ; i<b ; i++)
// #define N 1000000
// #define pb push_back

bool isPrime(int n){
	if( n%2 == 0){
		return false;
	}

	int j=3;
	while( j*j <= n ){
		if( n%j == 0 ){
			return false;
		}
		j+=2;
	}
	return true;
}

int main(){

	int n, m, j, i;
	bool prime, emirp;
	int numbers[1000005];

	// do{
	// 	if( cin>>n ){
	// 		numbers.pb(n);
	// 	}
	// }
	// while( cin && cin.peak() != '\n' );

	// while( cin>>n ){
	// 	numbers.pb(n);
	// }

	j = 0;
	while( scanf("%d", &n)==1 ){
		// cout<<n<<"\n";
		numbers[j]=n;
		j++;
	}
	// cout<<j<<"\n";

	// vec::iterator it;

	for( i=0 ; i<j ; i++ ){
		
		prime = isPrime( numbers[i] );
		
		if( prime == true ){
			
			n = numbers[i];
			m=0;
			while(n){
				m *= 10;
				m += (n%10);
				n /= 10;
			}

			// cout<<m<<"\n";
			emirp = isPrime(m);

			if( emirp == true ){
				cout<<"N is emirp.\n";
			}
			else{
				cout<<"N is prime.\n";
			}
		}
		else{
			cout<<"N is not prime.\n";
		}

	}

	return 0;
}
