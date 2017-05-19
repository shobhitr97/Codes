// #include<iostream>

// using namespace std;

// typedef long long int ll;

// ll mi, ma;

// ll max(ll a,ll b){
// 	if(a>b){
// 	return a;
// 	}
// 	return b;
// }

// ll min(ll a,ll b){
// 	if(a<b){
// 	return a;
// 	}
// 	return b;
// }

// // // ll perm(ll t){
// // // 	if(t==0){
// // // 		return d;
// // // 	}
	
// // // 	d=(d*(u+1-t))/t;
// // // 	return d;
// // // }

// // int main(){
// // 	ll n, c1, c2, mi, ma, cost_2, cost_1, temp, comb;		
// // 	int i, bits;

// // 	cin >> n >> c1 >> c2 ;

// // 	mi = min(c1, c2);
// // 	ma = max(c1, c2);

// // 	cost_2 = ( n*(n-1) )/2 * mi + ma * n;

// // 	temp = 1;
// // 	i = 0;
// // 	while( temp < n ){
// // 		temp = temp<<1;
// // 		i++;
// // 	}
// // 	bits = i;

// // 	// cout<<bits<<"\n";

// // 	temp = n;
// // 	comb = 1;
// // 	cost_1 = 0;
// // 	i=0;

// // 	while( temp && comb <= temp ){
// // 		// cout<<comb<<"\n";
// // 		cost_1 += comb*( (bits-i)*mi + i*ma );
// // 		temp -= comb;
// // 		comb = ( comb*(bits-i) )/( i+1 ) ;
// // 		i++;
// // 		// cout<<cost_1<<"\n";
// // 	}

// // 	cost_1 += temp*( (bits-i)*mi + i*ma );  //check for negative of there is any problem

// // 	cout<<min(cost_1, cost_2)<<"\n";

// // 	// if(mi==0){
// // 	// 	cout<<ma*(n);
// // 	// 	return 0;
// // 	// }
// // 	// //to find number of bits
// // 	// i=0;
// // 	// c=1;
// // 	// temp=n;
// // 	// while(temp>=2){
// // 	// 	temp/=2;
// // 	// 	i++;
// // 	// 	c*=2;
// // 	// }
// // 	// u=i;


// //  // 	if(u){
// //  // 		ans=0;
// //  // 		d=1;
// // 	// 	ans+=(u*(c/2)*(c1+c2));

// // 	// 	k=(n-c+((n-c)%2))/2;
// // 	// 	j=0;
// // 	// 	pt=perm(j);
// // 	// 	while(k>pt){
// // 	// 		ans+=((u-j)*mi+j*ma)*pt;	
// // 	// 		k-=pt;
// // 	// 		j++;
// // 	// 		pt=perm(j);
// // 	// 		cout<<u<<":C:"<<j<<" :"<<pt<<"\n";
// // 	// 	}
// // 	// 	cout<<k;
// // 	// 	ans+=((u-j)*mi+j*ma)*k;

// // 	// 	ans+=(k*ma+k*mi);
// //  // 	}
// //  // 	else{
// //  // 		ans=mi;
// //  // 	}

// // 	// cout<<ans<<"\n";

// // 	return 0;
// // }

// //Recursive approach

// ll find_cost(ll n){
	
// 	if( n == 1 ){
// 		return 0;
// 	}
	
// 	int logn;
// 	ll  ans, temp;

// 	temp = 1;
// 	logn = 0;

// 	while( temp < n){
// 		temp = temp<<1;
// 		logn++;
// 	}
	
// 	if( temp == n ){
// 		ans = (logn * ( mi + ma ) * temp)/2;
// 	}
// 	else{
// 		ans = ( (logn - 1) * ( mi + ma ) * (temp/2) )/2;
// 		ans += (temp/2)*mi;
// 		ans += ( n - temp/2 ) * ma + find_cost( n - temp/2 );
// 	}

// 	return ans;
		
// }

// int main(){
// 	ll n, c1, c2;
// 	cin >> n >> c1 >> c2;
// 	mi = min(c1, c2);
// 	ma = max(c1, c2);
// 	if( mi == 0 ){
// 		cout<<((n-1)*ma)<<"\n";
// 		return 0;
// 	}
// 	cout<<find_cost(n)<<"\n";
// 	return 0;
// }

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstdlib>
#include<new>

using namespace std;

typedef long long int ll;

struct Node{
	ll val, minm;
	struct Node *parent, *right, *left, *minn ;
};

struct Node* make_node( ll value ){
	struct Node* node;
	node = (struct Node*)malloc(sizeof(struct Node));
	node->val = value;
	node->parent=NULL;
	node->right=NULL;
	node->left=NULL;
	node->minn=NULL;
	return node;
}

int main(){
	ll n, c0, c1;
	int i;

	cin >> n >> c0 >> c1;

	if( min(c0, c1) == 0 ){
		cout<<(n-1)*max(c0, c1)<<"\n";
		return 0;
	}

	struct Node* root = make_node(0);
	root->minn = root;
	root->minm = 0;

	struct Node *par, *node, *nod1, *nod2;

	ll ans = 0;

	for( i=0 ; i<n ; i++ ){
		par = root->minn;
		nod1 = make_node(par->val + c0);
		nod2 = make_node(par->val + c1);
		ans += par->val + c0 + c1;
		nod1->minn = nod1;
		nod2->minn = nod2;
		nod1->minm = nod1->val;
		nod2->minm = nod2->val;
		nod1->parent = par;
		par->left = nod1;
		par->right = nod2;
		node = par;
		while(node != NULL ){
			if( node->left->minm < node->right->minm ){
				node->minm = node->left->minm;
				node->minn = node->left->minn;
			}
			else{
				node->minm = node->right->minm;
				node->minn = node->right->minn;	
			}
			node = node->parent;
		}
	}

	cout<<ans<<"\n";

	return 0;
}
