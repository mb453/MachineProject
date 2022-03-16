/**
 * @file PositionSource.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_POSITIONSOURCE_H
#define CANADIANEXPERIENCE_POSITIONSOURCE_H
#include "Component.h"
/**
 * Moves the position of the component its associated with
 */
class PositionSource {
private:
    ///Location of the position source
    wxPoint mPosition;
    ///Vector of components
    std::vector <std::shared_ptr<Component>> mComponents;


public:
    /**
     * Set the position of this PositiionSource
     * @param point
     */
    void SetPosition(wxPoint point);
    /**
     * Add a component to the vector
     * @param comp component to add
     */
    void AddComponent(std::shared_ptr<Component> comp){mComponents.push_back(comp);}
    /**
     * Get the position of this PositionSource
     * @return mPosition
     */
    wxPoint GetPosition(){return mPosition;}
    /**
     * PositionSource Constructor
     */
    PositionSource();

    /// Copy constructor (disabled)
    PositionSource(const PositionSource &) = delete;

    /// Assignment operator
    void operator=(const PositionSource &) = delete;



};

#endif //CANADIANEXPERIENCE_POSITIONSOURCE_H
