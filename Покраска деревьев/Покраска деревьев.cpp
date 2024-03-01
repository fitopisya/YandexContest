#include <iostream> 
#include <algorithm> 
using namespace std; 

int main() { 
  int vasyaTree, vasyaV, mashaTree, mashaV; 
  cin >> vasyaTree >> vasyaV >> mashaTree >> mashaV; 
  cout << 2 * (vasyaV + mashaV + 1) - max(0, min(vasyaTree + vasyaV, mashaTree + mashaV) - max(vasyaTree - vasyaV, mashaTree - mashaV) + 1); 
}
