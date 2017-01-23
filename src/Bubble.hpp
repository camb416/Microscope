//
//  Bubble.hpp
//  Microscope
//
//  Created by Cameron Browning on 1/22/17.
//
//

#ifndef Bubble_hpp
#define Bubble_hpp

#include "poScene/View.h"
#include "poScene/ShapeView.h"

#include <stdio.h>

class Bubble;
typedef std::shared_ptr<Bubble> BubbleRef;

class Bubble : public po::scene::View{
public:
    static BubbleRef create(std::string name, ci::Color color,float radius);
    void setup(std::string, ci::Color color, float radius);
    
protected:
    // nothing is protected
private:
    po::scene::ViewRef mBaseShape;
    ci::vec2 mBasePosition;
    ci::Color mBaseColor;
    
    void showIndicator();
    float mRadius;
    
};

#endif /* Bubble_hpp */
