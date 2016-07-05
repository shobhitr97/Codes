#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

using namespace std;

#define number 500000

int list[1101];

void prime(int b){
	int num,i,count,limit;
	//limit=(int)sqrt(b);
	int *sieve=(int*)calloc((b+1),sizeof(int));
	for(i=0;i<=b;i++){
		list[i]=0;
	}
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
	/*for(i=0;list[i]!=0;i++){
		cout<<list[i]<<"\n";
	}
	*/
	  
}

int search_1(int n){
	int i;
	for(i=1;list[i]>0&&list[i]<=n;i++){
		if(list[i]==n){
			return 1;
		}
	}
	return 0;
}

int main(){
	int i,j,factors,num,power[2],p,ch,k=0;
	prime(1100);
	
	for(i=50;i<=999728;i++){
		j=1;
		num=i;
		ch=1;
		factors=0;
		while(list[j]&&list[j]*list[j]<=i){
			p=0;
			while(i%list[j]==0){
				i/=list[j];
				p++;
			}
			if(p){
				if(!search_1(p+1)){
					ch=0;
					break;
				}
				else{
					power[factors]=p;
					factors++;
					if(factors==2){
						break;
					}
				}
			}

			j++;
		}
		if(ch&&factors){
			if(factors==1&&i!=1){
				power[factors]=1;
				factors++;
				i=1;
			}
			
		    if(factors==2&&power[0]!=power[1]&&i==1){
		    	if(k%9==0){
		    		//cout<<"p:"<<power[0]<<";q:"<<power[1]<<"\n";
			    	cout<<num<<"\n";
			    }
			    k++;
		    }
			/*i=num;
			continue;
			*/
		
		
		}
		
		i=num;

	}
	cout<<"999927\n";

	return 0;
}


