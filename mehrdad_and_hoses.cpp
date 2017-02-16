#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector< vector<int> > vv;
typedef vector<int> vec;

#define num 1005

ll bb[num];

ll max(ll a,ll b){
	if(a>b){
		return a;
	}
	return b;
}

int n,m,w,wt[num],sum_w;
ll bty[num],wt_set[num],sum;
bool vis[num];

vv rel;

void printt(ll arr[],int n,int set){
	for(int i=set;i<=set+n-1;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void dfs_p(int node){
	if(vis[node]){
		return;
	}
	vis[node]=1;
	sum_w += wt[node];
	sum += bty[node];
	
	int i;
	i=0;
	while( (i + wt[node]) <= w ){
		if(bb[i]||i==0){
			wt_set[ i + wt[node] ] =max(wt_set[ i+wt[node] ] ,bb[ i ] +  bty[node] );
		}
		i++;
	
	}
	
	// cout<<node<<":"<<wt[node]<<":"<<bty[node]<<"\n";
	// printt(wt_set,w+1,0);
	vec::iterator it;

	for(it=rel[node].begin();it!=rel[node].end();it++){
	
		if(vis[*it]==0){
			dfs_p(*it);
		}

	}
}



int main(){

	cin>>n>>m>>w;

	rel.resize(n+1);

	int i,j,x,y;

	for(i=1;i<=n;i++){
		cin>>wt[i];
	}

	for(i=1;i<=n;i++){
		cin>>bty[i];
	}
	
	for(j=0;j<=w;j++){
		bb[i]=0;
	}

	for(i=1;i<=n;i++){
		vis[i]=0;
	}	

	for(i=0;i<m;i++){
		cin>>x>>y;
		rel[x].push_back(y);
		rel[y].push_back(x);
	}

	// printt(bb,w+1,0);
	for(i=1;i<=n;i++){
		
		if(vis[i]==1){
			continue;
		}
		// cout<<i<<"\n";
		for(j=0;j<=w;j++){
			wt_set[j]=bb[j];
		}
		
		sum=0;
		sum_w=0;

		dfs_p(i);

		// cout<<sum_w<<":"<<sum<<"\n";

		j=w;
		while( (j-sum_w)>=0 ){
			if(bb[j-sum_w]||(j-sum_w)==0){
				bb[j]=max( bb[ j ] , ( bb[j-sum_w]+sum ) );
			}
			j--;
		}

		// printt(bb,w+1,0);

		for(j=0;j<=w;j++){
			bb[j]=max(bb[j],wt_set[j]);
		}
		// printt(bb,w+1,0);
	}

	sum=0;
	for(i=0;i<=w;i++){
		sum=max(sum,bb[i]);
	}

	cout<<sum<<"\n";

	return 0;
}
