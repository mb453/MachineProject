/**
 * @file RodSink.h
 * @author matt5
 *
 *
 */

#ifndef CANADIANEXPERIENCE_RODSINK_H
#define CANADIANEXPERIENCE_RODSINK_H
#include "INegotiator.h"
#include "Component.h"
#include "Sink.h"
/**
 * Takes a rod to move a component touching th rod
 */
class RodSink : public Sink{
private:
    ///Component
    Component* mComponent = nullptr;
    ///INegotiator to talk to the lever
    INegotiator* mNegotiator = nullptr;

public:

    RodSink(Component* component, INegotiator* mNegotiator);
    /**
     * Negotiate this rod and rodsink
     * @param rod
     */
    void Negotiate(Rod *rod);
    /// Copy constructor (disabled)
    RodSink(const RodSink &) = delete;

/// Assignment operator
    void operator=(const RodSink &) = delete;



};

#endif //CANADIANEXPERIENCE_RODSINK_H
