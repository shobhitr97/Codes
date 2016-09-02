#include<iostream>
#include<tuple>
#include<stack>
#include<queue>
#typedef tuple<int,int,int> tup

using namespace std;

int len[505][1000];
int len1[505][505];
int adj[505][505];    //will store cost as well
int inc[505];

struct greaterbylength{
	bool operator()(tup p1,tup p2){
		return get<3>(tup1)>get<3>(tup2);
	}
}

void take_input(){
	int m,i,u,v,c,l;
	cin>>m;
	for(i=0;i<m;i++){
		cin>>u>>v>>c>>l;
		adj[u][v]=c;
		len1[u][v]=l;
	}
}

priority_queue <tup,vector<tup>,greaterbylength> qu;

int main(){
	qu.push(make_tuple(1,0,0));
	while(!qu.empty()){
		tup t1=qu.top();
		qu.pop();
		v=get<1>(t1);
		length=get<3>(t1);
		cost=get<2>(t1);
		if(inc[v]==1){
			continue;
		}
		inc[v]=1;
		for(i=1;i<=n;i++){                      //we can iterate i over an array containing the index of vertices that ave been included rather than the inc array
			if(adj[i][v]!=0&&inc[i]){    		// 0 can be replaced by infinty
				for(j=1;j<=b;j++){
					if(len[i][j]!=INT_MAX){
						if(adj[i][v]+j<b)
							len[v][j+adj[i][v]]=min(len[v][j+adj[i][v]],len[i][j]+len1[i][v]);
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			if(adj[v][i]&&!inc[i]){
				qu.push(make_tuple(i,adj[v][i],len1[v][i]));
			}
		}
	}
	return 0;
}
first we pick our source vertex 
then we mark all the adjacent vertices with the rudimentary length their path is going to have(priority queue) 
then we pick out te verex with the minimum length 
see all the vertices that direct to it and have already been considered 
for each of these vertices mark len[v][b]  u all the elements that direct to it(this is to be repeated for every b)
then again mark all it's adjacent vertices with the value