/**
 * @file ActualMachine.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "ActualMachine.h"
#include "Component.h"

void ActualMachine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{

    for (auto component : mComponents)
    {

        component->DrawComponent(graphics, x , y );
    }

}

void ActualMachine::AddComponent(std::shared_ptr<Component> component)
{

    mComponents.push_back(component);
    component->SetActualMachine(this);

}

void ActualMachine::SetTime(double time)
{

    for (auto component : mComponents)
    {
        component->SetTime(time);
    }

}

ActualMachine::ActualMachine(int mach)
{

}
