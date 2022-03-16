/**
 * @file Arm.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H
#include "Component.h"
#include "RotationSink.h"
#include "PositionSource.h"
#include "PositionSink.h"
/**
 * Arm component which translates rotation movement to a rod
 */
class Arm : public Component{
private:

    ///Length of arm
    double mLength;
    ///Rotation sink of arm
    RotationSink mRotationSink;
    ///Positionsink of arm
    PositionSink mPositionSink;

    /// Rotation source for this component
    PositionSource mPositionSource;

public:
    /**
     * Get the rotation sink of the arm
     * @return mRotationSink
     */
    RotationSink *GetSink() {return &mRotationSink;}
    /**
     * Get the positionsource of the arm
     * @return mPositionSource
     */
    PositionSource *GetPositionSource() {return &mPositionSource;}
    /**
     * Set the rotation of the machine
     * @param rotation rotation to set to
     */
    virtual void SetRotation(double rotation) override;
    /**
     * Arm constructor
     * @param length  length of the arm
     */
    Arm(double length);
    /// Copy constructor (disabled)
    Arm(const Arm &) = delete;

    /// Assignment operator
    void operator=(const Arm &) = delete;



};

#endif //CANADIANEXPERIENCE_ARM_H
