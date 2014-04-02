#ifndef __FARM_COORDINATE_H__
#define __FARM_COORDINATE_H__

#include "cocos2d.h"

struct FarmCell {
	int cellX;
	int cellY;
	int width;
	int height;
	// left point of rhombus
	cocos2d::Point left;
	// right point of rhombus
	cocos2d::Point right;
	// top point of rhombus
	cocos2d::Point top;
	// right point of rhombus
	cocos2d::Point bottom;
};

class FarmCoordinate 
{
public:
	static float FARM_GRID_WIDTH;
	static float FARM_GRID_HEIGHT;
	static float FARM_GRID_SIZE;
	static FarmCell* getCellAt(int i, int j, int w=1, int h=1);
	static cocos2d::Point translateFromFarmPoint(float x, float y, float z=0);
};

#endif // __FARM_COORDINATE_H__
