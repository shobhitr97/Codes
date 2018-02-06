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

int main(){

	ll bounty, increase, damage;
	vll s, maxHealth, r;
	vector<vii> enemyTime;
	vector<pair<double, int> > timeLine;

	int n, m, cnt, prevHealth;
	ll a, b, c, ans=0;
	bool isInf = false;
	double timeIntersection, prevTime;

	cin>>n>>m;

	cin>>bounty>>increase>>damage;

	fori(0, n){
		cin>>a>>b>>c;
		if(a < damage)	isInf = true;
		maxHealth.pb(a);
		s.pb(b);
		r.pb(c);
	}

	enemyTime.resize(n);
	fori(0, m){
		cin>>a>>b>>c;
		enemyTime[b-1].pb(mp(a, c));
	}

	if(increase > 0 && isInf == true){
		cout<<"-1\n";
		return 0;
	}

	fori(0, n){
		sort(enemyTime[i].begin(), enemyTime[i].end());
	}

	cnt = 0;
	fori(0, n){

		if(maxHealth[i] <= damage){
			cnt++;
			continue;
		}

		prevHealth = s[i];
		prevTime = 0;

		if(prevHealth <= damage){ cnt++; }

		if(enemyTime[i].size() > 0){
			
			int siz = enemyTime[i].size();

			forn(j, 0, siz){

				if(r[i] == 0){
					if(prevHealth > damage && enemyTime[i][j].se <= damage){ timeLine.pb( mp( (double)enemyTime[i][j].fi, -1 ) ); }
					if(prevHealth <= damage && enemyTime[i][j].se > damage){ timeLine.pb( mp( (double)enemyTime[i][j].fi, 1 ) ); }
				}
				else{

					if(prevHealth > damage && enemyTime[i][j].se <= damage){
						timeLine.pb( mp( (double)enemyTime[i][j].fi, -1 ) );
					}
					
					if(prevHealth <= damage){
						timeIntersection = prevTime + (double)(damage - prevHealth)/(double)r[i];
						if(enemyTime[i][j].fi > timeIntersection){
							timeLine.pb( mp( timeIntersection, 1 ) );
							if(enemyTime[i][j].se <=  damage){
								timeLine.pb( mp( (double)enemyTime[i][j].fi, -1 ) );
							}
						}
						else{
							if(enemyTime[i][j].se > damage){
								timeLine.pb( mp( (double)enemyTime[i][j].fi, 1 ) );
							}
						}
					}
				}

				prevTime = enemyTime[i][j].fi;            // No explicit integer to double conversion
				prevHealth = enemyTime[i][j].se;

			}
		}

		if(prevHealth <= damage && r[i] > 0){
			timeLine.pb( mp( prevTime + (double)(damage - prevHealth)/(double)r[i] , 1 ) );
		}

	}

	sort(timeLine.begin(), timeLine.end());

	int t, siz = timeLine.size();

	ans = 0;
	fori(0, siz){
		
		if(timeLine[i].se < 0){
			cnt++;
		}
		else{ 
			t = ((int)ceil(timeLine[i].fi))-1;
			cout<<cnt<<" : "<<t<<" "<<timeLine[i].fi<<"\t"<<ceil(timeLine[i].fi)<<" "<<(int)ceil(timeLine[i].fi)<<"\n";
			ans = max(ans, cnt*(bounty + increase*t) );
			cnt--;
		}

	}

	cout<<ans<<"\n";

	return 0;
}