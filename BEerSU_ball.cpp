// //maximum matching
// #include<iostream>
// #include<stack>
// #include<utility>
// #include<stdlib.h>
// #include<math.h>

// using namespace std;

// // stack <pair<int,int> > st;

// int max(int a,int b){
// 	if(a>b){
// 		return a;
// 	}
// 	return b;
// }

// int adj[105][105],vis[2][105];
// // //boys 0
// // //girls 1
// // int get_val(int sex,int start){
// //     int i,ch;
// //     ch=0;
// //     if(sex){
// //         for(i=0;i<n;i++){
// //             if(adj[i][start]==1){
// //                 ch=1;
// //                 break;
// //             }
// //         }
// //     }
// //     else{
// //         for(i=0;i<m;i++){
// //             if(adj[start][i]==1){
// //                 ch=1;
// //                 break;
// //             }
// //         }
// //     }
// //     if(!ch){
// //         return 0;
// //     }
// //     vis[sex][start]=1;

// // 	st.push(make_pair(sex,start));
// // 	int k=0,num,s,index;
// // 	while(!st.empty()){
// // 		s=st.top().first;
// // 		index=st.top().second;

// // 		st.pop();

// // 		k=max(k,vis[s][index]);
	  
// // 	    s=1-s;
// // 		if(s){
// //     		for(i=0;i<m;i++){
// //     			if(adj[index][i]==1){
// //     			    if(vis[s][i]==0){
// //     			        vis[s][i]=vis[!s][index]+1;
// //     				    st.push(make_pair(s,i));
// //     			    }
// //     			}
// //     		}
// // 	    }
// // 	    else{
// // 	        for(i=0;i<n;i++){
// //     			if(adj[i][index]==1){
// //     			    if(vis[s][i]==0){
// //         			    vis[s][i]=vis[!s][index]+1;
// //         				st.push(make_pair(s,i));
// //     			    }
// //     			}
// //     		}
// // 	    }
// // 	}
// // 	return k;
// // }

// // int main(){
// // 	int skill[2][100],j,i,sum,x;
// // 	cin>>n;
// // 	for(i=0;i<n;i++){
// // 		cin>>skill[0][i];
// // 	}
// // 	cin>>m;
// // 	for(i=0;i<m;i++){
// // 		cin>>skill[1][i];
// // 	}
// // 	for(i=0;i<max(m,n);i++){
// // 	    vis[0][i]=vis[1][i]=0;
// // 	}
// // 	for(i=0;i<n;i++){
// // 		for(j=0;j<m;j++){
// // 			if(abs(skill[0][i]-skill[1][j])<=1){
// // 				adj[i][j]=adj[j][i]=1;
// // 			}
// // 			else{
// // 			    adj[i][j]=0;
// // 			}
// // 		}
// // 	}
// // // 	for(i=0;i<n;i++){
// // // 	    for(j=0;j<m;j++){
// // // 	        cout<<adj[i][j]<<" ";
// // // 	    }
// // // 	    cout<<"\n";
// // // 	}
// // 	sum=0;

// // 	for(i=0;i<n;i++){
// // 		if(vis[0][i]!=0){
// // 			continue;
// // 		}
// // 		else{
// // 			x=get_val(0,i);
// // 			sum+=floor((x+1)/2);
// // 		}
// // 	}
	
// // 	for(i=0;i<m;i++){
// // 	    if(vis[1][i]!=0){
// // 	        continue;
// // 	    }
// // 	    else{
// // 	        x=get_val(1,i);
// // 	        sum+=floor((x+1)/2);
// // 	    }
// // 	}
// // 	cout<<sum<<"\n";
// // 	return 0;
// // }

// int count[105],b[105],maxm,bo[105],gi[105];
// void sort_arr(int *a,int n){
// 	int i;
// 	for(i=0;i<=100;i++){
// 		count[i]=0;
// 	}
// 	for(i=1;i<=n;i++){
// 		count[a[i]]++;
// 	}
// 	for(i=1;i<=100;i++){
// 		count[i]=count[i-1]+count[i];
// 	}
// 	for(i=1;i<=n;i++){
// 		b[count[a[i]]]=a[i];
// 		count[a[i]]--;
// 	}
// 	for(i=1;i<=n;i++){
// 		a[i]=b[i];
// 	}
// 	// for(i=1;i<=n;i++){
// 	// 	cout<<a[i]<<" ";
// 	// }
// 	// cout<<"\n";
// }

