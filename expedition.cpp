#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int heapArr[10005];

void insert(int val, int n){
	heapArr[n]=val;
	int index, temp;
	index=n;
	while(index>0&&heapArr[index]>heapArr[(index-1)/2]){
		temp=heapArr[index];
		heapArr[index]=heapArr[(index-1)/2];
		heapArr[(index-1)/2]=temp;
		index=(index-1)/2;
	}
}

void maxHeapify(int index, int n){
	int temp, minm=index;
	if(2*index+1<n&&heapArr[2*index+1]>heapArr[index])	minm=2*index+1;
	if(2*index+2<n&&heapArr[2*index+2]>heapArr[minm])	minm=2*index+2;		
	if(minm!=index){
		temp=heapArr[minm];
		heapArr[minm]=heapArr[index];
		heapArr[index]=temp;
		maxHeapify(minm, n);
	}
}

int extractMax(int n){
	int temp, val;
	val=heapArr[0];
	temp=heapArr[n-1];
	heapArr[n-1]=heapArr[0];
	heapArr[0]=temp;
	heapArr[n-1]=0;
	maxHeapify(0, n-1);
	return val;
}

int main(){
	int n, l, p, x, y, cnt, t;
	vector<pair<int, int> > lst;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			lst.push_back(make_pair(x, y));
		}
		cin>>l>>p;
		for(int i=0;i<n;i++){
			lst[i].first=l-lst[i].first;
		}
		sort(lst.begin(), lst.end());
		// for(int i=0;i<n;i++)	cout<<lst[i].first<<" "<<lst[i].second<<"\n";
		x=p;
		int i=0, tmp=0;
		cnt=0;
		while(i<n&&x<l){
			if(lst[i].first<=x){
				insert(lst[i].second, tmp);
				tmp++, i++;
				// cout<<lst[i-1].second<<" "<<tmp<<"\n";
			}
			else{
				if(tmp==0)	break;
				y=extractMax(tmp);
				// cout<<y<<"\n";
				cnt++;
				tmp--;
				x+=y;
			}
		}
		while(x<l&&tmp){
			y=extractMax(tmp);
			// cout<<y<<"\n";
			cnt++;
			tmp--;
			x+=y;
		}
		if(x<l)	cout<<"-1\n";
		else	cout<<cnt<<"\n";
		lst.clear();
	}
	return 0;
}