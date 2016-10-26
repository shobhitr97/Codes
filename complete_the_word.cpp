#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


int a[26],n;
int check(char* str){
	int i,que,dis,j;
	for(i=0;i<26;i++){
		a[i]=0;
	}	
	dis=0;que=0;
	for(i=0;i<26;i++){
		if(str[i]!='?'){
			if(a[str[i]-'A']==0){
				dis++;
			}
			a[str[i]-'A']++;
		}
		else{
			que++;
		}
	}
	//cout<<"distinct:"<<dis<<"\n";

	//cout<<"question marks:"<<que<<"\n";
	if((que+dis)!=26){
		return 0;
	}
	
	return 1;
}

void fill(char *pp){
	int i,j;
	i=0;j=0;
	

	while(i!=26&&j!=26){
		if(pp[i]!='?'){
			i++;
			continue;
		}
		while(a[j]==1){
			j++;
		}
		pp[i]='A'+j;
		a[j]=1;
		i++;
	}
}

int main(){
	char st[50005],ch;
	int i,t,j,n;
	gets(st);
	n=strlen(st);
	//cout<<n<<"\n";
	if(n<26){
		cout<<"-1";
		return 0;
	}
	t=0;
	for(i=0;i+25<n;i++){
		if(check(st+i)){
			t=1;
			fill(st+i);
			break;
		}
	}
	if(t==0){
		cout<<"-1";
	}
	else{
		for(i=0;i<n;i++){
			if(st[i]!='?'){
				cout<<st[i];
			}
			else{
				cout<<'A';
			}
		}
	}
	return 0;
}