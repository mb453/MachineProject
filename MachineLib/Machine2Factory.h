/**
 * @file Machine2Factory.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINE2FACTORY_H
#define CANADIANEXPERIENCE_MACHINE2FACTORY_H
class ActualMachine;
/**
 * Setup a Spartan Machine factory
 */
class Machine2Factory {

private:
/// The images directory
    std::wstring mImagesDir;

public:
    /**
     * Machine2Factory Constructor
     * @param imagesDir
     */
    Machine2Factory(std::wstring imagesDir);
    /**
    * Create an Actual Machine
    * @return pointer to actual machine
    */
    std::shared_ptr<ActualMachine> CreateMachine();
    
    
    /// Default constructor (disabled)
    Machine2Factory() = delete;
    
    /// Copy constructor (disabled)
    Machine2Factory(const Machine2Factory &) = delete;
    
    /// Assignment operator
    void operator=(const Machine2Factory &) = delete;
    
    

};

#endif //CANADIANEXPERIENCE_MACHINE2FACTORY_H
