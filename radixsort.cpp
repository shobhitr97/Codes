#include<iostream>
#include<stdlib.h>
int rem(int d,int n){
	int r;
	for(int i=0;i<n;i++){
		r=d%10;
		d/=10;
		if(!d&&i!=n-1){
			r=0;
			break;
		}
	}
	return r;
}



int main(){
	int n,d2,i,*a,r,d,*b,j,c[10],p;
	
	std::cin>>n>>d2;
	a=(int*)malloc(n*sizeof(int));
	b=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		std::cin>>a[i];
	}
	
	j=d2-1;
	while(j>=0){
		for(i=0;i<10;i++){
			c[i]=0;
		}
		for(i=0;i<n;i++){
			r=rem(a[i],d2-j);
			c[r]++;
		}
		for(i=1;i<10;i++){
			c[i]+=c[i-1];
		}
		i=n-1;
		while(i>=0){
			r=rem(a[i],d2-j);
			b[c[r]-1]=a[i];
			c[r]--;
			i--;
		}
		for(i=0;i<n;i++){
			a[i]=b[i];
		}
	
		j--;
	}
	std::cout<<"sorted array:"<<"\n";
	for(i=0;i<n;i++){
		std::cout<<a[i]<<"\n";
	}
	return 0;
}