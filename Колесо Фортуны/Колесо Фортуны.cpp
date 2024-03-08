#include <iostream>
#include <vector>
using namespace std;

void Check(int a, int k, int N, int& max, vector<int>& vec) {
    int quantity = ((a - 1) / k) % N;
    int left_index = !quantity ? quantity : N - quantity, right_index = quantity;
    if (vec[left_index] > vec[right_index]) {
        max < vec[left_index] ? max = vec[left_index] : 0;
    } else {
        max < vec[right_index] ? max = vec[right_index] : 0;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> vec;
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> vec.emplace_back(value);
    }
    int a, b, k, max = 0;
    cin >> a >> b >> k;
    if (a == b) {
        Check(a, k, N, max, vec);
        cout << max << endl;
        return 0;
    }
    unsigned long long tmp;
    if ((b + 1) < (a + N * (unsigned long long)k + 1)) {
        tmp = (b + 1);
    } else {
        tmp = a + N * (unsigned long long)k + 1;
    }
    for (auto i = a; i < tmp; i += k) {
        Check(i, k, N, max, vec);
    }
    cout << max << endl;
}
