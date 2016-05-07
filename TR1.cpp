#include<iostream>
#include<stdlib.h>
int **a,**m;
int main(){
	int N,t;
	std::cin>>N>>t;
	a=(int**)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		a[i]=(int*)calloc(n,sizeof(int));
	}

	m=(int**)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		m[i]=(int*)calloc(n,sizeof(int));
	}
	for(i=0;i<n;i++){
		std::cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
}