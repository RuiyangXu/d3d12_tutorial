#pragma once

#include "DXSample.h"

class DXLearnSample : DXSample {
public:
    DXLearnSample(UINT width, UINT height, std::wstring name);
    virtual void OnInit();
    void InitD3D12();
    void InitSwapChain();
    virtual void OnUpdate();
    virtual void OnRender();
    virtual void OnDestroy();
protected:
    ComPtr<IDXGIFactory4> m_factory;
    ComPtr<ID3D12Device> m_device;
	ComPtr<ID3D12CommandQueue> m_commandQueue;
	ComPtr<ID3D12CommandAllocator> m_commandAllocator;
	ComPtr<ID3D12GraphicsCommandList> m_commandList;
    ComPtr<IDXGISwapChain3> m_swapChain;
    UINT m_frameIndex;
};