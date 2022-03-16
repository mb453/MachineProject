/**
 * @file Source.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SOURCE_H
#define CANADIANEXPERIENCE_SOURCE_H
class RotationSink;
/**
 * Base class that handles source functions
 */
class Source {
private:
    ///Vector of RotationSinks
    std::vector<RotationSink *> mSinks;

public:

    Source(){};

    /// Copy constructor (disabled)
    Source(const Source &) = delete;

    /// Assignment operator
    void operator=(const Source &) = delete;


    /**
     * Add a RotationSink to the Vector
     * @param sink
     */
    void AddSink(RotationSink * sink){mSinks.push_back(sink);}
    /**
     * Set the rotation of this Source
     * @param rotation
     */
    void SetRotation(double rotation);

};

#endif //CANADIANEXPERIENCE_SOURCE_H
