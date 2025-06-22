#include "DXLearnSample.h"
#include <d3d12.h>

DXLearnSample::DXLearnSample(UINT width, UINT height, std::wstring name) : DXSample(width, height, name)
{
}

void DXLearnSample::OnInit()
{
	InitD3D12();
	InitSwapChain();
}

void DXLearnSample::InitD3D12()
{
	UINT dxgiFactoryFlags = 0;
#if defined(_DEBUG) || defined(DEBUG)
	ComPtr<ID3D12Debug> debugController;
	if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
	{
		debugController->EnableDebugLayer();
	}
	dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
#endif
	ThrowIfFailed(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&m_factory)));

	ThrowIfFailed(D3D12CreateDevice(
		nullptr, // Use the default adapter
		D3D_FEATURE_LEVEL_11_0,
		IID_PPV_ARGS(&m_device)
	));

	D3D12_COMMAND_QUEUE_DESC commandQueueDesc{ D3D12_COMMAND_LIST_TYPE_DIRECT, D3D12_COMMAND_QUEUE_PRIORITY_NORMAL, D3D12_COMMAND_QUEUE_FLAG_NONE, 0 };
	ThrowIfFailed(m_device->CreateCommandQueue(
		&commandQueueDesc,
		IID_PPV_ARGS(&m_commandQueue)
	));
	ThrowIfFailed(m_device->CreateCommandAllocator(
		D3D12_COMMAND_LIST_TYPE_DIRECT,
		IID_PPV_ARGS(&m_commandAllocator)
	));
	ThrowIfFailed(m_device->CreateCommandList(
		0,
		D3D12_COMMAND_LIST_TYPE_DIRECT,
		m_commandAllocator.Get(),
		nullptr,
		IID_PPV_ARGS(&m_commandList)
	));
	ThrowIfFailed(m_commandList->Close());
}

void DXLearnSample::InitSwapChain()
{

	// Describe and create the swap chain.
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
	swapChainDesc.BufferCount = 2;
	swapChainDesc.Width = m_width;
	swapChainDesc.Height = m_height;
	swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.SampleDesc.Count = 1;

	ComPtr<IDXGISwapChain1> swapChain;

	ThrowIfFailed(m_factory->CreateSwapChainForHwnd(
		m_commandQueue.Get(),
		Win32Application::GetHwnd(),
		&swapChainDesc,
		nullptr,
		nullptr,
		&swapChain
	));
	ThrowIfFailed(swapChain.As(&m_swapChain));
	m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

}

void DXLearnSample::OnUpdate()
{
}

void DXLearnSample::OnRender()
{
}

void DXLearnSample::OnDestroy()
{
}
