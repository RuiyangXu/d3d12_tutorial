#pragma once

#include "DXSample.h"

class DXLearnSample : DXSample {
public:

    DXLearnSample(UINT width, UINT height, std::wstring name);
    virtual void OnInit();
    virtual void OnUpdate();
    virtual void OnRender();
    virtual void OnDestroy();
};