#include <iostream>
#include <Windows.h>
using namespace std;

int map[8][8] = {
    0,1,0,0,1,0,0,0,
    0,1,0,0,0,0,1,0,
    0,0,0,0,1,1,1,0,
    0,1,1,0,1,0,1,0,
    0,1,0,0,0,0,1,0,
    0,0,0,0,1,1,0,0,
    0,1,1,0,1,1,0,1,
    0,1,1,0,1,0,0,0,
};

int used[8][8];
int direct[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };

void print(int nowY, int nowX)
{
    system("cls");
    for (int x = 0; x < 10; x++) cout << "■";
    cout << endl;
    for (int y = 0; y < 8; y++) {
        cout << "■";
        for (int x = 0; x < 8; x++) {
            if (y == nowY && x == nowX) {
                cout << "★";
            }
            else if (map[y][x] == 0) {
                cout << "  ";
            }
            else {
                cout << "■";
            }
        }
        cout << "■";
        cout << endl;
    }
    for (int x = 0; x < 10; x++) cout << "■";
    Sleep(50);
}

void run(int nowY, int nowX)
{
    print(nowY, nowX);
    if (nowY == 7 && nowX == 7) {
        cout << "발견" << endl;
        system("color 1F");
        Sleep(1000);
        system("color 07");
        return;
    }

    for (int t = 0; t < 4; t++) {
        int ny = nowY + direct[t][0];
        int nx = nowX + direct[t][1];

        if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8) continue;
        if (map[ny][nx] == 1) continue;
        if (used[ny][nx] == 1) continue;
        used[ny][nx] = 1;
        run(ny, nx);
        print(nowY, nowX);
        used[ny][nx] = 0;
    }

}

int main()
{
    used[0][0] = 1;
    run(0, 0);

    return 0;
}