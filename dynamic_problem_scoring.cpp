#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

#define fori(a, b) for( int i=a ; i<b ; i++ )
#define mod 1000000007

// 2 4 6 8 10 12

int minUsers, x1, x2, x3, x4, x5, possible[7], mpv[7], success[6], unsuccess[6];
float l[7], r[7];

int calculate(int x, int state, int number){
	
	if( x<0 ){
		if( state != 0 && possible[number] == 1 ){
			return ( unsuccess[number]*( (int)(1.0/l[state]) ) + 1 - ( success[number]+unsuccess[number] ) );
		}
		else{
			return 0;
		}
	}

	if( x>0 ){
		return ( success[number]*( (int)(1.0/r[state]) ) - ( success[number]+unsuccess[number] ) );
	} 
}

int calc( int state1, int state2, int state3, int state4, int state5){
	int new_users = calculate(x1, state1, 1);
	new_users = max(new_users, calculate(x2, state2, 2));
	new_users = max(new_users, calculate(x3, state3, 3));
	new_users = max(new_users, calculate(x4, state4, 4));
	new_users = max(new_users, calculate(x5, state5, 5));

	return new_users;
}

void func(int problem, int state1, int state2, int state3, int state4, int state5){

	switch(problem){
		case 1:	
		if( x1 > 0 ){
			for(int i=state1-1 ; i>=0 ; i-- ){
				func(problem+1, i, state2, state3, state4, state5);
			}
		}
		else{
			if( x1 == 0 ){
				func(problem+1, state1, state2, state3, state4, state5);
				break;
			}
			fori(state1, 6){
				func(problem+1, i, state2, state3, state4, state5);
			}
		}
		break;
		case 2:
		if( x2 > 0 ){
			for(int i=state2-1 ; i>=0 ; i-- ){
				func(problem+1, state1, i, state3, state4, state5);
			}
		}
		else{
			if( x2 == 0 ){
				func(problem+1, state1, state2, state3, state4, state5);
				break;
			}
			fori(state2, 6){
				func(problem+1, state1, i, state3, state4, state5);
			}
		}
		break;
		case 3:
		if( x3 > 0 ){
			for(int i=state3-1 ; i>=0 ; i-- ){
				func(problem+1, state1, state2, i, state4, state5);
			}
		}
		else{
			if( x3 == 0 ){
				func(problem+1, state1, state2, state3, state4, state5);
				break;
			}
			fori(state3, 6){
				func(problem+1, state1, state2, i, state4, state5);
			}
		}
		break;
		case 4:
		if( x4 > 0 ){
			for(int i=state4-1 ; i>=0 ; i-- ){
				func(problem+1, state1, state2, state3, i, state5);
			}
		}
		else{
			if( x4 == 0 ){
				func(problem+1, state1, state2, state3, state4, state5);
				break;
			}
			fori(state4, 6){
				func(problem+1, state1, state2, state3, i, state5);
			}
		}
		break;
		case 5:
		if( x5 > 0 ){
			for(int i=state5-1 ; i>=0 ; i-- ){
				func(problem+1, state1, state2, state3, state4, i );
			}
		}
		else{
			if( x5 == 0 ){
				func(problem+1, state1, state2, state3, state4, state5 );
				break;
			}
			fori(state5, 6){
				func(problem+1, state1, state2, state3, state4, i );
			}
		}
		break;
		case 6: break;
	}

	int diff, newUsers;

	diff = 0;
	diff += (x1*mpv[state1]);
	diff += (x2*mpv[state2]);
	diff += (x3*mpv[state3]);
	diff += (x4*mpv[state4]);
	diff += (x5*mpv[state5]);

	if( diff > 0 ){
		newUsers = calc(state1, state2, state3, state4, state5);
		cout<<state1<<" "<<state2<<" "<<state3<<" "<<state4<<" "<<state5<<":"<<newUsers<<"\n";
		minUsers = min(minUsers, newUsers);
	}

}

int main(){

	r[5] = 1.0;
	l[5] = 0.5;
	r[4] = 0.5;
	l[4] = 0.25;
	r[3] = 0.25;
	l[3] = 0.125;
	r[2] = 0.125;
	l[2] = 0.0625;
	r[1] = 0.0625;
	l[1] = 0.03125;
	r[0] = 0.03125;
	l[0] = 0.0;

	mpv[0] = 12;
	mpv[1] = 10;
	mpv[2] = 8;
	mpv[3] = 6;
	mpv[4] = 4;
	mpv[5] = 2;

	// cout<<( (int)(1.0/l[1]) )<<"\n";

	int n, subm[130][7];
	
	fori(0, 6){
		success[i] = 0;
		unsuccess[i] = 0;
	}

	cin>>n;

	fori(0, n){
		for( int j=0 ; j<5 ; j++ ){
			cin>>subm[i][j];
			if( subm[i][j] == -1 ){
				subm[i][j] = 250;
				unsuccess[j+1]++;
			}
			else{
				success[j+1]++;
			}
		}
	}

	fori(0, 5){
		if( subm[0][i] != -1 ){
			possible[i+1] = 1;
		}
		else{
			possible[i+1] = 0;
		}
	}

	x1 = subm[1][0] - subm[0][0];
	x2 = subm[1][1] - subm[0][1];
	x3 = subm[1][2] - subm[0][2];
	x4 = subm[1][3] - subm[0][3];
	x5 = subm[1][4] - subm[0][4];

	float rate;
	int state, state1, state2, state3, state4, state5;
	fori(1, 6){
		rate = (float)success[i]/(float)(success[i]+unsuccess[i]);
		state = (rate>=l[0]) + (rate>l[1]) + (rate>l[2]) + (rate>l[3]) + (rate>l[4]) + (rate>l[5]) - 1;
		// cout<<rate<<" "<<state<<"\n";
		switch(i){
			case 1:	state1 = state;
					break;
			case 2:	state2 = state;
					break;
			case 3:	state3 = state;
					break;
			case 4:	state4 = state;
					break;
			case 5:	state5 = state;
					break;
		}
	}

	// cout<<state1<<" "<<state2<<" "<<state3<<" "<<state4<<" "<<state5<<"\n";

	minUsers = mod;

	int diff;

	diff = 0;
	diff += (x1*mpv[state1]);
	diff += (x2*mpv[state2]);
	diff += (x3*mpv[state3]);
	diff += (x4*mpv[state4]);
	diff += (x5*mpv[state5]);

	if( diff<=0 ){
		func(1, state1, state2, state3, state4, state5);
		if(minUsers == mod){
			cout<<"-1\n";
		}
		else{
			cout<<minUsers<<"\n";
		}
	}
	else{
		cout<<"0\n";
	}


	return 0;
}