#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
	char stack[252],ch,arr[252];
	int sym[256],prior[6],ch_in;
	sym['#']=-1;
	sym[')']=0;
	sym['-']=1;
	sym['+']=2;
	sym['*']=3;
	sym['/']=4;
	sym['(']=0;
	prior[1]=1;
	prior[2]=1;
	prior[3]=2;
	prior[4]=2;
	prior[0]=0;
	prior[5]=-1;
	cin>>t;
	while(t--){
		//build stack of symbols;
		ch_in=getchar();
		arr[0]='#';
		stack[0]='#';
		j=1;
		i=1;
		while(ch_in!='\n'&&ch_in!=' '&&ch_in!=EOF){
			arr[i]=ch_in;
			i++;
			if(ch_in<'a'||ch_in>'z'){
				stack[j]=ch_in;
				j++;
			}
			if(ch_in=='(')
			ch_in=getchar();
		}
		arr[i]='#';
		stack[j]='#';
	}



	return 0;
}