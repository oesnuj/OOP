//202111602 김준서
//잘 작동합니다.
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int board[19][19], boardSize = 19;

const int ways = 4;
const int dir[4][2] = { {1, 0}, //아래
                       {0, 1}, //오른쪽
                       {1, 1}, //오른쪽 아래 대각선
                       {1, -1} }; //왼쪽 아래 대각선

void makeBoard();
int isWinner();
bool checkOmok(int x, int y, int stone);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    makeBoard();
    if (isWinner() == 1)
        cout << "Black";
    else if (isWinner() == 2)
        cout << "White";
    else
        cout << "Not Finished";

    return 0;
}

void makeBoard()
{
    ifstream f("board.txt");
    f >> boardSize;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            int stone;
            f >> stone;
            board[i][j] = stone;
        }
    }
}

int isWinner() {
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (board[i][j] == 1)
            {
                if (checkOmok(i, j, 1))
                    return 1;
            }
            else if (board[i][j] == 2)
            {
                if (checkOmok(i, j, 2))
                    return 2;
            }
        }
    }
    return 0;
}


bool checkOmok(int x, int y, int stone)
{
    for (int w = 0; w < ways; w++) {
        int cnt = 1; //이미 하나는 놓아져 있는 상태에서 탐색
        int nx = x + dir[w][0], ny = y + dir[w][1];
        while (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && board[nx][ny] == stone)
        {
            cnt++;
            if (cnt == 5)
                return true;

            nx += dir[w][0];
            ny += dir[w][1];
        }
    }
    return false;
}