#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	while(a||b||c){
		if(a!=c&&(a+c-2*b)==0){
			cout<<"\n"<<"AP "<<(2*c-b);
		}
		else{
			cout<<"\n"<<"GP "<<((c*c)/b);
		}
		cin>>a>>b>>c;	
	}
	return 0;
}