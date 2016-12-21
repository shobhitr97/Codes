#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define num 1005
typedef vector< vector<int> > vv;
typedef vector<int> vec;

int n,m,k;
int gov[num],deg[num],parent[num],rule[num],nedge[num];
bool vis[num];

stack <int> st;

vv edge;

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

void printt(int arr[],int n){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

//considering that there could exist subgraphs that are not connected to any gov.

int main(){
	cin>>n>>m>>k;
	
	edge.resize(n+5);
	
	int i,u,v,vv,pp,count,to_deg,total,maxm,max_gov,rem;

	for(i=1;i<=k;i++){
		cin>>gov[i];
	}

	for(i=1;i<=n;i++){
		deg[i]=0;
		vis[i]=0;
	}

	for(i=1;i<=m;i++){
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}

	for(i=1;i<=k;i++){
		rule[i]=0;		
	}

	for(i=1;i<=n;i++){
		parent[i]=-1;
	}

	vec::iterator it;

	maxm=0;

	total=0;
	max_gov=1;
	while(!st.empty()){
		st.pop();
	}

	for(i=1;i<=k;i++){
		
		to_deg=0;
		count=0;
		
		st.push(gov[i]);
		
		while(!st.empty()){
		
			pp=st.top();
			st.pop();
			if(vis[pp]){
				continue;
			}
			// cout<<pp<<"\n";
			vis[pp]=1;
			parent[pp]=gov[i];
		
			count++;
		
			to_deg+=deg[pp];
		
			for(it=edge[pp].begin();it!=edge[pp].end();it++){
				if(!vis[*it]){
					st.push(*it);
				}
			}
		
		}

		rule[i]=count;
		nedge[i]= (to_deg / 2) ;
		total+=count;
		if(count>maxm){
			max_gov=i;
			maxm=count;
		}
	}

	if(total<n){
		rem=n-total;
	}

	rule[max_gov]+=rem;

	// printt(deg,n);
	// printt(rule,k);
	// printt(nedge,k);

	rem=0;

	for(i=1;i<=k;i++){
		rem+=( ( ( rule[i]*( rule[i]-1 ) ) / 2 )- nedge[i] );
	}

	to_deg=0;
	for(i=1;i<=n;i++){
		if(parent[i]==-1){
			to_deg+=deg[i];
		}
	}
	to_deg=to_deg/2;

	cout<<(rem-to_deg)<<"\n";

	return 0;
}