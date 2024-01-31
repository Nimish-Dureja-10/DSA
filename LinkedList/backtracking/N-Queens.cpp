// N - Queen Problem
#include <iostream>
#include <vector>
using namespace std;

bool canWePlace(int row,int col,vector<vector<char> > &grid) {
    // we will check vertically
    for(int i = row-1;i>=0;i--) {
        if(grid[i][col]=='Q') {
            return false;
        }
    }

    // we will check left top digonally
    for(int i=row-1, j=col-1;i>=0 && j>=0;i--,j--) {
        if(grid[i][j]=='Q') {
            return false;
        }
    }

    // we will check right top digonal
    for(int i=row-1, j=col+1;i>=0 && j<grid.size();i--,j++) {
        if(grid[i][j]=='Q') {
            return false;
        }
    }

    // if queen is safe to be placed
    return true;
}

void nqueen(int currRow,int n,vector<vector<char> > &grid) {
    if(currRow == n) {
        cout<<"Queen can be placed in this order"<<endl;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"********"<<endl;
        return;
    }

    for(int col=0;col<n;col++) {
        // we will check for all the cols
        // lets check if we can place a queen at currRow and col
        if(canWePlace(currRow,col,grid)) {
            grid[currRow][col] = 'Q';
            nqueen(currRow+1,n,grid);
            grid[currRow][col] = '.';
        }
    }
}

int main(){
    int n =4;
    vector<vector<char> > grid(n,vector<char> (n,'.'));
    nqueen(0,n,grid);
    return 0;
}