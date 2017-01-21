#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "poScene/Scene.h"
#include "ViewController.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace po::scene;

class MicroscopeApp : public App {
  public:
	void setup() override;
	void update() override;
	void draw() override;
    
    SceneRef mScene;
    microscope::ViewControllerRef mViewController;
};

void MicroscopeApp::setup()
{
    setWindowSize(1280,720);
    mViewController = microscope::ViewController::create();
    mScene = Scene::create(mViewController);
}


void MicroscopeApp::update()
{
    mScene->update();
}

void MicroscopeApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    mScene->draw();
}

CINDER_APP( MicroscopeApp, RendererGl )
