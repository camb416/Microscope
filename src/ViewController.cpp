//
//  ViewController.cpp
//  Microscope
//
//  Created by Cameron Browning on 1/20/17.
//
//

#include "ViewController.h"

#include "cinder/app/App.h"
#include "cinder/ImageIo.h"
#include "cinder/Rand.h"

using namespace po::scene;

namespace microscope {
    
    ViewControllerRef ViewController::create(){
        
        ViewControllerRef node(new ViewController());
        node->setup();
        return node;
        
    }
    
    ViewController::ViewController(){
            // empty constructor
    }
    
    void ViewController::setup(){
        // do things!
//        
//        //	Load the mask texture
//        ci::gl::TextureRef maskTexture = ci::gl::Texture::create(ci::loadImage(ci::app::loadAsset("circle_mask_blurred.png")));
//        
//        //	Create the mask shape
//        //mMask = Shape::create(maskTexture);
//        mMask = ShapeView::createRect(100, 100);
//        mMask->setAlignment(Alignment::CENTER_CENTER);
//        mMask->setPosition(ci::app::getWindowWidth() / 2, ci::app::getWindowHeight() / 2);
//        ci::app::timeline().apply(&mMask->getRotationAnim(), 0.0f, ci::toRadians(360.0f), 1.0f).loop();
//        ci::app::timeline().apply(&mMask->getScaleAnim(), ci::vec2(1.0f, 1.0f), ci::vec2(4.0f, 4.0f), 1.0f).loop().pingPong();
//        
//        //	Load the image texture
//        ci::gl::TextureRef texture = ci::gl::Texture::create(ci::loadImage(ci::app::loadAsset("cat.jpg")));
//        
//        //	Create the image shape
//        mImage = ImageView::create(texture);
//        getView()->addSubview(mImage);
//        
//        //	Set the image mask
//        getView()->setMask(mMask);
//        
//        // CB - test masking with alpha
//        //setAlpha(0.5f);
//        //mMask->setAlpha(0.5f);
//        
//        //	Connect mouse event
//        getView()->getSignal(MouseEvent::MOVE).connect(std::bind(&ViewController::onMouseMove, this, std::placeholders::_1));
        
        ci::app::console() << "ViewController::setup";
        //b = Bubble::create("My Bubble", ci::Color(255.f / 255, 147.f / 255, 30.f / 255), 100.0f);
      //  b->setPosition(ci::vec2(100,100));
      //  getView()->addSubview(b);
        
        for(int i=0;i<64;i++){
            BubbleRef thisBubble = Bubble::create("A Bubble", ci::Color(1,0,0), ci::randFloat(100.0f) );
            thisBubble->setPosition(ci::vec2(ci::randFloat(ci::app::getWindowWidth()), ci::randFloat(ci::app::getWindowHeight())));
            getView()->addSubview(thisBubble);
            bubbles.push_back(thisBubble);
            
        }
    
    }
    
    void ViewController::onMouseMove(po::scene::MouseEvent &evt){
        ci::app::console() << "ViewController::onMouseMove";
        ci::vec2 maskPos = evt.getWindowPos();
        mMask->setPosition(maskPos);
        
        
    }
    
    
}
