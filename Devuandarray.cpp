#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;

int main(){
	int N,Q,t;
	int num,min,max;
	cin>>N>>Q;
	min=INT_MAX;
	max=0;
	for(int i=0;i<N;i++){
		cin>>num;
		if(num<=min){
			min=num;
		}
		if(num>=max){
			max=num;
		}
	}
	while(Q--){
		cin>>t;
		if(t<=max&&t>=min){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
	return 0;
}