/**
 * @file MachineDrawable.cpp
 * @author matt5
 */
#include "pch.h"
#include "MachineDrawable.h"

void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double scale = 0.75f;

    graphics->PushState();
    graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
    graphics->Scale(scale, scale);

    if(mMachine->GetMachineNumber()==1){
        mMachine->SetLocation(wxPoint( 300, 400));
    }

    if(mMachine->GetMachineNumber()==2){
        mMachine->SetLocation(wxPoint( 900, 400));
    }


    mMachine->DrawMachine(graphics);
    mMachine->SetFrameRate(mTimeline->GetFrameRate());
    mMachine->SetSpeed(1);
    //SetTimeline(mTimeline);

    auto sto = mTimeline->GetStartFrame();

    auto sto2 =  mTimeline->GetCurrentFrame();
    if(mTimeline->GetStartFrame() < mTimeline->GetCurrentFrame() || mTimeline->GetStartFrame() == mTimeline->GetCurrentFrame() )
    {
        mMachine->SetMachineFrame(mTimeline->GetCurrentFrame());
    }

   // mMachine->SetMachineNumber(1);
    graphics->PopState();

}

MachineDrawable::MachineDrawable(const std::wstring &name, const std::wstring filename) :
        Drawable(name)
{

    MachineFactory factory(filename);
    auto machine = factory.CreateMachine();
    //machine->SetMachineNumber(1);

    mMachine = machine;

    mMachine->SetSpeed(1);

   // mMachine->SetLocation(wxPoint( x, y));

}

bool MachineDrawable::HitTest(wxPoint point)
{

    return false;

}

void MachineDrawable::SetTimeline(Timeline* timeline)
{
    Drawable::SetTimeline(timeline);

    mTimeline = timeline;
}

void MachineDrawable::ShowDialogBox(wxWindow* parent)
{

    MachineDialog dlg(parent, mMachine);

    if (dlg.ShowModal() == wxID_OK)
    {
        // A machine has been selected


        mMachine->SetMachineNumber(mMachine->GetMachineNumber());

    }

}
