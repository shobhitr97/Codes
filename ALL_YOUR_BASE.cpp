#include<bits/stdc++.h>

int main(){
	int t,k,j,len;
    unsigned long long int num,i,a[255],b[255],d,p,n;
	char str[62];
	std::cin>>t;
	for(k=1;k<=t;k++){
		
		scanf("%s ",str);
		d=0,num=0;
		for(i=0;i<255;i++){
			a[i]=0;
			b[i]=0;
		}
		len=strlen(str);
		for(i=0;i<len;i++){
			a[str[i]]=1;
		}
		for(i=0;i<255;i++){
			if (a[i]){
				d++;
			}
		}
		if (d==1){
			d=2;
		}
		//std::cout<<"base:"<<d<<"\n";
		i=1;
		for(j=0;j<len;j++){
			if(b[str[j]]==0){
				b[str[j]]=i;
				i++;
			}
		}
		/*for(j=0;j<len;j++){
			if(b[str[j]]==1){
				b[str[j]]=-2;
				break;
			}
		}

		for(j=0;j<len;j++){
			if(b[str[j]]==2){
				b[str[j]]=1;
				break;
			}
		}

		for(j=0;j<len;j++){
			if(b[str[j]]==-2){
				b[str[j]]=2;
				break;
			}
		}*/
		i=0;
		p=1;
		for(j=len-1;j>=0;j--){
			if (b[str[j]]==1){
				n=2;
			}
			else{
				if(b[str[j]]==2){
					n=1;
				}
				else{
					n=b[str[j]];
				}
			}
			num+=p*(n-1);
			p=p*d;
		}
		std::cout<<"Case #"<<k<<": "<<num<<"\n";
	}
	return 0;
}