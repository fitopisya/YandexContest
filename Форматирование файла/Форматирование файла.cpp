#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    int cnt;
    cin >> cnt;
    uint64_t spaceres = 0;
    for (int i = 0; i < cnt; ++i) {
        int spaceNum;
        cin >> spaceNum;
        int res = spaceNum / 4; 
        spaceNum %= 4; 
        if (spaceNum != 0) {
            (spaceNum == 1) ? ++res : res += 2;
        }
        spaceres += res;
    }
    cout << spaceres;
}
