#include<stdio.h>
#include<stdlib.h>

int *a;
void mergesort(int p,int q){
	if(p==q)
		return;
	int r,i,j,k;
	r=(p+q)/2;
	int *n;
	n=(int*)malloc((q-p+1)*sizeof(int));
	mergesort(p,r);
	mergesort(r+1,q);
	i=p;
	j=r+1;k=0;
	while( !( (i==(r+1)) && (j==(q+1)) ) ){
		if(i<=r&&j<=q){
			if(a[i]>a[j]){
				n[k]=a[j];
				j++;
				k++;
			}
			else{
				n[k]=a[i];	
				i++;
				k++;
			}
		}
		else{
			if(i>r){	
				n[k]=a[j];
				j++;
				k++;
			}
			else{
				n[k]=a[i];
				k++;
				i++;
			}
		}
	}
	for(i=p;i<q+1 ;i++){
		a[i]=n[i-p];
	}
	free(n);
}


int main(){
	int n,i;
	scanf("%d ",&n);
	a=(int*)malloc((n+1)*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d ",&a[i]);
	}
	mergesort(0,n-1);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
