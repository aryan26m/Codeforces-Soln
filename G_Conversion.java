#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    n= s.size();
    for(int i=0;i<n;i++){
        if(s[i]==',')
        swap(s[i]," ");
        else if(s[i]>='a' and s[i]<='z')
        swap(s[i],(s[i]-'a'+'A'));
        else if(s[i]>='A' and s[i]<='Z')
        swap(s[i],(s[i]-'A'+'a'));
    }
    cout<<s<<endl;
}