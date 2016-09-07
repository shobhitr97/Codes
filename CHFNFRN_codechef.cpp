#include<iostream>
#include<vector>
#include<utility>
#include<stack>

using namespace std;
/*
//might be helpful somewhere else here it seems completely useless
vector <vector <int> > pp(2,vector<int>(0));
//priority_queue<int,vector<int>,greater<int> > pr;
int arr[1005];
for(i=0;i<=1000;i++){
	arr[i]=0;
}
for(i=0;i<m;i++){
	cin>>a>>b;
	arr[a]++;
	arr[b]++;
}

//sort arr
//so that the probability of a node to be connected to all the nodes of both the lists is least		 

pp[0].push_back(1);
for(i=2;i<=n;i++){
	ans=0;
	// if the node under consideration is not connected to any node from both the lists then the seating is not possible
	//so we just have to consider each node and add it to the list of which all the nodes it is connected to 
	//keep on maintaining the two lists
	//problem:if node is connected to all the nodes of both the lists then it is not clear what to do
	for(j=0;j<2;j++){
		if(pp[j].empty()){
			continue;
		}
		inc=1;
		for(vector<int>::iterator it=pp[j].begin();it!=pp[j].end();it++){
			if(conn[v][*it]!=1){
				inc=0;
				break;
			}
		}
		if(inc==1){
			ans=1;
		}
	}
	if(ans==0){
		//cout no
		break;
	}
}
*/
//a different approach
// almost correct 
//flaw:this is not exhaustive since any cycle with odd number of edges would result in a NO,not just 3.
/*
typedef vector<int> vec;
int a[1001][1001];
int check(int n){
	int i,j;
	vec p;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(a[i][j]==1&&i!=j){                  //they do not know each other
				if(p.empty()){
					p.push_back(j);
					continue;
				}
				for(vec::iterator it=p.begin();it!=p.end();it++){
					if(a[j][*it]==1){
						p.clear();
						//cout<<i<<":"<<j<<":"<<*it<<"\n";
						return 0;
					}
				}
				p.push_back(j);
			}
		}
		p.clear();
	}

	return 1;
}


int main(){
	int i,n,m,t,x,y,j;
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(n==1||n==2){
			cout<<"YES\n";
			continue;
		}		
		for(i=0;i<=n;i++){
		    for(j=0;j<=n;j++){
		        if(i==j){
		            a[i][i]=0;
		        }
		        else{
		        a[i][j]=1;
		        }
		    }
		}
		for(i=0;i<m;i++){
			cin>>x>>y;
			a[x][y]=0;
			a[y][x]=0;
		}
		if(check(n)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}
*/


int visited[1005],a[1005][1005];

int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}

int dfs(int n){
	stack <pair<int,int> > st;
	int i,j,col,t,ans,ind;
	ans=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(a[i][j]==1&&i!=j){
				ans=1;
				ind=i;
				break;
			}
		}
		if(ans==1){
			break;
		}
	}
	if(ans==0){
		return 1;
	}
	st.push(make_pair(ind,1));
	while(!st.empty()){
		pair<int,int> p=st.top();
		st.pop();
		t=p.first;
		col=p.second;
		if(visited[t]!=0){
			if(col!=visited[t]){
				while(!st.empty()){
					st.pop();
				}
				return 0;
			}
			else{
				continue;
			}
		}
		visited[t]=col;
		col=(2*col)%3;   //colour inverse:1->2;2->1
		for(i=1;i<=n;i++){
			if(i!=t&&a[i][t]==1){
				st.push(make_pair(i,col));
			}
		}
	}
	return 1;
}

int main(){
	int i,t,j,n,m,x,y;
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(n==2||n==1){
			cout<<"YES\n";
			continue;
		}
		for(i=0;i<=n;i++){
			visited[i]=0;
			for(j=0;j<=n;j++){
				if(i!=j)
					a[i][j]=1;
				else{
					a[i][i]=0;
				}
			}
		}
		for(i=0;i<m;i++){
			cin>>x>>y;
			a[x][y]=a[y][x]=0;
		}
		if(dfs(n)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}


