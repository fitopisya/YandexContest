#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    string lhs, rhs;
    cin >> lhs >> rhs;
    sort(lhs.begin(), lhs.end());
    sort(rhs.begin(), rhs.end());
    if ( lhs == rhs){
        cout << "YES";
    } else {
        cout << "NO";
    }
}
