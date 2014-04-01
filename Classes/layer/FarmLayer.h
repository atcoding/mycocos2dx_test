#ifndef __FARM_LAYER_H__
#define __FARM_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class TouchPoint : public cocos2d::Ref
{
public:
	Point getPoint();
	void setPoint(Point &p);
	static TouchPoint* initWithPoint(Point &p);
private:
	Point m_point;
};

class FarmLayer : public cocos2d::Layer
//class FarmLayer : public cocos2d::Sprite
{
public:
	static FarmLayer* getInstance();
    FarmLayer();
	~FarmLayer();
	void scaleOut();
	void scaleIn();
	virtual void onEnter() override;
    virtual void onExit() override;
    void onTouchesBegan(const std::vector<Touch*>& touches, cocos2d::Event  *event);
    void onTouchesMoved(const std::vector<Touch*>& touches, cocos2d::Event  *event);
    void onTouchesEnded(const std::vector<Touch*>& touches, cocos2d::Event  *event);
private:
	virtual bool init();
	Sprite* m_floor;
	Point m_floorStartPoint;
	//draw test
	virtual void draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated) override;
	void onDraw(const kmMat4 &transform, bool transformUpdated);
    CustomCommand _customCommand;
};

#endif // __FARM_LAYER_H__
