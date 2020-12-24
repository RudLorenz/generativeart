#pragma once

#include "icolor.h"
#include "idrawable.h"
#include "ccs.h"

#include <functional>

class PlotFunction : public IDrawable
{
public:
    PlotFunction(CCS ccs, std::function<double(double)> func);
    void draw(BitmapImg& canvas, const IColor& color) const override;

private:
    CCS ccs_;
    std::function<double(double)> func_;
};
