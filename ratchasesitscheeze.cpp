#include<iostream>
using namespace std;
bool ratchase(char maze[][10], int sol[][10], int i, int j, int m, int n) {
    //base case
    if (i == m - 1 and j == n - 1) {
        sol[i][j] = 1;

        return true;
    }
    //recursive case
    sol[i][j] = 1;
    if (j + 1 < n and maze[i][j + 1] != 'X'  and (sol[i][j + 1] != 1)) {
        bool kyaright = ratchase(maze, sol, i, j + 1, m, n);
        if (kyaright == true) return true;
    }
    if (i + 1 < m and maze[i + 1][j] != 'X' and (sol[i + 1][j] != 1)) {
        bool kyabottom = ratchase(maze, sol, i + 1, j, m, n);
        if (kyabottom == true) return true;
    }
    if (j - 1 >= 0 and maze[i][j - 1] != 'X' and  (sol[i][j - 1] != 1)) {
        bool kyaleft = ratchase(maze, sol, i, j - 1, m, n);
        if (kyaleft == true) return true;
    }
    if ((i - 1 >= 0) and maze[i - 1][j] != 'X' and (sol[i - 1][j] != 1)) {
        bool kyaup = ratchase(maze, sol, i - 1, j, m, n);
        if (kyaup == true) return true;
    }
    sol[i][j] = 0;
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    char maze[10][10];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
        }
    }
    int sol[10][10] = {0};
    bool ans = ratchase(maze, sol, 0, 0, m, n);
    if (ans) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    else {
        cout << "No path found";
    }
    return 0;
}