#include<bits/stdc++.h>

int main(){
	long long int t,max_i=2,max,i,n,limit,a[1000000],fn[1000000],j;
	a[0]=a[1]=0;
	fn[0]=0;
	fn[1]=1;
	std::cin>>t;
	while(t--){
		std::cin>>n;
		if(n>=max_i){
			i=max_i;
			while(i<=n){
				//max=0;

				j=2;
				while(i%j){
					j++;
				}
				if(i==j){
					fn[i]=1;
				}
				else{
					if(i!=(j*j)){
						fn[i]=fn[i/j]+fn[j]+j+i/j;
					}	
					else{
						max=fn[j]+j;
					}
				}
				fn[i]=max;
				a[i]=fn[i]+a[i-1];
				i++;
			}
			max_i=i;
		}
		std::cout<<a[n]<<"\n";
	}
	return 0;
}