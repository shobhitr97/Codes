#include<iostream>
#include<vector>

using namespace std;

typedef long long int ll;
typedef vector<int> vv;

#define num 200005
#define randn -1011011111111111

ll max(ll a,ll b){

	if(a>b){
		return a;
	}

	return b;

}

void printt(ll *arr,int n){
	int i;
	for(i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void printtt(int *arr,int n){
	int i;
	for(i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

ll  sum[num] , maxx[num], pl[num] ,  kk[num];
int n , consider[num] , parent[num] , vis[num] ,nodes[num];
vector < vv > rel ;

int check(vv p,int u){
	int count=0;
	for(vv::iterator it=p.begin();it!=p.end();it++){
		if(*it==parent[u]){
			continue;
		}
		count++;
		if(count>0){
			return 1;
		}
	}
	return 0;
}

void traverse(int u){
	
	vis[u]=1;
	nodes[u]=0;
	for(vv::iterator it=rel[u].begin() ; it!=rel[u].end() ; it++){
		
		if(vis[*it]==1){
		
			parent[u]=*it;
			continue;
		
		}
		
		traverse(*it);
		nodes[u]+=(1+nodes[*it]);
	 }

}

void fill_kk(int u){

	ll summ;
	
	summ=pl[u];

	for(vv::iterator it = rel[u].begin() ; it!=rel[u].end() ; it++){
		
		if(*it == parent[u]){
			continue;
		}
		
		fill_kk(*it);
		summ += kk[*it];
	
	}
	
	kk[u]=summ;
}

void fill_pleasant(int u){

	if( kk[u]==pl[u] && nodes[u]==0){
		maxx[u]=kk[u];
		consider[u]=0;
		return;
	}

	int flag2=1,flag1=1;

	ll maxm , maxmm=randn , max_sum;
	
	consider[u]=1; 

	
	for(vv::iterator it=rel[u].begin();it!=rel[u].end();it++){
	
		if(*it==parent[u]){
			continue;
		}
	
		fill_pleasant(*it); 

		if(flag1){
			maxm=maxx[*it];
			flag1=0;
			continue;
		}

		if(maxx[*it]>maxm){
	
			maxmm=maxm;
			maxm=maxx[*it];
		}
		else{
			maxmm=max(maxmm,maxx[*it]);
		}
	}

	maxx[u]=max(maxm,kk[u]);

	for(vv::iterator it=rel[u].begin();it!=rel[u].end();it++){

		if(*it==parent[u]){
			continue;
		}

		if(consider[*it]==0){
			continue;
		}

		if(flag2){
	
			max_sum=sum[*it];
			flag2=0;
			continue;
	
		}
	
		max_sum=max(max_sum,sum[*it]);
	
	}


	if(maxmm==randn){

		if(flag2==0){
			sum[u]=max_sum;
		}
		else{
			consider[u]=0;
		}
	}
	else{
		if(flag2==0)
			sum[u]=max(maxm+maxmm,max_sum);
		else{
			sum[u]=maxm+maxmm;
		}
	}
	// if(u==3){
	// 	cout<<flag2<<"\n";
	// 	cout<<"maxm:"<<maxm<<"\n";
	// 	cout<<"maxmm:"<<maxmm<<"\n";
	// 	cout<<max_sum<<"\n";
	// }
}

int main(){
	
	int i,u,v;
	cin>>n;
	rel.resize(n+1);

	for(i=1;i<=n;i++){
		vis[i]=0;
		rel[i].resize(0);
	}
	vis[1]=1;

	for(i=1;i<=n;i++){
		cin>>pl[i];
	}

	parent[1]=1;
	
	for(i=1;i<=n-1;i++){
		cin>>u>>v;
		rel[u].push_back(v);
		rel[v].push_back(u);
	}



	traverse(1);
	// printtt(parent,n);

	// for(i=1;i<=n;i++){
	// 	cout<<check(rel[i],i)<<" ";
	// }
	// cout<<"\n";

	// vv::iterator it;

	// for(i=1;i<=n;i++){
	// 	for(it=rel[i].begin();it!=rel[i].end();it++){
	// 		cout<<*it<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	// printtt(nodes,n); 
	fill_kk(1);
	// printt(kk,n);

	fill_pleasant(1);
	// printt(maxx,n);
	// printtt(consider,n);
	// printt(sum,n);

	if(consider[1]==0){
		cout<<"Impossible\n";
	}
	else{
		cout<<sum[1]<<"\n";
	}

	return 0;
}