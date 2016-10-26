#include<iostream>

using namespace std;

int main(){
	int t,n,p[3],i,x,extra,flag,inc;
	cin>>t;
	while(t--){
		flag=1;
		cin>>n;
		inc=0;
		p[0]=p[1]=p[2]=0;
		for(i=0;i<n;i++){
			cin>>x;
			if(x>1||x<-1){
				if(inc==0){
					extra=x;
					inc=1;
				}
				else{
					flag=0;
					continue;
				}
			}
			p[1+x]++;
		}

		if(inc==1&&!p[2]){
			cout<<"no\n";
			continue;
		}
		if(flag==0){
			cout<<"no\n";
			continue;
		}
		if(n==1){
			cout<<"yes\n";
			continue;
		}
		if(p[0]>=2&&p[2]==0){
			flag=0;
			cout<<"no\n";
			continue;
		}
		if(p[0]&&inc){
			if(!p[2]){
				flag=0;
				cout<<"no\n";
				continue;
			}
		}
		else{

		}
		cout<<"yes\n";
	}
	return 0;
}