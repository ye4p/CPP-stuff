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
    const int screenHeight = 36; // number of rows in the ASCII screen
    const int screenWidth = 80;
    const double maxHeight = 36.0; // map 20 meters to 20 rows
    const double maxWidth = 80.0;
    system("mode con cols=120 lines=40");
    const double dt = 0.05;
    const double T = 10.0;
    for (double t = 0; t < T; t += dt)
    {
        output = "";
        for (int row = 0; row < screenHeight; row++)
        {
            if (row == 0 || row == screenHeight - 1)
            {
                output += "+";
                for (int _ = 0; _ < screenWidth; _++)
                {
                    output += "-";
                }
                output += "+\n";
                continue;
            }
            else
            {
                output += "|";
                for (int _ = 0; _ < screenWidth - 2; _++)
                {
                    output += " ";
                }
                output += "|\n";
            }
            // for (int column = 0; column < screenWidth; column++)
            // {
            //     // if (row == ballRow && column == ballCol)
            //     //     output += "O";
            //     // else
            //     //     output += " ";
            //     if (column == 0 || column == screenWidth - 1)
            //     {
            //         output += "|";
            //     }
            //     else
            //     {
            //         output += " ";
            //     }
            //     output += "\n";
            // }
        }
        cout << output << "                                                                                                                 " << endl;

        this_thread::sleep_for(chrono::milliseconds(50));
    }
}
int main()
{
    display();
    // string stop = "";
    // while (stop==" ") {
    //     cin >> stop;
    // }
}