// void recur(int index,int origin,int gender,int n,int m){
// 	int i,val,limit;
// 	cout<<gender<<":"<<index<<"\n";
// 	if(gender==0){
// 		val=bo[i];
// 		limit=m;
// 	}
// 	else{
// 		val=gi[i];
// 		limit=n;
// 	}
// 	vis[gender][index]=max(vis[gender][origin],val+vis[!gender][origin]);

// 	if(vis[gender][index]>0){
// 		if(val+vis[1-gender][origin]>vis[gender][index]){
// 			vis[gender][index]=val+vis[1-gender][origin];			
// 		}
// 		else{
// 			return;
// 		}
// 	}
// 	else{
// 		vis[gender][index]=val+vis[1-gender][origin];
// 	}
// 	maxm=max(maxm,vis[gender][index]);
// 	for(i=1;i<=limit;i++){
// 		if(limit==m){
// 			for(i=1;i<=limit;i++){
// 				if(adj[index][i]==1&&i!=origin){
// 					recur(i,index,1,n,m);
// 				}
// 			}
// 		}
// 		else{
// 			for(i=1;i<=n;i++){
// 				if(adj[i][index]==1&&i!=origin){
// 					recur(i,index,0,n,m);
// 				}
// 			}
// 		}
// 	}
// }

// int main(){
// 	int i,n,m,j;
// 	cin>>n;
// 	for(i=1;i<=n;i++){
// 		cin>>bo[i];
// 	}
// 	sort_arr(bo,n);
// 	cin>>m;
// 	for(i=1;i<=m;i++){
// 		cin>>gi[i];
// 	}
// 	sort_arr(gi,m);

// 	for(i=1;i<=n;i++){
// 		for(j=1;j<=m;j++){
// 			if(i!=j){
// 				if(abs(bo[i]-gi[j])<=1){
// 					adj[i][j]=1;				}
// 			}
// 		}
// 	}

// 	maxm=0;

// 	for(i=0;i<=100;i++){
// 		vis[0][i]=vis[1][i]=0;
// 	}

	

	
// 	for(i=1;i<=n;i++){
// 		if(vis[0][i]==0){
// 			vis[0][i]=1;
// 			for(j=1;j<=m;i++){
// 				if(adj[i][j]==1){
// 					break;
// 				}
// 			}
// 			recur(j,i,1,n,m);	
// 		}
// 	}
	

// 	for(i=0;i<=100;i++){
// 		cout<<vis[0][i]<<":"<<vis[1][i]<<"\n";
// 	}
// 	for(i=1;i<=m;i++){
// 		if(vis[1][i]==0){
// 			vis[1][i]=1;
// 			for(j=1;j<=n;i++){
// 				if(adj[j][i]==1){
// 					break;
// 				}
// 			}
// 			recur(j,i,0,n,m);
// 		}
// 	}
// 	vis[1][i]=1;
// 	recur(1,i,0,n,m);
// 	for(i=0;i<=100;i++){
// 		cout<<vis[0][i]<<":"<<vis[1][i]<<"\n";
// 	}
// 	cout<<maxm/2<<"\n";
// 	return 0;
// }
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef vector<int> vec;

int main(){
	vec girls, boys;
	int n, m, i, j, count, x;

	cin>>n;

	for( i=0 ; i<n ; i++ ){
		cin>>x;
		boys.push_back(x);
	}

	cin>>m;

	for( i=0 ; i<m ; i++ ){
		cin>>x;
		girls.push_back(x);
	}
	sort(boys.begin(),boys.end());
	sort(girls.begin(),girls.end());
	count = 0;
	for( i=0 ; i<n ; i++ ){
		for( j=0 ; j<m ; j++ ){
			if(abs(boys[i]-girls[j])<=1){
				count++;
				girls[j] = 10000;
				break;
			}
		}
	}
	cout<<count<<"\n";
	return 0;
}