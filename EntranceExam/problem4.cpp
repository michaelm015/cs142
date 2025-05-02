#include <iostream>
using namespace std;

int main() {
    int n, temp;
    string s1, s2;
    cin >> n >> s1 >> s2;

    int arr[n+1][n+1];
    for(int i = 0; i <= n; i++) {
        arr[i][0] = i;
        arr[0][i] = i;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                arr[i][j] = arr[i-1][j-1];
            } else {
                temp = arr[i-1][j-1];
                if(arr[i][j-1] < temp) {
                    temp = arr[i][j-1];
                }
                if(arr[i-1][j] < temp) {
                    temp = arr[i-1][j];
                }
                arr[i][j] = temp+1;
            }
        }
    }

    cout << arr[n][n] << endl;

    return 0;
}