#include<iostream>
#include<stdio.h>

using namespace std;

typedef long long int ll;

int main(){

	ll n,x,val,power,i,k,y;
	int arr[62],length,ch,j;

	cin>>n;
	
	ch=getchar();
	ch=getchar();
	
	i=0;
	
	while(ch!=' '&&ch!='\n'&&ch!=EOF){

		arr[i]=ch-'0';
		i++;

		ch=getchar();
	}

	length=i;
	if(length==1&&arr[0]==0){
		cout<<"0\n";
		return 0;
	}

	i=length-1;
	if((n-1)/10 == 0){
		k=1;
		x=0;
		for(i=length-1;i>=0;i--){
			x+=(k*arr[i]);
			k=k*n;
		}
		cout<<x<<"\n";
		return 0;
	}
	k=1;
	val=0;
	x=0;
	power=1;
	while(i>=0){
		val=arr[i]*k+val;
		
		if(arr[i]==0){
			// if( arr[i-1]*k*10 + val > (n-1) ){
			// 	x+=(val*power);
			// 	power=power*n;
			// 	val=0;
			// 	k=10;
			// 	i--;
			// 	continue;
			// }
			j=i;
			y=k;
			while(arr[j]==0){
				j--;
				y=y*10;
			}
			if(arr[j]*y+val > n-1 ){
				x+=(val*power);
				if(i!=(length-1))
				power=power*n;
				
				y=(y/k);
				k=10;
				val=(y*arr[j]);
				while(val>(n-1)){
					val/=10;
					power=power*n;
				}
				k=(val/arr[j])*10;
				i=j;
				i--;
				continue;
			}

		}

		if(val<=(n-1)){
			k=k*10;
		}
		else{
			val=val-arr[i]*k;
			x+=(val*power);
			power=power*n;
			val=arr[i];
			k=10;
		}
		i--;

	}
	x+=(val*power);
	cout<<x<<"\n";

	return 0;
}