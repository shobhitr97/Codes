#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;
#define num 1000002
int main(){
int i,j,t,len,temp,mid,ch;
char a[num],*ptr,temp2='0';
//long long int n;
scanf("%d\n",&t);
while(t--){
    i=0;
    scanf("%s ",a);
    len=strlen(a);
    if(len==1&&a[0]=='0'){
        cout<<"1\n";
        continue;
    }
    //cout<<len<<"\n";
    mid=temp=(len-1)/2;
    j=mid+1;
    //cout<<j<<"\n";
    ch=1;
    while(j<len){        //&&ch){
        if(a[j]<a[len-1-j]){
            ch=0;
            break;
        }
        j++;
    }
    if(ch){
        while(a[temp]=='9'){
            temp2='9';
            a[temp]='0';
            if(!temp){
                break;
            }
            temp--;
        }
        if(temp==0&&a[temp]=='0'&&temp2=='9'){
            len++;
            mid=(len-1)/2;
            a[mid]=a[mid-1];
            a[0]='1';
            temp2='0';
        }
        else{
            a[temp]++;
        }
        
    }
    a[len]='\0';
    
    if(len%2){
        mid--;
    }
    
    for(i=mid;i>=0;i--){
        a[len-1-i]=a[i];
    }
    
    ptr=a;
    while(*ptr=='0'){
        ptr++;
    }
    
    printf("%s\n",ptr);
}
return 0;
}
