#include<iostream>

using namespace std;

int vis[105],crush[105];

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int gcd(int a,int b){
	int temp;
	if(a<b){
		temp=a;
		a=b;
		b=temp;
	}
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int lcm(int a,int b){
	int g;
	g=gcd(a,b);
	return a*(b/g);
}

int main(){
	int n,i,bcrush[105],crush[105],vis[105],j,cycle,sup_cycle,p;
	cin>>n;
	for(i=0;i<101;i++){
		bcrush[i]=0;
	}
	for(i=1;i<=n;i++){
		cin>>crush[i];
		bcrush[ crush[i] ]++;
		if(bcrush[ crush[i] ]>1){
			cout<<"-1\n";
			return 0;
		}
	}

	
	for(i=1;i<=n;i++){
		vis[i]=0;
	}

	int flag=1;	

	for(i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		}
		j=i;
		
		cycle=0;
		while(vis[j]!=1){
			// cout<<j<<"\n";
			vis[j]=1;
			cycle++;
			j=crush[j];
		}
		// cout<<cycle<<"\n";
		if(cycle==1){
			p=1;
		}else{
			if(cycle%2==1){
				p=cycle;
			}
			else{
				p=(cycle/2);
			}
		}
		// cout<<p<<"\n";
		if(flag==1){
			sup_cycle=p;
			flag=0;
			continue;
		}
		// cout<<sup_cycle<<"\n";
		sup_cycle=lcm(sup_cycle,p);
	}
	cout<<(sup_cycle)<<"\n";
	
	return 0;
}