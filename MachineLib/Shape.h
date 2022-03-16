/**
 * @file Shape.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H
#include "Component.h"
#include "RotationSink.h"
/**
 * Class that will allow sinks  to talk to component
 */
class Shape : public Component{
private:
    ///RotationSink
    RotationSink mRotationSink;

public:
    /**
     * Sink Constructor
     */
    Shape();
    
    /// Copy constructor (disabled)
    Shape(const Shape &) = delete;
    
    /// Assignment operator
    void operator=(const Shape &) = delete;
    /**
     * Get the RotationSink
     * @return mRotationSink
     */
    RotationSink *GetSink() {return &mRotationSink;}
    
    




};

#endif //CANADIANEXPERIENCE_SHAPE_H
