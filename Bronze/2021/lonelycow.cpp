#include <iostream>
#include <string>
using namespace std;
int main() {
  int a = 0;
  int L;
  string strings;
  cin >> L;
  cin >> strings;
  for (int i = 0; i < L-2; i++) {
    int G = 0;
    int H = 0;
    for (int r = i;r < L;r++) {
      if (strings[r] == 'G') {
        G += 1;
      } else {H += 1;}
      if (G+H >= 3 &&(G == 1 || H == 1)) {
          
        a += 1;

      }

    }
    

  }
  cout << a;
}
