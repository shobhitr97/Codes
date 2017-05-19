#include<string>
#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

typedef long long int ll;

#define fori(a, b) for( int i=a ; i<b ; i++ )
#define num 100005

int diff[num];

int main(){

	string s;

	int temp, iter, tears, j, len, q;
	bool ans, flag;

	cin>>q;

	while(q--){

		cin>>s;

		len = s.length();

		diff[0] = 0;

		fori(1, len){
			
			temp = s[i]-s[i-1];
			
			if( temp < 0 ){
				temp = 0 - temp;
			}

			diff[i] = diff[i-1] + temp;

		}

		// fori(0, len){
		// 	cout<<diff[i]<<" ";
		// }
		// cout<<"\n";

		iter = len;

		ans = false;

		flag = true;

		tears = 0;

		while(ans == false && iter > 0){
			
			for( j=0 ; j<len ; j+=iter ){
				if( diff[j+iter-1] - diff[j] == 0 ){
					ans = true;
					// cout<<j<<" "<<j+iter-1<<"\n";
					break;
				}
			}

			if( ans == true ){
				break;
			}

			if( iter%2 == 1 ){
				flag = false;
				break;
			}

			tears ++;
			// cout<<iter<<"-cut\n";

			iter = iter/2;

		}

		if( flag == false ){
			cout<<"-1\n";
		}
		else{
			cout<<tears<<"\n";
		}

	}

	return 0;
}