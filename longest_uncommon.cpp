#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
	char a[100005],b[100005],ch;
	int i,len1,len2;

	scanf("%s\n%s",a,b);

	len1=strlen(a);
	len2 = strlen(b);

	if (len1 == len2 && strcmp(a,b) == 0){
		
		cout<<"-1\n";
		return 0;
		
	}

	if (len1>len2){
		cout<<len1<<"\n";
	}
	else{
		cout<<len2<<"\n";
	}

	return 0;
}