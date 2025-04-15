#include <iostream>
using namespace std;

int main() {
    string houses, house1 = "", house2 = "", score_houses;
    int score_h1 = 0, score_h2 = 0;
    getline(cin, houses);
    
    bool space_found = false;
    for(int i = 0; i < houses.size(); i++) {
        if(houses[i] == ' ') {
            space_found = true;
        }
        if(houses[i] != ' ' && !space_found) {
            house1 += houses[i];
        }
        else if(houses[i] != ' ' && space_found) {
            house2 += houses[i];
        }
    }
    
    while(getline(cin, score_houses)) {
        if(score_houses == house1) {
            score_h1 += 10;
        }
        else if(score_houses == house2) {
            score_h2 += 10;
        }
        else {
            if(score_houses[0] == house1[0]) {
                score_h1 += 150;
            } else {
                score_h2 += 150;
            }
            break;
        }
    }

    if(score_h1 > score_h2) {
        cout << house1 << " wins" << endl;
        cout << score_h1 << "-" << score_h2 << endl;
    } else if(score_h2 > score_h1) {
        cout << house2 << " wins" << endl;
        cout << score_h2 << "-" << score_h1 << endl;
    } else {
        cout << "Tie" << endl;
        cout << score_h1 << "-" << score_h2 << endl;
    }
    
    return 0;
}