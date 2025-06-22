#include "Win32Application.h"
#include <windows.h>
#include <d3d12.h>
#include "DXLearnSample.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    DXLearnSample sample{ 800, 600, L"D3D12" };
    return Win32Application::Run(reinterpret_cast<DXSample*>(&sample), hInstance, nCmdShow);
}