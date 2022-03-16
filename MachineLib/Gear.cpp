/**
 * @file Gear.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "Gear.h"
const double ToothDepth = 5;     ///< Depth of a tooth in pixels
const double ToothWidth = 0.33;  ///< Width of a tooth at the top as fraction of tooth pitch
const double ToothSlope = 0.1;   ///< Fraction of pitch where the tooth slopes up or down
/// PI * 2 constant
const double PI2 = M_PI * 2;

void Gear::DrawComponent(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Component::DrawComponent(graphics, x, y);

}

Gear::Gear(int radius, int numTeeth) : mRadius(radius), mNumTeeth(numTeeth)
{
    // Where the tooth starts in the arc
    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;
    double innerRadius = radius - ToothDepth;

    for (int t = 0; t < numTeeth; t++)
    {
        double angle1 = double(t) / double(numTeeth) * PI2;
        double angle2 = double(t + toothStart) / double(numTeeth) * PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(numTeeth) * PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(numTeeth) * PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(numTeeth) * PI2;

        AddPoint(innerRadius * cos(angle1), innerRadius * sin(angle1));
        AddPoint(innerRadius * cos(angle2), innerRadius * sin(angle2));
        AddPoint(radius * cos(angle3), radius * sin(angle3));
        AddPoint(radius * cos(angle4), radius * sin(angle4));
        AddPoint(innerRadius * cos(angle5), innerRadius * sin(angle5));
    }


    mRotationSink.SetComponent(this);

}

void Gear::Drive(std::shared_ptr<Gear> gear, double phase)
{

    auto sink = gear->GetSink();

    mSource.AddSink(sink);
    sink->SetSpeed(-(double)mNumTeeth / (double)gear->mNumTeeth);
    sink->SetPhase(phase);

}

void Gear::SetRotation(double rotation)
{
    Component::SetRotation(rotation);

    mSource.SetRotation(rotation);
}
