#include<iostream>
#include<limits.h>

using namespace std;

#define size 200005
#define number 200000

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
	int n,a[size],d[size],s[size],b[size],i,maxm;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(i==0){
			s[i]=a[i];
			continue;
		}
		s[i]=s[i-1]+a[i];
	}
	for(i=0;i<n;i++){
		cout<<s[i]<<"\n";
	}	
	d[n-1]=0;
	b[n-1]=s[n-1];
	d[n-2]=a[n-2]+a[n-1];
	b[n-2]=s[n-2]-d[n-2];
	maxm=b[n-2];
	for(i=n-1;i>=0;i--){
		if(i==n-1||i==n-2){
			continue;
		}
		d[i]=maxm;
		b[i]=s[i]-d[i];
		maxm=max(maxm,b[i]);
	}
	for(i=0;i<n;i++){
		cout<<d[i]<<"\n";
	}
	cout<<d[0]<<"\n";
	return 0;
}