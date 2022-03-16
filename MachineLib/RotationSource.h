/**
 * @file RotationSource.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONSOURCE_H
#include "Source.h"
/**
 * Class for the source of a rotation, which will talk to all the sinks
 */
class RotationSource : public Source {
private:

public:

RotationSource(){};
/// Copy constructor (disabled)
RotationSource(const RotationSource &) = delete;

/// Assignment operator
void operator=(const RotationSource &) = delete;



};

#endif //CANADIANEXPERIENCE_ROTATIONSOURCE_H
