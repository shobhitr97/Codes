//For small n's
#include<iostream>

usind namespace std;
long long int bank[1000001];
int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
long long int f(long long int n){
	if(bank[n]!=-1){
		return bank[n];
	}
	bank[n]=max(n,f(n/2)+f(n/3)+f(n/4));
	return bank[n];
}
long long int f1(long long int n){
	if(n<=1000000){
		return f(n);
	}
	return max(n,f1(n/2)+f1(n/3)+f1(n/4));
}

int main(){
	int t,i;
	long long int n;
	bank[0]=0;
	bank[1]=1;
	bank[2]=2;
	bank[3]=3;
	for(i=4;i<=1000000;i++){
		bank[i]=-1;
	}
	while(1){
		cin>>n;
		cout<<f(n)<<"\n";
	}
	return 0;
}