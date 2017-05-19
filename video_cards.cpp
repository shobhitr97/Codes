// #include<iostream>

// using namespace std;

// typedef long long int ll;
// #define num 200000 

// int min(ll a,ll b){
// 	if(a<b){
// 		return a;
// 	}
// 	return b;
// }

// ll max(ll a,ll b){
// 	if(a>b){
// 		return a;
// 	}
// 	return b;
// }

// int main(){
//     int n,i,ind,ind2,upper;
//     ll sum,maxm,j;
//     ll c[200005],a[200005],b[200005],ans[200005];
//     cin>>n;
//     upper=0;
//     for(i=0;i<=num;i++){
//     	c[i]=0;
//     	ans[i]=0;
//     }

//     for(i=0;i<n;i++){
//    		cin>>a[i];
//    		upper=max(upper,a[i]);
//    		c[a[i]]++;
//     }
//     for(i=0;i<n;i++){
//     	b[c[a[i]]-1]=a[i];
//     	c[a[i]]--;
//     }
//     for(i=1;i<=num;i++){
//     	c[i]+=c[i-1];
//     }
//     //  	 	cout<<"upper bound:"<<upper<<"\n";
//     maxm=0;
//     for(i=0;i<n;i++){
//     	sum=0;
//    		for(j=1;j*a[i]<=upper;j++){
//    			ind=min(num,a[i]*(j+1)-1);
//    			ind2=a[i]*j-1;
//    			sum+=((c[ind]-c[ind2])*(a[i]*j));
//    		}
//    		maxm=max(sum,maxm);
//    	}
//    	cout<<maxm<<"\n";
//     return 0;
// }


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define num 400005
typedef long long int ll;
typedef vector<int> vec;
typedef vector<ll> vecl;

int max( int a, int b){
  if( a>b ){
    return a;
  }
  return b;
}
int maxl( ll a, ll b){
  if( a>b ){
    return a;
  }
  return b;
}

int min( int a, int b){
  if( a<b ){
    return a;
  }
  return b;
}

int main(){

  int n, i, t;
  int x, arr[num], m, y;
  ll temp, sum; 
  vec a;

  cin >> n;

  for( i=0 ; i<400001 ; i++ ){
    arr[i] = 0;
  }

  m = 0;
  for( i=0 ; i<n ; i++ ){
    cin>>t;
    a.push_back(t);
    arr[t]++;
    m = max(m, t);
  }

  for( i=1 ; i<=(m<<1)+1 ; i++ ){
    arr[i] = arr[i-1] + arr[i];
  }

  sort(a.begin(), a.end());

  vec::iterator it;

  sum = 0;
  for( it = a.begin() ; it != a.end() ; it++ ){
    // cout<<(*iot)<<"\n";
    temp = 0;
    x = (*it);
   
    while( x <= m ){
      // y = min( x + (*it) - 1, m);
      temp += ((ll)arr[ x + (*it) - 1 ] - arr[ x - 1 ])*x;
      x = x + (*it);
    } 
    
    sum = maxl(sum, temp);
  
  }

  cout<<sum<<"\n";

  return 0;
} 