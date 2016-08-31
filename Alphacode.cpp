#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
	int a[5000],len,i,n,last_index;
	long long int num;
	int ch;
	vector <long long int> cost;
	while(1){
		i=0;
		ch=getchar();
		if(ch=='0'){
			break;
		}
		while(ch!='\n'){
			a[i]=ch-48;
			//cout<<a[i]<<" ";
			i++;
			ch=getchar();
		}
		//cout<<"\n";
		len=i;
		cost.push_back(1);
		//cout<<"0:1\n";
		for(i=1;i<len;i++){
			if(!a[i]){
				if(a[i-1]==1||a[i-1]==2){
					if(i>1)
						num=cost[i-2];
					else{
						num=1;
					}
					cost[i-1]=num;
					cost.push_back(num);
					continue;
				}
				else{
					cout<<"0\n";
					cost.clear();
					break;
				}
				
			}
			num=cost[i-1];
			cost.push_back(num);
			if(a[i-1]!=0&&a[i-1]*10+a[i]<=26){

				if(i>1)
					cost[i]+=cost[i-2];
				else{
					cost[i]+=1;
				}
			}
			//cout<<i<<":"<<cost[i]<<"\n";
		}

		cout<<cost[len-1]<<"\n";
		cost.clear();
		
	}
	return 0;
}