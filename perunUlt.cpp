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
#define num 100005

int main(){

	ll bounty, increase, ans = 0;
	int s[num], maxHealth[num], r[num], damage;
	vii enemyTime[num];
	vii timeLine;

	int n, m, cnt, prevHealth;
	int a, b, c;
	bool isInf = false;
	double timeIntersection, prevTime;
	// int x[num], y[num], z[num];

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &bounty, &increase, &damage);

	fori(0, n){
		scanf("%d %d %d", &maxHealth[i], &s[i], &r[i]);
	}

	fori(0, m){
		scanf("%d %d %d", &a, &b, &c);
		enemyTime[b-1].pb(mp(a, c));
	}

	fori(0, n){
		if(maxHealth[i] <= damage)	isInf = true;
	}

	if(increase > 0 && isInf == true){
		cout<<"-1\n";
		return 0;
	}

	fori(0, n){
		if(enemyTime[i].size()>0)	sort(enemyTime[i].begin(), enemyTime[i].end());
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
					if(prevHealth > damage && enemyTime[i][j].se <= damage){ timeLine.pb( mp( enemyTime[i][j].fi, -1 ) ); }
					if(prevHealth <= damage && enemyTime[i][j].se > damage){ timeLine.pb( mp( enemyTime[i][j].fi - 1, 1 ) ); }
				}
				else{

					if(prevHealth > damage && enemyTime[i][j].se <= damage){
						timeLine.pb( mp( enemyTime[i][j].fi, -1 ) );
					}
					
					if(prevHealth <= damage){
						timeIntersection = prevTime + (double)(damage - prevHealth)/(double)r[i];
						if(enemyTime[i][j].fi > timeIntersection){
							timeLine.pb( mp( (int)floor(timeIntersection) , 1 ) );
							if(enemyTime[i][j].se <=  damage){
								timeLine.pb( mp( enemyTime[i][j].fi, -1 ) );
							}
						}
						else{
							if(enemyTime[i][j].se > damage){
								timeLine.pb( mp( enemyTime[i][j].fi - 1, 1 ) );
							}
						}
					}
				}

				prevTime = enemyTime[i][j].fi;            // No explicit integer to double conversion
				prevHealth = enemyTime[i][j].se;

			}
		}

		if(prevHealth <= damage && r[i] > 0){
			timeLine.pb( mp( (int)floor( prevTime + (double)(damage - prevHealth)/(double)r[i] ) , 1 ) );
		}

		if(prevHealth <= damage && r[i] == 0 && increase > 0){
			cout<<"-1\n";
			return 0;
		}

	}

	if(increase == 0 && timeLine.size() == 0){
		cout<<cnt*bounty<<"\n";
		return 0;
	}

	sort(timeLine.begin(), timeLine.end());

	int t, negChange, posChange, siz = timeLine.size();

	negChange = 0;
	posChange = 0;

	fori(0, siz){
		
		t = timeLine[i].fi; 

		if(timeLine[i].se < 0){
			posChange++;
		}
		else{ 
			negChange++;
		}

		ans = max(ans, (cnt + posChange)*(bounty + increase*t));

		if(i == siz-1 || timeLine[i+1].fi != timeLine[i].fi ){
			ans = max(ans, (cnt + posChange)*(bounty + increase*t));
			cnt += (posChange - negChange);
			posChange=0;
			negChange=0;
		}

	}

	cout<<ans<<"\n";

	return 0;
}