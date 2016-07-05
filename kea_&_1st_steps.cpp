#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){
	int n,a[100000],i,max,length;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	max=1;
	length=1;
	for(i=1;i<n;i++){
		if(a[i]>=a[i-1]){
			length++;
		}
		else{
			if(length>max){
				max=length;
				length=1;
			}
		}
	}
	cout<<max<<"\n";
	return 0;
}