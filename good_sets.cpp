#include<iostream>

using namespace std;

#define lp(i,lm,beg) for(int i=beg;i<lm;i++);
#define ma 750001;

int num[750005],ans[750005],visited[750005],maxm;

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int fn(int k){
	int sum=1;
	for(i=2*k,i<=maxm;i+=k){
		if(num[i]!=0){
			if(visited[i]!=0){
				sum+=ans[i];
			}
			else{
				visited[i]=1;
				ans[i]=fn(i);
				sum+=ans[i];
			}
		}
	}
	return sum;
}

int main(){
	int t,sum,n,x;
	cin>>t;
	while(t--){
		cin>>n;
		lp(i,ma,0){
			visited[i]=0;
			num[i]=0;
		}
		maxm=0;
		lp(i,n,0){
			cin>>x;
			maxm=max(maxm,x);
			num[x]++;
		}

		sum=0;
		lp(i,maxm,2){
			if(num[i]==0){
				continue;
			}
			if(visited[i]!=0){
				sum+=ans[i];
				continue;
			}
			visited[i]=1;
			ans[i]=fn(i);
			sum+=ans[i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}	
