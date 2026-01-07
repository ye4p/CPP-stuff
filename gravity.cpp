#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double hi, vi, T;
    cout << "Initial height: ";
    cin >> hi;
    cout << "Initial Velocity: ";
    cin >> vi;
    cout << "Motion time: ";
    cin >> T;
    const double g = 9.8;
    const double dt =1;
    // cout << "Position init: " << xi <<"\nVelocity: " << v << "\nMotion time: " << T;
    for (double t = 0; t <= T; t=t+dt) {
        const double v=vi+(g*t);
        const double h =hi - vi*t -g*(t*t)/2;
        cout << "Height at a time t=" << t << " is " << h << " meters.\n";
        cout << "Velocity at a time t=" << t << " is " << v << " meters per second.\n";
    }
} 