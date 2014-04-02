#include "FarmCoordinate.h"
#include "cocos2d.h"
#include "layer\FarmLayer.h"
#include <math.h>

USING_NS_CC;

float FarmCoordinate::FARM_GRID_SIZE = 40;
float FarmCoordinate::FARM_GRID_WIDTH = 116;
float FarmCoordinate::FARM_GRID_HEIGHT = 85;

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

Map<float, TouchPoint*> s_cell_pt_map;

const float DEFORMATION = 1.118033989;
const float xCartFactor =0.8944271909999159; //0.8
const float yCartFactor =0.4472135954999579; //0.6

Point FarmCoordinate::translateFromFarmPoint(float x, float y, float z) {
	/*
	auto key = x + y * FARM_GRID_WIDTH;
	if (s_cell_pt_map.at(key)) {
		return s_cell_pt_map.at(key)->getPoint();
	}
	auto src =Point(FarmLayer::getFloorX() + x, FarmLayer::getFloorY() + y);
	auto c = FarmLayer::getFloorCenterPoint();
	auto r = c.getDistance(src);
	auto b = src.getAngle() - M_PI_4;
	auto tp = TouchPoint::initWithPoint(Point(r*cos(b), r*sin(b)));
	s_cell_pt_map.insert(key, tp);
	return tp->getPoint();
	*/
	/*
	auto src =Point(FarmLayer::getFloorX() + x, FarmLayer::getFloorY() + y);
	auto c = FarmLayer::getFloorCenterPoint();
	auto r = c.getDistance(src);
	auto b = src.getAngle() - M_PI_4;
	return Point(r*cos(b), r*sin(b));*/
	//x += FarmLayer::getFloorX();
	//y += FarmLayer::getFloorY();
	auto xx = x *DEFORMATION;
	auto yy = y *DEFORMATION;
	auto zz = z *DEFORMATION;

	auto xCart  =  FarmLayer::getFloorX() +  (xx + yy) *xCartFactor ;
	auto yCart  = FarmLayer::getFloorY() +  zz + (xx - yy) * yCartFactor;
            
    return Point(xCart, -yCart);
}