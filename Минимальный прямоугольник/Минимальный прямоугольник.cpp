#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> x, y;
    x.reserve(N);
    y.reserve(N);
    for (int i = 0; i < N; i++){
        int value;
        cin >> x.emplace_back(value);
        cin >> y.emplace_back(value);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << x[0] << " " << y[0] << " " << x[x.size()-1] << " " << y[y.size()-1];
}
