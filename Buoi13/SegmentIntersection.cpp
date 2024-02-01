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
int n, ans = 0;

#define Point pair<float, float>
#define x first
#define y second

struct Line {
    float a, b, c;
    Point u, v;
    Line(Point _u, Point _v) {
        a = _u.y - _v.y;
        b = _v.x - _u.x;
        c = _u.x * _v.y - _u.y * _v.x;
        u = _u, v = _v;
    }

    Point Intersect(Line l) {
        return Point(
            (b * l.c - c * l.b) * 1.0 / (a * l.b - b * l.a),
            (c * l.a - a * l.c) * 1.0 / (a * l.b - b * l.a)
        );
    }

    bool isParallel(Line l) {
        return fabs(a * l.b - b * l.a) < 1e-9;
    }
};

bool areCollinear(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    return area == 0;
}

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) {
        return areCollinear(p, q, r);
    }
    return false;
}

vector<Line> lines;

void Input() {
    cin >> n;
    loop(i, 1, n) {
        float x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines.push_back(Line(Point(x1, y1), Point(x2, y2)));
    }
}

void Process() {
    loop(i, 0, n - 2) {
        loop(j, i + 1, n - 1) {
            if(lines[i].isParallel(lines[j])) continue;
            Point p = lines[i].Intersect(lines[j]);
            if(onSegment(lines[i].u, p, lines[i].v) && onSegment(lines[j].u, p, lines[j].v)) {
                ans++;
            }
        }
    }
}

void Output() {
    cout << ans;
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