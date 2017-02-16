#include<iostream>
#include<vector>

using namespace std;

typedef vector < vector <int> > vvec;
typedef vector < int > vec;

vvec fin;
vec f;

int main(){

	int n,i,j,m,x;
	bool visf[100005],flag=1;

	cin>>n;

	f.resize(n+2);
	fin.resize(n+2);

	vec g;
	g.resize(n+2);
	vec h;
	h.push_back(0);
	vec::iterator it;

	for( i=1 ; i<=n ; i++ ){
		cin>>f[i];
		fin[f[i]].push_back(i);
		visf[i] = 0;
	}

	m = 1;

	for( i=1 ; i <= n ; i++ ){
		x = f[i];
		if(visf[x]){
			continue;
		}

		visf[x]=1;

		for (it = fin[x].begin() ; it!=fin[x].end() ; it++ ){
			g[*it] = m;
		}

		h.push_back(x);

		if(g[x] != m){
			flag=0;
			break;
		}

		m++;

	}

	if(flag==0){
		cout<<"-1\n";
		return 0;
	}

	m--;
	cout<<m<<"\n";

	for(i=1 ; i<=n ; i++){
		cout<<g[i]<<" ";
	}
	cout<<"\n";

	for(i=1 ; i<=m ; i++ ){
		cout<<h[i]<<" ";
	}
	cout<<"\n";

	return 0;
}