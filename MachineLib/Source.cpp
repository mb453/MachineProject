/**
 * @file Source.cpp
 * @author matt5
 */
#include "pch.h"
#include "Source.h"
#include "RotationSink.h"

void Source::SetRotation(double rotation)
{

    for(auto sinks : mSinks)
    {
        sinks->Rotate(rotation);
    }


}
