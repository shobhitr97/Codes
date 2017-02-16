#include<bits/stdc++.h>

#define vv vector< vector <char> > 
#define vec vector<char> 
#define vi vector<int> 

using namespace std;

vv com;
vector< vi > com_heirarchy;
vec str;
vi cind;
int n,max_level,t;

int dfs(int index,int num,int level){
	
	int j;
	
	if(level>max_level){
		vi p;
		p.push_back(index);
		com_heirarchy.push_back(p);
		max_level=level;
	}
	else{
		com_heirarchy[level].push_back(index);
	}

	j=0;
	while(j!=num){
		index++;
		index=dfs(index,cind[index],level+1);
		j++;
	}
	return index;
}

int main(){

	int ch,i,index;

	cind.clear();
	i=0;
	while(1){

		str.clear();

		ch=getchar();
		while(ch!=','&&ch!='\n'&&ch!=' '){
			str.push_back(ch);
			ch=getchar();
		}

		com.push_back(str);

		ch=getchar();
		t=0;
		while(ch!=','&&ch!=' '&&ch!='\n'){
			t=( (t*10) + (ch-'0') );
			ch=getchar();
		}
		cind.push_back(t);
		i++;
		if(ch==' '||ch=='\n'){
			break;
		}

	}

	n=i;

	// vec::iterator jt;
	// vv::iterator it;
	// i=0;
    //
	// for(it=com.begin();it!=com.end();it++){
	// 	for(jt = (*it).begin() ; jt != (*it).end() ; jt++){
	// 		cout<< (*jt);
	// 	}
	// 	cout<<"\n"<<cind[i++]<<"\n";
	// }

	max_level=-1;
	index=0;
	while(index!=n){
		index=dfs(index,cind[index],0);
		index++;
	}

	cout<<(max_level+1)<<"\n";

	vector< vi > ::iterator it;
	vi::iterator jt;
	vec::iterator kt;

	for(it=com_heirarchy.begin();it!=com_heirarchy.end();it++){
		for(jt=(*it).begin();jt!=(*it).end();jt++){
			for(kt=com[*jt].begin();kt!=com[*jt].end();kt++){
				cout<<(*kt);
			}
			cout<<" ";
		}
		cout<<"\n";
	}

	return 0;
}