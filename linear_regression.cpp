#include <iostream>
#include <vector>

using namespace std;

double predict(double x, double w, double b) {
    return w * x + b;
}

double compute_cost(vector<double> &x, vector<double> &y, double w, double b) {
    int n = x.size();
    double cost = 0.0;
    for (int i = 0; i < n; i++) {
        double f = predict(x[i], w, b);
        cost += (f - y[i]) * (f - y[i]);
    }
    return cost / n;
}

void gradient_descent(vector<double> &x, vector<double> &y, double &w, double &b, double lr, int iterations) {
    int n = x.size();
    for (int it = 0; it < iterations; it++) {
        double dw = 0.0, db = 0.0;
        for (int i = 0; i < n; i++) {
            double f = predict(x[i], w, b);
            dw += (f - y[i]) * x[i];
            db += (f - y[i]);
        }
        dw /= n;
        db /= n;

        w -= lr * dw;
        b -= lr * db;

        if (it % 100 == 0) {
            cout << "Iteration " << it << " Cost: " << compute_cost(x, y, w, b) << endl;
        }
    }
}

int main() {
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 4, 6, 8, 10};

    double w = 0.0;
    double b = 0.0;
    double lr = 0.01;
    int iterations = 1000;

    gradient_descent(x, y, w, b, lr, iterations);

    cout << "Final model: y = " << w << "x + " << b << endl;

    return 0;
}
