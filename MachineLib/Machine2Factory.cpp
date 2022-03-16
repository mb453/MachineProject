/**
 * @file Machine2Factory.cpp
 * @author matt5
 */
#include "pch.h"
#include "Machine2Factory.h"

#include <wx/stdpaths.h>
#include "Machine1Factory.h"
#include "ActualMachine.h"
#include "Component.h"
#include "Shape.h"
#include "Motor.h"
#include "Gear.h"
using namespace std;
/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";

std::shared_ptr<ActualMachine> Machine2Factory::CreateMachine()
{

    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor so it knows
    // its number.
    auto machine = make_shared<ActualMachine>(2);

    // The motor
    auto motor = make_shared<Motor>(mImagesDir);
    motor->SetPosition(wxPoint(23, 34));
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);

    auto gear1 = make_shared<Gear>(20, 10);
    gear1->SetImage(mImagesDir + L"/rust.png");
    gear1->SetPosition(wxPoint(125, -50));
    machine->AddComponent(gear1);

    //The flag attached to the lever
    //Adding the points allows (0,0) be at the end
    //of the flagpole, so it rotates around that point.
    auto flag = make_shared<Shape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(mImagesDir + L"/msu-flag.png");
    flag->SetPosition(gear1->GetPosition());
    machine->AddComponent(flag);
    gear1->GetSource()->AddSink(flag->GetSink());

    motor->GetSource()->AddSink(gear1->GetSink());






    return machine;
}

Machine2Factory::Machine2Factory(std::wstring imagesDir) : mImagesDir(imagesDir)
{



}
