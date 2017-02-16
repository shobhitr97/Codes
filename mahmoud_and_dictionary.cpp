#include<iostream>
#include<map>
#include<cstdio>
#include<vector>

using namespace std;

typedef vector <int> vec;
typedef vector < vector<int> > vvec;


map <string,int> dict;
vvec rels;
vvec rela;
bool vis[100005],val[100005];
int parent[100005];
// void dfs(int index, int value, int parent ){

// 	if(vis)

// }

// antonym -> 0
// synonym -> 1

void printt(vec vv){
	vec::iterator it;
	for( it=vv.begin() ; it != vv.end() ; it++ ){
		cout<<*it<<" ";
	}
	cout<<"\n";
}

void printt(int arr[],int n){
	int i;

	for( i=1 ; i<=n ;i++){
		cout<<arr[i] <<" ";
	}
	cout<<"\n";
}

void printt(bool arr[],int n){
	int i;

	for( i=1 ; i<=n ;i++){
		cout<<arr[i] <<" ";
	}
	cout<<"\n";
}

int par(int x){
	
	while(parent[x] != x ){
		x = parent[parent[x]];
	}
}

int value(int x){
	int t=x;
	bool c=val[x];
	while( parent[t] != t ){
		if(val[parent[t]] == 0 ){
			c = (!c);
		}
		t=parent[t];	
	}
	return c;
}

int main(){
	
	int n, m, q, i, x, y, z, par_x, par_y, val_x, val_y;
	string str,a,b,mem[100005];

	cin>>n>>m>>q;

	rels.resize(n+3);
	rela.resize(n+3);

	for( i=1 ; i<= n ;i++ ){

		cin>>mem[i];
		dict.insert( make_pair( mem[i] , i ) );
		// mem[i]=str;

	}

	for( i=1 ; i<=n ; i++ ){
		vis[i]=0;
		parent[i]=i;
	}

	for( i=1 ; i<=m ; i++ ){
		
		cin>>z;
		cin>>a>>b;

		x = dict[a];
		y = dict[b];

		par_x=par(x);
		par_y=par(y);

		// validity check
		if( vis[ x ] == 1 && vis[ y ] == 1 ){
			val_x = value(x);
			val_y = value(y);
			// cout<<"Value x:"<<val_x<<a<<" Value y:"<<val_y<<b<<"\n";
			if(par_x == par_y ){
				if(z==1){
					if(val_x != val_y ){
						cout<<"NO\n";
						continue;
					}
				}
				else{
					if(val_x == val_y ){
						cout<<"NO\n";
						continue;

					}
				}
			}
			else{
				
				// change in values of val due to change in ancestors
				/*If all the values do not come in sync then change the value of par(y) to zero
				  That would rectify the value of the parent and for all it's generations as they are aware that they have to take the complement
				  if the value of par(y) is zero
				*/
				
				if(z==1){
					if(val_x != val_y ){
						val[par_y]=0;
					}
				}
				else{
					if( val_x == val_y ){
						val[par_y]=0;
					}
				}
					
				parent[par_y]=par_x;

			}

		}
		else{

			if ( !vis[x] && !vis[y] ){
				
				parent[x] = x;
				parent[y] = x;
				val[x] = 1;
				val[y] = (z==1);
			
			}
			else{
				
				if(vis[x]){
					
					if(z==1){
						val[y]=val[x];
					}
					else{
						val[y] = (!val[x]);
					}
					parent[y]=parent[x];
		
				}
				else{
					
					if(z==1){
						val[x]=val[y];
					}
					else{
						val[x] = (!val[y]);
					}
					parent[x]=parent[y];
		
				}
		
			}
		
		}

		vis[x]=1;
		vis[y]=1;

		if(z==1){
			rels[ x ].push_back( y );
			rels[ y ].push_back( x );
		}
		else{
			rela[ x ].push_back( y );
			rela[ y ].push_back( x );			
		}
		cout<<"YES\n";
		// printt(parent,n);
		// printt(val,n);
		// printt(vis,n);
	}


	for( i=0 ; i<q ; i++ ){
		cin>>a>>b;
		x = dict[a];
		y = dict[b];
	
		if( vis[x]==0 || vis[y]==0 ){
			cout<<"3\n";
		}
		else{
			
			if( par(x) != par(y) ){
				cout<<"3\n";
			}
			else{
				
				if( value(x) != value(y) ){
					cout<<"2\n";
				}
				else{
					cout<<"1\n";
				}
	
			}
		
		}
	
	}

	return 0;
}