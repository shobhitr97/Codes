#include<bits/stdc++.h>

int main(){
	long long int t,max_i=2,max,i,n,limit,a[1000000],fn[1000000],j;
	a[0]=a[1]=0;
	std::cin>>t;
	while(t--){
		std::cin>>n;
		if(n>=max_i){
			i=max_i;
			while(i<=n){
				max=0;
				j=2;
				limit =sqrt(i);
				//std::cout<<limit<<"\n";
				while(j<=limit){
					if(i%j==0){
						if(i!=(j*j))
							max+=(j+i/j);
						else
							max+=(j);
					}
					j++;
				}
				max++; 
				fn[i]=max;	
				a[i]=fn[i]+a[i-1];
				i++;
			}
			max_i=i;			// for 1 
			//std::cout<<max<<"\n";         
			//max_i++;	           //also see how we change max when n<max_i
		}
		std::cout<<a[n]<<"\n";
	}
	return 0;
}