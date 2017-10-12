#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long int ll;

int maxHeap[125005];

void insertMax(int val, int n){
	maxHeap[n]=val;
	int index, temp;
	index=n;
	while(index>0&&maxHeap[index]>maxHeap[(index-1)/2]){
		temp=maxHeap[index];
		maxHeap[index]=maxHeap[(index-1)/2];
		maxHeap[(index-1)/2]=temp;
		index=(index-1)/2;
	}
}

void maxHeapify(int index, int n){
	int temp, minm=index;
	if(2*index+1<n&&maxHeap[2*index+1]>maxHeap[index])	minm=2*index+1;
	if(2*index+2<n&&maxHeap[2*index+2]>maxHeap[minm])	minm=2*index+2;		
	if(minm!=index){
		temp=maxHeap[minm];
		maxHeap[minm]=maxHeap[index];
		maxHeap[index]=temp;
		maxHeapify(minm, n);
	}
}

int extractMax(int n){
	int temp, val;
	val=maxHeap[0];
	temp=maxHeap[n-1];
	maxHeap[n-1]=maxHeap[0];
	maxHeap[0]=temp;
	maxHeap[n-1]=0;
	// maxHeapify(0, n-1);
	n--;
	int index=0;
	int maxm=index;
	while(index<n){
		if(2*index+1<n&&maxHeap[2*index+1]>maxHeap[index])	maxm=2*index+1;
		if(2*index+2<n&&maxHeap[2*index+2]>maxHeap[maxm])	maxm=2*index+2;		
		if(maxm!=index){
			temp=maxHeap[maxm];
			maxHeap[maxm]=maxHeap[index];
			maxHeap[index]=temp;
			// maxHeapify(minm, n);
			index=maxm;
		}
		else	break;
	}
	return val;
}

int main(){
	int n, k, n1, n2, val, maxm=100000000;;
	cin>>n;
	n1=0, n2=0;
	for(int i=0;i<n;i++){
		cin>>k;
		insertMax(k, n1);
		n1++;
		while(n1>n/2){
			val=extractMax(n1);
			n1--;
			maxm=min(maxm, val);
		}
	}
	// cout<<maxHeap[0]<<" "<<maxm<<"\n";
	ll ans=(ll)maxm+(ll)maxHeap[0];
	if(n%2)	printf("%.1f\n", (double)maxm);
	else	printf("%.1f\n", (double)ans/2.0);
	return 0;
}