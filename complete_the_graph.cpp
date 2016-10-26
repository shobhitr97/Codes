#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<limits.h>

typedef long long int ll;

using namespace std;

ll w[1005],adj[1005][1005],L;
int parent[1005],vis[1005],n;

class Compare{
	public:
		bool operator()(int a,int b){
			if(w[a]>w[b]){
				return true;
			}
			return false;
		}
};

priority_queue < int,vector <int>,Compare > pr;
stack < pair<int,int> > st;
vector<pair<int,int> >p;

//to print the path and it's total length
void print_path(int s,int e){
	int v=e;
	cout<<e;
	while(v!=s){
		
		cout<<"->("<<parent[v]<<" "<<adj[v][parent[v]]<<")";
		v=parent[v];
	}
	cout<<"\n"<<w[e]<<"\n";
}

void initialize_(ll *pt,int val){
	int i;
	for(i=0;i<=1000;i++){
		pt[i]=val;
	}
}
void initialize_(int *pt,int val){
	int i;
	for(i=0;i<=1000;i++){
		pt[i]=val;
	}
}

void find_min(){
	int v,i;
	
	initialize_(vis,0);
	while(!pr.empty()){
		v=pr.top();
		pr.pop();
		if(vis[v]==1){
			continue;
		}
		vis[v]=1;
		for(i=0;i<=n;i++){
			if(adj[i][v]>0&&(!vis[i])){
				if(w[i]>w[v]+adj[v][i]){
					w[i]=w[v]+adj[v][i];
					parent[i]=v;
				}
				pr.push(i);
			}
		}
	}

}


// void test(){
// 	int i;
// 	for(i=0;i<10;i++){
// 		w[i]=5*i-i*i;
// 		cout<<w[i]<<"\n";
// 		pr.push(i);
// 	}
// 	while(!pr.empty()){
// 		cout<<pr.top();
// 		pr.pop();
// 	}
// }

void markall_empty(int a,int b){
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			if(adj[i][j]==a){
				adj[i][j]=b;
				st.push(make_pair(i,j));
			}
		}
	}
}


int main(){
	int i,s,e,v,m,x,y,z,j,ch;
	cin>>n>>m>>L>>s>>e;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			adj[i][j]=-1;
		}
	}
	for(i=0;i<m;i++){
		cin>>x>>y>>z;
		p.push_back(make_pair(x,y));
		adj[x][y]=adj[y][x]=z;
	}
	//s=starting point e=end point
	//to check if the shortest path is lesss than L
	initialize_(w,INT_MAX);
	w[s]=0;
	pr.push(s);
	find_min();
	// print_path(s,e);
	if(w[e]<L){
	    
		cout<<"NO\n";
		return 0;
	}

	//to check if we with weight 1,there exists shortest path >L 
	markall_empty(0,1);   //to mark all the variable edges with weight 1
	initialize_(w,INT_MAX);
	w[s]=0;
	pr.push(s);
	find_min();
	// print_path(s,e);
	if(w[e]>L){
	    
		cout<<"NO\n";
		return 0;
	}
    cout<<"YES\n";
	v=e;
	initialize_(vis,0);
	while(v!=s){
		 vis[v]=1;
		 v=parent[v];
	}
	vis[s]=1;
	
	//to retain the zero weights of variable edges
	while(!st.empty()){
		x=st.top().first;
		y=st.top().second;
		adj[x][y]=adj[y][x]=0;
		st.pop();
	}

	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			if(adj[i][j]==0){
				if(vis[i]==1&&vis[j]==1){
					if(!(i==parent[j]||j==parent[i])){
						adj[i][j]=L+1;
					}
				}else{
					adj[i][j]=L+1;
				}
			}
		}
	}


	//assuming that the variable edges in the shortest path(which had 1 weight edges) are all marked 0
	
	v=e;
	//vv=e;
	ch=0;
	while(v!=s){
		if(adj[parent[v]][v]==0){
			if(ch==0){
				adj[parent[v]][v]=adj[v][parent[v]]=L-w[e]+1;
				ch=1;
			}else{
				adj[parent[v]][v]=adj[v][parent[v]]=1;
			}
			
		}
		v=parent[v];
	}
	for(i=0;i<m;i++){
		cout<<p[i].first<<" "<<p[i].second<<" "<<adj[p[i].first][p[i].second]<<"\n";
	}
	p.clear();
	// print_path(s,e);
	return 0;
	
}