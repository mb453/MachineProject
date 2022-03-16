/**
 * @file PositionSink.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "PositionSink.h"
#include "PositionSource.cpp"

PositionSink::PositionSink()
{

}

void PositionSink::SetPosition(wxPoint point)
{
    GetComponent()->SetPosition(point);
}
