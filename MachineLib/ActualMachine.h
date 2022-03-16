/**
 * @file ActualMachine.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ACTUALMACHINE_H
#define CANADIANEXPERIENCE_ACTUALMACHINE_H

class ModifiedMachine;
class Component;
/**
 * Class that resulted from solving the parable of the tree.
 */
class ActualMachine{
private:

    /// The ModifiedMachine this actual machine is associated with
    std::shared_ptr<ModifiedMachine> mMachine = nullptr;

    /// The images directory
    std::wstring mImagesDir;

    ///components vector
    std::vector<std::shared_ptr<Component>> mComponents;

public:
/**
 * Draw the machine on the frame
 * @param graphics graphics pointer
 * @param x x coordinate
 * @param y y coordinate
 */
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);
    /**
     * Add a component to the machine
     * @param component component to add
     */
    void AddComponent(std::shared_ptr<Component> component);
    /**
     * Set the time of the machine
     * @param time
     */
    virtual void SetTime(double time);
    /**
     * Constructor for our machine
     * @param mach machine number
     */
    ActualMachine(int mach);

    /// Copy constructor (disabled)
    ActualMachine(const ActualMachine &) = delete;

    /// Assignment operator
    void operator=(const ActualMachine &) = delete;




};

#endif //CANADIANEXPERIENCE_ACTUALMACHINE_H
