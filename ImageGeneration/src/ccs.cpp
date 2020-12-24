#include "ccs.h"

#include "line.h"


CCS::CCS(Point center, size_t scale)
    : center_(center)
    , scale_(scale)
{
}

void CCS::draw(BitmapImg& canvas, const IColor& color) const
{
    const auto canvas_width = canvas.getWidth() - 1;
    const auto canvas_height = canvas.getHeight() - 1;
    const auto Ox = Line(0, center_.y(), canvas_width, center_.y());
    const auto Oy = Line(center_.x(), 0, center_.x(), canvas_height);

    std::vector<Line> incisions;
    incisions.reserve((canvas_width - center_.x()) / scale_ + (canvas_height - center_.y()) / scale_);

    for (int x = center_.x(); x < canvas_width; x += scale_) {
        incisions.emplace_back(Line{x, center_.y() - 5, x, center_.y() + 5});
    }
    for (int x = center_.x(); x > 0; x -= scale_) {
        incisions.emplace_back(Line{x, center_.y() - 5, x, center_.y() + 5});
    }
    for (int y = center_.y(); y < canvas_height; y += scale_) {
        incisions.emplace_back(Line{center_.x() - 5, y, center_.x() + 5, y});
    }
    for (int y = center_.y(); y > 0; y -= scale_) {
        incisions.emplace_back(Line{center_.x() - 5, y, center_.x() + 5, y});
    }

    for (const auto& item : incisions) {
        item.draw(canvas, color);
    }

    Ox.draw(canvas, color);
    Oy.draw(canvas, color);
}

Point CCS::center() const
{
    return center_;
}

size_t CCS::scale() const
{
    return scale_;
}
