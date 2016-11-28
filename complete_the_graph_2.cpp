#include<iostream>
#include<stack>
#include<vector>
#include<queue>

typedef long long int ll;

using namespace std;

vector< pair<int,int> > vv;
ll w[1005],adj[1005][1005],L;
int child[1005],isvacant[1005],ispath[1005][1005],n,m,s,e,vis[1005];

class Compare{
	public:
		bool operator()(int a,int b){
			if(w[a]>w[b]){
				return true;
			}
			return false;
		}
};

int adjj(int x,int y){
	if(adj[x][y]==0){
		return 1;
	}
	return adj[x][y];
}

void mark_adj(int val){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			adj[i][j]=-1;
		}
	}
}

int main(){
	int i,j,x,y,ind;
	cin>>n>>m>>L>>s>>e;
	stack < pair < int,int > > st;
	pair <int,int> p;
	ll rem,weight;
	mark_adj(-1);

	for(i=0;i<m;i++){
		cin>> x >> y >> weight;
		if (weight == 0) {
			st.push(make_pair(x,y));
		}
		adj[x-1][y-1]=adj[y][x]=weight;
	}

	priority_queue < int , vector < int > , Compare > pr; 

	pr.push(s);

	for(i=0;i<n;i++){
		w[i]=0;
		isvacant[i]=0;
		vis[i]=0;
	}
	while(!pr.empty()){
		ind=pr.top();
		pr.pop();
		if(vis[ind]!=0){
			continue;
		}
		vis[ind]=1;
		for(i=0;i<n;i++){
			if(adj[ind][i]>=0&&w[ind]+adj[ind][i]<=L){
				if(w[i]==0||w[ind]+adj[ind][i]<w[i]){
					w[i]=w[ind]+adj[ind][i];
					child[i]=ind;
					isvacant[i]=isvacant[ind];
					if(adj[ind][i]==0){
						isvacant[i]++;
					}
					
				}
				pr.push(i);   //no because this would result in multiple copes of the same index in the priority queue with same weights.the same 
				// weight concept is caused by the changing the value of weight upon which the index was ordered previously in the queue.
			}
		}
	}
	if(w[e]<L){
		if(isvacant[e]==0){
			cout<<"NO\n";
			return 0;
		}
	}
	else{
		if(w[e]>=L){
			cout<<"NO\n";
			return 0;
		}
	}

	rem=L-w[e];


	pr.push(s);

	for(i=0;i<n;i++){
		w[i]=0;
		vis[i]=0;
	}
	while(!pr.empty()){
		ind=pr.top();
		pr.pop();
		if(vis[ind]!=0){
			continue;
		}
		vis[ind]=1;
		for(i=0;i<n;i++){
			if(adjj(ind,i)>=0&&w[ind]+adjj(ind,i)<=L){
				if(w[i]==0||w[ind]+adjj(ind,i)<w[i]){
					w[i]=w[ind]+adjj(ind,i);
				}
				pr.push(i);   //no because this would result in multiple copes of the same index in the priority queue with same weights.the same 
				// weight concept is caused by the changing the value of weight upon which the index was ordered previously in the queue.
			}
		}
	}
	if(w[e]>L){
		cout<<"NO\n";
		return 0;
	}
	i=e;

	while(i!=s){
		if(adj[i][child[i]]>0){
			i=child[i];
			continue;
		}
		adj[i][child[i]]=adj[child[i]][i]=(rem)/(isvacant[i]);
		rem-=(rem/isvacant[i]);
	}

	while(!st.empty()){
		p=st.top();
		st.pop();
		x=p.first;
		y=p.second;

		if(adj[x][y]==0){
			adj[x][y]=L;
		}
	}	

	for(i=0;i<n;i++){
		for(j	=0;j<=i;j++){
			if(adj[i][j]){
				cout<<i<<" "<<j<<" "<<adj[i][j]<<"\n";
			}
		}
	}

	return 0;
}