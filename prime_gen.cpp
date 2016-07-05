

#include<bits/stdc++.h>
using namespace std;
#define number 1000000002
int *sieve;

void printn(int num,int a,int b){
	if(num<=1){
		return;
	}
	if(num==2&&num>=a){
		cout<<num<<"\n";
		return;
	}
	if(num>=a){
		printn(num-1,a,b);
		if(sieve[num]&&num<=b){
			cout<<num<<"\n";
		}
	}
}

int main(){
	int t;
	int a,b,n=1000000000,i,num,max;
	//limit=(int)sqrt(b);
	int sieve[number];
	
	//list=(int*)malloc((n+2)*sizeof(int));
	sieve[1]=-1;
	cin>>t;
	max=2;
	while(t--){
		cin>>a>>b;
		printn(max,a,b);
		i=max+1;
		while(i<=b){
			if(sieve[i]==0){
				if(i>=a){
					cout<<i<<"\n";
					//count++;
				}
				sieve[i]=1;
				//list[sieve[i]-1]=i;
				num=i*i;
				while(num<=n){
					sieve[num]=-1;
					num+=i;
				}
			}
			
			i+=2;			
		}
		max=i-1;
		//std::cout<<"the count is:"<<count<<"\n";
	
		//std::cout<<count<<"\n";
	}
	return 0;
}
/*
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;
#define number 100000000
#define number1 1000000000

int list[number];
void printn(int index,int a,int b){
	if(index==0&&list[index]>=a){
		cout<<list[0]<<"\n";
		return ;
	}
	if(list[index]>=a){
		printn(index-1,a,b);
		if(list[index]<=b){
			cout<<list[index]<<"\n";
		}
	}
}
int main(){

	int j,i,ch,count=2,t,max=3,a,b;

	list[0]=2;
	list[1]=3;

	cin>>t;
	while(t--){
		cin>>a>>b;

		printn(count-1,a,b);
		
		if(b>max+1){

			for(i=max+2;i<=b;i+=2){
				ch=1;

				//cout<<i<<":\n";

				for(j=0;j<count&&list[j]*list[j]<=i;j++){
					if(i%list[j]==0){
						ch=0;
						break;
					}
				}
				if(ch){
					list[count]=i;
					if(i>=a){
						cout<<i<<"\n";
					}
					count++;
				}
			}
		}
	}
		//cout<<count<<"\n";
	return 0;
}
*/