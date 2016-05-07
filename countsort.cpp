#include<iostream>
#include<stdlib.h>

int main(){
	int n,k=49,i,a[10],b[10],c[50];
	std::cin>>n;
	for(i=0;i<k+1;i++){
		c[i]=0;
	}
	for(i=0;i<n;i++){
		std::cin>>a[i];
		c[a[i]]++;
	}


	
	for(i=1;i<k+1;i++){
		c[i]=c[i]+c[i-1];
		//std::cout<<"\n"<<c[i];
	}
	for(i=n-1;i>=0;i--){
		b[c[a[i]]-1]=a[i];
		c[a[i]]=c[a[i]]-1;		
	}
	std::cout<<"\n";
	for(i=0;i<n;i++){
		std::cout<<b[i]<<"\n";
	}
	return 0;
}