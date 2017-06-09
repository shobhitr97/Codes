#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

#define num 100005
#define forn(a,b) for( int i=a ; i<b  ; i++ )
#define pb push_back

typedef vector<int> vec;
typedef vector< vector <int> > vvec;
typedef long long int ll;

vvec rel;
ll dp[num][25][3], ans[num];
int n, a[num], nbits, arr[num][25];
bool vis[num];

int max(int a, int b){
    if( a>b ){
        return a;
    }
    return b;
}

void dfs( int index ){

    vis[index] = 1;

    vec::iterator it;


    ll sum1[25], sum0[25], pro00[25], pro01[25], pro11[25];    
    forn(0,nbits){
        sum0[i] = 0;
        sum1[i] = 0;
        pro00[i] = 0;
        pro01[i] = 0;
        pro11[i] = 0;
    }

    for( it = rel[index].begin() ; it != rel[index].end() ; it++ ){
        if( vis[(*it)]){
            continue;
        }

        dfs( (*it) );

        forn(0,nbits){
            
            if( arr[index][i] ){
                dp[index][i][0] += dp[(*it)][i][1];
                dp[index][i][1] += dp[(*it)][i][0];
            }
            else{
                dp[index][i][0] += dp[(*it)][i][0];
                dp[index][i][1] += dp[(*it)][i][1];
            }

            sum0[i] += dp[(*it)][i][0];
            sum1[i] += dp[(*it)][i][1];
            pro00[i] += (dp[(*it)][i][0]*dp[(*it)][i][0]);
            pro01[i] += (dp[(*it)][i][0]*dp[(*it)][i][1]);
            pro11[i] += (dp[(*it)][i][1]*dp[(*it)][i][1]);

        }

    }
    // cout<<"\n>"<<index<<"\n";

    forn(0,nbits){

        if( arr[index][i] ){
            dp[index][i][1] ++;
            ans[i] += ( ( ( sum1[i]*sum1[i] ) - pro11[i] )/2 + ( ( sum0[i]*sum0[i] ) - pro00[i] )/2  );
        }
        else{
            dp[index][i][0] ++;
            ans[i] += ( ( sum1[i]*sum0[i] ) - pro01[i] );
        }

        // cout<<dp[index][i][0]<<" "<<dp[index][i][1]<<"\n";

        ans[i] += dp[index][i][1];
        // cout<<ans[i]<<" ";
    }
    // cout<<"\n";

}

int main(){

    int u, v, maxm, temp;
    ll sum;

    cin >> n;

    rel.resize(n+2);

    maxm = 0;
    forn(1,n+1){
        cin>>a[i];
        maxm = max(maxm, a[i]);
        vis[i] = 0;
    }

    forn(1,n){
        cin>>u>>v;
        rel[u].pb(v);
        rel[v].pb(u);
    }

    // cout<<maxm<<"\n";
    nbits = 0;
    while(maxm){
        maxm = maxm/2;
        nbits++;
    }

    // cout<<nbits<<"\n";

    forn(1,n+1){
        temp = a[i];
        for( int j=0 ; j<nbits ; j++ ){
            arr[i][j] = temp%2;
            temp /= 2;

            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
            // cout<<arr[i][j]<<" ";
        }
        // cout<<"\n";
        ans[i] = 0;
    }

    dfs(1);
    ll t = 1;
    t = 1;
    sum = 0;
    // cout<<"\n";
    forn(0,nbits){
        // cout<<ans[i]<<"\n";
        sum += (t*ans[i]);
        t = t<<1;

    }
    // cout<<"\n";

    cout<<sum<<"\n";

    return 0;
}