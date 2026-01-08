#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    string output="";
    gotoxy(0,0);
    double v, T, angleDegrees;
    // cout << "Initial height: ";
    // cin >> hi;
    // cout << "Initial Velocity: ";
    // cin >> vi;
    // cout << "Motion time: ";
    // cin >> T;
    v = 30;
    T = 10;
    const double g = 9.8;
    const double dt = .05;
    angleDegrees= 60;
    double angleRadians=angleDegrees*numbers::pi/ 180.0;

    const int screenHeight = 36;   // number of rows in the ASCII screen
    const double maxHeight = 36.0; // map 20 meters to 20 rows
    for (double t=0; t<=T; t+=dt) {
        double vx = v * cos(angleRadians);
        double vy = v * sin(angleRadians)- g*t;
        double h = v * sin(angleRadians)*t - g*t*t/2;
        double x = vx*t;
        int ballrow;
        if (h<=0 && t>0) {
            break;
        }
        int ballRow = screenHeight - (int)((h / maxHeight) * screenHeight);
        

        //cout << "vx: " << vx << " vy: " << vy << " h: " << h << "\n";

    }
} 