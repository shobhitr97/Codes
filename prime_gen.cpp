#include<bits/stdc++.h>
int main(){
	int t;
	long long int a,b=100000000,i,num;
	//limit=(int)sqrt(b);
	long long int *sieve=(long long int*)calloc((b+2),sizeof(long long int));
	long long int *list=(long long int*)malloc((b+2)*sizeof(long long int));
	i=2;
	while(i!=b){

		if(sieve[i]==0){
			//count++;
			sieve[i]=1+sieve[i-1];
			list[sieve[i]-1]=i;
			num=i*2;
			while(num<=b){
				sieve[num]=-1;
				num+=i;
			}
		}
		else{
			sieve[i]=sieve[i-1];
		}
		++i;		
	}
	std::cin>>t;
	while(t--){
		std::cin>>a>>b;
		//std::cout<<"the count is:"<<count<<"\n";
		if(sieve[a]-sieve[a-1]){
			i=sieve[a];
		}
		else{
			i=sieve[a]+1;
		}
		while(i<=sieve[b]-1){
			std::cout<<list[i]<<"\n";
			i++;
		}
		//std::cout<<count<<"\n";
	}
	return 0;
}