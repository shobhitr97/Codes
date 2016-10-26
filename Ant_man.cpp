#include<iostream>
#include<stdlib.h>
#include<limits.h>

typedef long long int ll;
#define D_MAX 100000000000;

using namespace std;

ll min(ll a,ll b){
	if(a<b){
		return a;
	}
	return b;
}

void print_arr(int arr[],int st,int en){
	int i=st;
	while(i<=en){
		cout<<arr[i]<<" ";
		i++;	
	}
	cout<<"\n";
}

ll w[5005][5005];
int s,N;

//array is being passed by refernce so the function is not working properly
ll min_time(int S[],int ind,int n){
	if(n==2){
		return w[s][ind];
	}
	int i,count=0;
	ll min_m,val;
	min_m=D_MAX;
	S[ind]=0;
	i=1;
	while(count<=(n-1)&&i<=N){
		if(S[i]==0){
			i++;
			continue;
		}
		count++;
		if(i==s||i==ind){
			i++;
			continue;
		}
		val=min_time(S,i,n-1)+w[i][ind];
		if(val==0){
			cout<<"index:"<<i;
		}
		min_m=min(min_m,val);
		i++;
	}
	S[ind]=1;
	return min_m;
}

int main(){
	int e,x[5005],c[5005],d[5005],a[5005],b[5005],S[5005];
	int i,j;

	// input
	cin>>N>>s>>e;
	for(i=1;i<=N;i++){
		cin>>x[i];
	}
	// print_arr(x,1,n);
	for(i=1;i<=N;i++){
		cin>>a[i];
	}
	// print_arr(a,1,n);
	for(i=1;i<=N;i++){
		cin>>b[i];
	}
	// print_arr(b,1,n);
	for(i=1;i<=N;i++){
		cin>>c[i];
	}
	// print_arr(c,1,n);
	for(i=1;i<=N;i++){
		cin>>d[i];
	}
	// print_arr(d,1,n);
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			if(i==j){
				w[i][i]=0;
			}
			else{
				if(i>j){
					w[i][j]=abs(x[i]-x[j])+c[i]+b[j];
				}
				else{
					w[i][j]=abs(x[i]-x[j])+d[i]+a[j];
				}
			}
		}
	}
	// for(i=1;i<=N;i++){
	// 	for(j=1;j<=N;j++){
	// 		cout<<w[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }



	for(i=1;i<=N;i++){
		S[i]=1;	
	}
	cout<<min_time(S,e,N)<<"\n";
	return 0;
}