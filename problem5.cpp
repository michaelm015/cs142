#include <iostream>
#include <queue>
#include <array>
using namespace std;

int possiblex[] = {1, 1, 2, 2, -1, -1, -2, -2};
int possibley[] = {2, -2, 1, -1, 2, -2, 1, -1};

int bfs(int x, int y, int endx, int endy, int arr[8][8]) {
    int moves = 0;

    queue<array<int, 3>> q;
    q.push({x,y,0});
    arr[x][y] = 9;
    
    while(!q.empty()) {
        array<int, 3> square = q.front();
        q.pop();
        x = square[0], y = square[1], moves = square[2];

        if((x == endx) && (y == endy)) {
            return moves;
        }

        for(int i = 0; i < 8; i++) {
            int newx = x + possiblex[i];
            int newy = y + possibley[i];
            
            if((newx >= 0) && (newx < 8) && (newy >= 0) && (newy < 8) && arr[newx][newy] != 9) {
                q.push({newx,newy,moves+1});
                arr[newx][newy] = 9;
            }
        }
    }

    return -1;
}

int main() {
    int n, board = 1, startx, starty, endx, endy;
    cin >> n;
    string in;

    while(n != -1) {
        int arr[8][8] = {0};
        
        for(int i = 0; i < n; i++) {
            cin >> in;
            if(in[0] == 'a') {
                arr[0][in[1]-'1'] = 9;
            } else if(in[0] == 'b') {
                arr[1][in[1]-'1'] = 9;
            } else if(in[0] == 'c') {
                arr[2][in[1]-'1'] = 9;
            } else if(in[0] == 'd') {
                arr[3][in[1]-'1'] = 9;
            } else if(in[0] == 'e') {
                arr[4][in[1]-'1'] = 9;
            } else if(in[0] == 'f') {
                arr[5][in[1]-'1'] = 9;
            } else if(in[0] == 'g') {
                arr[6][in[1]-'1'] = 9;
            } else if(in[0] == 'h') {
                arr[7][in[1]-'1'] = 9;
            }
        }

        cin >> in;
        startx = in[0] - 'a';
        starty = in[1] - '1';

        cin >> in;
        endx = in[0] - 'a';
        endy = in[1] - '1';

        int result = bfs(startx, starty, endx, endy, arr);

        if(result == -1) {
            cout << "Board " << board << ": not reachable" << endl;
        } else {
            cout << "Board " << board << ": " << result << " moves" << endl;
        }

        board++;
        cin >> n;
    }

    return 0;
}