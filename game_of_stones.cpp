#include<iostream>
#include<set>

using namespace std;

int gr[64],vis[65];

int dfs(int num){
	if(num == 0){
		return 0;
	}
	// cout<<"----\n";
	set <int> lis;
	set<int>::iterator it;
	int t,i;
	lis.clear();
	for( i=1 ; i<=num ; i++ ){
		if(!vis[i]){
			vis[i]=1;
			t = dfs(num-i);
			lis.insert(t);
			vis[i]=0;
		}
	}

	// for( it = lis.begin() ; it!= lis.end() ; it++ ){
	// 	cout<<(*it)<<" ";
	// }
	// cout<<"\n";

	if( lis.empty() ){
		return 0;
	}
	
	for( i=0 ; i<=num ; i++ ){
		if( lis.find(i) == lis.end() ){
			// cout<<i<<"\n";
			return i;
		}
	}

	return 0;

}

int main(){
	
	int i,j;

	int gr[] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};
	// int n;
	// cin>>n;	

	// for( i=1 ; i<=n ; i++ ){
	// 	for( j = 1 ; j <= 60 ; j++ ){
	// 		vis[j]=0;
	// 	}
	// 	gr[i] = dfs(i);
	// 	cout<<gr[i]<<",";
	// }
	// cout<<"\n";

	int n,s,ans;

	cin>>n;
	ans=0;

	for( i=1 ; i<=n ; i++){
		cin>>s;
		ans = ans^gr[s];
	}

	if(ans==0){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	return 0;
}