// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<utility>
// #include<stdio.h>
// #include<set>
// #include<map>
// #include<cmath>
// #include<queue>
// #include<stack>

// using namespace std;

// typedef long long int ll;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef pair<int, int> ii;
// typedef vector<ii> vii;
// typedef pair<int, ii> iii;
// typedef vector<iii> viii;
// typedef set<int> si;

// #define pb push_back
// #define mp make_pair
// #define fori(a, b) for(int i=a ; i<b ; i++ )
// #define forn(i, a, b) for(int i=a ; i<b ; i++ )
// #define forin(a, b) for(int i=a ; i>=b ; i-- )
// #define fi first
// #define se second
// #define INF 1000000007
// #define num 10005

// int main(){
// 	int n, x, arr1[num], arr2[num], k, r, c, per[105], t=0;
// 	double p;
// 	vector<double>output;
// 	while(1){
// 		cin>>n>>x;
// 		if(n==0&&x==0)	break;
// 		c=1;
// 		t++;
// 		fori(1, n+1){
// 			cin>>p;
// 			r=(int)(p*100.0);
// 			if(i==x)	k=r;
// 			else	per[c++]=r;
// 		}
// 		if(k<=5000){
// 			forn(j, 0, num-4)	arr1[j]=0, arr2[j]=0;
// 			arr1[k]=1, arr2[k]=1;
// 			forn(i, 1, n){
// 				forn(j, 0, num-4){
// 					if(arr1[j])	arr2[j+per[i] ]=1;
// 				}
// 				forn(j, 0, num-4)	arr1[j]=arr2[j];
// 			}
// 			r=-1;
// 			forn(i, 5000, 10001){
// 				if(arr1[i]){
// 					r=i;
// 					break;
// 				}
// 			}
// 		}
// 		else	r=k;
// 		if(r==-1){
// 			output.pb((double)(k/100.0));
// 		}
// 		else{
// 			// cout<<r<<"\n";
// 			p=(double)k/r;
// 			// cout<<p<<"\n";
// 			p=p*10000.000;
// 			r=(int)p;
// 			if(p-r>=0.5)	r++;
// 			output.pb((double)p/100);
// 		}
// 	}
// 	fori(0, t){
// 		printf("%.2f\n", output[i]);
// 	}
// 	return 0;
// }

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef set<int> si;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007

int main(){
	int n, x, t=0, j;
	bool dp[101][50004];
	double arr[103], tmp, per, minm;
	vector<double>output;
	while(1){
		cin>>n>>x;
		if(n==0&&x==0)	break;
		t++;
		j=1;
		fori(1, n+1){
			cin>>tmp;
			if(i==x)	per=tmp;
			else	arr[j++]=tmp;
		}

		if(per>50.00){
			output.pb(100.00);
		}
		else{
			minm=100.00;
			forn(k, 0, n)	fori(0, 5001)	dp[k][i]=false;
			dp[0][(int)(per*100.00)]=true;
			
			fori(1, n){
				forn(k, 0, 5001){
					if(dp[i-1][k]==true){
						dp[i][k]=true;
						if(k+(int)(arr[i]*100.00) > 5000)	minm=min(minm, (double)((double)k/100.000000)+arr[i]);
						else	dp[i][k+(int)(arr[i]*100.00)]=true;
					}
				}
			}
			tmp=(double)(per*100.00)/(minm);
			// cout<<tmp<<"\n";
			// tmp=86.657;
			output.pb(tmp);
		}
	}
	fori(0, t)	printf("%.2f\n", output[i]);
	return 0;
}