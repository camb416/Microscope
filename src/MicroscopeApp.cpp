#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MicroscopeApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void MicroscopeApp::setup()
{
}

void MicroscopeApp::mouseDown( MouseEvent event )
{
}

void MicroscopeApp::update()
{
}

void MicroscopeApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( MicroscopeApp, RendererGl )
