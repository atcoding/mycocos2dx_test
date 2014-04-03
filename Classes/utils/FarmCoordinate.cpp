#include "FarmCoordinate.h"
#include <math.h>
#include "layer\FarmLayer.h"

USING_NS_CC;

FarmCell* FarmCoordinate::getCellAt(int i, int j, int w, int h){

	int lx = i;
	int rx = (i+w) ;
	int ty = (j+h)  ;
	int by = j ;

	auto ret = new FarmCell();
	ret->cellX = i;
	ret->cellY = j;
	ret->width = w;
	ret->height = h;
	
	ret->left = FarmCoordinate::translateFarmCellPosToLayerPos(lx, ty);
	ret->top = FarmCoordinate::translateFarmCellPosToLayerPos(rx,ty);
	ret->right = FarmCoordinate::translateFarmCellPosToLayerPos(rx, by);
	ret->bottom = FarmCoordinate::translateFarmCellPosToLayerPos(lx, by);

	return ret;
}


Point FarmCoordinate::translateFarmCellPosToLayerPos(float x, float y, float z) {
	auto xx = (x+y)* FARM_GRID_DIAGONAL_2;
	auto yy = (y-x)* FARM_GRID_DIAGONAL_2 * FARM_Y_PERSPECTIVE_FACTOR;

	return Point(FARM_START_POINT_X + xx, FARM_START_POINT_Y + yy);
}