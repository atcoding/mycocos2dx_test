#ifndef __GAME_VARS_H__
#define __GAME_VARS_H__

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
整个农场的对角线长度是3500,格子数是44个,则每个格子对角线为87.5。
农场中心的世界坐标是(0,0)[world]
默认农场左点起坐标(5,5)[cell]终于(49,49)[cell]
也就是(-1750,0)[world] 终于 (1750,0)[world]
预留农场周围10个单位的空白
则(0,0)[cell]对应的是(-2147.7272727272727272727272727273,0)[world]
*/
//农场起始点
const double FARM_START_POINT_X = -2147.7272727272727272727272727273;
const double FARM_START_POINT_Y = 0;
//农场格子起始X,[cell]
const int FARM_GRID_START_CELL_X = 5;
//农场格子起始Y,[cell]
const int FARM_GRID_START_CELL_Y = 5;
//农场格子宽度
const int FARM_GRID_WIDTH = 44;
//农场格子高度
const int FARM_GRID_HEIGHT = 44;
//农场每个格子对角线长度
const double FARM_GRID_DIAGONAL = 79.545454545454545454545454545455;
//农场每个格子对角线长度的一半
const double FARM_GRID_DIAGONAL_2 = 39.772727272727272727272727272727;
//农场Y轴的视角系数,角度大概是41度，cos(41.75)
const double FARM_Y_PERSPECTIVE_FACTOR = 0.74605737506169950089839219852075;

#endif // __GAME_VARS_H__
