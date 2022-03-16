/**
 * @file PositionSink.h
 * @author matt5
 *
 *
 */

#ifndef CANADIANEXPERIENCE_POSITIONSINK_H
#define CANADIANEXPERIENCE_POSITIONSINK_H
#include "Component.h"
class PositionSource;
/**
 * Takes the position source to move the component its assciated with
 */
class PositionSink {
private:
    ///Position source pointer
    std::shared_ptr<PositionSource> mSource = nullptr;
    ///Component Pointer
    Component* mComponent = nullptr;

public:
    /**
     * Set the component for this Positin sink
     * @param component component to set to
     */
    void SetComponent(Component* component){mComponent = component;}
    /**
     * Get the component
     * @return mComponent
     */
    Component* GetComponent(){return mComponent;}
    /**
     * Set the position of this position sink
     * @param point
     */
    void SetPosition(wxPoint point);
    /**
     * PositionSink Constructor
     */
    PositionSink();
    /// Copy constructor (disabled)
    PositionSink(const PositionSink &) = delete;

    /// Assignment operator
    void operator=(const PositionSink &) = delete;



};

#endif //CANADIANEXPERIENCE_POSITIONSINK_H
