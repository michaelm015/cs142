#include <iostream>
#include <vector>
using namespace std;



int lus(vector<int>& arr) {
    int n = arr.size();
    if(n < 3) {
        return 0;
    }

    vector<int> lis(n, 1);
    vector<int> lds(n, 1);

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                lds[i] = max(lds[i], lds[j]+1);
            }
        }
    }

    int longest = 0;
    for(int i = 0; i < n; i++) {
        if(lis[i] > 1 && lds[i] > 1) {
            longest = max(longest, lis[i] + lds[i] - 1);
        }
    }

    if(longest < 3) {
        return 0;
    }
    else {
        return longest;
    }
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << lus(arr) << endl;

    return 0;
}