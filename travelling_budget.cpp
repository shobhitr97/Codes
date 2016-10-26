#include<iostream>
#include<tuple>
#include<stack>
#include<queue>
#include<limits.h>
#include<tr1/tuple>

using namespace std;
//typedef tuple<int,int,int> tup;
int len[505][1005];	  //to store length of path taken to reach a vertex with y coordinte denoting th ecost
int len1[505][505];	  //to store the lengths between nodes
int adj[505][505];    //will store cost as well
int inc[505],n,m,b;   //to keep track of the considerd vertices

struct greaterbylength{
	bool operator()(std::tr1::tuple<int,int,int> p1,std::tr1::tuple<int,int,int> p2){
		return get<3>(p1)>get<3>(p2);
	}
};

void take_input(){
	int m,n,b,i,u,v,c,l;
	cin>>n>>m>>b;

	for(i=0;i<m;i++){
		cin>>u>>v>>c>>l;
		adj[u][v]=c;
		len1[u][v]=l;
	}
}

void init(){
	int i,j;
	for(i=0;i<505;i++){
		for(j=0;j<1005;j++){
			len[i][j]=INT_MAX;
			if(j<505){
				adj[i][j]=0;
			}
		}
		inc[i]=0;
	}
}
int minim(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}

void ret_out(){
	int q,i;
	cin>>q;
	while(q--){
		cin>>v;
		if(len[v][1002]!=INT_MAX)
			cout<<len[v][1002]<<"\n";
		else
			cout<<"-1\n";
	}
}

priority_queue <std::tr1::tuple<int,int,int>,vector<std::tr1::tuple<int,int,int>>,greaterbylength> qu;

int main(){
	int t,min,v,cost,length,i,j;
	cin>>t;
	while(t--){

		init();
		take_input();
		
		qu.push(make_tuple(1,0,0));

		while(!qu.empty()){
			min=INT_MAX;
			std::tr1::tuple<int,int,int> t1=qu.top();
			qu.pop();
			v=get<1>(t1);
			length=get<3>(t1);
			cost=get<2>(t1);
			if(inc[v]==1){                         // to ensure that we visit a node only once
				continue;
			}
			inc[v]=1;								//mark visited
			for(i=1;i<=n;i++){                      //we can iterate i over an array containing the index of vertices that ave been included rather than the inc array
				if(adj[i][v]!=0&&inc[i]){    		// 0 can be replaced by infinty
					for(j=1;j<=b;j++){
						if(len[i][j]!=INT_MAX){
							if(adj[i][v]+j<b){
								len[v][j+adj[i][v]]=minim(len[v][j+adj[i][v]],len[i][j]+len1[i][v]);
								min=minim(min,len[v][j+adj[i][v]]);
							}

						}
					}
				}
			}
			len[v][1002]=min;
			for(i=1;i<=n;i++){
				if(adj[v][i]&&!inc[i]){
					qu.push(make_tuple(i,adj[v][i],min+len1[v][i]));        //i don't use cost(ad[v][i]) that i get from the queue so i don't need to care what it is
				}
			}
		}
		ret_out();
	}
	return 0;
}
/*
first we pick our source vertex 
then we mark all the adjacent vertices with the rudimentary length their path is going to have(priority queue) 
then we pick out te verex with the minimum length 
see all the vertices that direct to it and have already been considered 
for each of these vertices mark len[v][b]  u all the elements that direct to it(this is to be repeated for every b)
then again mark all it's adjacent vertices with the value
*/