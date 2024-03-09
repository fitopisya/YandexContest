#include <iostream>
#include <vector>
using namespace std;

int FindPerimeter(int N, vector<vector<bool>>& board, const vector<int>& coordX, const vector<int>& coordY) {
    int res = 0;
    vector<vector<int>> offset = { {1,0},{-1,0},{0,1},{0,-1} };
    for (int i = 0; i < N; ++i) {
        board[coordX[i]][coordY[i]] = true;
        int tmp = 0;
        for (int j = 0; j < 4; j += 1)
            if (board[coordX[i] + offset[j][0]][coordY[i] + offset[j][1]]) {
                tmp += 1;
            }
        if (tmp == 0) {
            res += 4;
        }
        else if (tmp == 1) {
            res += 2;
        }
        else if (tmp == 3) {
            res -= 2;
        }
    }
    return res;
}
int main()
{
    int N;
    cin >> N;
    vector<int> coordX, coordY;
    coordX.reserve(N);
    coordY.reserve(N);
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        coordX[i] = value;
        cin >> value;
        coordY[i] = value;
    }
    vector<vector<bool>> board;
    board.reserve(10);
    for (int i = 0; i < 10; ++i) {
        board[i].assign(10, 0);
    }
    cout << FindPerimeter(N, board, coordX, coordY) << endl;
}
