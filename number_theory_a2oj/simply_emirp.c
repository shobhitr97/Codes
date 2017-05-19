#include<stdio.h>

int isPrime(int n){
	if( n%2 == 0){
		return 0;
	}

	int j=3;
	while( j*j <= n ){
		if( n%j == 0 ){
			return 0;
		}
		j+=2;
	}
	return 1;
}

int main(){

	int n, m, j, i;
	int prime, emirp;
	int numbers[1000005];

	j = 0;
	while( scanf("%d", &n)==1 ){
		numbers[j]=n;
		j++;
	}

	for( i=0 ; i<j ; i++ ){
		
		prime = isPrime( numbers[i] );
		
		if( prime == 1 ){
			
			n = numbers[i];
			m=0;
			while(n){
				m *= 10;
				m += (n%10);
				n /= 10;
			}

			emirp = isPrime(m);

			if( emirp == 1 ){
				printf("N is emirp.\n");
			}
			else{
				printf("N is prime.\n");
			}
		}
		else{
			printf("N is not prime.\n");
		}

	}

	return 0;
}
