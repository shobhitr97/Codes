#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>

using namespace std;

int main(){
	int t,n,i,ch,p;
	int j,sum;
	float cpi;
	cin>>t;

	while(t--){
		cin>>n;
		ch=1;
		p=0;
		sum=0;
		for(i=0;i<n;i++){
			cin>>j;
			if(j==2){
				ch=0;
				break;
			}
			if(j==5){
				p=1;
			}
			sum+=j;
		}
		cpi=float(sum)/float(n);
		cout<<cpi;
		if(ch==1&&p==1&&cpi>=4.00000){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
	return 0;
}