/**
 * @file Component.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H
#include "Polygon.h"
class ActualMachine;

class Motor;
/**
 * Component will be a base class for all the machine appendages.
 */
class Component : public Polygon{
private:
    ///Position of component
    wxPoint mPosition;
    ///Time of Component
    double mTime;
    ///ActualMachine of Component
    ActualMachine* mActualMachine = nullptr;
    ///Speed of component
    double mSpeed = 1.0;
    ///Rotation of component
    double mRotation;
    ///Vector of motors in this machine
    std::vector<std::shared_ptr<Motor>> mMotors;

public:
    /**
     * Draw component on the screen
     * @param graphics graphic pointer
     * @param x xcoordinate
     * @param y ycoordinate
     */
   virtual void DrawComponent(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);
    /**
     * Set the actual pointer to this machine
     * @param machine actual pointer to machine
     */
   void SetActualMachine(ActualMachine* machine){mActualMachine = machine; }
    /**
     * Get the position of this component
     * @return mPosition
     */
   wxPoint GetPosition(){return mPosition;}
    /**
     * Change the position of this component
     * @param point point to change component to
     */
   virtual void SetPosition(wxPoint point){mPosition = point;}

   //void SetSource(Component component);

   //void AddSink(Component component);
   /**
    * Set the time of the machine
    * @param time time to set machine
    */
   virtual void SetTime(double time);

   Component(){};

   /// Copy constructor (disabled)
   Component(const Component &) = delete;

   /// Assignment operator
   void operator=(const Component &) = delete;


};

#endif //CANADIANEXPERIENCE_COMPONENT_H
