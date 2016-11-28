#include<iostream>
#include<stdio.h>

using namespace std;

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
	char s[200005],ch;
	int alpha[27],i,dist,prev,j;
	for(i=0;i<26;i++){
		if(i==0||i==4||i==8||i==14||i==24||i==20){
			alpha[i]=1;
		}
		else{
			alpha[i]=0;
		}
	}
	scanf("%s\n",s);
	i=0;
	dist=0;
	prev=-1;
	while(s[i]!='\0'){
		if(alpha[s[i]-'A']==1){
			dist=max(dist,i-prev);
			prev=i;
		}
		i++;
	}
	
	dist=max(dist,i-prev);
	cout<<dist<<"\n";
	return 0;
}