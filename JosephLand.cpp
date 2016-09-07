#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

//vector < vector<int> > vec(100005,vector<int>(0));
vector <vector<int> > k(100005,vector<int>(0));
vector <vector<long long int> > w(100005,vector<long long int>(0));

int take_input(int *arr,int n,int m,int *city){
	int i,x;
	for(i=0;i<n;i++){
		cin>>x;
		cin>>arr[x];
		
		//vec[arr[x]].push_back(x);
	}
	int t;long long int l;
	for(i=0;i<m;i++){
		cin>>x;
		cin>>t>>l;
		k[x].push_back(t);
		w[x].push_back(l);
	}
	int z;
	cin>>z;
	
	for(i=0;i<z;i++){
		cin>>city[i];
	}
	return z;
}

long long int min(long long int a,long long int b){
    if(a<b){
        return a;
    }
    return b;
}

int main(){
	queue <int> p;
	int m,n,c_to[100005],city[100005],q,visited[100005];
	long long int cost[100005];
	cost[1]=0;
	cin>>n>>m;
	int ca,cb,i,j;

	q=take_input(c_to,n-1,m,city);
	for(i=1;i<=n;i++){
		visited[i]=0;
	}
	p.push(1);
	while(!p.empty()){
		int d=p.front();
		p.pop();
		if(visited[d]==1){
			continue;
		}
		visited[d]=1;
		//cout<<d<<"\n";
		if(d!=1){

			m=INT_MAX;
			j=0;
			for(vector<int>::iterator it=k[d].begin();it!=k[d].end();it++){  //for all the tickets available at d city
				i=0;
			    ca=d;		    
    			while(i<k[d][j]&&ca!=1){
    				cb=c_to[ca];
    				m=min(m,cost[cb]+w[d][j]);
    				//if(ca!=d)
    				    //cout<<"("<<ca<<":"<<cost[ca]<<")\n";
    				ca=cb;
    				i++;
    			}
    			j++;
			}
			cost[d]=m;
		}

		
		//cout<<d<<"->"<<cost[d]<<"\n";
		j=0;
		//look into c_from 10^10 size
		for(i=1;i<=n;i++){
			if(c_to[i]==d){
				p.push(i);
			}
		}

	}
	k.clear();
	w.clear();
	//cout<<q<<"\n";
	for(i=0;i<q;i++){
		cout<<cost[city[i]]<<"\n";
	}
	
	return 0;
}