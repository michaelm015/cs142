#include <iostream>
#include <array>
using namespace std;

int main() {
    int T, n, m, score = 0;
    cin >> T >> n >> m;
    int scores[T] = {};

    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = a; j <= b; j++) {
            if(c == 1) {
                scores[j] = 3;
            } else {
                scores[j] = 1;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = a; j <= b; j++) {
            if(c == 1) {
                scores[j] = 3;
            } else if(scores[j] == 0){
                scores[j] = 1;
            }
        }
    }

    for(int i = 0; i < T; i++) {
        score += scores[i];
    }

    cout << score << endl;

    return 0;
}
