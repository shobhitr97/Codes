#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define num 1000000007
#define num1 1299827	
#define num3 1000679
#define num2 1016027

typedef long long int ll;
typedef vector< long long int > vecl;
typedef vector<int> vec;
typedef vector < vector<int> > vvec;

ll fact[num2+2];
vvec g;

void fill(int n){

	ll i=2;

	fact[1] = 1;
	fact[0] = 1;

	while(i<=n){

		fact[i] = ( fact[i-1] * i )%num ;
		i++;
	
	}

}

ll poww(int a,int b ){
	ll x,y;
	y=a;
	x=1;
	while(b){
		if(b%2==1){
			x = (x*y)%num;
		}
		y = (y*y)%num;
		b/=2;
	}
	return x;
}

// 0 -> equal,   -1 -> less,   1 -> greater
int compare( int i1, int i2 ){
	
	vec::iterator r1;
	vec::iterator r2;

	int siz1, siz2;
	
	siz1 = g[i1].size();
	siz2 = g[i2].size();

	int siz = min(siz1, siz2);

	for( int i=0 ; i<siz ; i++ ){
		if( g[i1][i] == g[i2][i]){
			continue;
		}

		if( g[i1][i] < g[i2][i] ){
			return -1;
		}
		else{
			return 1;
		}
	}

	if( siz1 == siz2 ){
		return 0;
	}
	
	if( siz1 > siz2 ){
		return 1;
	}

	return -1;

}

void merge( int l1, int r1, int l2, int r2){

	int op_res, counter2, counter1, counter, i;

	counter1 = l1;
	counter2 = l2;
	counter = 0;

	vvec temp;
	temp.resize( r2 - l1 + 3);

	while( counter1 <= r1 && counter2 <= r2 ){

		op_res = compare(counter1, counter2);

		if( op_res == 0 || op_res == -1 ){
			temp[counter].assign(g[counter1].begin(), g[counter1].end() );
			counter1++;
		}
		else{
			temp[counter].assign(g[counter2].begin(), g[counter2].end() );
			counter2++;
		}

		counter++;
	
	}

	if( counter1 <= r1 || counter2 <= r2 ){
		if( counter1 <= r1 ){
			while(counter1 <= r1){
				temp[counter].assign(g[counter1].begin(), g[counter1].end() );
				counter1++;	
				counter++;
			}
		}
		else{
			while( counter2 <= r2 ){
				temp[counter].assign(g[counter2].begin(), g[counter2].end() );
				counter2++;
				counter++;
			}
		}
	}

	for( i=0 ; i < (r2-l1+1) ; i++ ){
		// g[ l1 + i ].clear();
		g[ l1 + i ].assign(temp[i].begin(), temp[i].end() );
		temp[i].clear();
	}

}

void mergesort( int l, int r){
	
	if( l >= r ){
		return ;
	}

	int mid = (l+r)/2;

	mergesort( l, mid);
	mergesort( mid+1, r);

	merge( l, mid, mid+1, r);

}

int main(){

	int n, m, i, gi, t;
	cin >> n >> m ;
	fill(m+2);

	g.resize(m+5); //for the types of pokemons 

	for( i=0 ; i<n ; i++ ){
		cin>>gi;
		while( gi-- ){
			
			cin>>t;
	
			g[t].push_back(i);
	
		}
	
	}
	// g.clear();
	// Sorting g : main step

	// mergesort(1, m );
	for( i=1 ; i<=m ; i++ ){
		sort(g[i].begin(), g[i].end());
	}
	sort(g.begin()+1, g.end()-4);

	// printing
	// cout<<"\n";
	// vec::iterator it;
	// for( i=1 ; i<=m ; i++ ){
	// 	cout<<"-";
	// 	for( it = g[i].begin() ; it != g[i].end() ; it++ ){
	// 		cout<<(*it)<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	// Calculation
	// cout<<"\n";
	int p=1;
	ll ans = 1;
	// cout<<1<<" ";
	for( i=2 ; i<=m ; i++ ){
		if(  g[i]==g[i-1]  ){
			// cout<<i<<" ";
			p++;
			continue;
		}
		ans  = (ans*fact[p])%num;
		// cout<<"fact["<<p<<"]="<<fact[p];
		// cout<<"\n"<<i<<" ";
		p=1;
	}
	ans  = (ans*fact[p])%num;

	// cout<<"\n";
	cout<<ans<<"\n";

}

// int main(){

// 	int n,m,i,g,j,k,sec,x;
// 	ll ans;

// 	fill();
// 	// for(i=0;i<=10;i++){
// 	// 	cout<<i<<" : "<<fact[i]<<"\n";
// 	// }

// 	vl a1;
// 	vl a2;
// 	vl a3;
// 	// vi pp;
// 	vl ff;

// 	cin>>n>>m;

// 	// pp.resize(m+2);
// 	ff.resize(m+2);
// 	a2.resize(m+2);
// 	a1.resize(m+2);
// 	a3.resize(m+2);
// 	//vi g;

// 	//g.resize(n+1);

// 	for(i=0;i<m;i++){
// 		ff[i]=0;
// 		a1[i]=0;
// 		a2[i]=0;
// 		a3[i]=0;
// 	}

// 	for( i=0 ; i < n ; i++ ){
		
// 		cin>>g;

// 		for( j=0 ; j < g ; j++ ){
// 			cin>>k;
// 			ff[k-1]+= 1;
// 			// x = poww(num1,i)%num;
// 			// cout<<x<<"\n";
// 			a1[k-1] = ( a1[k-1]+ ( ( poww(num1,i) )%num ) )%num; //poww will calculated multiple times
// 			a2[k-1] = ( a2[k-1]+ ( ( poww(num2,i) )%num ) )%num;
// 			a3[k-1] = ( a3[k-1]+ ( ( poww(num3,i) )%num ) )%num;
// 		}

// 	}

// 	// for(i=0;i<m;i++){
// 	// 	cout<<a1[i]<<" ";
// 	// }
// 	// cout<<"\n";

// 	// for(i=0;i<m;i++){
// 	// 	cout<<a2[i]<<" ";
// 	// }
// 	// cout<<"\n";	

// 	sort(a1.begin(),a1.begin()+m);
// 	sort(a2.begin(),a2.begin()+m);
// 	sort(a3.begin(),a3.begin()+m);

// 	// for(i=0;i<m;i++){
// 	// 	cout<<a1[i]<<" ";
// 	// }
// 	// cout<<"\n";

// 	// for(i=0;i<m;i++){
// 	// 	cout<<a2[i]<<" ";
// 	// }
// 	// cout<<"\n";

// 	sec=1;
// 	i=1;
// 	ans=1;

// 	while(i!=m){
// 		if( ff[i] && a1[i]==a1[i-1] &&  a2[i]==a2[i-1] && a3[i]==a3[i-1] ){
// 			sec++;
// 		}
// 		else{
// 			// cout<<sec<<":"<<fact[sec]<<"\n";
// 			ans = ( ans*fact[sec] )%num;
// 			sec=1;
// 		}
// 		i++;
// 	}
// 	ans = ( ans*fact[sec] )%num;     // for the end 

// 	cout<<ans<<"\n";

// 	return 0;
// }

