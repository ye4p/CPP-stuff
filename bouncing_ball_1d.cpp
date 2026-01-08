#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <chrono>

using namespace std;

int main()
{
    double hi, vi, T;
    // cout << "Initial height: ";
    // cin >> hi;
    // cout << "Initial Velocity: ";
    // cin >> vi;
    // cout << "Motion time: ";
    // cin >> T;
    hi = 10;
    vi = 0;
    T = 10;
    const double g = 9.8;
    const double dt = .05;
    const double energyFactor = 0.9;
    double v = vi;
    double h = hi;
    const int screenHeight = 20;   // number of rows in the ASCII screen
    const double maxHeight = 20.0; // map 20 meters to 20 rows
    // cout << "Time\tHeight\tVelocity\n";
    for (double t = 0; t <= T; t = t + dt)
    {
        system("cls");
        int ballRow = screenHeight - (int)((h / maxHeight) * screenHeight);
        if (ballRow < 0)
            ballRow = 0;
        if (ballRow >= screenHeight)
            ballRow = screenHeight - 1;
        cout << t << "\t" << h << "\t" << v << "\n";
        v = v + dt * g;
        h = h - dt * v;
        // cout << "\nh: " << h<< " t: " << t << " v: " << v <<"\n";
        if (h <= 0)
        {
            v = -v * energyFactor;
            h = 0;
        }
        for (int row = 0; row < screenHeight; row++)
        {
            if (row == ballRow)
                cout << "O\n";
            else
                cout << "|\n";
        }

        cout << "====\nt=" << t << "  h=" << h << "  v=" << v << endl;

        v = v + g * dt;
        h = h - v * dt;

        if (h <= 0)
        {
            h = 0;
            v = -v * energyFactor;
        }

        this_thread::sleep_for(chrono::milliseconds(50));
    }
}