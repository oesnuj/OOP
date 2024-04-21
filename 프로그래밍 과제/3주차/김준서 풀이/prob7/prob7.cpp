//202111602 김준서
//잘 작동합니다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countStoneToCapture(int x, int y, int color);
void printBoard(int(*arr)[8]);
void computerMove(int& computer_x, int& computer_y);
bool isGameOver();
bool isValidMove(int x, int y, int color);
void flipStones(int x, int y, int color);
int countScore(int player);
void determineWinner();
struct Point
{
    int x;
    int y;

};
vector<Point> flipCoords;

const int boardSize = 8;
int board[boardSize][boardSize]{ 0 };
const int WAYS = 8;
const int WAY[8][2] = { { -1, 0 },
                        { 1, 0 },
                        { 0, -1 },
                        { 0, 1 },
                        { -1, 1 },
                        { -1, -1 },
                        { 1, -1 },
                        { 1, 1 } };

int main()
{
    // 기본 세팅
    board[3][3] = 2;
    board[3][4] = 1;
    board[4][3] = 1;
    board[4][4] = 2;
    printBoard(board);

    // 게임 루프
    while (!isGameOver()) {
        int player_x, player_y;
        cout << "말을 놓을 위치를 입력하시오 (x y): ";
        cin >> player_x >> player_y;

        if (!isValidMove(player_x, player_y, 1)) {
            cout << "불가능한 위치입니다. 다시 입력하세요.\n";
            continue;
        }

        // 플레이어의 돌 놓기
        board[player_x][player_y] = 1;
        flipStones(player_x, player_y, 1);
        printBoard(board);

        // 컴퓨터의 턴
        int computer_x, computer_y;
        computerMove(computer_x, computer_y);
        if (isValidMove(computer_x, computer_y, 2)) {
            board[computer_x][computer_y] = 2;
            flipStones(computer_x, computer_y, 2);
            cout << "컴퓨터가 [" << computer_x << ", " << computer_y << "]에 말을 놓았습니다.\n";
            printBoard(board);
        }
        else {
            cout << "컴퓨터가 놓을 수 있는 위치가 없습니다.\n";
        }
    }
    determineWinner();
    cout << "게임이 종료되었습니다.\n";
    return 0;
}


void printBoard(int(*arr)[8])  //보드판 출력함수
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int countStoneToCapture(int x, int y, int color) {  //잡을 수 있는 상대 말의 개수
    bool flipPossible = false;
    int totalFlips = 0;

    for (int i = 0; i < 8; ++i) {
        int dx = WAY[i][0];
        int dy = WAY[i][1];

        int nx = x + dx;
        int ny = y + dy;

        // 현재 방향으로 탐색을 시작하기 전에 먼저 다른 색의 돌을 만나는지 확인
        if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && board[nx][ny] == (3 - color)) {
            bool currentDirectionFlipPossible = false;
            int currentDirectionFlips = 0;
            bool sameColorFound = false;
            // 다른 색의 돌을 만나면 현재 방향으로 계속해서 탐색
            while (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
                // 같은 색의 돌을 만나면 탐색을 중단하고 뒤집는 게 가능함을 표시
                if (board[nx][ny] == color) {
                    sameColorFound = true;
                    break;
                }
                // 빈 공간을 만나면 탐색을 중단하고 뒤집는 게 불가능함을 표시
                else if (board[nx][ny] == 0) {
                    break;
                }
                // 다른 색의 돌을 계속해서 만나면 탐색을 계속 진행
                nx += dx;
                ny += dy;
                currentDirectionFlips++;
            }

            // 같은 색의 돌이 있고, 뒤집는 게 가능하다면 해당 플립 수를 누적
            if (sameColorFound && currentDirectionFlips > 0) {
                totalFlips += currentDirectionFlips;
                flipPossible = true;
            }
        }
    }

    // 모든 방향에서 뒤집는 게 가능하다면 총 뒤집을 수 있는 돌의 수 반환
    if (flipPossible) {
        return totalFlips;
    }
    else {
        return 0; // 뒤집을 수 있는 돌이 없는 경우 0 반환
    }
}


void computerMove(int& computer_x, int& computer_y) {
    int maxFlips = 0;
    vector<Point> maxFlipsCoords;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (isValidMove(i, j, 2)) {
                int flips = countStoneToCapture(i, j, 2);
                if (flips > maxFlips) {
                    maxFlips = flips;
                    maxFlipsCoords.clear();
                    maxFlipsCoords.push_back({ i, j });
                }
                else if (flips == maxFlips) {
                    maxFlipsCoords.push_back({ i, j });
                }
            }
        }
    }

    // 가장 많은 돌을 뒤집을 수 있는 위치 중 하나를 선택
    // 여기에서 무작위 선택 대신에 첫 번째 위치를 선택합니다.
    if (!maxFlipsCoords.empty()) {
        computer_x = maxFlipsCoords[0].x;
        computer_y = maxFlipsCoords[0].y;
    }
    else {
        // 놓을 수 있는 위치가 없을 때의 예외 처리
        cout << "컴퓨터가 놓을 수 있는 위치가 없습니다." << endl;
        // 게임 종료 또는 다른 처리
    }
}

bool isValidMove(int x, int y, int color) {
    // 이미 돌이 놓여있는 경우 이동할 수 없습니다.
    if (board[x][y] != 0) return false;
    // 놓을 수 있는 위치인지 확인합니다.
    return countStoneToCapture(x, y, color) > 0;
}
bool isGameOver() {
    // 모든 칸이 차 있거나, 양 팀 모두 더 이상 놓을 수 있는 위치가 없으면 게임이 종료됩니다.
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            // 빈 칸이 있고, 해당 위치에 어느 색의 돌이든 놓을 수 있다면 게임은 계속됩니다.
            if (board[i][j] == 0 && (isValidMove(i, j, 1) || isValidMove(i, j, 2))) {
                return false;
            }
        }
    }
    return true;
}

void flipStones(int x, int y, int color) {
    board[x][y] = color; // 선택한 위치에 돌을 놓습니다.
    for (int i = 0; i < WAYS; ++i) {
        int dx = WAY[i][0];
        int dy = WAY[i][1];

        vector<Point> tempFlipCoords; // 임시로 뒤집을 돌의 좌표를 저장합니다.

        int nx = x + dx;
        int ny = y + dy;

        while (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
            if (board[nx][ny] == 0) {
                break; // 빈 칸을 만나면 중단합니다.
            }
            if (board[nx][ny] == color) {
                for (auto& p : tempFlipCoords) { // 뒤집을 돌이 확정되었으므로 뒤집습니다.
                    board[p.x][p.y] = color;
                }
                break; // 같은 색의 돌을 만나면 루프를 종료합니다.
            }
            // 다른 색의 돌을 만나면 뒤집을 목록에 추가합니다.
            tempFlipCoords.push_back({ nx, ny });

            nx += dx;
            ny += dy;
        }
    }
}

int countScore(int player) {
    int score = 0;
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == player) {
                score++;
            }
        }
    }
    return score;
}

void determineWinner() {
    int blackScore = countScore(1);
    int whiteScore = countScore(2);

    if (blackScore > whiteScore) {
        cout << "흑돌이 승리했습니다!" << endl;
    }
    else if (blackScore < whiteScore) {
        cout << "백돌이 승리했습니다!" << endl;
    }
    else {
        cout << "무승부입니다!" << endl;
    }
}