#include <bits/stdc++.h>

using namespace std;

#define M_PI 3.14159265358979323846

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {

    }
};



Point GenerateRandomPoint(std::mt19937& engine, std::uniform_real_distribution<double>& dis) {
    return Point(dis(engine), dis(engine));
}

double CountPi(int n, std::mt19937& engine, std::uniform_real_distribution<double>& dis) {
    double m = 0;
    for (int i = 0; i < n; ++i) {
        Point p = GenerateRandomPoint(engine, dis);
        if (p.x * p.x + p.y * p.y <= 1) {
            ++m;
        }
    }
    return 4 * m / static_cast<double>(n);
}

int main() {
    std::mt19937 engine;
    engine.seed(std::time(nullptr));
    std::uniform_real_distribution<double> dis(-1.0, 1.0);
    ofstream fout;
    fout.open("generated_data.txt", std::ofstream::out);
    vector<double> pi;
    for (int i = 100; i < 5001; i += 100) {
        pi.push_back(CountPi(i, engine, dis));
    }
    for (int i = 100; i < 5001; i += 100) {
        fout << i << " ";
    }
    fout << endl;
    for (int i = 0; i < pi.size(); ++i) {
        fout << setprecision(15) << pi[i] << " ";
    }
    fout << endl;
    for (int i = 0; i < pi.size(); ++i) {
        fout << setprecision(15) << (pi[i] - M_PI) / M_PI * 100 << " ";
    }
    fout << endl;
    fout.flush();
    fout.close();
    return 0;
}