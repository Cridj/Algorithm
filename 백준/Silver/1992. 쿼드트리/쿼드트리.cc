#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> board;

struct Pos
{
    int y;
    int x;
};

void check(Pos start, Pos end, string &s)
{
    int first = board[start.y][start.x];
    bool clear = true;

    for (int y = start.y; y < end.y; y++)
    {
        for (int x = start.x; x < end.x; x++)
        {
            if (board[y][x] != first)
            {
                clear = false;
                break;
            }
        }
    }

    if (clear) // 만약 다 같으면 0 또는 1 더하기
    {
        s += to_string(first);
        return;
    }

    s += "(";
    int half = (end.x - start.x) / 2;
    check({start.y, start.x}, {start.y + half, start.x + half}, s); // 좌상
    check({start.y, start.x + half}, {start.y + half, end.x}, s); // 우상
    check({start.y + half, start.x}, {end.y, start.x + half}, s); // 좌하
    check({start.y + half, start.x + half}, {end.y, end.x}, s); //우하
    s += ")";
}

int main()
{
    cin >> N;
    board.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int n = 0; n < N; n++)
        {
            board[i][n] = s[n] - '0';
        }
    }
    Pos start = {0, 0};
    Pos end = {N, N};
    string s;
    check(start, end, s);
    cout << s;
}