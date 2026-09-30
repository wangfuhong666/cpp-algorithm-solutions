#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
    point(double A, double B) {
        x = A, y = B;
    }
    point() = default;
};
point operator-(point a, point b)
{
    return { a.x - b.x,a.y - b.y };
}
point operator+(point a, point b)
{
    return { a.x + b.x,a.y + b.y };
}
double operator*(point a, point b)
{
    return a.x * b.y - b.x * a.y;
}
point operator*(double a, point b)
{
    return { a * b.x,a * b.y };
}
struct line {
    point point_A, point_B;
    line(point A, point B) {
        point_A = A, point_B = B;
    }
    line() = default;
};

point findMeetingPoint(line line_A, line line_B)
{

    // TODO: 在这里输入你的代码，求直线 line_A 与 line_B 的交点
    point p1 = line_A.point_A;
    point p2 = line_A.point_B;
    point p3 = line_B.point_A;
    point p4 = line_B.point_B;
    if (fabs((p1 - p2) * (p3 - p4)) < 1e-9)return { -1,-1 };
    double t = ((p3 - p1) * (p4 - p3)) / ((p2 - p1) * (p4 - p3));
    return p1 + t * (p2 - p1);
}

int main() {
    point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    line AB = line(A, B);
    line CD = line(C, D);
    point ans = findMeetingPoint(AB, CD);
    cout << fixed << setprecision(12) << ans.x << " " << ans.y;
    return 0;
}