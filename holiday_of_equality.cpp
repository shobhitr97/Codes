#include<iostream>
#include<stdio.h>

using namespace std;

int max(int a ,int b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
	int a[105],maxm,i,sum,n;
	sum=0;
	maxm=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		maxm=max(maxm,a[i]);
		sum+=a[i];
	}
	cout<<(n*maxm-sum)<<"\n";
	return 0;
}