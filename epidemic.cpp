#include<iostream>

using namespace std;

int main(){
	int n,k,a[505],b[505],ind[505],counter,mark,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>k;
	for(i=0;i<k;i++){
		cin>>b[k];
	}
	counter=0;
	sum=0;
	ind[0]=0;
	ind[k]=n-1;
	for(i=0;i<n;i++){
		if(sum==b[counter]){
			sum=0;
			ind[counter+1]=i-1;
			counter++;
		}
		sum+=a[i];
	}
	if(counter!=k-1){
		cout<<"NO\n";
		return 0;
	}
	//now thw whole array is divided into k segments such that i-th segment sums up to b[i].now i just have todefine the order in which
	//monsters have to be eaten.This task is simple if i can sort the segments while storing their original positions. 
	counter=0;
	while(counter!=k-1){

	}

}