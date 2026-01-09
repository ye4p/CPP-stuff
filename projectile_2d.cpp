#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <windows.h>
#include <cstdlib>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void display()
{
    string output = "";
    gotoxy(0, 0);
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
    angleDegrees = 60;
    const double pi = acos(-1);
    double angleRadians = angleDegrees * pi / 180.0;

    const int screenHeight = 36; // number of rows in the ASCII screen
    const int screenWidth = 80;
    const double maxHeight = 36.0; // map 20 meters to 20 rows
    const double maxWidth = 80.0;
    system("mode con cols=120 lines=40");
    for (double t = 0; t <= T; t += dt)
    {
        double vx = v * cos(angleRadians);
        double vy = v * sin(angleRadians) - g * t;
        double h = v * sin(angleRadians) * t - g * t * t / 2;
        double x = vx * t;
        if (h <= 0 && t > 0)
        {
            break;
        }
        int ballRow = screenHeight - (int)((h / maxHeight) * screenHeight);
        int ballCol = (int)((x / maxWidth) * screenWidth);
        string output = "";
        gotoxy(0, 0);
        if (ballRow < 0)
            ballRow = 0;
        if (ballRow >= screenHeight)
            ballRow = screenHeight - 1;
        // if (ballCol < 0)
        //     ballCol = 0;
        if (ballCol >= screenWidth)
            ballCol = screenWidth - 1;
        for (int row = 0; row < screenHeight; row++)
        {
            for (int column = 0; column < screenWidth; column++)
            {
                if (row == ballRow && column == ballCol)
                    output += "O";
                else
                    output += " ";
            }
            output += "\n";
        }
        cout << output << "\n" << "vx: " << vx << " vy: " << vy << " h: " << h << "x: " << x << "                                     " << endl;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main()
{
    string line = "";
    while (line.length() == 0)
    {
        cin >> line;
    }
    display();
}
