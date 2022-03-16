/**
 * @file Lever.cpp
 * @author Matthew Baxter
 */


#include "pch.h"
#include "Lever.h"

Lever::Lever(double length, double height) : mLength(length), mRodSink(this, this)
{

    mLength = length;
    height = 50;
    int width = mLength;
    Rectangle(-mLength/2,height/2, width, height);

    //mRodSink.SetComponent(this);


}


void Lever::Negotiate(Rod *rod)
{


    int a = mDriveEnd;

    int b = rod->GetLength();

    double x2 = GetPosition().x;
    double y2 = GetPosition().y;

    double x1 =rod->GetPosition().x;
    double y1 = rod->GetPosition().y;

    double c = std::sqrt(pow((y2-y1),2.0)+pow((x2-x1),2.0));

    double delta = atan2(-1*(y2-y1),x2-x1);

    double alpha = acos((pow(b,2.0)+pow(c,2.0)-pow(a,2.0))/(2*b*c));

    double theta = delta-alpha;

    double x3 = (x1+b*cos(-1*theta));

    double y3 = (y1+b*sin(-1*theta));

    double phi = atan2((y3-y2),(x3-x2));




    Component::SetRotation(phi*.16);

    mSource.SetRotation(phi*.16);


    Component::SetRotation(phi*.16);


    mSource.SetRotation(phi*.16);
    //Component::SetPosition(wxPoint(x3,y3));

    mPSource.SetPosition(wxPoint(x2-a*cos(phi),y2-a*sin(phi)));

    rod->SetRotation(((-1.0*theta)*.16)+0.75);


}


