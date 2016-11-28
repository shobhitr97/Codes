#include<iostream>
#include<stack>

using namespace std;

int main(){
	int n,i,t,a[30005],vis[30005],p;
	cin>>n;
	cin>>t;
	for(i=1;i<=n-1;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		vis[i]=0;
	}
	stack <int> st;
	st.push(1);
	while(!st.empty()){
		p=st.top();
		st.pop();
		if(vis[p]==1){
			continue;
		}

		vis[p]=1;
		
// 		cout<<p<<"\n";
		if(p+a[p]==t){
		    cout<<"YES\n";
		    return 0;
		}
		st.push(p+a[p]);
		
	}
	cout<<"NO\n";	
	return 0;
}