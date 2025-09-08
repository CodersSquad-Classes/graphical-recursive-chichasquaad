#include <iostream>
using namespace std;

int koch_curve(int n) {
    if (n == 0) {
        return 1; // Base case: a single line segment
    } else {
        return 4 * koch_curve(n - 1); // Each segment is divided into 4 segments
    }
}

int main() {
    koch_curve(3);

    return 0;
}