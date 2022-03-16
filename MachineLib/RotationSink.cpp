/**
 * @file RotationSink.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "RotationSink.h"

void RotationSink::Rotate(double rotation)
{
    mRotation = rotation;
    GetComponent()->SetRotation(rotation * mSpeed + mPhase);
}

RotationSink::RotationSink()
{

}
