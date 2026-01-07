#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double xi, v, T;
    cout << "Initial position: ";
    cin >> xi;
    cout << "Velocity: ";
    cin >> v;
    cout << "Motion time: ";
    cin >> T;
    // cout << "Position init: " << xi <<"\nVelocity: " << v << "\nMotion time: " << T;
    const double dt = 1;
    for (double t = 0; t <= T; t=t+dt) {
        const double x=xi+(v*t);
        cout << "Position at a time t=" << t << " is " << x << " meters.\n";
    }
} 