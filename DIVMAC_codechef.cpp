#include<iostream>
#include<stdio.h>

using namespace std;

#define num 1000001

int lpd[1000005],a[100005],tree[200005];

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

void fill(){
	int i,x;
	
	for(i=0;i<num;i++){
		lpd[i]=i;
	}
	lpd[0]=1;
	i=2;
	while(i*i<num){
		if(lpd[i]!=i){
			i++;
			continue;
		}
		x=i*i;
		while(x<num){
			if(lpd[x]==x)
				lpd[x]=i;
			x+=i;
		}
		i++;
	}
}


//segment tree
//apply lazy propagation
int number;

void build(int node,int start,int end){
    number++;
	if(start==end){
		tree[node]=lpd[a[start]];
		//cout<<node<<":"<<tree[node]<<"\n";
		return;
	}
	int mid=(start+end)/2;
	build(2*node+1,start,mid);
	build(2*node+2,mid+1,end);
	tree[node]=max(tree[2*node+1],tree[2*node+2]);
	//cout<<node<<":"<<tree[node]<<"\n";
}

void update(int node,int start,int end,int l,int r){
	if(l>end||r<start||tree[node]==1){
		return;
	}
	if(start==end){
		
		a[start]=a[start]/tree[node];
		tree[node]=lpd[a[start]];
		return ;
	}
	int mid=(start+end)/2;
	update(2*node+1,start,mid,l,r);
	update(2*node+2,mid+1,end,l,r);
	tree[node]=max(tree[2*node+1],tree[2*node+2]);
}

int query(int node,int start,int end,int l,int r){
	if(l>end||r<start||tree[node]==1){
		return 1;
	}
	if(l<=start&&r>=end){
		return tree[node];
	}
	int mid=(start+end)/2;
	return max(query(2*node+1,start,mid,l,r),query(2*node+2,mid+1,end,l,r));
}


int main(){
	int t,x,n,m,i,j,l,r;
	cin>>t;
	fill();
	for(i=0;i<200005;i++){
	    tree[i]=1;
	}
	while(t--){
	    number=0;
		cin>>n>>m;

		for(i=0;i<n;i++){
			cin>>a[i];
		//	cout<<lpd[a[i]]<<" ";
		}
		
		build(0,0,n-1);
		//cout<<"\nNumber of nodes:"<<number<<"\n";
		//for(i=0;i<number;i++){
		//	cout<<tree[i]<<"\n";
		//}
		
		for(i=0;i<m;i++){
			cin>>x>>l>>r;
			switch(x){
				case 0:
				update(0,0,n-1,l-1,r-1);
				break;
				case 1:
				cout<<query(0,0,n-1,l-1,r-1)<<" ";
				break;
			}
		}
		cout<<"\n";
		
	}
	return 0;
}


