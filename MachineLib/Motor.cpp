/**
 * @file Motor.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "Motor.h"
void Motor::DrawComponent(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{

    //    // The body
    mPoly = std::make_shared<Polygon>();
//    int wid = 550;
//
    mPoly->SetImage(mImagesDir + L"/motor-frame.png");
    mPoly->Rectangle(50, -40, 100, 100);


    mPoly->DrawPolygon(graphics, x+GetPosition().x,y+GetPosition().y+8);

    Component::DrawComponent(graphics, 100+x, -85+y);

    mPoly->GetRotation();
}

void Motor::SetTime(double time)
{




    SetRotation(mSpeed * time);
}

//void Motor::SetPosition(int x, int y)
//{
//    mPosition.x = x;
//    mPosition.y = y;
//
//
//}

void Motor::SetSpeed(double speed)
{

    mSpeed = speed;
}

Motor::Motor(std::wstring mImagesDir) : mImagesDir(mImagesDir)
{

    CenteredSquare(50);
    SetImage(mImagesDir + L"/electric-wheel.png");

}

void Motor::SetRotation(double rotation)
{
    Component::SetRotation(rotation);

    mSource.SetRotation(rotation);


}

