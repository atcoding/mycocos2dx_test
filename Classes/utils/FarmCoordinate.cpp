#include "FarmCoordinate.h"
#include "cocos2d.h"
#include "layer\FarmLayer.h"
#include <math.h>

USING_NS_CC;

Point FarmCoordinate::FARM_START_POINT = Point(-2187.5f,0);
int FarmCoordinate::FARM_GRID_START_CELL_X = 10;
int FarmCoordinate::FARM_GRID_START_CELL_Y = 10;
int FarmCoordinate::FARM_GRID_WIDTH = 80;
int FarmCoordinate::FARM_GRID_HEIGHT = 80;
float FarmCoordinate::FARM_GRID_DIAGONAL = 43.75;
float FarmCoordinate::FARM_GRID_DIAGONAL_2 = 21.875;
double FarmCoordinate::FARM_Y_PERSPECTIVE_FACTOR = 0.75470958022277199794298421956102;

FarmCell* FarmCoordinate::getCellAt(int i, int j, int w, int h){

	auto lx = i;
	auto rx = (i+w) ;
	auto ty = (j+h)  ;
	auto by = j ;

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


Point FarmCoordinate::translateFromFarmPoint(float x, float y, float z) {
	auto xx = (x+y)*FarmCoordinate::FARM_GRID_DIAGONAL_2;
	auto yy = (y-x)*FarmCoordinate::FARM_GRID_DIAGONAL_2 * FarmCoordinate::FARM_Y_PERSPECTIVE_FACTOR;

	return Point(FARM_START_POINT.x + xx, FARM_START_POINT.y + yy);
}