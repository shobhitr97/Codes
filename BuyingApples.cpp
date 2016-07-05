#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<limits.h>

using namespace std;

int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}

int main(){
	int N,W,x,y,i,price,t,min1;
	int cost[101];
	
	cin>>t;
	while(t--){	
		cin>>N>>W;
		for(x=0;x<=100;x++){
			cost[x]=0;

		}
		
		for(i=1;i<=W;i++){
			cin>>price;
			if(price==-1){
				continue;
			}

			for(x=W;x>=i;x--){
				if(cost[x]>0||x==W){	
						
					if(cost[x-i]==0){
						cost[x-i]=cost[x]+price;
					}
					else{
						cost[x-i]=min(cost[x-i],cost[x]+price);
					}
					
				}
			}
			
	
		}

		min1=INT_MAX;
		
		if(cost[x]>0){
			cout<<cost[0]<<"\n";
		}
		else{
			cout<<"-1\n";
		}

	}


	return 0;
}
