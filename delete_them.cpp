#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	int count[105][128],n,m,i,mark[105],arr[105],length,len[105],j,flag;
	char st[105][105],pattern[105],ch;

	cin>>n>>m;

	for(i=1;i<=n;i++){
		scanf("%s\n",st[i]);
		j=0;
		while(st[i][j]!='\0'){
			j++;
		}
		len[i]=j;
	}

	for(i=1;i<=n;i++){
		mark[i]=0;
	}

	for(i=1;i<=m;i++){
		cin>>arr[i];
		mark[ arr[i] ]=1;
	}

	for(i=1;i<=100;i++){
		for(j=1;j<=127;j++){
			count[i][j]=0;
		}
	}

	
	
	length = len[ arr[1] ];
	// cout<<"Length:"<<length<<"\n";
	for(i=1;i<=m;i++){
		if(len[ arr[i] ] != length){
			// cout<<len[ arr[i] ]<<"\n";
			cout<<"No\n";
			return 0;
		}
		j=0;
		while(st[ arr[i] ][ j ]!='\0'){
			count[ j ][ st[ arr[i] ][ j ]-'a'+97 ]++;
			j++;
		}
	}

	for(i=0;i<length;i++){
		ch='?';
		for(j=1;j<=127;j++){
			if(count[i][j]==m){
				ch='a'+j-97;
				break;
			}
		}
		pattern[i]=ch;
		// cout<<ch;
	}
	// cout<<"\n";
	// cout<<count[0][97]<<"\n";
	for(i=1;i<=n;i++){
		if(mark[i]){
			continue;
		}
		if(len[i]!=length){
			continue;
		}
		flag=0;
		for(j=0;j<length;j++){
			if(pattern[j]=='?'){
				continue;
			}
			if(st[i][j]!=pattern[j]){
				flag=1;
				break;
			}

		}
		if(flag==0){
			// cout<<"message "<<i<<" matches the pattern.\n";
			cout<<"No\n";
			return 0;
		}
	}

	cout<<"Yes\n";
	for(i=0;i<length;i++){
		cout<<pattern[i];
	}
	cout<<"\n";

	return 0;
}
