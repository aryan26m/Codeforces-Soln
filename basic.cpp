#include<bits/stdc++.h>
using namespace std;
int countDigits(int n) {
    // code here
    int a=0;
        while(n!=0){
           n=n/10;
           a++;
        }
    cout<<a<< endl;
    }
    int main(){
        int n;
        cin>>n;
        countDigits(n);
    }