/**
 * @file RotationSink.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSINK_H
#define CANADIANEXPERIENCE_ROTATIONSINK_H
#include "Sink.h"
/**
 * Tells a Component to rotate when a Rotation source points to it
 */
class RotationSink : public Sink {
private:
    ///Speed
    double mSpeed = 1;
    ///Phase
    double mPhase = 0;
    ///Rotation
    double mRotation;

public:
    /**
     * Rotate this RotationSink
     * @param rotation
     */
    void Rotate(double rotation);
    /**
     * Set the speed of this RotationSink
     * @param speed
     */
    void SetSpeed(double speed){mSpeed = speed;}
    /**
     * Set the Phase of this RotationSink
     * @param phase
     */
    void SetPhase(double phase){mPhase = phase;}


    /**
     * RotationSink Constructor
     */
    RotationSink();
    
    

};

#endif //CANADIANEXPERIENCE_ROTATIONSINK_H
