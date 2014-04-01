#include "FarmLayer.h"
#include "utils\FarmCoordinate.h"

USING_NS_CC;

Point TouchPoint::getPoint() {
	return this->m_point;
}

void TouchPoint::setPoint(Point &p) {
	this->m_point = p;
}

TouchPoint* TouchPoint::initWithPoint(Point &p) {
	auto ret = new TouchPoint();
	ret->setPoint(p);
	ret->autorelease();
	return ret;
}

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
	//m_floor->setPosition(Point(m_floor->getContentSize().width /2 , m_floor->getContentSize().height/2));
	m_floor->setPosition(Point(0,0));

    // add the sprite as a child to this layer
    this->addChild(m_floor, -1);

	m_floorStartPoint = Point(-m_floor->getContentSize().width /2 , -m_floor->getContentSize().height/2);

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
    //auto listener = EventListenerTouchOneByOne::create();
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(FarmLayer::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(FarmLayer::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(FarmLayer::onTouchesEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void FarmLayer::onExit()
{
    //Sprite::onExit();
	Layer::onExit();
} 

static Map<int,TouchPoint*> s_map;

void FarmLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
	for(auto &item : touches) {
		s_map.insert(item->getID(),  TouchPoint::initWithPoint(item->getLocation()));
	}
}

void FarmLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
	auto &item = touches[0];
	auto lastpt = s_map.at(item->getID());
	auto dx = item->getLocation().x - lastpt->getPoint().x;
	auto dy = item->getLocation().y - lastpt->getPoint().y;
	lastpt->setPoint(item->getLocation());
	auto cur = getPosition();
	setPosition(Point(cur.x + dx,cur.y+dy));
	//CCLOG("dx=%f,dy=%f", dx, dy);
}

void FarmLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event  *event)
{
	for(auto &item : touches) {
		s_map.erase(item->getID());
	}
	//设置一下锚点
	auto ccsize = m_floor->getContentSize();
	CCLOG("size,width=%f,height=%f", ccsize.width, ccsize.height);
	auto xsize = Size(ccsize.width*getScale(), ccsize.height*getScale());
	CCLOG("Fix size ,width = %f,height=%f", xsize.width, xsize.height);
	auto pt = getPosition();
	CCLOG("pt,x=%f,y=%f", pt.x, pt.y);
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