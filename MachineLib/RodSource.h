/**
 * @file RodSource.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_RODSOURCE_H
#define CANADIANEXPERIENCE_RODSOURCE_H

#include "RodSink.h"
class Rod;
/**
 *Gives a RodSink a movement order
 */
class RodSource {
private:
    ///Vector of RodSinks
    std::vector<RodSink *> mRodSinks;

public:
    /**
     * Add a sink to Rodsink vector
     * @param sink
     */
    void AddSink(RodSink * sink){mRodSinks.push_back(sink);}
    /**
     * Negotiate each of the sinks
     * @param rod
     */
    void Negotiate(Rod *rod);
    /**
     * RodSourceConstructor
     */
    RodSource();

    /// Copy constructor (disabled)
    RodSource(const RodSource &) = delete;

    /// Assignment operator
    void operator=(const RodSource &) = delete;



};

#endif //CANADIANEXPERIENCE_RODSOURCE_H
