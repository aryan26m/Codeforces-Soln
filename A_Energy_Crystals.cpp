#include <iostream>
#include <vector>

using namespace std;
int solve(){
    int n;
    cin>>n;
   int k=0;
    while(n){
      n=n/2;
      k++;        
    }
    return (k*2)+1;
}
int main() {
  int t;
    cin >> t;
    while (t--) {
       cout<<solve()<<endl;
    }
}\