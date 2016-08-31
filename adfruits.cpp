#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>

using namespace std;

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
	int ch=0,max1,len[101][101],i,j,length,length1,length2,index;
	
	char *a,*b;
	while(1){

        a=(char*)malloc(101*sizeof(char));
        b=(char*)malloc(101*sizeof(char));
		max1=0;
		/*
		ch=getchar();
		if(ch==EOF){
			break;
		}
		while(ch!=' '){
			a[length1]=ch;
			length1++;
			ch=getchar();
		}

		ch=getchar();
		while(ch!='\n'||ch!=EOF){
			b[length2]=ch;
			length2++;
			ch=getchar();
		}
		*/
		try{
        	scanf("%s ",a);
        }
        catch(exception& e){
        	break;
        }
        if(strcmp(a,"end")==0){
        	break;
        }
        scanf("%s\n",b);
        length1=strlen(a);
        length2=strlen(b);
        
		for(i=0;i<=length1;i++){
			for(j=0;j<=length2;j++){
				if(i==0||j==0){
					len[i][j]=0;
					continue;
				}
				if(a[i-1]==b[j-1]){
				    if(i>1){
				        if(a[i-1]==a[i-2]){
					        len[i][j]=max(len[i-1][j],len[i][j-1]);
				        }
				        else{
				            len[i][j]=len[i-1][j-1]+1;
				        }
				    }
				    else{
					    len[i][j]=len[i-1][j-1]+1;
				    }
				}
				if(a[i-1]!=b[j-1]){
					len[i][j]=max(len[i-1][j],len[i][j-1]);
				}
				if(len[i][j]>max1){
					index=j-1;
					max1=len[i][j];
				}
			}
		}
		for(i=0;i<=length1;i++){
			for(j=0;j<=length2;j++){
				cout<<len[i][j]<<" ";
			}
			cout<<"\n";
		}
		length=len[length1][length2];
		cout<<length<<"\n";
		for(i=index-length+1;i<=index;i++){
			cout<<b[i];
		}
		cout<<"\n";
		for(i=0;i<=index-length;i++){
			cout<<b[i];
		}
		for(i=0;i<length1;i++){
			cout<<a[i];
		}
		for(i=index+1;i<length2;i++){
			cout<<b[i];
		}
		cout<<"\n";
		delete(a);
		delete(b);
		//break;
	}
	return 0;
}