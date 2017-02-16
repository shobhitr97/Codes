#include<iostream>
#include<utility>
#include<stack>

using namespace std;

#define num 200005
typedef long long int ll;

ll w[num],a[num],dis[num];
int p[num],n,level[num],max_lvl;
int anc[num][18],cont[num],stop[num];

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int llog(int a){
	int i;
	for(i=0;1<<i<=a;i++);
	i--;
	return i;
}

ll do_fill(int ind,int vis[]){
	if(vis[ind]==1){
		return dis[ind];
	}
	vis[ind]=1;
	dis[ind]=w[ind]+do_fill(p[ind],vis);
	level[ind]=1+level[p[ind]];
	max_lvl=max(max_lvl,level[ind]);
	return dis[ind];
}

void fill_dis(){
	int vis[num];
	int st=n,i;

	for(i=1;i<=n;i++){
		vis[i]=0;
	}

	dis[1]=0;
	vis[1]=1;
	level[1]=1;
	for(st=n;st>=2;st--){
		if(vis[st]){
			continue;
		}
		dis[st]=do_fill(st,vis);
	}
}

void anc_fill(int powr){
	int i,j;
	for(i=1 ; i<=n ; i++){
		for(j=0 ; j<=powr; j++){
			anc[i][j]=-1;
		}
	}

	for(i=1; i<=n; i++){
		anc[i][0]=p[i];
	}

	for(j=1;j<=powr ; j++){
		for(i=2 ; i<=n ; i++){
			anc[i][j]=anc[ anc[i][j-1] ][j-1];
		}
	}
}

void printt(ll arr[]){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<"\n";
	}
}

void printt(int arr[]){
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<"\n";
	}
}

int main(){

	int i,log,j;

	cin>>n ;
	max_lvl=n;
	for(i=1 ; i<=n ; i++){
		cin>>a[i];
	}

	p[1]=-1;
	w[1]=0;
	for(i=2 ; i<=n;i++){
		cin>>p[i]>>w[i];
	}

	fill_dis();

	// printt(dis);
	// printt(level);

	for(log=0 ; 1<<log <= max_lvl;log++);
	log--;

	anc_fill(log);

	// for(i=1;i<=n;i++){
	// 	for(j=0;j<=log;j++){
	// 		cout<<anc[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	for(i=0;i<=n;i++){
		cont[i]=0;
	}

	//the node which the source node can be controlled can be
	//as follows
	int tmp;
	

	for(i=1;i<=n;i++){
		stop[i]=0;
	}

	for(i=2;i<=n;i++){
		tmp=i;
		for(j=llog(level[i]);j>=0;j--){
			if(anc[tmp][j]!=-1&&dis[i]-dis[ anc[tmp][j] ]<=a[i]){
				tmp=anc[tmp][j];
			}
		}
		stop[tmp]++;
	}
	// printt(upto);

	// now i need it to add 1 to all those ancestors lie in the
	//path from i to upto[i]

	vector< vector<int> > child (n,vector<int> (0));

	for(i=1;i<=n;i++){
		child[p[i]].push_back(i);
	}



	return 0;
}