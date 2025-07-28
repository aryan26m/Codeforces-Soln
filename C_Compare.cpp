#include<bits/stdc++.h>

using namespace std;

int main(){

    string s1,s2,s="";

    cin>>s1>>s2;
  int n = min(s1.size(),s2.size());
//   cout<<n<<endl;
    for(int i=0;i<n;i++){

            if(s1[i]<s2[i]){
                s=s1;
                break;
            }
            else if(s1[i]>s2[i]){
                s=s2;
                break;
            }
        }

        if(s==""){
            if(s1.size()<s2.size()){
                s=s1;
            }
            else{
                s=s2;
            }
        }
cout<<s<<endl;

return 0;

}