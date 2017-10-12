#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef set<int> si;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 100005

int lps[num], n;
string s, p, stat;
vector<string>input, output;
bool status[27];

bool SearchPat(string pattern){
    int lenP=pattern.length(), i, j;
    int lenT=s.length();
    bool flag;
    if(lenP!=lenT){
        int starFlag=-1;
        forn(k, 0, lenT)   if(s[k]=='*')   starFlag=k;
        if(starFlag==-1)    return false;
        if(lenP<lenT){
            if(lenP==(lenT-1)){
                i=0, j=0;
                flag=true;
                while(i<lenT){
                    if(pattern[j]==s[i]){
                        j++, i++;
                        continue;
                    }
                    if(s[i]=='?'){
                        if(status[pattern[j]-'a']==false){
                            flag=false;
                            break;
                        }
                    }
                    else{
                        if(s[i]=='*'){
                            i++;
                            continue;
                        }
                        else{
                            flag=false;
                            break;
                        }
                    }
                    j++, i++;        
                }
                return flag;
            }
            else    return false;
        }
        else{
            flag=true;
            for(i=0;i<starFlag;i++){
                if(pattern[i]==s[i]){
                    continue;
                }
                if(s[i]=='?'){
                    if(status[pattern[i]-'a']==false){
                        flag=false;
                        break;
                    }
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag==false) return false;
            j=lenP-1;
            for(i=lenT-1;i>starFlag;i--){
                if(pattern[j]==s[i]){
                    j--;
                    continue;
                }
                if(s[i]=='?'){
                    if(status[pattern[j]-'a']==false){
                        flag=false;
                        break;
                    }
                }
                else{
                    flag=false;
                    break;
                }
                j--;
            }
            if(flag==false) return false;
            for(i=starFlag;i<lenP-(lenT-starFlag-1);i++){
                if(status[pattern[i]-'a']==true)    return false;
            }
            return flag;
        }
    }
    else{
        flag=true;
        for(i=0; i<lenT; i++){
            if(pattern[i]==s[i]){
                continue;
            }
            if(s[i]=='?'){
                if(status[pattern[i]-'a']==false){
                    flag=false;
                    break;
                }
            }
            else{
                if(s[i]=='*'){
                    if(status[pattern[i]-'a']==true){
                        flag=false;
                        break;
                    }
                }
                else{
                    flag=false;
                    break;
                }
            }
        }   
        return flag;
    }
}

int main(){
    string pattern;
    int strLen;

    cin>>stat;
    cin>>s;
    cin>>n;
    fori(0, n){
        cin>>pattern;
        input.pb(pattern);
    }

    fori(0, 27) status[i]=false; 
    fori(0, stat.length())  status[stat[i]-'a']=true;

    fori(0, n){
        strLen=input[i].length();
        if(SearchPat(input[i])==true)   output.pb("YES");
        else    output.pb("NO");
    }
    fori(0, n)  cout<<output[i]<<"\n";
    return 0;
}