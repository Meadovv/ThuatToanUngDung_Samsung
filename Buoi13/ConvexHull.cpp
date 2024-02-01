#include <bits/stdc++.h>
#define loop(_i, a, b) for(int _i = a; _i <= b; ++_i)
#define loopr(_i, a, b) for(int _i = a; _i >= b; --_i)
#define ii pair<int,int>
#define InputFormFile(name) freopen(name".input", "r", stdin)
#define OutputToFile(name) freopen(name".output", "w", stdout)
#define FAST(a) ios_base::sync_with_stdio(a); cin.tie(a); cout.tie(a);
#define FILE_NAME "input" // Edit here
using namespace std;

const int N = 1000006;
int n;

struct Point {
    int x, y;

    bool operator < (const Point &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

bool clock_wise(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < 0;
}

bool counter_clock_wise(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) > 0;
}

vector<Point> findConvexHull(vector<Point> &points) {
    sort(points.begin(), points.end());
    if(points.size() <= 2) return points;
    vector<Point> convexHull, upper, lower;
    Point mostLeft = points[0], mostRight = points.back();
    upper.push_back(mostLeft);
    lower.push_back(mostLeft);

    loop(i, 0, points.size() - 1) {
        if(i == points.size() - 1 || clock_wise(mostLeft, points[i], mostRight)) {
            while(upper.size() >= 2 && !clock_wise(upper[upper.size() - 2], upper[upper.size() - 1], points[i])) {
                upper.pop_back();
            }
            upper.push_back(points[i]);
        }

        if(i == points.size() - 1 || counter_clock_wise(mostLeft, points[i], mostRight)) {
            while(lower.size() >= 2 && !counter_clock_wise(lower[lower.size() - 2], lower[lower.size() - 1], points[i])) {
                lower.pop_back();
            }
            lower.push_back(points[i]);
        }
    }

    loop(i, 0, upper.size() - 1) convexHull.push_back(upper[i]);
    loopr(i, lower.size() - 2, 1) convexHull.push_back(lower[i]);

    return convexHull;
}

vector<Point> points, convexHull;
int numPoint;
void Input() {
    cin >> numPoint;
    points.resize(numPoint);
    loop(i, 0, numPoint - 1) cin >> points[i].x >> points[i].y;
}

void Process() {
    convexHull = findConvexHull(points);
}

void Output() {
    cout << convexHull.size() << "\n";
    for(Point p : convexHull) cout << p.x << " " << p.y << "\n";
}

int main() {
    // Do not put your code here
    if(!(FILE_NAME == "DEFAULT")) {
        InputFormFile(FILE_NAME);
        // OutputToFile(FILE_NAME);
        FAST(0);
    }
    Input(), Process(), Output();
    return 0;
}