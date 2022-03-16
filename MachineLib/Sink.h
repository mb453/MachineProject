/**
 * @file Sink.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SINK_H
#define CANADIANEXPERIENCE_SINK_H
class Source;
#include "Component.h"
/**
 * Base class that deals with sinks
 */
class Sink {
private:
    ///Source pointer
    std::shared_ptr<Source> mSource = nullptr;
    ///Component Pointer
    Component* mComponent = nullptr;
public:


    /**
     * Set the component
     * @param component
     */
    void SetComponent(Component* component){mComponent = component;}
    /**
     * Get the component
     * @return mComponent
     */
    Component* GetComponent(){return mComponent;}
    /**
     * Sink Constructor
     */
    Sink();

    /// Copy constructor (disabled)
    Sink(const Sink &) = delete;

    /// Assignment operator
    void operator=(const Sink &) = delete;



};

#endif //CANADIANEXPERIENCE_SINK_H
