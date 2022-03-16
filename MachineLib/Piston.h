/**
 * @file Piston.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PISTON_H
#define CANADIANEXPERIENCE_PISTON_H
#include "Component.h"
#include "INegotiator.h"
#include "RodSink.h"
class Rod;
/**
 * Piston component for the machine
 */
class Piston : public Component, public INegotiator{
private:
    ///Rodsink
    RodSink mRodSink;

public:
    /**
     * Piston Consructor
     */
    Piston();
    /**
     * Get the rodsink
     * @return mRodSink
     */
    RodSink *GetRodSink() {return &mRodSink;}

    /**
     * Negotiate from the lever to the rod to the piston
     * @param rod rod which is negotiating piston
     */
    void Negotiate(Rod *rod);

    /// Copy constructor (disabled)
    Piston(const Piston &) = delete;

    /// Assignment operator
    void operator=(const Piston &) = delete;



};

#endif //CANADIANEXPERIENCE_PISTON_H
