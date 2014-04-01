#ifndef __FARM_LAYER_H__
#define __FARM_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class FarmLayer : public cocos2d::Layer
{
public:
	static FarmLayer* getInstance();
    FarmLayer();
	~FarmLayer();
	void scaleOut();
	void scaleIn();
	virtual void onEnter() override;
    virtual void onExit() override;
	bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
private:
	virtual bool init();
	cocos2d::Sprite* m_floor;
	//draw test
	virtual void draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated) override;
	void onDraw(const kmMat4 &transform, bool transformUpdated);
    CustomCommand _customCommand;
};

#endif // __FARM_LAYER_H__
