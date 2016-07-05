#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<string>
#include<vector>


using namespace std;

struct product{
	vector <int> list;
	int val;
};

class Marketing{
	int siz,ans;
	vector <int> val;
	vector <int> visit;
	vector <struct product> pp;
	stack <struct product*> com;
	public:
	
		struct product *make_obj(int num,int value){
			if(visit[num]==1){
				if(value==val[num]){
					ans=0;
				}
				else{
					ans=1;
				}
				return NULL;
			}
			val[num]=(!value);
			return &pp[num];
		}
		long howMany(int compete[30][50]){
			int i,j,size_,value,h;
			siz=30;
			long answer=1;
			struct product* k,*ptr_obj;

			pp.resize(siz);
			val.resize(siz);
			visit.resize(siz);


			
			for(i=0;i<siz;i++){
				visit[i]=0;
	
				j=0;
				while(compete[i][j]!=-1){
					pp[i].list.push_back(compete[i][j]);
					j++;
				}
			}

			i=1;
			
			
			while(i<siz){
				if(visit[i]==1){
					i++;
					continue;
				}
				ptr_obj=make_obj(i,0);
				com.push(ptr_obj);
				while(com.empty()==false){
					//pop objects
					k=com.top();
					com.pop();
					h=0;
					value=k->val;
					while(h<k->list.size()){
						ptr_obj=make_obj(k->list[h],value);
						if(ptr_obj==NULL){
							if(ans==0)
								return -1;
						}
						else{
							com.push(ptr_obj);
						}
						h++;
					}
				}
				answer*=2;
				i++;
			}
			return answer;

		}

};
int main(){
	int j,p,row;
	int a[30][50];
	cin>>row;
	for(int i=0;i<row;i++){
		j=0;
		while(1){
			cin>>p;
			a[i][j]=p;
			if(p==-1){
				break;
			}
			j++;
		}
	}
	Marketing pi;
	cout<<pi.howMany(a)<<"\n";
	return 0;
}