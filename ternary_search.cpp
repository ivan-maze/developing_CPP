#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Example: maximum or minimum point for a quadratic function
// Function to optimize (must be unimodal in the interval)
double f(double x) {
    return (x - 2) * (x - 2) + 3;  // Minimum at x = 2, value = 3
}

// Ternary Search on real numbers (minimization)
double ternarySearch(double left, double right, double epsilon = 1e-7) {
    while (right - left > epsilon) {
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;

        if (f(mid1) > f(mid2))
            left = mid1;
        else
            right = mid2;
    }

    return (left + right) / 2;
}

int main() {
    double left = -10;
    double right = 10;

    double result = ternarySearch(left, right);

    cout << fixed << setprecision(7);
    cout << "Minimum point found at x = " << result << endl;
    cout << "Minimum value is f(x) = " << f(result) << endl;

    return 0;
}
