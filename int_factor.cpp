#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<vector>
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

int main(){
    long long int p=1000000000000000,n;
    int *list,num,limit,power,i;
    num=sqrt(p);
    //cin>>num;   
    list=prime(num);
    //cout<<num;
    cin>>n;
    while(n){
        limit=sqrt(n);
        i=1;
        while(list[i]<=limit){
            if(n%list[i]==0){
                power=0;
                while(n%list[i]==0){
                    power++;
                    n/=list[i];
                }
                cout<<list[i]<<"^"<<power<<" ";
            }
            i++;
        }
        if(n!=1){
            cout<<n<<"^1 ";
        }
        cout<<"\n";
        cin>>n;
    }
    return 0;
}
