#include<bits/stdc++.h>
using namespace std;
bool palindrome(int i,int j ,string &s){
    if(i>j){
        // cout<<n<<endl;
        return true;
    }
    if(s[i]!=s[j]){
        return false;
    }
    palindrome(i+1,j-1,s);
}
int main(){
    int n=s.size();
    int a[10];   
}