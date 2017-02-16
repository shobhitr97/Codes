#include<iostream>
#include<string>
#include<stdio.h>
// #include<cstring>

using namespace std;

int main(){
	int i,a[28],counter,eln;

	string x;

	cin>>x;

	eln = x.length();

	for(i=0;i<26;i++){
		a[i]=0;
	}

	counter=0;

	for( i = 0 ; i < eln ; i++ ){
		if(a[ x[i]-'a' ]){
			continue;
		}
		if(x[i]-'a' == counter ){
			a[counter]=1;
			counter++;
		}
		else{
			cout<<"NO\n";
			return 0;
		}
	}

	cout<<"YES\n";

	return 0;
}