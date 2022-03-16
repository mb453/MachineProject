/**
 * @file Gear.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_GEAR_H
#define CANADIANEXPERIENCE_GEAR_H
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"
/**
 * Gear spins from the motor.
 */
class Gear : public Component{
private:
    ///Rotationsink for the gear
    RotationSink mRotationSink;

    /// Rotation source for this component
    RotationSource mSource;
    ///Radius of the gear
    int mRadius;
    ///Number of teeth
    int mNumTeeth;

public:
    /**
     * Draw this component
     * @param graphics graphics pointer
     * @param x x coord
     * @param y y coord
     */
    virtual void DrawComponent(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;
    /**
     * Get the rotation sink for the gear
     * @return mRotationSink
     */
    RotationSink *GetSink() {return &mRotationSink;}

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    RotationSource *GetSource() { return &mSource; }
    /**
     * Drive another gear
     * @param gear gear to drive
     * @param phase how fast it will spin
     */
    void Drive(std::shared_ptr<Gear> gear, double phase);
    /**
     * Set rotation of the gear
     * @param rotation rotation to set to
     */
    virtual void SetRotation(double rotation) override;
    /**
     * Constructor for a gear
     * @param radius
     * @param numTeeth
     */
    Gear(int radius, int numTeeth);
    /// Copy constructor (disabled)
    Gear(const Gear &) = delete;

    /// Assignment operator
    void operator=(const Gear &) = delete;


};

#endif //CANADIANEXPERIENCE_GEAR_H
