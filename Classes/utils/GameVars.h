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
����ũ���ĶԽ��߳�����3520,��������44��,��ÿ�����ӶԽ���Ϊ80��
ũ�����ĵ�����������(0,0)[world]
Ĭ��ũ�����������(5,5)[cell]����(49,49)[cell]
Ҳ����(-1760,0)[world] ���� (1760,0)[world]
Ԥ��ũ����Χ5����λ�Ŀհ�
��(0,0)[cell]��Ӧ����(-2160,0)[world]
*/
//ũ����ʼ��
const float FARM_START_POINT_X = -2160.0f;
const float FARM_START_POINT_Y = 0.0f;
//ũ��������ʼX,[cell]
const int FARM_GRID_START_CELL_X = 5;
//ũ��������ʼY,[cell]
const int FARM_GRID_START_CELL_Y = 5;
//ũ�����ӿ��
const int FARM_GRID_WIDTH = 44;
//ũ�����Ӹ߶�
const int FARM_GRID_HEIGHT = 44;
//ũ��ÿ�����ӶԽ��߳���
const float FARM_GRID_DIAGONAL = 80.0f;
//ũ��ÿ�����ӶԽ��߳��ȵ�һ��
const float FARM_GRID_DIAGONAL_2 = 40.0f;
//ũ��Y����ӽ�ϵ��,�Ƕȴ����41.6�ȣ�cos(41.6)
const double FARM_Y_PERSPECTIVE_FACTOR = 0.74779809049853187810572050805846;

#endif // __GAME_VARS_H__
