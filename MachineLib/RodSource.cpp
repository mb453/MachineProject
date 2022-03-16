/**
 * @file RodSource.cpp
 * @author Matthew Baxter
 */
#include "pch.h"
#include "RodSource.h"
#include "Rod.h"

void RodSource::Negotiate(Rod* rod)
{

    for (auto sink : mRodSinks )
    {

        sink->Negotiate(rod);
    }

}

RodSource::RodSource()
{

}
