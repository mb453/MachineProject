/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"
using namespace std;

/**
 * Factory method to create a new picture.
 * @param imagesDir Directory that contains the images for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Picture> picture = make_shared<Picture>();


    // Create the background and add it
    auto background = make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 500));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 520));
    picture->AddActor(sparty);

    auto test = make_shared<Actor>(L"test");

    auto background2 =
            make_shared<MachineDrawable>(L"test", imagesDir);
    test->AddDrawable(background2);


    auto testTwo = make_shared<Actor>(L"testTwo");

    auto backgroundThree =
            make_shared<MachineDrawable>(L"testTwo", imagesDir);
    testTwo->AddDrawable(backgroundThree);

    picture->AddActor(test);

    picture->AddActor(testTwo);
    picture->AddMachineDrawable(background2);
    backgroundThree->SetMachNum(2);
    picture->AddMachineDrawable(backgroundThree);

    return picture;
}

