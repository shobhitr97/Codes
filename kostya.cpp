#include<iostream>

using namespace std;

typedef long long int ll;

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int l[100004],r[100004],b[100004],pos[100004],c[100004];

void ssort(int ind){
	int temp,i;

	if(l[i]>r[i]){
		temp=l[i];
		l[i]=r[i];
		r[i]=temp;
	}
	if(r[i]>b[i]){
		temp=r[i];
		r[i]=b[i];
		b[i]=temp;
	}
	else{
		if(l[i]>r[i]){
			temp=l[i];
			l[i]=r[i];
			r[i]=temp;
		}
	}
}

void mergesort(int off,int len){
	if(len==1){
		return;
	}
	int rank,i,j;
	mergesort(off,len/2);
	mergesort(off+(len/2)+1-(len%2),len-len/2);
	rank=0;
	i=0;
	j=0;
	while(i!=len/2&&j!=(len-len/2)){
		if(r[off+i]>r[off+j]){
			c[rank]=r[off+i];
			pos[off+rank]=pos[off+i];
			i++;
		}
		else{
			c[rank]=r[off+j];
			pos[off+rank]=pos[off+j];
			j++;
		}
		rank++;
	}
	if(i!=len/2||j!=(len-len/2)){
		
		if(i!=len/2){
			while(i!=len/2){
				c[rank]=r[off+i];
				pos[off+rank]=pos[off+i];
				rank++;
				i++;
			}
		}
		if(j!=(len-len/2)){
			while(j!=(len-len/2)){
				c[rank]=r[off+j];
				pos[off+rank]=pos[off+j];
				j++;
				rank++;
			}
		}
	}
	for(i=0;i<rank;i++){
		r[i]=c[i];
	}
}

int main(){
	int n,i,maxm,max_a,max_b,l1[100004],r1[100004],b1[100004],s_max;
	cin>>n;
	maxm=0;
	for(i=0;i<n;i++){
		cin>>l[i]>>r[i]>>b[i];
		pos[i]=i;
		ssort(i);
		if(l[i]>maxm){
			max_a=i;
			maxm=l[i];
		}
		l1[i]=l[i];
		r1[i]=r[i];
		b1[i]=b[i];
	}
	s_max=maxm;
	cout<<maxm<<"\n";
	mergesort(0,n);
	for(i=0;i<n;i++){
		cout<<r[i]<<"\n";
	}
	for(i=1;i<n;i++){
		if(r[i]==r[i-1]){
			if(b[pos[i]]==b[pos[i-1]]){
				if(l[pos[i]]+l[pos[i-1]]>maxm){
					max_a=pos[i];
					max_b=pos[i-1];
					maxm=l[pos[i]]+l[pos[i-1]];
				}
			}
		}
	}
	cout<<maxm<<"\n";
	if(s_max==maxm){
		cout<<"1\n";
		cout<<max_a+1;
	}
	else{
		if(s_max<maxm){
			cout<<"2\n";
			cout<<max_a+1<<" "<<max_b+1<<"\n";
		}
	}
	return 0;
}