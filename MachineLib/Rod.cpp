/**
 * @file Rod.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "Rod.h"
#include "RodSource.h"

Rod::Rod(double length, double width) : mLength(length)
{

    Rectangle(-width/2,length, width, length);

    mLength = length;

    mRotationSource.SetComponent(this);
    mPositionSink.SetComponent(this);


    //mRodSource = std::make_shared<RodSource>();
    //mRodSink->SetComponent(this);

}

void Rod::SetPosition(wxPoint point)
{
    Component::SetPosition(point);

    mPositionSource.SetPosition(point);
    if( mRodSink !=nullptr)
    {
        //mRodSource->Negotiate(this);
        mRodSink->Negotiate(this);
    }
}

void Rod::DrawComponent(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::DrawComponent(graphics, x, y);
}
