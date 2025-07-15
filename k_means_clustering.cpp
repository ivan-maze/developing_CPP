#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point {
    double x, y;
    int cluster;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void kmeans(vector<Point> &points, vector<Point> &centroids, int k, int iterations) {
    int n = points.size();
    for (int it = 0; it < iterations; it++) {
        // Assign clusters
        for (int i = 0; i < n; i++) {
            double min_dist = 1e9;
            int cluster_id = -1;
            for (int j = 0; j < k; j++) {
                double dist = distance(points[i], centroids[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    cluster_id = j;
                }
            }
            points[i].cluster = cluster_id;
        }

        // Update centroids
        vector<double> sum_x(k, 0.0), sum_y(k, 0.0);
        vector<int> count(k, 0);
        for (int i = 0; i < n; i++) {
            int c = points[i].cluster;
            sum_x[c] += points[i].x;
            sum_y[c] += points[i].y;
            count[c]++;
        }

        for (int j = 0; j < k; j++) {
            if (count[j] > 0) {
                centroids[j].x = sum_x[j] / count[j];
                centroids[j].y = sum_y[j] / count[j];
            }
        }
    }
}

int main() {
    srand(time(0));
    int n = 10; // number of data points
    int k = 2;  // number of clusters

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
        points[i].cluster = -1;
    }

    vector<Point> centroids(k);
    for (int j = 0; j < k; j++) {
        centroids[j].x = rand() % 100;
        centroids[j].y = rand() % 100;
    }

    kmeans(points, centroids, k, 10);

    cout << "Final centroids:\n";
    for (int j = 0; j < k; j++) {
        cout << "Cluster " << j << ": (" << centroids[j].x << ", " << centroids[j].y << ")\n";
    }

    cout << "\nPoint assignments:\n";
    for (int i = 0; i < n; i++) {
        cout << "Point (" << points[i].x << ", " << points[i].y << ") -> Cluster " << points[i].cluster << "\n";
    }

    return 0;
}
