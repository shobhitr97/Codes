#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

#define fori(a,b) for( int i=a ; i<b ; i++ )
#define pb push_back

typedef vector<int> vec;

string n;

void printt(){
	int len = n.length();
	fori(0,len){
		if( n[i] != '!'){
			cout<<n[i];
		}
	}
	cout<<"\n";
}

int check(){
	int count = 0, i=0, len;
	len = n.length();

	while( ( n[i] == '0' || n[i] == '!') && i < len ){
		if( n[i] == '0' ){
			count++;
		}
		i++;
	}
	return count;
}

int main(){


	cin>>n;

	int len, count1, count2, sum, x, j, check1, check2, p;

	string temp("##");

	len = n.length();

	sum = 0;

	count1 = 2;
	count2 = 2;

	vec arr1, arr2;

	for( j=len-1 ; j>=0 ; j-- ){
		
		x = n[j]-'0';
		
		sum += x ;

		if( x%3 == 1 ){
			if( count1){
				arr1.pb(j);
				count1--;
			}
		}

		if( x%3 ==2 ){
			if( count2){
				arr2.pb(j);
				count2--;
			}
		}

	}

	switch(sum%3){
		case 0:
		break;

		case 1: 
		check1 = -1;
		check2 = -1;

		if( count1 != 2 ){
			temp[0] = n[ arr1[0] ];
			n[ arr1[0] ] = '!';
			check1 = 1 + check();
			// printt();
			n[ arr1[0] ] = temp[0];
		}
		
		if( !count2 ){
			temp[0] = n[ arr2[0] ];
			temp[1] = n[ arr2[1] ];
			n[ arr2[0] ] = '!';
			n[ arr2[1] ] = '!';
			check2 = 2 + check();
			// printt();
			n[ arr2[0] ] = temp[0];
			n[ arr2[1] ] = temp[1];
		}
		// cout<<check1<<" "<<check2<<"\n";

		if( check1 == -1 && check2 == -1 ){
			cout<<"-1\n";
			return 0;
		}

		if( check2 == -1 ){
			n[ arr1[0] ] = '!';
			break;
		}
		
		if( check1 == -1 ){
			n[ arr2[0] ] = '!';
			n[ arr2[1] ] = '!';
			break;
		}

		if( check1 <= check2 ){
			n[ arr1[0] ] = '!';
			break;
		}

		if( check2 < check1 ){
			n[ arr2[0] ] = '!';
			n[ arr2[1] ] = '!';
			break;
		}

		case 2:
		check1 = -1;
		check2 = -1;

		if( count2 != 2 ){
			temp[0] = n[ arr2[0] ];
			n[ arr2[0] ] = '!';
			check1 = 1 + check();
			// printt();
			n[ arr2[0] ] = temp[0];
		}

		if( !count1 ){
			temp[0] = n[ arr1[0] ];
			temp[1] = n[ arr1[1] ];
			n[ arr1[0] ] = '!';
			n[ arr1[1] ] = '!';
			check2 = 2 + check();
			// printt();
			n[ arr1[0] ] = temp[0];
			n[ arr1[1] ] = temp[1];
		}

		// cout<<check1<<" "<<check2<<"\n";

		if( check1 == -1 && check2 == -1 ){
			cout<<"-1\n";
			return 0;
		}

		if( check1 == -1 ){
			n[ arr1[0] ] = '!';
			n[ arr1[1] ] = '!';
			break;
		}

		if( check2 == -1 ){
			n[ arr2[0] ] = '!';
			break;
		}

		if( check2 < check1 ){
			n[ arr1[0] ] = '!';
			n[ arr1[1] ] = '!';
			break;
		}

		if( check1 <= check2 ){
			n[ arr2[0] ] = '!';
			break;
		}

	}

	j = 0;

	p = -1;
	while( ( n[j] == '0' || n[j] == '!' ) && j<len){
		if( n[j] == '0' ){
			p = j;
		}
		n[j] = '!';
		j++;
	}
	// printt();

	int count;

	count = 0;
	fori(0,len){
		if( n[i] != '0' && n[i] != '!' ){
			count++;
		}
	}

	// printt();
	// cout<<count<<"\n";
	if( !count ){
		if( p != -1 ){
			n[p] = '0';
		}
		else{
			cout<<"-1\n";
			return 0;
		}
	}

	printt();

	return 0;
}