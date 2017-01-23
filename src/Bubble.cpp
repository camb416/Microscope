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
#include "poScene/ImageView.h"

using namespace po::scene;

BubbleRef Bubble::create(std::string name, ci::Color color, float radius){
    BubbleRef ref (new Bubble());
    ref->setup(name,color,radius);
    return ref;
}

void Bubble::setup(std::string name, ci::Color color, float radius=100.0f){
    
    
    // load an image and put it in a texture
    mTex = ci::gl::Texture::create(ci::loadImage(ci::app::loadAsset("cat.jpg")));
    mTex->setWrap(GL_CLAMP_TO_BORDER, GL_CLAMP_TO_BORDER);
    
    mRadius = radius;
   //  ci::app::console() << "Bubble::setup";
    // create shape
    mBaseShape = ShapeView::createRect(100,100);
    mCircleShape = ShapeView::createCircle(radius);
    mBaseColor = color;
    
    mBaseShape->setStrokeEnabled(true);
    mBaseShape->setStrokeColor(color);
    mBaseShape->setFillEnabled(false);
    mCircleShape->setFillColor(ci::Color(1,1,1));

    
    // learn texturemanager!
     mCircleShape->setTexture(mTex,po::scene::TextureFit::Type::INSIDE,po::scene::Alignment::CENTER_CENTER);
    addSubview(mCircleShape);
    addSubview(mBaseShape);
    
    
    // create label
    // nah
    
    // add signal to all mouse clicks
    getSignal(MouseEvent::DOWN_INSIDE).connect(std::bind(&Bubble::showIndicator, this));
    
}

void Bubble::showIndicator(){
    cinder::app::console() << "showIndicator";
}

