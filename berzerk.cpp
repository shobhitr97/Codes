#include<iostream>
#include<vector>

using namespace std;

#define forn(a,b) for( int i=a ; i<b ; i++ )
#define num 7005
#define pb push_back

typedef vector<int> vec;
typedef vector< vector<int> > vvec;

int n, k1, k2;
vec s1, s2;
int state[2][num];
bool vis[2][num], count[2][num], explored[2][num];

void recur( int index , int player){

	if( explored[player][index] ){
		return ;
	}
	cout<<index<<" "<<player<<"\n";

	explored[player][index] = 1;


	vec::iterator it;
	int flag = 0, new_state = 1, isflag = 1, next_player, next_state;

	next_player = (player+1)%2;

	if( !player ){

		for( it = s1.begin() ; it != s1.end() ; it++ ){

			next_state = ( index + (*it) )%n ;

			recur( next_state , next_player );

			if( state[ next_player ][ next_state ] != -1 ){
				isflag = 0;
				new_state = new_state & state[ next_player ][ next_state ];
			}
			else{
				flag++;
			}

		}

	}
	else{

		for( it = s2.begin() ; it != s2.end() ; it++ ){
			
			next_state = ( index + (*it) )%n ;

			recur( next_state , next_player );

			if( state[ next_player ][ next_state ] != -1 ){
				isflag = 0;
				new_state = new_state & state[ next_player ][ next_state ];
			}
			else{
				flag++;
			}

		}

	}

	if( isflag != 1 ){

		if( flag == 0 && new_state == 1 ){
			vis[player][index] = 1;
			state[player][index] = 0;
		}
		if( new_state == 0 ){
			vis[player][index] = 1;
			state[player][index] = 1;
		}
	}

}

int main(){

	int j;

	cin>>n;
	
	cin>>k1;
	forn(0,k1){
		cin>>j;
		s1.pb(j);
	}

	cin>>k2;
	forn(0,k2){
		cin>>j;
		s2.pb(j);
	}

	forn(1,n){
		state[0][i] = -1;
		state[1][i] = -1;
		vis[0][i] = 0;
		vis[1][i] = 0;
	}

	state[0][0] = 0;
	state[1][0] = 0;
	vis[0][0] = 1;
	vis[1][0] = 1;

	forn(1,n){

		for( j=1 ; j<n ; j++ ){
			explored[0][j] = vis[0][j];
			explored[1][j] = vis[1][j];
		}
		recur(i, 0);
		recur(i, 1);
	}

	forn(1,n){
		switch(state[0][i]){
			case 0:cout<<"Lose ";break;
			case 1:cout<<"Win ";break;
			case -1:cout<<"Loop ";break;
		}
	}
	cout<<"\n";

	forn(1,n){
		switch(state[1][i]){
			case 0:cout<<"Lose ";break;
			case 1:cout<<"Win ";break;
			case -1:cout<<"Loop ";break;
		}
	}
	cout<<"\n";

	return 0;
}
