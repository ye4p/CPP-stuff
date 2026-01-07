#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double hi, vi, T;
    cout << "Initial height: ";
    cin >> hi;
    cout << "Initial Velocity: ";
    cin >> vi;
    cout << "Motion time: ";
    cin >> T;
    const double g = 9.8;
    const double dt = .01;
    const double energyFactor = 0.9;
    double v = vi;
    double h = hi;
    const int screenHeight = 20;   // number of rows in the ASCII screen
    const double maxHeight = 20.0; // map 20 meters to 20 rows
    cout << "Time\tHeight\tVelocity\n";
    for (double t = 0; t <= T; t = t + dt)
    {
        cout << t << "\t" << h << "\t" << v << "\n";
        v = v + dt * g;
        h = h - dt * v;
        // cout << "\nh: " << h<< " t: " << t << " v: " << v <<"\n";
        if (h <= 0)
        {
            v = -v * energyFactor;
            h = 0;
        }
        // if (v<=.01) {
        //     break;
        // }s
    }
}