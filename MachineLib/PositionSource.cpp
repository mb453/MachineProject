/**
 * @file PositionSource.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "PositionSource.h"

void PositionSource::SetPosition(wxPoint point)
{
    mPosition = point;
    for(auto component : mComponents)
    {
        component->SetPosition(point);
    }

}

PositionSource::PositionSource()
{

}




