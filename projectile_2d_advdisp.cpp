#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <windows.h>
#include <cstdlib>
#include <cstdint>

using namespace std;

static const int W = 800;
static const int H = 800;
static uint32_t *gPixels = nullptr;
static BITMAPINFO gBmi = {};

void InitFramebuffer()
{
    gPixels = new uint32_t[W * H];

    gBmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    gBmi.bmiHeader.biWidth = W;
    gBmi.bmiHeader.biHeight = -H;
    gBmi.bmiHeader.biPlanes = 1;
    gBmi.bmiHeader.biBitCount = 32;
    gBmi.bmiHeader.biCompression = BI_RGB;
}
void ShutdownFramebuffer()
{
    delete[] gPixels;
    gPixels = nullptr;
}
void Clear(uint32_t color)
{
    for (int i = 0; i < W * H; i++)
    {
        gPixels[i] = color;
    }
}
void PutPixel(int x, int y, uint32_t color)
{
    if (x < 0 || x >= W || y < 0 || y >= H)
    {
        return;
    }
    gPixels[y * W + x] = color;
}
void PutPixel2(int ind, uint32_t color)
{
    if (ind < 0 || ind >= W * H)
    {
        return;
    }
    gPixels[ind] = color;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_TIMER:
        InvalidateRect(hwnd, nullptr, FALSE);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        StretchDIBits(
            hdc,
            0, 0, W, H,
            0, 0, W, H,
            gPixels,
            &gBmi,
            DIB_RGB_COLORS,
            SRCCOPY);
        EndPaint(hwnd, &ps);
        return 0;
    }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void display()
{
    double v, T, angleDegrees;
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
    // system("mode con cols=120 lines=40");
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

        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main()
{
    InitFramebuffer();
    WNDCLASSW wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = L"MySimWindowClass";
    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        wc.lpszClassName,
        L"Simulation",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        W, H,
        nullptr, nullptr,
        wc.hInstance, nullptr);
    ShowWindow(hwnd, SW_SHOW);
    SetTimer(hwnd, 1, 16, nullptr);
    MSG msg;
    int squareW = 600;
    int squareH = 600;
    // top line: (squareW*(H-squareH)/2 +(W-squareW)/2 < i && squareW*(H-squareH)/2 +(W-squareW)/2 >i)

    // i < W || i % W == 0 || i % W == W - 1 || i >= W * (H - 1)
    for (int i = 0; i < W * H; i++)
    {
        if ((squareW * (H - squareH) / 2 + (W - squareW) / 2 > i && squareW * (H - squareH) / 2 + (W - squareW) / 2 < i))
        {
            PutPixel2(i, 0x00FFFFFF);
        }
        else
        {
            PutPixel2(i, 0x00000000);
        }
    }
    InvalidateRect(hwnd, nullptr, FALSE);
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    ShutdownFramebuffer();
    return 0;
}