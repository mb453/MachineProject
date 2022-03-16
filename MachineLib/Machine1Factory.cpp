/**
 * @file Machine1Factory.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "pch.h"
#include <wx/stdpaths.h>
#include "Machine1Factory.h"
#include "ActualMachine.h"
#include "Component.h"
#include "Shape.h"
#include "Motor.h"
#include "Gear.h"
#include "Arm.h"
#include "Rod.h"
#include "Lever.h"
#include "Piston.h"
using namespace std;
/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";

std::shared_ptr<ActualMachine> Machine1Factory::CreateMachine()
{

    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor so it knows
    // its number.
    auto machine = make_shared<ActualMachine>(1);






    // The base
    auto base = make_shared<Shape>();
    int wid = 550;
    base->Rectangle(-wid/2, 39, wid, 40);
    base->SetImage(mImagesDir + L"/base.png");
    machine->AddComponent(base);


    // The motor
    auto motor = make_shared<Motor>(mImagesDir);
    motor->SetPosition(wxPoint(23, 34));
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);


    auto gear1 = make_shared<Gear>(20, 10);
    gear1->SetImage(mImagesDir + L"/iron.png");
    gear1->SetPosition(wxPoint(125, -50));
    machine->AddComponent(gear1);

    motor->GetSource()->AddSink(gear1->GetSink());


    // A post that holds the larger gear
    auto gear2post = make_shared<Shape>();
    gear2post->Rectangle(-10, 0, 20, 30);
    gear2post->SetPosition(wxPoint(gear1->GetPosition().x + 55, 0));
    gear2post->SetColor(wxColour(0, 128, 0));
    machine->AddComponent(gear2post);

    // The second gear
    // Radius=40pixels, 20 teeth
    auto gear2 = make_shared<Gear>(40, 20);
    gear2->SetImage(mImagesDir + L"/hammered-copper.png");
    gear2->SetPosition(wxPoint(gear1->GetPosition().x + 55, gear1->GetPosition().y));

    gear1->Drive(gear2, 0.1);

    gear1->GetSink()->SetPhase(2);

    gear1->GetSource()->AddSink(gear2->GetSink());

    machine->AddComponent(gear2);


    // The arm attached to the second gear
    // 50 pixels long
    auto arm = make_shared<Arm>(50);
    arm->SetImage(mImagesDir + L"/arm1.png");
    arm->SetPosition(gear2->GetPosition());
    machine->AddComponent(arm);

    gear2->GetSource()->AddSink(arm->GetSink());


    //The lever
    auto lever = make_shared<Lever>(400);
    lever->SetPosition(wxPoint(0, -190));
    lever->SetImage(mImagesDir + L"/lever.png");
    lever->SetDriveEnd(185);
    machine->AddComponent(lever);

    //The flag attached to the lever
    //Adding the points allows (0,0) be at the end
    //of the flagpole, so it rotates around that point.
    auto flag = make_shared<Shape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(mImagesDir + L"/flag.png");
    flag->SetPosition(lever->GetPosition());
    machine->AddComponent(flag);
    lever->GetSource()->AddSink(flag->GetSink());



    // The column that holds the lever
    auto column = make_shared<Shape>();
    column->Rectangle(-20, 0, 40, 220);
    column->SetImage(mImagesDir + L"/column.png");


    // Column is added after the lever so it is in front
    machine->AddComponent(column);



    // Column is added after the lever so it is in front
    machine->AddComponent(column);

    // Rod from arm to lever
    // 150 pixels long, 7 pixels wide
    auto rod1 = make_shared<Rod>(150,5);
    int gray = 50;
    rod1->SetColor(wxColour(gray, gray, gray));
    machine->AddComponent(rod1);

    arm->GetPositionSource()->AddComponent(rod1);
    rod1->SetRodSink(lever->GetRodSink());

    // Rod from lever to Piston
    // 50 pixels long, 5 pixels wide
    auto rod2 = make_shared<Rod>(50,5);
    rod2->SetColor(wxColour(gray, gray, gray));

    lever->GetPositionSource()->AddComponent(rod2);

    // Piston
    // The points are added so that (0,0) is
    // the attachment point for the rod.
    auto piston = make_shared<Piston>();
    double pistonH = 90;
    double pistonW = 0.386 * pistonH;
    double pistonC = 13.0 / 215.0 * pistonH;
    piston->AddPoint(-pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC + pistonH);
    piston->AddPoint(-pistonW / 2, -pistonC + pistonH);
    piston->SetImage(mImagesDir + L"/piston.png");
    piston->SetPosition(wxPoint(-175, -150));
    machine->AddComponent(piston);
    rod2->SetRodSink(piston->GetRodSink());

    machine->AddComponent(rod2);


    // Cylinder
    auto cylinder = make_shared<Shape>();
    cylinder->Rectangle(-30, 0, 60, 120);
    cylinder->SetPosition(wxPoint(-175, 8));
    cylinder->SetImage(mImagesDir + L"/cylinder.png");
    machine->AddComponent(cylinder);


    return machine;
}

Machine1Factory::Machine1Factory(std::wstring imagesDir) : mImagesDir(imagesDir)
{



}



