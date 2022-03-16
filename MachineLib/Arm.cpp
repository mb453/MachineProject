/**
 * @file Arm.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "Arm.h"

Arm::Arm(double length) : mLength(length)
{

    Rectangle(-5, 5, mLength+5, 10);

    mRotationSink.SetComponent(this);


}

//void Arm::SetPosition(wxPoint point)
//{
//    Component::SetPosition(point);
//
//    double x = mPosition.x + mLength * cos(mRotationSink.GetRotation() * M_PI * 2);
//    double y = mPosition.y + mLength * sin(mRotationSink.GetRotation() * M_PI * 2);
//
//    mPositionSource.SetPosition(wxPoint(x,y));
//}

void Arm::SetRotation(double rotation)
{
    Component::SetRotation(rotation);

    double x = GetPosition().x + mLength * cos(rotation * M_PI * 2);
    double y = GetPosition().y + mLength * sin(rotation * M_PI * 2);

    mPositionSource.SetPosition(wxPoint(x,y));
    //mPositionSink.SetPosition(wxPoint(x,y));
}
