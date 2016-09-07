#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
	char s[12348];
	int length,i,ind_end,ans;
	for(i=0;i<=ind_end;i++){
		s[i]='\0';
	}
	scanf("%s\n",s);
	length =strlen(s);
	ind_end=length-1;
	ans=0;
	for(i=0;i<=length/2;i++){
		if(s[i]!='.'&&s[ind_end-i]!='.'){
			if(s[i]==s[ind_end-i]){
				continue;
			}
			else{
				ans=-1;
				break;
			}
		}
		if(s[i]=='.'&&s[ind_end-i]!='.'){
			s[i]=s[ind_end-i];
		}
		else{
			if(s[i]!='.'&&s[ind_end-i]=='.'){
				s[ind_end-i]=s[i];
			}
			else{
				s[i]=s[ind_end-i]='a';
			}
		}
	}
	if(ans==-1){
		cout<<"-1\n";
	}
	else{
		for(i=0;i<=ind_end;i++){
			cout<<s[i];
		}
		cout<<"\n";
	}
	return 0;
}