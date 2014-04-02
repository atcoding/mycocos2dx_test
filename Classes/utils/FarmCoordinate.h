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
ũ������һϵ�������Ǹ���jpgͼƬ��������
����ũ���ĶԽ��߳�����3500,��������80��,��ÿ�����ӶԽ���Ϊ43.75��
ũ�����ĵ�����������(0,0)[world]
Ĭ��ũ�����������(10,10)[cell]����(90,90)[cell]
Ҳ����(-1750,0)[world] ���� (1750,0)[world]
Ԥ��ũ����Χ10����λ�Ŀհ�
��(0,0)[cell]��Ӧ����(-1750-10*43.75,0)[world] => (-2187.5,0)[world]
**/
class FarmCoordinate 
{
public:
	//ũ����ʼ��,����(0,0)[cell]����������(-2187.5,0)[world]
	static cocos2d::Point FARM_START_POINT;
	//ũ��������ʼX,[cell]
	static int FARM_GRID_START_CELL_X;
	//ũ��������ʼY,[cell]
	static int FARM_GRID_START_CELL_Y;
	//ũ�����ӿ��
	static int FARM_GRID_WIDTH;
	//ũ�����Ӹ߶�
	static int FARM_GRID_HEIGHT;
	//ũ��ÿ�����ӶԽ��߳���
	static float FARM_GRID_DIAGONAL;
	//ũ��ÿ�����ӶԽ��߳��ȵ�һ��
	static float FARM_GRID_DIAGONAL_2;
	//ũ��Y����ӽ�ϵ��,�Ƕȴ����40�ȣ�cos(41)
	static double FARM_Y_PERSPECTIVE_FACTOR;
	static FarmCell* getCellAt(int i, int j, int w=1, int h=1);
	static cocos2d::Point translateFromFarmPoint(float x, float y, float z=0);
};

#endif // __FARM_COORDINATE_H__
