/**
 * @file RodSink.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "RodSink.h"

/**
 * Constructor
 * @param component Component we are connected to.
 * @param mNegotiator The negotiator we will negotiate with
 */
RodSink::RodSink(Component* component, INegotiator *mNegotiator) : mNegotiator(mNegotiator), mComponent(component)
{

}

void RodSink::Negotiate(Rod* rod)
{
    mNegotiator->Negotiate(rod);

}
