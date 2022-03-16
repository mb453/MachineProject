/**
 * @file Rod.h
 * @author Matthew Baxter
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ROD_H
#define CANADIANEXPERIENCE_ROD_H
#include "Component.h"
#include "RotationSink.h"
#include "PositionSink.h"
#include "PositionSource.h"
#include "RodSink.h"
#include "RodSource.h"
/**
 * Rod component for the machine.
 */
class Rod : public Component{
private:
    ///Length of the rod
    double mLength;
    ///RotationSource
    RotationSink mRotationSource;
    ///Rodsink
    RodSink* mRodSink = nullptr;
    ///RodSource
    RodSource mRodSource;
    ///PositionSink
    PositionSink mPositionSink;

    /// Rotation source for this component
    PositionSource mPositionSource;

public:
    /**
     * Draw this Rod
     * @param graphics
     * @param x
     * @param y
     */
    virtual void DrawComponent(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    //RotationSink *GetSink() {return &mRotationSink;}
    /**
     * Set the RodSink
     * @param rod rod to set the sink
     */
    void SetRodSink(RodSink* rod){mRodSink = rod; mRodSource.AddSink(mRodSink);}
    /**
     * Get the length of this rod
     * @return mLength
     */
    double GetLength(){return mLength;}

    //void SetRodSource(RodSource* rod){mRodSource = rod;}
    /**
     * Get this RodSource
     * @return
     */
    RodSource* GetSource() {return &mRodSource;}

    /**
     * Set the position of this rod
     * @param point new point to set position to
     */
    virtual void SetPosition(wxPoint point) override;
    /**
     * Constructor for rod
     * @param length rodlength
     * @param width rodwidth
     */
    Rod(double length, double width);
    
    /// Copy constructor (disabled)
    Rod(const Rod &) = delete;
    
    /// Assignment operator
    void operator=(const Rod &) = delete;
    
    

};

#endif //CANADIANEXPERIENCE_ROD_H
