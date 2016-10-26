#include<iostream>

using namespace std;

int main(){
	int n,k,add1,req,add2,i,temp,a[505],b[505],c[505];
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	req=0;
	add1=0;
	for(i=0;i<n;i++){
		if(a[i]>req){
			b[i]=a[i];
			if(a[i]>=k){
				req=0;
				continue;
			}
			else{
				req=k-a[i];
				continue;
			}
			
		}
		else{
			b[i]=req;
			add1+=(req-a[i]);
			req=k-req;
		}
	}
	req=0;
	add2=0;
	for(i=n-1;i>=0;i--){
		if(a[i]>req){
			c[i]=a[i];
			if(a[i]>=k){
				req=0;
				continue;
			}
			else{
				req=k-a[i];
				continue;
			}
			
		}
		else{
			c[i]=req;
			add2+=(req-a[i]);
			req=k-req;
		}
	}
	if(add2>add1){
		cout<<add2<<"\n";
		for(i=0;i<n;i++){
			cout<<c[i]<<" ";
		}
	}
	else{
		cout<<add1<<"\n";
		for(i=0;i<n;i++){
			cout<<b[i]<<" ";
		}
	}
	return 0;
}