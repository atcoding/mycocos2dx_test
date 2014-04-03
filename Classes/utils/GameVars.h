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
ũ������һϵ�������Ǹ���jpgͼƬ��������
����ũ���ĶԽ��߳�����3500,��������44��,��ÿ�����ӶԽ���Ϊ87.5��
ũ�����ĵ�����������(0,0)[world]
Ĭ��ũ�����������(5,5)[cell]����(49,49)[cell]
Ҳ����(-1750,0)[world] ���� (1750,0)[world]
Ԥ��ũ����Χ10����λ�Ŀհ�
��(0,0)[cell]��Ӧ����(-2147.7272727272727272727272727273,0)[world]
*/
//ũ����ʼ��
const double FARM_START_POINT_X = -2147.7272727272727272727272727273;
const double FARM_START_POINT_Y = 0;
//ũ��������ʼX,[cell]
const int FARM_GRID_START_CELL_X = 5;
//ũ��������ʼY,[cell]
const int FARM_GRID_START_CELL_Y = 5;
//ũ�����ӿ��
const int FARM_GRID_WIDTH = 44;
//ũ�����Ӹ߶�
const int FARM_GRID_HEIGHT = 44;
//ũ��ÿ�����ӶԽ��߳���
const double FARM_GRID_DIAGONAL = 79.545454545454545454545454545455;
//ũ��ÿ�����ӶԽ��߳��ȵ�һ��
const double FARM_GRID_DIAGONAL_2 = 39.772727272727272727272727272727;
//ũ��Y����ӽ�ϵ��,�Ƕȴ����41�ȣ�cos(41.75)
const double FARM_Y_PERSPECTIVE_FACTOR = 0.74605737506169950089839219852075;

#endif // __GAME_VARS_H__
