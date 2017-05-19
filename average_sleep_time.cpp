#include<iostream>
#include<stdio.h>

using namespace std;

typedef long long int ll;

#define fori(a, b) for(int i=a ; i<b ; i++ )

int main(){
	int a[200005];
	ll sum, t_sum;
	double average;
	int n, k, t, j;

	cin>>n>>k;
	t = n-k+1;
	fori(0, n){
		cin>>a[i];
	}

	average = 0.0000000000;

	j=0;
	sum = 0;
	fori(0, k){
		sum+=a[i];
	}
	t_sum += sum;
	fori(1, t){
		sum+=(a[j+k]-a[j]);
		t_sum += sum;
		j++;
	}

	average = (double)((double)t_sum/t);
	printf("%.10f\n",average);

	return 0;
}