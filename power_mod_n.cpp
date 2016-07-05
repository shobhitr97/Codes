#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;
int power(int a,int b,int n){
	int num,t;
	if(b==1){
		return a%n;
	}
	if(b%2){
		num=power(a,b/2,n);
		t=(num*num)%n;
		return (t*(a%n))%n;
	}
	num=power(a,b/2,n);
	return (num*num)%n;
}

int main(){
	int a,b,t,n;
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		cout<<power(a,b,n)<<"\n";
	}
	return 0;
}