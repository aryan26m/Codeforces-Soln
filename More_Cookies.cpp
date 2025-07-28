#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,c;
	    cin>>n>>c;
	    vector<int> cookies(n);
	    set<int> cntt;
	    for(int i=0;i<n;i++)
	    {
	        cin>>cookies[i];
	        cntt.insert(cookies[i]);
	    }

	    int extra = 0;
	    while(true) {
	        int ttl = c + extra;

	        if (cntt.count(ttl)) {
	            extra++;
	            continue;
	        }
	        bool check = false;
	        for(int fcnt : cookies) {
	            if (fcnt < ttl) {
	                check = true;
	                break;
	            }
	        }

	        if (check) {
	            cout << extra << endl;
	            break; 
	        } else {
	            extra++;
	        }
	    }
	}
	return 0;
}