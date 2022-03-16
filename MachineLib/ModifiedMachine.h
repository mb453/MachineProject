/**
 * @file ModifiedMachine.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MODIFIEDMACHINE_H
#define CANADIANEXPERIENCE_MODIFIEDMACHINE_H
#include "pch.h"
#include "Machine.h"

class ActualMachine;
/**
 * Holds pointer to Machine
 */
class ModifiedMachine : public Machine{
private:
    ///Location of modified machine
    wxPoint mLocation;
    ///Framerate of modified machine
    double mFrameRate;
    ///Speed of modified Machine
    double mSpeed;
    ///Machine Number
    int mNumber;
    ///Machine time
    double mTime;

    /// The ModifiedMachine this actual machine is associated with
    std::shared_ptr<ActualMachine> mMachine= nullptr;

    /// The images directory
    std::wstring mImagesDir;


public:

    /**
     * Draw this Actual machine
     * @param graphics graphics pointer
     */
    virtual void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;
    /**
     * Set location of this actual machine
     * @param point point to draw this actual machine
     */
    void SetLocation(wxPoint point){mLocation = point;}

    /**
* Set the current machine animation frame
* @param frame Frame number
*/
    virtual void SetMachineFrame(int frame);

    /**
     * Set the expected frame rate in frames per second
     * @param rate Frame rate in frames per second
     */
    virtual void SetFrameRate(double rate);

    /**
    * Set  the bend angleGetM
    * @param speed Speed from 0 to 1, where 1 is full speed
    */
    virtual void SetSpeed(double speed);

    /**
    * Set the machine number
    * @param machine An integer number. Each number makes a different machine
    */
    virtual void SetMachineNumber(int machine);

    /**
     * Get the current machine number
     * @return Machine number integer
     */
    virtual int GetMachineNumber(){return mNumber;}
    /**
     * Get machine location
     * @return mLocation
     */
    virtual wxPoint GetLocation(){return mLocation;}

    /**
     * Get the current machine time.
     * @return Machine time in seconds
     */
    virtual double GetMachineTime();
    /**
     * ModifiedMachine location
     * @param mImagesDir
     */
    ModifiedMachine(std::wstring mImagesDir);

    /// Copy constructor (disabled)
    ModifiedMachine(const ModifiedMachine &) = delete;

    /// Assignment operator
    void operator=(const ModifiedMachine &) = delete;



};

#endif //CANADIANEXPERIENCE_MODIFIEDMACHINE_H
