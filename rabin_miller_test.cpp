#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

#define number 1000000000

long long int power(long long int a,long long int b,long long int n){
	long long int num,t;
	if(b==1){
		return a%n;
	}
	if(b%2){
		num=power(a,b/2,n);
		t=(num*num)%n;
		return (t*(a%n))%n;
	}
	num=power(a,b/2,n);
	return (num*num)%n;
}

int check(int n,int a){

	long long int m,s,temp,limit,i,r;
	limit=sqrt(n);
	if(n%2==0){
		return 0;
	}

	s=0;
	temp=n-1;
	while(temp/2==0){
		temp/=2;
		s++;
	}

	m=temp;
	//cout<<"s:"<<s<<"; m:"<<m<<"\n";
	while(n%a==0){
		a++;
	}
	//cout<<"a:"<<a<<"\n";
	r=power(a,m,n);
	//cout<<r<<"\n";
	if(r==1||r==n-1){
		return 1;
	}
	i=1;
	while(i<s){
		r=(r*r)%n;
		//cout<<r<<"\n";
		if(r==1){
			return 0;
		}
		if(r==n-1){
			return 1;
		}
		i++;
	}
	return 0;

}

int main(){
	long long int n,a,b,p;
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		n=a;
		while(n<=b){
			p=2;
		    if(n==1){
		        n++;
		    }
    		if(n==2||n==3){
    		    cout<<n<<"\n";
    		    n++;
    		    continue;
    		}
    		if(check(n,p)){
    			if(n>1000){
    				if(check(n,p+100)){
    					if(n>100000){
    						if(check(n,p+1000)){
    							cout<<n<<"\n";
    						}
    					}
    					else{
    						cout<<n<<"\n";
    					}
    				}
	    			
    			}
    			else{
    				if(check(n,p+10)){
    					cout<<n<<"\n";
    				}
    			}
    		}
    		n++;
		}
		cout<<"\n";
	}
	return 0;
}