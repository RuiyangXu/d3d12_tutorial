#include <windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    MessageBoxW(nullptr, L"Hello, D3D12 world!", L"MyD3D12App", MB_OK);
    return 0;
}
