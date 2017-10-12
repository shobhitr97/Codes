#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long int ll;

int maxHeap[83500], minHeap[83400];

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

void insertMin(int val, int n){
	minHeap[n]=val;
	int index, temp;
	index=n;
	while(index>0&&minHeap[index]<minHeap[(index-1)/2]){
		temp=minHeap[index];
		minHeap[index]=minHeap[(index-1)/2];
		minHeap[(index-1)/2]=temp;
		index=(index-1)/2;
	}
}

void minHeapify(int index, int n){
	int temp, minm=index;
	if(2*index+1<n&&minHeap[2*index+1]<minHeap[index])	minm=2*index+1;
	if(2*index+2<n&&minHeap[2*index+2]<minHeap[minm])	minm=2*index+2;		
	if(minm!=index){
		temp=minHeap[minm];
		minHeap[minm]=minHeap[index];
		minHeap[index]=temp;
		minHeapify(minm, n);
	}
}

int extractMin(int n){
	int temp, val;
	val=minHeap[0];
	temp=minHeap[n-1];
	minHeap[n-1]=minHeap[0];
	minHeap[0]=temp;
	minHeap[n-1]=0;
	// minHeapify(0, n-1);
	n--;
	int index=0;
	int minm=index;
	while(index<n){
		if(2*index+1<n&&minHeap[2*index+1]<minHeap[index])	minm=2*index+1;
		if(2*index+2<n&&minHeap[2*index+2]<minHeap[minm])	minm=2*index+2;		
		if(minm!=index){
			temp=minHeap[minm];
			minHeap[minm]=minHeap[index];
			minHeap[index]=temp;
			// minHeapify(minm, n);
			index=minm;
		}
		else	break;
	}
	return val;
}

int main(){
	int n, x, y, cnt, maxCnt, ans, val, cntMax;
	cin>>n;
	maxCnt=83400;
	cnt=0, ans=0, cntMax=0;
	while(n--){
		cin>>x;
		if(x==1){
			cin>>y;
			if(ans==0||y<=minHeap[0]){
				insertMax(y, min(cntMax, maxCnt));
				// cout<<"Inserted "<<y<<" in maxHeap\n";
				cntMax++;
			}
			else{
				insertMin(y, ans);
				// cout<<"Inserted "<<y<<" in minHeap\n";
				val=extractMin(ans+1);
				insertMax(val, min(cntMax, maxCnt));
				// cout<<"Extracted "<<val<<" from minHeap and inserted it into the maxHeap\n";
				cntMax++;
			}
			cnt++;
			if(cnt/3>ans){
				// if(ans>0){
				val=extractMax(min(cntMax, maxCnt));
				cntMax--;
				insertMin(val, ans);
				// cout<<"Extracted "<<val<<" from the maxHeap and inserted it into the minHeap\n";
				// }
				ans=cnt/3;
			}
		}
		else{
			if(ans>0)	cout<<minHeap[0]<<"\n";
			else	cout<<"No reviews yet\n";
		}
	}
	return 0;
}