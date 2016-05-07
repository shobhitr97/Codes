#include<iostream>
#include<stdlib.h>

int main(){
	int n,i,j,*a,c;
	std::cin>>n;
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		std::cin>>a[i];
	}
	i=0;
	j=n-1;
	while(i<j){
		while(!a[i]){
			i++;
		}
		while(a[j]){
			j--;
		}
		if(i<j){
			c=a[j];
			a[j]=a[i];
			a[i]=c;
		}
	}
	for(i=0;i<n;i++){
		std::cout<<a[i]<<"\n";
	}
	return 0;
}