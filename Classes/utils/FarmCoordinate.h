#ifndef __FARM_COORDINATE_H__
#define __FARM_COORDINATE_H__

#include "game.h"

class FarmCoordinate 
{
public:
	static FarmCell* getCellAt(int i, int j, int w=1, int h=1);
	static cocos2d::Point translateFarmCellPosToLayerPos(float x, float y, float z=0);
};

#endif // __FARM_COORDINATE_H__
