#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
class ZigZag{
	int diff[50],S[50],temp,i,j,max,start;
	public:
	int longestZigZag(int *seq,int n){
		for(i=0;i<n;i++){
		    diff[i]=0;
		    S[i]=1;
		}
		
		
	    i=1;
	    while(seq[i]==seq[i-1]){
	        i++;
	    }
	    diff[i]=seq[i]-seq[i-1];
	    start=i;
		S[start]=2;
		max=0;
		i++;
		
		while(i<n){
			temp=0;
			j=i-1;
			while(j>=start){
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
			//cout<<S[i]<<"\n";
			i++;
		}
		
		return max;
	}
	
};

int main(){
	int A[51],n,i;
	cin>>n;
	for(i=0;i<n;i++){
		scanf("%d, ",&A[i]);
	}
	ZigZag obj;
	cout<<obj.longestZigZag(A,n)<<"\n";
	
    return 0;
}
