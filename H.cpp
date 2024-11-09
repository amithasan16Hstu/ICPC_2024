#include <bits/stdc++.h>
using namespace std;


long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}


void convertToFraction(double number, long long& p, long long& q) {
    const double epsilon = 1e-9;  
    int sign = (number < 0) ? -1 : 1;  
    number = fabs(number);

    long long integral = static_cast<int>(number);
    double fractional = number - integral;

    
    if (fractional < epsilon) {
        p = sign * integral;
        q = 1;
        return;
    }

    
    const int maxDenominator = 1000000;
    q = 1;
    double closestError = fabs(number - static_cast<double>(integral));

    
    for (int i = 1; i <= maxDenominator; ++i) {
        int numerator = static_cast<int>(number * i + 0.5);  
        double error = fabs(number - static_cast<double>(numerator) / i);
        
        if (error < closestError) {
            closestError = error;
            p = numerator * sign;
            q = i;
            
            if (error < epsilon) break;  
        }
    }

   
    int commonDivisor = gcd(abs(p), abs(q));
    p /= commonDivisor;
    q /= commonDivisor;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        
        long double s = (x + y + z) / 2.0;
        
      
        long double area = ((s - x) * (s - y) * (s - z)) / s;
        
        
        long long p, q;
        convertToFraction(area, p, q);
        
        
        cout << p << "/" << q << endl;
    }
}
