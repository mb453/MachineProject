/**
 * @file Piston.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "Piston.h"
#include "Rod.h"

void Piston::Negotiate(Rod* rod)
{

    double a = rod->GetLength();
    double x1 = rod->GetPosition().x;
    double y1 = rod->GetPosition().y;
    double x2 = GetPosition().x;
    double y2 = GetPosition().y;
    double alpha = asin((x2-x1)/a);
    double beta = M_PI/2-alpha;

    double rot = beta*(0.16);
    double pistonY = sqrt(pow((a), 2) - pow((x2-x1), 2))+y1;

    Component::SetPosition(wxPoint(x2, pistonY));

    //rod->SetPosition(wxPoint(x2, alpha));
    rod->SetRotation(rot+0.75);


}

Piston::Piston() : mRodSink(this, this)
{


}
