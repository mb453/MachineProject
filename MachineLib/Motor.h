/**
 * @file Motor.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H
#include "pch.h"
#include "Component.h"
#include "Polygon.h"
#include "RotationSource.h"
/**
 * Motor Component for the machine
 */
class Motor : public Component {
private:
    ///Polygon pointer
    std::shared_ptr<Polygon> mPoly;

    /// The images directory
    std::wstring mImagesDir;
    ///The position of the machine
    wxPoint mPosition;
    ///The speed of the machine
    double mSpeed = 1.0;
    ///The rotation of the machine
    double mRotation;

    /// Rotation source for this component
    RotationSource mSource;

public:

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    RotationSource *GetSource() { return &mSource; }
    /**
     * Draw the component for this motor
     * @param graphics
     * @param x
     * @param y
     */
    virtual void DrawComponent(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;
    /**
     * Set the time for this motor
     * @param time
     */
    virtual void SetTime(double time) override;
    /**
     * Motor constructor
     * @param mImagesDir
     */
    Motor(std::wstring mImagesDir);

    //void SetPosition(int x, int y);
    /**
     * Set speed of this motor
     * @param speed
     */
    void SetSpeed(double speed);
    /**
     * Set rotation of this motor
     * @param rotation
     */
    void SetRotation(double rotation);

    /// Copy constructor (disabled)
    Motor(const Motor &) = delete;

    /// Assignment operator
    void operator=(const Motor &) = delete;



};

#endif //CANADIANEXPERIENCE_MOTOR_H
