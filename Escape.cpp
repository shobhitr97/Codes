#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<string>
#include<vector>
using namespace std;
#include<limits.h>
struct object{
	int x;
	int y;
	int lives;
};

class Escape{
	int visited[501][501],cost[501][501],grid[501][501];
	public:
		Escape(){
			int j;
			for(int i=0;i<=500;i++){
				for(j=0;j<=500;j++){
					cost[i][j]=INT_MAX;
					visited[i][j]=0;
					grid[i][j]=0;
				}
			}
		}
		/*int lowest(String harmful[],String deadly[]){


			stack <struct object> st;
			while(st.empty==false){
				struct object obj;
				obj=st.top();
				st.pop();
				if(obj.x>500||obj.x<0||obj.y>500||obj.y<0){
					continue;
				}
	 			if(visited[obj.x][obj.y]==1){
					if(obj.lives<cost[obj.x][obj.y]){
						cost[obj.x][obj.y]=obj.lives;
					}
					continue;
				}
				visited[obj.x][obj.y]=1;
				cost[obj.x][obj.y]=obj.lives;

			}
		}
		*/
		//recursive approach
		int min(int a,int b){
			if(a<b){
				return a;
			}
			return b;
		}
		int max(int a,int b){
			if(a>b){
				return a;
			}
			return b;
		}		
		void recur(int x,int y,int lives){
			if(grid[x][y]==-1){
				return; 
			}
			if(visited[x][y]==1&&lives+grid[x][y]>=cost[x][y]){
				return ;
			}
			visited[x][y]=1;
			if(lives+grid[x][y]<cost[x][y]){
				cost[x][y]=lives+grid[x][y];
			}
			recur(x,y+1,cost[x][y]);
			recur(x,y-1,cost[x][y]);
			recur(x-1,y,cost[x][y]);
			recur(x+1,y,cost[x][y]);
		}
		int lowest2(vector <vector <int> > harmful,vector <vector <int> > deadly){

			int it,i,j;	
			it=harmful.size();										//it is the length of harmful array
			while(it>=0){
				for(i=min(harmful[it][0],harmful[it][2]);i<=max(harmful[it][0],harmful[it][2]);i++){
					for(j=min(harmful[it][1],harmful[it][3]);j<=max(harmful[it][1],harmful[it][3]);j++){
						grid[i][j]=1;
					}
				}
				it--;
			}
			//it is the length of deadly
			it=deadly.size();
			while(it>=0){
				for(i=min(deadly[it][0],deadly[it][2]);i<=max(deadly[it][0],deadly[it][2]);i++){
					for(j=min(deadly[it][1],deadly[it][3]);j<=max(deadly[it][1],deadly[it][3]);j++){
						grid[i][j]=-1;
					}
				}
				it--;
			}
			visited[0][0]=1;
			grid[0][0]=0;
			recur(0,0,0);
			if(visited[500][500]==0){
				cost[500][500]=-1;
			}
			return cost[500][500];
		}
};

int main(){
	int i,j,input;
	vector <vector <int> > h;
	vector <vector <int> > d;
	cin>>input;
	i=-1;
	j=0;
	while(input!=-1){
		if(j%4==0){
			i++;
			h.resize(i+1);
		}
		h[i].push_back(input);
		j++;
		cin>>input;
	}

	cin>>input;
	i=-1;
	j=0;
	while(input!=-1){
		if(j%4==0){
			i++;
			d.resize(i+1);
		}
		d[i].push_back(input);
		j++;
		cin>>input;
	}
	Escape st;
	cout<<st.lowest2(h,d)<<"\n";

}