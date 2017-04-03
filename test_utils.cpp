#include <iostream>

#include "utils.h"

using namespace std;

int main() {
    Utils utils = Utils();
    
    for (int i = 0; i < 10; i++) {
        cout << utils.rand_int_between(0, 10) << endl;
    }
    return 0;
}

