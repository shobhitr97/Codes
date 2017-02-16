#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define mod 1000000007
typedef long long int ll;

int min(int a,int b){
	if(a < b){
		return a;
	}
	return b;
}

int max(int a,int b){
	if(a > b){
		return a;
	}
	return b;
}

void printt(int a[],int n,int offset){
	for(int i=offset;i<offset+n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void printtt(ll a[],int n,int offset){
	for(int i=offset;i<offset+n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

int main(){

	int n,a[28],arr[1005],max_len[1005],maxm,p,i,j,index,first_index;
	char strr[1003];
	ll sum_ways[1005];

	int ch;

	scanf("%d\n",&n);

	maxm = 0;

	scanf("%s\n",strr);

	for ( i = 0 ; i < n ; i++ ){
		
		arr[i] = 1 + strr[i] - 'a';
		
	}

	

	for( i = 1 ; i <= 26 ; i++ ){
		cin>>a[i];
	}

	// printt(arr,n,0);
	// printt(a,26,1);

	for(i=0;i<n;i++){
		max_len[i]=10000;
		sum_ways[i+1]=0;
	}
	int last_index;
	for( i = 0 ; i < n ; i++ ){
		
		first_index = max( 0 , i - a[ arr[i] ]+1);
		// last_index = min(n-1, i + a[ arr[i] ]-1 );

		for( j=first_index ; j <= i/*last_index*/ ; j++ ){
		
			max_len[i]=min( max( i-j , a[ arr[j] ] ) , max_len[i] );
			
		}
		maxm = max( maxm , min(i+1,max_len[i]) );//,min(n-i-1,max_len[i]) );
		max_len[i] = min( i+1 , max_len[i]);
		
		
	}



	// printt(max_len,n,0);


	sum_ways[0]=1;

	for( i = 1 ; i <= n ; i++ ){

		index = i-1;

		first_index = max(0,i - max_len[ index ] );

		for( j=first_index ; j<= i-1 ;j++){
			sum_ways[i] = (sum_ways[j] + sum_ways[i])%mod;
		}

	}

	// printtt(sum_ways,n+1,0);

	i=n-1;
	p=0;
	while(i>=0){
		p++;
		i = i- max_len[ i ];
	}

	cout<<sum_ways[n]<<"\n"<<maxm<<"\n"<<p<<"\n";

	return 0;
}