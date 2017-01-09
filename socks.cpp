	#include<iostream>
	#include<vector>
	#include<algorithm>

	using namespace std;

	#define num 200005

	vector< vector <int> > nn(num,vector<int>(0));
	vector<int> color;
	int mark[num],c[num],vis[num];

	void dfs(int v){
		if(vis[v]){
			return;
		}
		vis[v]=1;
		color.push_back(c[v]);
		for(vector<int>::iterator it=nn[v].begin();it!=nn[v].end();++it){
			dfs(*it);
		}
	}

	int max(int a,int b){
		if(a>b){
			return a;
		}
		return b;
	}

	int main(){
		int n,m,k;
		int i,l,r,co;	

		cin>>n>>m>>k;

		for(i=0;i<n;i++){
			mark[i]=0;
		}

		for(i=0;i<n;i++){
			cin>>co;
			c[i]=co-1;
		}

		for(i=0;i<n;i++){
			vis[i]=0;
		}

		for(i=0;i<m;i++){
			cin>>l>>r;
			nn[l-1].push_back(r-1);
			nn[r-1].push_back(l-1);
			mark[l-1]=mark[r-1]=1;
		}
		int cc,cp,flag,siz,max_siz,size,ans;
		ans=0;
		for(i=0;i<n;i++){
			if(!mark[i]){
				continue;
			}
			if(vis[i]){
				continue;
			}
			color.clear();
			dfs(i);
			flag=1;
			siz=1;
			max_siz=0;
			sort(color.begin(),color.end());
			for(vector<int>::iterator ip=color.begin();ip!=color.end();++ip){
				if(flag){
					cp=*ip;
					flag=0;
					continue;
				}
				cc=*ip;
				if(cc!=cp){
					max_siz=max(max_siz,siz);
					siz=1;
					flag=1;
				}
				else{
					siz++;
					cp=cc;
				}
			}
			max_siz=max(max_siz,siz);
			ans+=( (int)color.size() - max_siz );
		
		}

		cout<<ans<<"\n";

		return 0;
	}
