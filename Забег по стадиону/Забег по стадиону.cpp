#include <iostream>
#include <set>
#include <iomanip>
using namespace std;

void CheckV1V2(double x1, double v1, double x2, double v2, int& tmp, double L, set<double>& cur) {
    double t = 0.;
    double vDiff = v1 - v2;
    double vSum = v1 + v2;
    if (v1 != v2) {
        t = (x2 - x1 + L * tmp) / vDiff;
        if (t >= 0) {
            cur.insert(t);
        }
        t = (x2 - x1 - L * tmp) / vDiff;
        if (t >= 0) {
            cur.insert(t);
        }
    }
    if (v1 != -v2) {
        t = (-x2 - x1 + L * tmp) / vSum;
        if (t >= 0) {
            cur.insert(t);
        }
        t = (-x2 - x1 - L * tmp) / vSum;
        if (t >= 0) {
            cur.insert(t);
        }
    } ++tmp;
}

pair<bool, double> FindMinTime(double L, double x1, double v1, double x2, double v2)
{
    int tmp = 0;
    set<double> cur;
    set<double> res;
    while (res.size() < 2) {
        cur.clear();
        CheckV1V2(x1, v1, x2, v2, tmp, L, cur);
        if (!cur.empty()) {
            res.insert(*cur.begin());
        }
    } return make_pair(true, *res.begin());
}

int main()
{
    double L, x1, v1, x2, v2;
    cin >> L >> x1 >> v1 >> x2 >> v2;
    if (x1 + x2 == L || x1 == x2) {
        cout << "YES" << "\n" << 0;
        return 0;
    }

    if (v1 == 0 && v2 == 0) {
        cout << "NO";
        return 0;
    }
    auto result = FindMinTime(L, x1, v1, x2, v2);
    if (result.first == true) {
        cout << "YES" << "\n";
        cout << std::fixed << std::showpoint;
        cout << setprecision(10);
        cout << result.second;
    }
    else {
        cout << "NO";
    }
}
