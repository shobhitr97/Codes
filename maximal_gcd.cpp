#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define fori(a, b) for(int i=a ; i<b ; i++ )
#define num 1000000007
#define limit 1000004 
#define mp make_pair
#define pb push_back

int sieve[limit], count;
ll gcd;
vi primes;
vii factors;

void createSieve(ll n){
	ll bar ;

	if( n>1000000 ){
		bar = 1000000;
	}
	else{
		bar = n+10;
	}

	if( n<=1 ){
		return;
	}

	fori(0, bar+1){
		sieve[i] = 1;
	}

	sieve[0] = 0;
	sieve[1] = 0;
	sieve[2] = 1;

	for(int i=4 ; i<=bar ; i+=2 ){
		sieve[i] = 0;
	}

	// cout<<"Primes:\n";

	primes.pb(2);
	count++;
	// cout<<"2\n";
	int k, j = 3;

	while( j<=bar ){
		if( sieve[j] == 0 ){
			j+=2;
			continue;
		}

		primes.pb(j);
		// cout<<j<<"\n";
		count++;
		k = 2*j;
		while(k<=bar){
			sieve[k] = 0;
			k+=j;
		}

		j+=2;
	}
}

void generateGCD(ll product, ll maxLimit, int index, int maxIndex){
	if( index >= maxIndex ){
		return;
	}

	ll factor = factors[index].first;

	fori(0, factors[index].second+1){
		if( product > maxLimit ){
			break;
		}
		if( product > gcd ){
			gcd = product;
			// cout<<gcd<<"\n";	
		}
		generateGCD(product, maxLimit, index+1, maxIndex);
		product *= factor;
	}
}

int main(){

	ll n, k, minSum, maxGCD, temp;
	int power;

	cin>>n>>k;

	if( k%2 == 0 ){
		minSum = k/2;
		minSum *= (k+1);
	}
	else{
		minSum = (k+1)/2;
		minSum *= k;
	}

	maxGCD = n/minSum;

	// cout<<minSum<<" "<<maxGCD<<"\n";

	// cout<<maxGCD<<"\n";

	if( maxGCD == 0 ){
		cout<<"-1\n";
		return 0;
	}

	count=0;
	createSieve(maxGCD);

	temp = n;
	int counter =0 ;
	fori(0, count){
		if( temp%primes[i] == 0 ){
			power = 0;
			while( temp%primes[i] == 0 ){
				temp/=primes[i];
				power++;
			}
			// cout<<primes[i]<<","<<power<<"\n";
			counter++;
			factors.pb( mp(primes[i], power) );
		}
	}
	if( temp != 1 ){
		counter++;
		factors.pb( mp(temp, 1) );
	}

	gcd = 1;
	generateGCD(1, maxGCD, 0, counter);

	// cout<<gcd<<"\n";

  	ll quo, rem, div;
  	div = n/gcd;
  	// cout<<div<<"\n";
  	div = div - minSum;
  	quo = div/k;
  	rem = div%k;

  	// cout<<quo<<" "<<rem<<"\n";

  	fori(1, k+1){
  		if( k-i < rem ){
  			cout<<gcd*(i+quo+1)<<" ";
  		}
  		else{
  			cout<<gcd*(i+quo)<<" ";
  		}
  	}
  	cout<<"\n";

	return 0;
}