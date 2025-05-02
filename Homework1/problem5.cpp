#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point {
    int x, y;
    
    bool operator < (const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int cross(const Point &o, const Point &a, const Point &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double area(const vector<Point> &hull) {
    double result = 0;
    int n = hull.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        result += hull[i].x * hull[j].y;
        result -= hull[i].y * hull[j].x;
    }
    return abs(result) / 2.0;
}

vector<Point> convexHull(vector<Point> &points) {
    sort(points.begin(), points.end());
    
    vector<Point> lower, upper;
    
    for (const Point &p : points) {
        while (lower.size() >= 2 && cross(lower[lower.size() - 2], lower[lower.size() - 1], p) <= 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }
    
    for (int i = points.size() - 1; i >= 0; --i) {
        while (upper.size() >= 2 && cross(upper[upper.size() - 2], upper[upper.size() - 1], points[i]) <= 0) {
            upper.pop_back();
        }
        upper.push_back(points[i]);
    }
    
    lower.pop_back();
    upper.pop_back();
    
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

int main() {
    vector<Point> points(4);
    
    for (int i = 0; i < 4; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    
    vector<Point> hull = convexHull(points);
    
    if (hull.size() == 2) {
        cout << "0.000000\n";
    } else {
        double result = area(hull);
        cout << fixed << setprecision(6) << result << endl;
    }

    return 0;
}