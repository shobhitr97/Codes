	#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

typedef long long int ll;
#define num 1000000007
#define lim 1000000

ll val[lim+7][26];

int sieve[1000009];//prime[100005];

vector< ll > vv;

void gen(){
	
	int i,j,k;
	// sieve[0]=0;
	sieve[1]=1;
	i=2;
	// k=0;
	while(i<=1000000){
		sieve[i]=2;
		i+=2;
	}
	i=3;
	while(i<=1000000){
		if(sieve[i]!=1){
			i++;
			continue;
		}
		// prime[k]=i;
		// k++;
		j=i;
		while(j<=1000003){
			if(sieve[j]!=1){
				j+=(2*i);
				continue;
			}
			sieve[j]=i;
			j+=(2*i);
		}
		i+=2;
	}
	
}

void fill(){
	int i,j;
	for(i=1;i<=25;i++){
		val[0][i]=2;
	}
	for(i=0;i<=lim+3;i++){
		val[i][0]=1;
	}
	for(i=1;i<=lim;i++){
		
		for(j=1;j<=25;j++){
			
			val[i][j] = ( val[i][j-1] + val[i-1][j] )%num ;

		}
	
	}

}

int main(){
	int q,r,j,n,temp,poww,i,aa;
	ll ans;
	cin>>q;
	
	for(i=0;i<=1000005;i++){
		sieve[i]=1;
	}
	
	gen();
	fill();
	
	// for(i=0;i<2;i++){
	// 	for(j=0;j<21;j++){
	// 		cout<<val[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	while(q--){
	
		cin>>r>>n;
		// prime factorize n
		temp=n;
		ans=1;
		i=0;
		// if(sieve[n]==1){
		// 	cout<<val[r][1]<<"\n";
		// 	// vv.push_back(val[r][1]);
		// 	continue;
		// }
		while( temp!=1 ){

			// if(sieve[temp]==1){
			// 	ans = (ans*val[r][1])%num;
			// 	temp=1;
			// 	break;
			// }
			// if( ( n%prime[i] ) != 0 ){
			// 	i++;
			// 	continue;
			// }
			
			// poww=0;
			// while( ( temp%prime[i] )==0 ){
			// 	temp/=prime[i];
			// 	poww++;
			// }
			// ans = ( ans*val[r][poww] )%num ;
			// i++;

			poww = 0 ;
			aa = sieve[temp] ;
			while( ( temp%aa )==0 ){
				temp/=aa;
				poww++;
			}
			ans = ( ans*val[r][poww] )%num ;

		}
		// if( temp!=1 && sieve[temp] ){
		// 	ans = ( ans*val[r][1] )%num ;
		// }

		cout<<ans<<"\n";
		// vv.push_back(ans);

	}
	
	// for( vector< ll >::iterator it=vv.begin() ; it!=vv.end() ; it++ ){
	// 	cout<<(*it)<<"\n";
	// }

	return 0;

}