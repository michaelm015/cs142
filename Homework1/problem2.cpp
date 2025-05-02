#include <iostream>
#include <cmath>
using namespace std;

bool checkTV(int x, int y) {
    double slope;
    if((y > 200) && (y < 300)) {
        return false;
    } else if(y > 300) {
        slope = double(y-300)/(x-500);
        if (abs(slope)>1) {
            return false;
        }
    } else if(y < 200) {
        slope = double(y-200)/(x-500);
        if (abs(slope)>1) {
            return false;
        }
    }
    return true;
}

bool checkRadiator(int c1, int c2, int rx, int ry, int x, int y) {
    double dist = sqrt((x-rx)*(x-rx) + (y-ry)*(y-ry));
    if((dist >= c1) && (dist <= c2)) {
        return true;
    }
    return false;
}

bool checkWindows(int s, int n, int x, int y){
    if(n == s) {
        if((x >= s) && (x <= s+100)) {
            return true;
        } else {
            return false;
        }
    }
    double slope = 500/(n - s);
    double sx = (x - (y/slope));
    if((sx >= s) && (sx <= s+100)) {
        return true;
    }
    return false;
}

int main() {
    int c1, c2, rx, ry, s, n, m;
    cin >> c1 >> c2 >> rx >> ry >> s >> n >> m;



    int x, y;
    string result;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        if((checkRadiator(c1, c2, rx, ry, x, y) == true) && (checkTV(x, y) == true) && (checkWindows(s, n, x, y) == true)) {
            result = "yes";
        } else {
            result = "no";
        }

        cout << result << endl;
    }

    return 0;
}