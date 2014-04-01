#include "FarmLayer.h"
#include "utils\FarmCoordinate.h"
#include "VisibleRect.h"

USING_NS_CC;

static FarmLayer *s_SharedFarmyLayer = nullptr;

FarmLayer* FarmLayer::getInstance() 
{
	if (!s_SharedFarmyLayer) {
		s_SharedFarmyLayer = new FarmLayer();
		s_SharedFarmyLayer->init();
		s_SharedFarmyLayer->autorelease();
	}

	return s_SharedFarmyLayer;
}

FarmLayer::FarmLayer()
{
	
}

FarmLayer::~FarmLayer() {

}

bool FarmLayer::init(void) {
	// add "HelloWorld" splash screen"
	m_floor = Sprite::create("res/farm_bg.jpg");

    // position the sprite on the center of the screen
	m_floor->setPosition(Point(m_floor->getContentSize().width /2 , m_floor->getContentSize().height/2));

    // add the sprite as a child to this layer
    this->addChild(m_floor, -1);

	return true;
}

void FarmLayer::scaleIn(void){
	float scale = this->getScale();
	scale += 0.2f;
	scale = scale>1 ? 1 : scale;
	this->setScale(scale);
}

void FarmLayer::scaleOut(void){
	float scale = this->getScale();
	scale -= 0.2f;
	scale = scale<0.2 ? 0.2 : scale;
	this->setScale(scale);
}

void FarmLayer::onEnter()
{
    //Sprite::onEnter();
	Layer::onEnter();
    
    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(FarmLayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(FarmLayer::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(FarmLayer::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void FarmLayer::onExit()
{
    //Sprite::onExit();
	Layer::onExit();
} 

bool FarmLayer::onTouchBegan(Touch* touch, Event* event)
{
    return true;
}

void FarmLayer::onTouchMoved(Touch* touch, Event* event)
{
    CCLOG("Paddle::onTouchMoved id = %d, x = %f, y = %f", touch->getID(), touch->getLocation().x, touch->getLocation().y);
    
    auto touchPoint = touch->getLocation();
    
    setPosition( Point(touchPoint.x, getPosition().y) );
}

void FarmLayer::onTouchEnded(Touch* touch, Event* event)
{
} 


void FarmLayer::draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated)
{
    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(FarmLayer::onDraw, this, transform, transformUpdated);
    renderer->addCommand(&_customCommand);
}

void FarmLayer::onDraw(const kmMat4 &transform, bool transformUpdated)
{
    kmGLPushMatrix();
    kmGLLoadMatrix(&transform);
    

    CHECK_GL_ERROR_DEBUG();

    // line: color, width, aliased
    // glLineWidth > 1 and GL_LINE_SMOOTH are not compatible
    // GL_SMOOTH_LINE_WIDTH_RANGE = (1,1) on iPhone
    //  glDisable(GL_LINE_SMOOTH);
    glLineWidth( 0.9f );
    DrawPrimitives::setDrawColor4B(255,0,0,255);

	auto fc = FarmCoordinate::getCellAt(0,0,10,10);
	DrawPrimitives::drawLine(fc->left, fc->top);
	 DrawPrimitives::setDrawColor4B(0,255,255,255);
	DrawPrimitives::drawLine(fc->top, fc->right);
	DrawPrimitives::drawLine(fc->right, fc->bottom);
	DrawPrimitives::drawLine(fc->bottom, fc->left);
	//CCLOG("%f,%f,%f,%f", fc->left.x, fc->left.y, fc->top.x, fc->top.y);
	//DrawPrimitives::drawLine( VisibleRect::leftTop(), VisibleRect::rightBottom() );
    
    CHECK_GL_ERROR_DEBUG();

	    
    //end draw
    kmGLPopMatrix();
}