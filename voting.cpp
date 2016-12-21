#include<iostream>

using namespace std;

#define num 200005

int c[num],posr[num],posd[num],mark[num];
int n;

int main(){
	int i,ri,di,endr,endd,remr,remd,ans,next;

	char ch;

	cin>>n;

	ri=0,di=0;
	
	for(i=0;i<n;i++){
		cin>>ch;
		if(ch=='R'){
			c[i]=1;
			posr[ri++]=i;
		}
		else{
			c[i]=0;
			posd[di++]=i;
		}
	}

	for(i=0;i<n;i++){
		mark[i]=1;
	}

	endd=di;
	endr=ri;

	remd=di;
	remr=ri;

	
	ri=0;
	di=0;
	next=c[0];

	int cycler=0,cycled=0;


	while(1){

		if(!remr){
			ans=0;
			break;
		}
		if(!remd){
			ans=1;
			break;
		}

		// if(flagr==1&&flagd==1){
		// 	i=0;
		// 	flagr=0;
		// 	flad=0;
		// 	continue;
		// }

		// cout<<"R:"<<cycler<<";D:"<<cycled<<"\n";
		if(next){
			// cout<<posr[ri]<<" ";
			mark[ posd[di] ]=0;
			// cout<<"--D["<<posd[di]<<"]--\n";
			remd--;
			
			if(!remd){
				continue;
			}
			
			while(mark[posd[di]]==0){
				
				di=(di+1)%endd;
				if(di==0){
					cycled++;
				}
			
			}

			ri=(ri+1)%endr;
			if(!ri){
				cycler++;
			}
			
			while(mark[posr[ri]]==0){
			
				
				
				ri=(ri+1)%endr;
				if(!ri){
					cycler++;
				}
			
			}
			if( posr[ri]+cycler*n > posd[di]+cycled*n ){
				next=0;
			}

		}
		else{
			// cout<<posd[di]<<" ";
			mark[posr[ri]]=0;
			// cout<<"--R["<<posr[ri]<<"]--\n";
			remr--;
			
			if(!remr){
				continue;
			}
			
			while(mark[posr[ri]]==0){
				ri=(ri+1)%endr;
				if(!ri){
					cycler++;
				}
			}

			di=(di+1)%endd;
			if(!di){
				cycled++;;
			}

			while(mark[posd[di]]==0){
			
				if( posr[ri]+cycler*n < posd[di]+cycled*n ){
					next=1;
				}
			
				di=(di+1)%endd;
				if(!di){
					cycled++;;
				}
			
			}
			if( posr[ri]+cycler*n < posd[di]+cycled*n ){
				next=1;
			}

		}

	}

	if(ans){
		cout<<"R\n";
	}
	else{
		cout<<"D\n";
	}

	return 0;
}