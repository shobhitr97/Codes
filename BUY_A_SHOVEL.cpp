#include<iostream>
#include<limits.h>

using namespace std;

int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}

int main(){
	int k1,k,r,ans,i;
	cin>>k>>r;
	ans=INT_MAX;
	if(k%10==0){
		ans=1;
	}
	else{
		if(k%5==0){
			ans=2;
		}
		else{
			if(k%2==0){
				ans=5;
			}
		}
	}
	k=k%10;
	k1=k;
	i=0;
	while((k1-r)%10!=0&&i<=ans){
		i++;
		k1+=k;
	}
	ans=min(ans,i+1);
	cout<<ans<<"\n";
	return 0;

}