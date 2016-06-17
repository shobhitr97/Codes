#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
uisng namespace std;
class ZigZag(){
	int diff[50],S[50],temp,i,j,max;
	public:
	int longestZigZag(int *seq,int n){
		for(i=0;i<n;i++){
			diff[i]=0;
			S[i]=1;
		}
		diff[0]=0;
		diff[1]=seq[1]-seq[0];
		S[0]=0;
		S[1]=2;
		max=0;
		for(i=2;i<n;i++){
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
			if(S[i]>max){
				max=S[i];
			}
		}
		return max;
	}
	
}
int main(){
	int A[51],n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>A[i];
	}
	ZigZag obj;
	cout<<obj.longestZigZag(A,n)<<"\n";
	
    return 0;
}
