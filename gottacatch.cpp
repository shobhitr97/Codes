#include<iostream>
#include<stdio.h>

using namespace std;

// "Bulbasaur"  B a b l r s u

int min(int a ,int b){
	if(a<b){
		return a;
	}
	return b;
}

int main(){
	int ch,i;
	int pp[106];
	for(i=0;i<100;i++){
		pp[i]=0;
	}
	ch=getchar();
	while(ch!=' '&&ch!='\n'&&ch!=EOF){
		pp[ch-'A']++;
		ch=getchar();
	}
	pp[52]=pp[52]/2;
	pp[32]=pp[32]/2;

	int minm=1000000;

	minm=min(minm,pp[1]);
	minm=min(minm,pp[32]);
	minm=min(minm,pp[33]);
	minm=min(minm,pp[43]);
	minm=min(minm,pp[49]);
	minm=min(minm,pp[50]);
	minm=min(minm,pp[52]);

	cout<<minm<<"\n";

	return 0;
}