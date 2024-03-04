#include <iostream>
#include <cstdint>

using namespace std;

int64_t FindNextDigit(int64_t oldValue, int k){
    oldValue *= 10;
    for (int i = 0; i < 10; ++i) {
        if ((oldValue + i) % k == 0) {
            return oldValue + i;
        }
    } return -1;
}

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    int64_t oldValue = n;
    oldValue = FindNextDigit(oldValue, k);
    cout << oldValue;
    if (oldValue != -1) {
        cout << string(d - 1, '0');
    }
}
