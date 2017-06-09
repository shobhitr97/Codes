#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef vector<string> vecp;

int main(){
	string s, t;
	int i, count, j, len;
	// char x;
	cin>>s;
	len = s.length();
	vecp arr;
	arr.push_back(s);
	for( i=1 ; i<len ; i++ ){
		t.assign(s.end()-1,s.end());
		s.erase(s.end()-1);
		s = t + s;
		arr.push_back(s);
	}

	count = 0;

	sort(arr.begin(), arr.end());
	
	for( i=0 ; i<len-1 ; i++ ){
		if( arr[i].compare(arr[i+1]) != 0 ){
			count++;
		}
	}

	count++;

	cout<<count<<"\n";
	return 0;
}