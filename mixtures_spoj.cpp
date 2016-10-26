#include<iostream>
#include<limits.h>
#include<stdio.h>

using namespace std;

int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}

int m[105][105],a[105],n;

int M(int i,int j){
	if(j>=i){
		return m[i][j];
	}
	return 0;
}

int sum(int i,int j){
	int k,x;
	x=0;
	if(j<i){
		return 0;
	}
	for(k=i;k<=j;k++){
		x+=a[k];
	}
	return x%100;
}

int main(){
	int i,j,k,p;
	while(cin>>n){
		
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		for(i=0;i<n;i++){
			m[i][i]=0;
			if(i>=1)
				m[i-1][i]=a[i]*a[i-1];
		}

		for(i=2;i<n;i++){
			for(j=i-1;j>=0;j--){
				p=INT_MAX;
				for(k=i;k>j;k--){
					p=min(p,M(k,i)+M(j,k-1)+sum(k,i)*sum(j,k-1));
				}
				m[j][i]=p;
			}	
		}
		cout<<m[0][n-1]<<"\n";
	}
	return 0;
}