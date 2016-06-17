#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
uisng namespace std;
class ZigZag(){
	int diff[50],S[50],temp,i,j;
	public:
	int longestZigZag(int *seq){
		memset(diff,0,50);
		memset(S,0,50);
		diff[0]=0;
		diff[1]=seq[1]-seq[0];
		S[0]=0;
		S[1]=1;
		for(i=2;seq[i]!='\0';i++){
			temp=0;
			j=i-1;
			while(j>=1){
				if((seq[i]-seq[j])*diff[j]<0){
					if(S[j]>S[i]){
						S[i]=S[j];
						diff[i]=seq[i]-seq[j];
					}
				}
				j--;
			}
			S[i]=S[i]+1;
		}
		return S[i-1];
	}
	
}
int main(){
		
    return 0;
}
