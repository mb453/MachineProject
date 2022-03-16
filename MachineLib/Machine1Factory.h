/**
 * @file Machine1Factory.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINE1FACTORY_H
#define CANADIANEXPERIENCE_MACHINE1FACTORY_H
#include "pch.h"
class ActualMachine;
/**
 * Setup a factory for Harolds machine
 */
class Machine1Factory {
private:

/// The images directory
    std::wstring mImagesDir;

public:
    /**
     * Constructor for Machine1Factory
     * @param imagesDir directory to grab images from
     */
    Machine1Factory(std::wstring imagesDir);
    /**
     * Create an Actual Machine
     * @return pointer to actual machine
     */
    std::shared_ptr<ActualMachine> CreateMachine();

    /// Default constructor (disabled)
    Machine1Factory() = delete;
    
    /// Copy constructor (disabled)
    Machine1Factory(const Machine1Factory &) = delete;
    
    /// Assignment operator
    void operator=(const Machine1Factory &) = delete;
    
    


};

#endif //CANADIANEXPERIENCE_MACHINE1FACTORY_H
