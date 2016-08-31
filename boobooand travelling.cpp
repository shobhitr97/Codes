//assuming we can write A[i] and B[j]

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
int prime[500];

int prime_gen(int n);

int check_validity(int a,int b);

int main(){




	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(k=1;k<=m;k++){
				if(check_validity(j,k)==1){
					if(j==k){
						c=a[i][j];
					}
					else{
						c=b[i][j];
					}

					temp[k]=min(temp[k],cost[j]+c);  //initialize all elements of array temp to int_max
				}
			}

		}
		for(p=1;p<=m;p++){
			cost[p]=temp[p];
		}
	}

	return 0;
}