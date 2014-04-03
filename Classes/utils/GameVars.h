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
整个农场的对角线长度是3520,格子数是44个,则每个格子对角线为80。
农场中心的世界坐标是(0,0)[world]
默认农场左点起坐标(5,5)[cell]终于(49,49)[cell]
也就是(-1760,0)[world] 终于 (1760,0)[world]
预留农场周围5个单位的空白
则(0,0)[cell]对应的是(-2160,0)[world]
*/
//农场起始点
const float FARM_START_POINT_X = -2160.0f;
const float FARM_START_POINT_Y = 0.0f;
//农场格子起始X,[cell]
const int FARM_GRID_START_CELL_X = 5;
//农场格子起始Y,[cell]
const int FARM_GRID_START_CELL_Y = 5;
//农场格子宽度
const int FARM_GRID_WIDTH = 44;
//农场格子高度
const int FARM_GRID_HEIGHT = 44;
//农场每个格子对角线长度
const float FARM_GRID_DIAGONAL = 80.0f;
//农场每个格子对角线长度的一半
const float FARM_GRID_DIAGONAL_2 = 40.0f;
//农场Y轴的视角系数,角度大概是41.6度，cos(41.6)
const double FARM_Y_PERSPECTIVE_FACTOR = 0.74779809049853187810572050805846;

#endif // __GAME_VARS_H__
