#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vect(n);

    for(int i = 0; i < n; i++) {
        int step;
        cin >> step;
        vect.at(i) = step;
    }
    int difference = vect.at(0) - vect.at(1);
    int difference2 = vect.at(1) - vect.at(2);
    if(difference != difference2) {
        if((vect.at(2) - vect.at(3)) == difference2) {
            cout << 1 << endl;
        } else if((vect.at(2) - vect.at(3)) == (vect.at(3) - vect.at(4))) {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    } else {
        for(int i = 0; i < n-1; i++) {
            if((vect.at(i) - vect.at(i+1)) != difference) {
                cout << i+2 << endl;
                break;
            }
        }
    }
    
    return 0;
}