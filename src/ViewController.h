//
//  ViewController.hpp
//  Microscope
//
//  Created by Cameron Browning on 1/20/17.
//
//

#ifndef ViewController_hpp
#define ViewController_hpp

#include "poScene/ViewController.h"
#include "poScene/ShapeView.h"
#include "poScene/ImageView.h"

#include <stdio.h>

namespace microscope {
    class ViewController;
    typedef std::shared_ptr<ViewController> ViewControllerRef; //create a reference
    
    class ViewController : public po::scene::ViewController {
    public:
      static ViewControllerRef create();
      void setup();
    protected:
        ViewController();
    private:
        // An Image
        po::scene::ImageViewRef mImage;
        
        // Mask shape
        po::scene::ShapeViewRef mMask;
        
        // Mouse Event Handlers
        void onMouseMove(po::scene::MouseEvent &evt);
        
    };
}


#endif /* ViewController_hpp */
