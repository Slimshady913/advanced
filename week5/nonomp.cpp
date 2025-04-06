// time./nonomp
// time ./yesomp
#include <iostream>
#include <vector>
#include <cmath>

double compute_value(int i) {
    double val = 0.0;
    for(int j = 0; j < 1000; j++) {
        val += std::sin(i * 0.0001) * std::cos(j * 0.0001);
    }
    return val;
}

int main() {
    const int n = 100000;
    std::vector<double> results(n);
    
    for(int i = 0; i < n; i++) {
        results[i] = compute_value(i);
    }
    return 0;
}