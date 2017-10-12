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
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007

vector<vector<int> > fu(int A){
	vector<vector<int> > solution;
    for(int i=0;i<2*A-1;i++){
        vector<int>vec;
        int num=A, j=0;
        while(j<2*A-1){
            if(i>=A-num&&i<A+num-1){
                if(j>=A-num&&j<A+num-2){
                    vec.push_back(num);
                    num--;
                }   
                else{
                	while(j<A-num||j>=A+num-1)	num++;
                	vec.push_back(num);
                }
            }
            else{
                num++;
                vec.push_back(num);
            }
            j++;
        }
        solution.push_back(vec);
    }
    return solution;
}

int main(){
	int a;
	cin>>a;
	vector<vector<int> >output=fu(a);
	fori(0, 2*a-1){
		forn(j, 0, 2*a-1)	cout<<output[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}