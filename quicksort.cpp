#include<iostream>
#include<stdlib.h>
	
int* quicksort(int *a ,int p,int r){
	if (p<0 || p>=r){
		return a;
	}
	int i,j=p,temp;
	for(i=p;i<r;i++){
		if(a[i]<a[r]){
			if(j!=i){
				//std::cout<<"\n exchanging :"<<i<<"-"<<j;
				temp=a[j]; 
				a[j]=a[i];
				a[i]=temp;
			}
			j++;
		}
	}

	
	temp=a[r]; 
	a[r]=a[j];
	a[j]=temp;

	//std::cout<<"\n"<<p<<" to "<<r<<"\n";
	//for(i=p;i<=r;i++)
	//	std::cout<<a[i]<<" ";

	a=quicksort(a,p,j-1);	
	a=quicksort(a,j+1,r);
	return a;
}

int main(){
	int n,*a;
	std::cout<<"enter the number of elements:";
	std::cin>>n;
	a=(int*)malloc((n+1)*sizeof(int));
	for(int i=0;i<n;i++)
		std::cin>>a[i];
	a=quicksort(a,0,n-1);
	std::cout<<"\n";
	for(int i=0;i<n;i++)
		std::cout<<a[i]<<" ";
	return 0;
}


