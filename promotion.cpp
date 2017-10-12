#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int maxHeap[1000005], minHeap[1000005];

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
	maxHeapify(0, n-1);
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
	minHeapify(0, n-1);
	return val;
}

int main(){
	int n, x, k, n1, n2;
	long long int ans=0;
	int p[1000005], val1, val2;
	for(int i=0;i<=1000000;i++)	p[i]=0;
	cin>>n;
	n1=0, n2=0;
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>x;
			insertMin(x, n1);
			p[x]++;
			insertMax(x, n2);
			n1++, n2++;
		}
		val1=extractMin(n1);
		n1--;
		while(p[val1]==0){
			val1=extractMin(n1);
			n1--;
		}
		p[val1]--;
		val2=extractMax(n2);
		n2--;
		while(p[val2]==0){
			val2=extractMax(n2);
			n2--;
		}
		p[val2]--;
		ans+=val2-val1;
	}
	cout<<ans<<"\n";
	return 0;
}