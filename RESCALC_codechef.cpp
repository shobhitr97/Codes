#include<iostream>
#include<vector>

uisng namespace std;


int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
int maxim[105];

void maxim_construct(){
	maxim[0]=maxim[1]=maxim[2]=maxim[3]=0;
	maxim[4]=1,maxim[5]=2,maxim[6]=4;
	for(i=7;i<=100;i++){
		maxim[i]=max(maxim[i-4]+1,maxim[i-5]+2,maxim[i-6]+4);
	}
}
int main(){
	int n,i,sum,x,j,score[105],m[105],a[105][105],index[7];
	maxim_construct();
	cin>>n;
	for(i=0;i<n;i++){
		cin>>m[i];
		for(j=0;j<7;j++){
			index[j]=0;
		}
		for(j=0;j<m[i];j++){
			cin>>x;
			a[i][index[x]]++;               //all indices are intialized to zero
			index[x]++;
		}
	}
	int maxm=0,win,win2=-1;
	for(i=0;i<n;i++){
		sum=0;
		score[i]=m[i];
		while(sum!=m[i]){
			score[i]+=maxim[a[i][j]];
			sum+=a[i][j];
			j++;
		}
		if(score>maxm){
			win=i;
		}
		else{
			if(score==maxm&&maxm){
				win2=i;
			}
		}
	}

	if(win2!=-1&&score[win]==score[win2]){
		cout<<"tie\n";
	}
	else{
		if(win==1){
			cout<<"chef\n";
		}
		else{
			cout<<win<<"\n";
		}
	}
	return 0;
}j