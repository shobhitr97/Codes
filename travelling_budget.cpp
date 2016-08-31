#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<limits.h>

using namespace std;
typedef tuple<int,int,int> triple_t;
 
int minim(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}
int main(){
	int t,n,m,B,x,y,u,v,cst,len,q,i,j,min,city,cost,length;
	int c[505][505];
	int l[505][505];
	int a[505][1005];
	cin>>t;
	while(t--){
		cin>>n>>m>>B;
		for(i=1;i<=n;i++){
			for(j=0;j<=B;j++){
				if(i==1){
					a[i][j]=0;
				}
				else{
					a[i][j]=-1;
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				c[i][j]=0;
				l[i][j]=0;
			}
		}
		for(i=0;i<m;i++){
			cin>>u>>v>>cst>>len;
			c[u][v]=cst,l[u][v]=len;
		}
	}
	queue< triple_t > cities;
	
	cities.push(make_tuple(1,0,0));
	while(!cities.empty()){
		triple_t obj=cities.front();
		cities.pop();
		city=get<0>(obj);
		cout<<city<<"\n";
		cost=get<1>(obj);
		length=get<2>(obj);
		for(i=1;i<=n;i++){
			if(city!=i&&c[city][i]!=0){
				if(cost+c[city][i]<=y){
					if(a[i][cost+c[city][i]]!=-1){
						if(a[i][cost+c[city][i]]>length+l[city][i]){
							a[i][cost+c[city][i]]=length+l[city][i];
							cities.push(make_tuple(i,cost+c[city][i],length+l[city][i]));
						}
					}
					else{
						a[i][cost+c[city][i]]=length+l[city][i];
						cities.push(make_tuple(i,cost+c[city][i],length+l[city][i]));
					}
				}
			}
		}
	}
	cin>>q;
	
	while(q--){
		cin>>x>>y;
		min=INT_MAX;
		for(i=1;i<=y;i++){
			min=minim(min,a[x][i]);
		}
		if(min!=INT_MAX)
			cout<<min<<"\n";
		else{
			cout<<"-1\n";
		}
		//calculate the answer
	}
	return 0;
}
