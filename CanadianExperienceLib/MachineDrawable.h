/**
 * @file MachineDrawable.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLE_H
#include <machine-api.h>
#include "pch.h"
#include "Drawable.h"
#include "Timeline.h"
/**
 * Drawable class for a Machine
 */
class MachineDrawable : public Drawable{
private:
    ///Pointer to Machine
    std::shared_ptr<Machine> mMachine;

    /// The underlying image we are drawing
    std::unique_ptr<wxImage> mImage;

    /// The graphics bitmap we will use
    wxGraphicsBitmap mBitmap;
    ///Pointer to timeline
    Timeline* mTimeline;

public:
    /**
     * MachineDrawable Constructor
     * @param name
     * @param filename
     */
    MachineDrawable(const std::wstring& name, const std::wstring filename);

    /**
     * Get machinenumber
     * @return machine number
     */
    int GetMachNum(){return mMachine->GetMachineNumber();}
    /**
     * Set Machine number
     * @param num number to set to
     */
    void SetMachNum(int num){mMachine->SetMachineNumber(num);}
    /**
     * Use machine dialog to show a dialog box
     * @param parent parent window to attach dialog box
     */
    void ShowDialogBox(wxWindow *parent);
    /**
     * Draw the MachineDrawable
     * @param graphics graphics pointer
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    /**
     * Override hittest to do nothing
     * @param point
     * @return
     */
    bool HitTest(wxPoint point) override;
    /**
     * Set the timeline
     * @param timeline
     */
    virtual void SetTimeline(Timeline *timeline) override;

};

#endif //CANADIANEXPERIENCE_MACHINEDRAWABLE_H
