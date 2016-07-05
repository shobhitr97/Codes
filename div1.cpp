#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

using namespace std;

#define num 32416
#define mod 1000000007
long long int a[num];

void func(int n,int x){
	if(x==0){
		return;
	}
	int temp=n;
	while(n>0){
		func(n,x/2);
		n=n-x;
	}
	a[temp]++;
}

int main(){
	memset(a,0,num);
	int t,max;
	int n;
	cin>>t;
	func(num,8);
	while(t--){
		cin>>n;
		cout<<a[4*n]%mod<<"\n";
	}
	return 0;
}