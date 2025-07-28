#include <iostream>
#include <vector>
using namespace std;



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> A(N, vector<char>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];

    int x, y;
    cin >> x >> y;
    x--; y--;  
    
    
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    bool ans=true;
    for (int d = 0; d < 8; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (A[nx][ny] != 'x'){
              ans=false;  
              break;
            } 
        }
    }
    if(ans){   
        cout << "yes\n";
    }
    else
        cout << "no\n";

    return 0;
}