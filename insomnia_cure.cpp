#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
int gcd(int a ,int b){
	if(a==0){
		return b;
	}
	int temp;
	if(a>b){
		temp=a;
		a=b;
		b=temp;
	}
	return gcd(b%a,a);
}
int lcm(int a,int b){
	int x;
	x=gcd(a,b);
	return (a*b)/x;
}
int main(){
	int a[4],M,i,j,sum;
	
	for(i=0;i<4;i++){
		cin>>a[i];
	}
	
	cin>>M;
	
	sum=0;
	
	for(i=0;i<4;i++){
		sum+=(M/a[i]);
	}
	
	for(i=0;i<4;i++){
		for(j=i+1;j<4;j++){
			sum-=(M/lcm(a[i],a[j]));
		}
	}
	
	for(i=0;i<4;i++){
		sum+=(M/(lcm(a[(i+1)%4],lcm(a[(i+2)%4],a[(i+3)%4]))));
	}
	
	sum-=M/(lcm(a[0],lcm(a[1],lcm(a[2],a[3]))));
	
	cout<<sum<<"\n";

}