//
//  Bubble.cpp
//  Microscope
//
//  Created by Cameron Browning on 1/22/17.
//
//


#include "Bubble.hpp"

#include "cinder/app/App.h"
#include "poScene/ShapeView.h"

using namespace po::scene;

BubbleRef Bubble::create(std::string name, ci::Color color, float radius){
    BubbleRef ref (new Bubble());
    ref->setup(name,color,radius);
    return ref;
}

void Bubble::setup(std::string name, ci::Color color, float radius=100.0f){
    mRadius = radius;
    ci::app::console() << "Bubble::setup";
    // create shape
    //mBaseShape = ShapeView::createRect(100,100);
    mBaseShape = ShapeView::createCircle(mRadius);
    mBaseColor = color;
    mBaseShape->setFillColor(color);
    addSubview(mBaseShape);
    
    // create label
    // nah
    
    // add signal to all mouse clicks
    getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Bubble::showIndicator, this));
    
}

void Bubble::showIndicator(){
    cinder::app::console() << "showIndicator";
}

