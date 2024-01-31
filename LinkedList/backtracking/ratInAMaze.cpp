// Rat in a maze problem using backtracking.
#include <iostream>
#include <vector>
using namespace std;

bool canWeGo(int a,int b,vector<vector<int> > &grid) {
    return (a < grid.size() && b < grid.size() && a >= 0 && b >= 0) && grid[a][b] == 1;
}

int f(int i,int j,vector<vector<int> > grid) {
    int n = grid.size();
    if(i==n-1 && j==n-1) return 1;

    int ans = 0;
    grid[i][j] = 2;
    if(canWeGo(i,j+1,grid)) // right
        ans += f(i,j+1,grid);
    
    if(canWeGo(i+1,j,grid)) // down
        ans += f(i+1,j,grid);
    
    if(canWeGo(i,j-1,grid)) // left
        ans += f(i,j-1,grid);
    
    if(canWeGo(i-1,j,grid)) // up
        ans += f(i-1,j,grid);
    
    // backtracking all visited node for checking in other paths.
    grid[i][j] = 1;
    return ans;
}

int main() {
    vector<vector<int> > grid = {
        {1,1,1,1},
        {0,1,0,1},
        {0,1,1,1},
        {0,1,1,1}
    };
    int res = f(0,0,grid);
    cout<<res<<endl;
    return 0;
}