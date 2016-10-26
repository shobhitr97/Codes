#include<iostream>
#include<stdio.h>
#include<math.h>
#include<limits.h>

using namespace std;

int max(int a,int b){
	if(a>b){
	return a;
	}
	return b;
}

int min(int a,int b){
	if(a<b){
	return a;
	}
	return b;
}

int min_m(int *a){
	if(a[0]<=a[1]){
		if(a[0]<=a[2]){
			return 0;
		}
		else{
			return 2;
		}
	}
	else{
		if(a[1]<=a[2]){
			return 1;
		}
		else{
			return 2;
		}
	}
}



int steps(int *a,int x){
	if(a[min_m(a)]==x){
		return 0;
	}
	int mi,ma,ind;
	ind=min_m(a);
	mi=min(a[(ind+1)%3],a[(ind+2)%3]);
	ma=max(a[(ind+1)%3],a[(ind+2)%3]);
	if(x<=ma+mi-1){
		a[ind]=x;
		return 1+steps(a,x);
	
	}
	a[ind]=ma+mi-1;
	// cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n";
	// 	cout<<a[ind]<<"\n";
	return 1+steps(a,x);

}

int main(){
	int x,y,c,b,a[3],k,m,n,i;
	cin>>x>>y;
	c=min(x,y);
	b=max(x,y);
	a[0]=a[1]=a[2]=c;
	// if(b-c<c){
	// 	cout<<"3\n";
	// 	return 0;
	// }
	//find x;
	// k=INT_MAX;
	// m=max(floor((b+3)/4)-1,c);
	// n=max(ceil((b+3)/4)+10,c);
	// for(i=m;i<=n;i++){
	// 	a[0]=i;
	// 	k=min(k,steps(a,c));
	// 	// cout<<i<<":"<<k<<"\n";
	// 	a[0]=a[1]=a[2]=b;
	// 	// cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n";
	// }
	// a[0]-=7;
	cout<<steps(a,b)<<"\n";
	return 0;
}