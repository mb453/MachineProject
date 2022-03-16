/**
 * @file Component.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "Component.h"

void Component::DrawComponent(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    DrawPolygon(graphics, x+mPosition.x, y+mPosition.y);

}

void Component::SetTime(double time)
{

    mTime = time;

}