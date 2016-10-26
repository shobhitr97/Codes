#include<iostream>
#include<limits.h>

using namespace std;

int w[505],P[505];
int cost[100005],n;

int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}

// int get_val(int W){
// 	if(W==0){
// 		return 0;
// 	}
// 	if(cost[W]!=0){
// 		return cost[W];
// 	}
// 	int k=INT_MAX,val,i;
// 	for(i=0;i<n;i++){
// 		if(W>=w[i]){
// 			val=get_val(W-w[i]);
// 			if(val!=-1)
// 				k=min(k,P[i]+val);
// 		}
// 	}
// 	if(k==INT_MAX){
// 		k=-1;
// 	}
// 	w[W]=k;
// 	return k;
// }

void get_val(int p,int c){
	int i,k,j;

	for(i=p;i<=c;i++){
		k=INT_MAX;
		for(j=0;j<n;j++){
			if(i>=w[j]){
				if(cost[i-w[j]]!=-1){
					k=min(k,P[j]+cost[i-w[j]]);
				}
			}
		}
		if(k==INT_MAX){
			cost[i]=-1;
		}
		else{
			cost[i]=k;
		}
	}
}

int main(){
	int i,j,t,e,f,val;
	cin>>t;
	// get_val();
	while(t--){
		cin>>e>>f;
		cin>>n;
		for(i=0;i<100005;i++){
			cost[i]=0;
		}
		int k=INT_MAX;
		for(i=0;i<n;i++){
			cin>>P[i]>>w[i];
			k=min(k,w[i]);
		}
		for(i=1;i<k;i++){
			cost[i]=-1;
		}
		//val=get_val(f-e);
		get_val(k,f-e);
// 		for(i=0;i<=110;i++){
// 		    cout<<cost[i]<<"\n";
// 		}
		val=cost[f-e];
		if(val!=-1){
			cout<<"The minimum amount of money in the piggy-bank is "<<val<<".\n";
		}
		else{
			cout<<"This is impossible.\n";
		}
	}
	return 0;
}