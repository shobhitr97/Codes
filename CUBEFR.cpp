#include<bits/stdc++.h>

int main(){
	int sieve[1000001],i,j,n,t=1,max_i=2,num,T;
	for(i=0;i<=1000000;i++){
		sieve[i]=1;
	}
	for(i=2;i<=100;i++){
		num=i*i*i;
		j=num;
		while(j<=1000000){
			sieve[j]=0;
			j+=num;
		}
	}
	for(i=2;i<=1000000;i++){
		sieve[i]=sieve[i-1]+sieve[i];
	}
	std::cin>>T;
	while(t<=T){
		std::cin>>n;
		/*if(n>=max_i){
			if(sieve[n]!=0){
				for(i=max_i;i<=n;i++){
					sieve[i]=sieve[i-1]+sieve[i];
					//std::cout<<sieve[i]-sieve[i-1]<<"->"<<sieve[i]<<"\n";
				}
				max_i=i;
				std::cout<<"Case "<<t<<": "<<sieve[n]<<"\n";
			}
			else{
				//std::cout<<sieve[i]<<"\n";
				std::cout<<"Case "<<t<<": Not Cube Free"<<"\n";
			}
		}
		else{*/
		if(sieve[n]-sieve[n-1]||n==1){
			std::cout<<"Case "<<t<<": "<<sieve[n]<<"\n";
		}
		else{
			std::cout<<"Case "<<t<<": Not Cube Free"<<"\n";
		}
		//}
		t++;
	}
	return 0;
}	