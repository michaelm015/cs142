#include <iostream>
using namespace std;

int main() {
    int num, rows, total = 0, largest = -1;
    cin >> num >> rows;
    int books[num];

    for(int i = 0; i < num; i++) {
        cin >> books[i];
        total += books[i];
        if(books[i] > largest) {
            largest = books[i];
        }
    }

    int width = (total + rows - 1)/rows;
    if(largest > width) {
        width = largest;
    }

    int result;
    while(width <= total) {
        int mid = (width + total)/2;
        int rownum = 1, curr = 0;

        for(int i = 0; i < num; i++) {
            if(curr + books[i] > mid) {
                rownum++;
                curr = 0;
            }
            curr += books[i];
        }

        if(rownum <= rows) {
            result = mid;
            total = mid - 1;
        } else {
            width = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}