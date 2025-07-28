#include <bits/stdc++.h>
using namespace std;
#define ll long long

class FastDeque {
    std::list<int> dll;
    std::unordered_map<int, std::list<int>::iterator> pos;

public:
    void insert(int x) {
        dll.push_back(x);
        pos[x] = std::prev(dll.end());
    }

    void removeFront() {
        if (!dll.empty()) {
            int val = dll.front();
            pos.erase(val);
            dll.pop_front();
        }
    }

    void removeElement(int x) {
        if (pos.count(x)) {
            dll.erase(pos[x]);
            pos.erase(x);
        }
    }
    int peekFront() {
    if (!dll.empty()) {
        return dll.front();
    } else {
        return -1;
    }
}

    void print() {
        for (int x : dll) std::cout << x << " ";
        std::cout << "\n";
    }
};

int main() {
    FastDeque dq;
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        dq.insert(x);
    }
    ll ans=0;          // Output: 10 20 30

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==dq.peekFront()){
 dq.removeFront();  
        }
        else{
 dq.removeElement(x);
 ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

