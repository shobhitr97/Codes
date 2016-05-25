#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;

int* prime(int b){
	int num,i,count,limit;
	//limit=(int)sqrt(b);
	int *sieve=(int*)calloc((b+1),sizeof(int));
	int *list=(int*)malloc((b+1)*sizeof(int));
	i=1;
	count =1;
	list[0]=1;
	while(i!=b){
		++i;
		if(sieve[i]==0){
			count++;
			list[count-1]=i;
			num=i;
			while(num<=b){
			sieve[num]=1;
			num+=i;
			}
		}
		else{
			continue;
		}
	}
	free(sieve);
	return list;
}

int main() {
    int *list,i,n,m,temp,c;
    long long int num,res;
    list=prime(100000000);
    cin>>T;
    while(T--){
        cin>>n>>m;
        i=2;
        res=1;
        while(list[i]<=n){
            temp=list[i];
            c=n/temp;
            while(c){
                num+=c;
                temp*=list[i];
                c=n/temp;
            }
            res*=(num+1);
            i++;
        }
        res--;
        res=res%m;
        cout<<res<<"\n";
    }
	return 0;
}
