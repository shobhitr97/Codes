#include<iostream>
#include<stdlib.h>
#include<math.h>

int left(int i){
	int j=0,c=0,s=0;
	while(1){
		c=(pow(2,j));
		if(s+c>=i){
			return (s+pow(2,j)+2*(i-s)-1);
		}
		else{
			s+=pow(2,j);
		}
		j++;
	}
}
int right(int i){
	int j=0,c=0,s=0;
	while(1){
		c=(pow(2,j));
		if(s+c>=i){
			return (s+pow(2,j)+2*(i-s));
		}
		else{
			s+=pow(2,j);
		}
		j++;
	}
}

int* max_heapify(int *a,int i,int size){
	int l,r,j,largest=i;
	l=left(i); 
	r=right(i);
	if(l<=size&&a[i]<a[l])
		largest=l;
	
	if(r<=size&&a[largest]<a[r])
		largest=r;

	if (largest!=i){
		j=a[i];
		a[i]=a[largest];
		a[largest]=j;
		a=max_heapify(a,largest,size);
	}
	return a;
}
int parent(int x){
	int j=0,c=0,s=0;
	while(1){
		c=(pow(2,j));
		if(s+c>=x){
			return (s-pow(2,j-1)+(x-s)/2);
		}
		else{
			s+=pow(2,j);
		}
		j++;
	}
	
}
int* insert_max_heap(int *a,int i){
	int p,tmp;
	p=parent(i);
	if(p>=0&&a[i]>a[p]){
		tmp=a[i];
		a[i]=a[p];
		a[p]=tmp;
		a=insert(a,p);
	}
	return a;

}
int* build_max_heapify_2(int *a,int n){
	for(int i=0;i<=n;i++){
		a=insert_max_heap(a,i))
	}
	return a;
}



int* build_max_heap_1(int *a,int n){
	for(int i=(n/2);i>=0;i--){
		a=max_heapify(a,i,n);
	}
	return a;
}


int* heapsort(int *a,int n){
	int j;
	a=build_max_heap_1(a,n);
	for(int i=n;i>=0;i--){
		a=max_heapify(a,0,i);
		j=a[i];
		a[i]=a[0];
		a[0]=j;
	}
	return a;
}
int main(){
	int n,*a,i;
	std::cout<<"enter n:";
	std::cin>>n;
	a=(int*)malloc((n+1)*sizeof(int));
	for(i=0;i<n;i++)
		std::cin>>a[i];
	a=heapsort(a,n-1);
	for(i=0;i<n;i++){
		std::cout<<"-"<<a[i]<<"\n";
	}
	return 0;
}
	

