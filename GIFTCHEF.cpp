#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

#define mod1 173357
#define mod2 281033
#define modn 1000000007
typedef long long int ll;

ll ab(int a,int b,int mod){
	ll x=1,y=a;
	while(b!=0){
		if(b%2==1){
			x=(x*y)%mod;
			// cout<<x<<" -> ";
		}
		y=(y*y)%mod;
		b=b/2;
	}
	// cout<<"<-\n";
	return x;
}

int main(){
	string ss;
	char s[300005],f[300005];	
	int i,check[300005],k,val1,val2,mlen,length,last_index;
	ll ans[300005],sum,h1[300005],h2[300005],c1,c2;
	scanf("%s %s\n",s,f);

	i=0,val1=0,val2=0;
	while(f[i]!='\0'){
		val1 = ( ( val1 * 26 )%mod1 + ( f[i]-'a') )%mod1;
		val2 = ( ( val2 * 26 )%mod2 + ( f[i]-'a') )%mod2;
		i++;  
	}
 	mlen=i;
    cout<<mlen<<" "<<val1<<" "<<val2<<"\n";
	i=0;
	while(s[i]!='\0'){
// 		str[i]=s[i]-'a';
		i++;
	}
	length = i;
	
	
	cout<<mod1<<"\n";
	h1[0]=0;
	for(i=0;i<mlen;i++){
		h1[0]= ( ( h1[0]*26 )%mod1 + ( s[i]-'a') )%mod1;
		
		k--;
	}
	cout<<h1[0]<<" ";
    i=1;
    c1=ab(26,mlen-1,mod1);
	while(i>=0&&i<length-mlen+1){
		h1[i] = ( ( ( h1[i-1] -  ( ( s[i-1]-'a') * c1 )%mod1 )*26 )%mod1 + ( s[i+mlen-1]-'a') )%mod1;
		if(h1[i]<0){
		    h1[i]+=mod1;
		}
		cout<<h1[i]<<" ";
		
		i++;
	}
    cout<<"\n";
    cout<<mod2<<"\n";
	h2[0]=0;
	for(i=0;i<mlen;i++){
		h2[0]= ( ( h2[0]*26 )%mod2 + ( s[i]-'a') )%mod2;
		
	}
	cout<<h2[0]<<" ";
    i=1;
    c2=ab(26,mlen-1,mod2);
	while(i>=0&&i<length-mlen+1){
		h2[i] = ( ( ( h2[i-1] -  ( ( s[i-1]-'a' ) * c2 )%mod2 )*26 )%mod2 + ( s[i+mlen-1]-'a' ) )%mod2;
		if(h2[i]<0){
		    h2[i]+=mod2;
		}
		cout<<h2[i]<<" ";
		i++;
	}
	cout<<"\n";
	
	for(i=0;i<length;i++){
		check[i] = (i+mlen<length+1) && (h1[i]==val1) && (h2[i]==val2) ;
		if(check[i]){
			cout<<i<<"\n";
		}
	}



	for(i=length-2;i>=0;i--){
		check[i]=check[i]+check[i+1];
	}	


	ans[length-1]=0;
	sum=0;
	for(i=length-2;i>=0;i--){
		if(check[i]==check[i+1]+1){
			ans[i]=sum;
			if(i+mlen<=length-1){
				ans[i]=(ans[i]+ans[i+mlen])%modn;
			}
			ans[i]=(ans[i]+1)%modn;	
			sum=ans[i];
			last_index=i;
		}
		else{
			ans[i]=ans[i+1];
		}
	}

	cout<<sum<<"\n";

	return 0;
}