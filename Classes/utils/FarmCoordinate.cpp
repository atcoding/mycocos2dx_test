#include "FarmCoordinate.h"
#include "cocos2d.h"

USING_NS_CC;

float FarmCoordinate::FARM_GRID_SIZE = 40;

FarmCell* FarmCoordinate::getCellAt(int i, int j, int w, int h){

	auto lx = i * FARM_GRID_SIZE;
	auto rx = (i+w) * FARM_GRID_SIZE;
	auto ty = (j+h) * FARM_GRID_SIZE;
	auto by = j * FARM_GRID_SIZE;

	auto ret = new FarmCell();
	ret->cellX = i;
	ret->cellY = j;
	ret->width = w;
	ret->height = h;
	
	ret->left = FarmCoordinate::translateFromFarmPoint(lx, ty);
	ret->top = FarmCoordinate::translateFromFarmPoint(rx,ty);
	ret->right = FarmCoordinate::translateFromFarmPoint(rx, by);
	ret->bottom = FarmCoordinate::translateFromFarmPoint(lx, by);

	return ret;
}

Point FarmCoordinate::translateFromFarmPoint(float x, float y) {

	return Point(x,y);
}