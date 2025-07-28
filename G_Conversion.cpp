#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n= s.size();
    for(int i=0;i<n;i++){
        if(s[i]==',')
            s[i] = ' ';
        else if(s[i]>='a' && s[i]<='z')
            s[i] = toupper(s[i]);
        else if(s[i]>='A' && s[i]<='Z')
            s[i] = tolower(s[i]);
    }
    cout<<s<<endl;
}