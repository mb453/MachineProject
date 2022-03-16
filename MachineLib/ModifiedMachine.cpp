/**
 * @file ModifiedMachine.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "ModifiedMachine.h"
#include "ActualMachine.h"
#include "Machine1Factory.h"
#include "Machine2Factory.h"

void ModifiedMachine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachine->DrawMachine(graphics, mLocation.x, mLocation.y);
}

void ModifiedMachine::SetMachineFrame(int frame)
{

    mTime = frame / mFrameRate * mSpeed;
    mMachine->SetTime(mTime);

}

void ModifiedMachine::SetFrameRate(double rate)
{

    mFrameRate = rate;

}

void ModifiedMachine::SetSpeed(double speed)
{
    mSpeed = speed;
}

void ModifiedMachine::SetMachineNumber(int machine)
{

    if(machine == 1)
    {
        Machine1Factory factory(mImagesDir);
        mMachine = factory.CreateMachine();
        mNumber = machine;
    }
    if(machine == 2)
    {
        Machine2Factory factory2(mImagesDir);
        mMachine = factory2.CreateMachine();
        mNumber = machine;
    }
}



double ModifiedMachine::GetMachineTime()
{
    return Machine::GetMachineTime();
}

ModifiedMachine::ModifiedMachine(std::wstring mImagesDir) : mImagesDir(mImagesDir)
{
    SetMachineNumber(1);
}
