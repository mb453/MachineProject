/**
 * @file Lever.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H
#include "Component.h"
#include "RotationSource.h"
#include "PositionSource.h"
#include "PositionSink.h"
#include "INegotiator.h"
#include "Rod.h"
#include "RodSink.h"
/**
 * The lever moves up and down from a rod
 */
class Lever : public Component , public INegotiator{
private:
    ///Length of the Lever
    double mLength;
    ///Drive end of the Lever
    double mDriveEnd = 185;
    ///RodSink for the Lever
    RodSink mRodSink;
    ///PositionSource
    PositionSource mPSource;
    ///RotationSource
    RotationSource mSource;

public:
    /**
     * Constructor for lever
     * @param mLength length of lever
     * @param hieght height of lever
     */
    Lever(double mLength, double hieght = -1);

    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    RotationSource *GetSource() { return &mSource; }
    /**
     * Get the rod sink of the lever
     * @return mRodSink
     */
    RodSink *GetRodSink() {return &mRodSink;}
    /**
     * Get the positionsource of the lever
     * @return mPSource
     */
    PositionSource *GetPositionSource() {return &mPSource;}
    /**
     * Set the Drive end for the Lever
     * @param point point to be new driveend
     */
    void SetDriveEnd(double point){mDriveEnd = point;}
    /**
     * Move the lever through negotiating it
     * @param rod rod to negotiate lever
     */
    virtual void Negotiate(Rod *rod) override;

    /// Copy constructor (disabled)
    Lever(const Lever &) = delete;

    /// Assignment operator
    void operator=(const Lever &) = delete;



};

#endif //CANADIANEXPERIENCE_LEVER_H
