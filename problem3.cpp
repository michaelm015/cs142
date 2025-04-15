#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
    string coords, coord1 = "", coord2 = "";
    double x = 0, y = 0, z = 0;
    int score = 0, n;
    cin >> n;
    getline(cin, coords);

    for(int i = 0; i < n; i++) {
        bool space_found = false;
        getline(cin, coords);

        for(int j = 0; j < coords.size(); j++) {
            if(coords[j] == ' ') {
                space_found = true;
            }
            if(coords[j] != ' ' && !space_found) {
                coord1 += coords[j];
            }
            else if(coords[j] != ' ' && space_found) {
                coord2 += coords[j];
            }
        }
        istringstream stox(coord1);
        stox >> x;
        istringstream stoy(coord2);
        stoy >> y;
        z = ((x*x) + (y*y));
        coord1 = "", coord2 = "";

        if(z <= 0.01) {
            score += 10;
        } else if(z <= 0.04) {
            score += 9;
        } else if(z <= 0.09) {
            score += 8;
        } else if(z <= 0.16) {
            score += 7;
        } else if(z <= 0.25) {
            score += 6;
        } else if(z <= 0.36) {
            score += 5;
        } else if(z <= 0.49) {
            score += 4;
        } else if(z <= 0.64) {
            score += 3;
        } else if(z <= 0.81) {
            score += 2;
        } else if(z <= 1) {
            score += 1;
        }
    }
    
    cout << score << endl;

    return 0;
}