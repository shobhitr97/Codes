#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int a[3], x, ans, diff;

	for(int i=0;i<3;i++)	cin>>a[i];

	sort(a, a+3);

	ans = a[0] + ((a[1]-a[0])/3) + ((a[2]-a[0])/3);

	x = a[0]/3 + a[1]/3 + a[2]/3;

	ans = max(ans, x);

	diff = 3;
	for(int i=0;i<3;i++){
		if(a[i]/3 && a[i]%3 == 0){
			x--;
		}
		else{
			diff = min(diff, a[i]%3);
		}
	}

	ans = max(ans, x+diff);

	cout<<ans<<"\n";

	return 0;
}
