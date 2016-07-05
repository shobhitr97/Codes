#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
int count;
void num_fac(int *a,int factor,int limit,int len,int num){
	int i;
	if(num==1){
		count++;
		for(i=0;i<len;i++){
			cout<<a[i];
			if(i<len-1){
				cout<<"*";
			}
		}
		cout<<"\n";
		
	}
	int new_limit,ch=0;
	for(i=factor;i<=limit&&num>i;i++){
		if(num%i==0&&i!=1){
			ch=1;
			a[len]=i;
			new_limit=sqrt(i);
			num_fac(a,i,limit,len+1,num/i);
		}
	}
	if(factor==1&&ch==0){
		return;
	}
	if(factor!=1&&num>=factor){
		a[len]=num;
		num_fac(a,num,limit,len+1,1);
	}
}


int main(){
	int a[10000],p,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,5);
		count=0;
		p=sqrt(n);
		num_fac(a,1,p,0,n);
		cout<<count<<"\n";
	}
	return 0;
}