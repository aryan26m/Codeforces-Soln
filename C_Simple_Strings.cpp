#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  string s;
  cin>>s;
  int n=s.length();
  for(int i=1;i<n;i++){
    if(s[i]==s[i-1]){
        // int q=-1;
        if(i!=n-1){
            // if(s[i]!=s[i+1]){
                int x=s[i]-'a';
                int q=s[i+1]-'a';
                if((x+1)!=q){
                    if(s[i]!='z'){
                        char ch=char('a'+(x+1));
                        s[i]=ch;
                    }
                    else{
                        if(s[i+1]=='a'){
                            s[i]='x';
                        }
                        else{
                            s[i]='a';
                        }
                    }
                }
                else{
                    x=x+2;
                    if(x<=25){
                          char ch=char('a'+(x));
                        s[i]=ch;
                    }
                    else{
                       x=x-3;
                        char ch=char('a'+(x));
                        s[i]=ch;
                    }
                }
        }
        else{
            int x=s[i-1]-'a';
            if(x!=25){
                x++;
                char ch=char('a'+x);
                s[i]=ch;
            }
            else{
                x--;
                char ch=char('a'+x);
                s[i]=ch;
            }
        }
      
      }
}
  cout<<s<<endl;
}
