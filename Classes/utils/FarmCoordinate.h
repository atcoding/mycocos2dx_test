#ifndef __FARM_COORDINATE_H__
#define __FARM_COORDINATE_H__

#include "cocos2d.h"

struct FarmCell {
	int cellX;
	int cellY;
	int width;
	int height;
	// center point of rhombus
	cocos2d::Point center;
	// left point of rhombus
	cocos2d::Point left;
	// right point of rhombus
	cocos2d::Point right;
	// top point of rhombus
	cocos2d::Point top;
	// right point of rhombus
	cocos2d::Point bottom;
};

/**
农场的这一系列数据是根据jpg图片分析而来
整个农场的对角线长度是3500,格子数是80个,则每个格子对角线为43.75。
农场中心的世界坐标是(0,0)[world]
默认农场左点起坐标(10,10)[cell]终于(90,90)[cell]
也就是(-1750,0)[world] 终于 (1750,0)[world]
预留农场周围10个单位的空白
则(0,0)[cell]对应的是(-1750-10*43.75,0)[world] => (-2187.5,0)[world]
**/
class FarmCoordinate 
{
public:
	//农场起始点,格子(0,0)[cell]的世界坐标(-2187.5,0)[world]
	static cocos2d::Point FARM_START_POINT;
	//农场格子起始X,[cell]
	static int FARM_GRID_START_CELL_X;
	//农场格子起始Y,[cell]
	static int FARM_GRID_START_CELL_Y;
	//农场格子宽度
	static int FARM_GRID_WIDTH;
	//农场格子高度
	static int FARM_GRID_HEIGHT;
	//农场每个格子对角线长度
	static float FARM_GRID_DIAGONAL;
	//农场每个格子对角线长度的一半
	static float FARM_GRID_DIAGONAL_2;
	//农场Y轴的视角系数,角度大概是40度，cos(41)
	static double FARM_Y_PERSPECTIVE_FACTOR;
	static FarmCell* getCellAt(int i, int j, int w=1, int h=1);
	static cocos2d::Point translateFromFarmPoint(float x, float y, float z=0);
};

#endif // __FARM_COORDINATE_H__
