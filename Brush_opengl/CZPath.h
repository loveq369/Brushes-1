
///  \file CPath.h
///  \brief This is the file declare the Class CPath.
///
///		(description)
///
///  \version	1.0.0
///	 \author	Charly Zhang<chicboi@hotmail.com>
///  \date		2014-09-11
///  \note

#ifndef _CZPATH_H_
#define _CZPATH_H_

#include "CZGeometry.h"
#include "CZ3DPoint.h"
#include "CZBrush.h"
#include "CZBezierSegment.h"
#include "CZShader.h"
#include <vector>

//#include "WDCoding.h"
/*
@class WDBezierNode;
@class WDBrush;
@class WDColor;
@class WDRandom;

typedef enum {
    WDPathActionPaint,
    WDPathActionErase
} WDPathAction;

*/
class CZPath
{
private:
	bool					closed;
	
	//WDColor *color;
	//@property (nonatomic) WDPathAction action;
	float					scale;

	/// ���ջ��Ƶ�Ĳ���
	std::vector<CZ2DPoint>	points;
	std::vector<float>		sizes;
	std::vector<float>		angles;
	std::vector<float>		alphas;

public:
	CZBrush							*brush;				///< ֻ�����ã���������������
	std::vector<CZBezierNode>		nodes;				///< �������������п��Ƶ�
	bool							limitBrushSize;
	float							remainder;			///< ���ƹ켣�����ɢ����ռ�õ��߿ռ�
	CZShader						*shader;			///< !Ŀǰ�������ã�ֻ������

	CZPath()
	{
		this->brush = NULL;
		scale = 1.0f;
		remainder = 0.0f;
		limitBrushSize = false;
	}
	~CZPath()
	{
		nodes.clear();
		points.clear();
		sizes.clear();
		angles.clear();
		alphas.clear();
	}

	/// ���ƹ켣
	CZRect paint(bool withBrush = true/*randomizer*/);
	/// ���ñպ�
	void setClosed(bool closed_);

private:
	/// �������ݣ�����OpenGL��ͼ�νӿڣ�
	/// 
	///		����С���ȵ���ɢ��(points_)Ϊ���ģ��γ�С���Ρ������˾�������ͨ��ͼ�νӿڻ��Ƴ�����
	///
	CZRect drawData();
	
	/// ֱ�ӻ������ݣ�����OpenGL��ͼ�νӿڣ�
	/// 
	///		����ͼ�νӿ�ֱ�ӽ����ݻ��Ƴ�����
	///
	CZRect drawDataDirectly();

	/// ��������֮�����.
	///
	///		�������Ƶ�(linePoints)֮�������ɢ�ɸ�С���ȵ���ɢ��(points)��
	///		����points,sizes,alphas,angles��������
	///		�������õ��˻�ˢ�Ĳ�����
	///
	///		/param lastLocation - �켣�����ɢ���λ��
	///		/param location		- ��ǰ���Ƶ��λ��
	///		/param randomizer	- �����
	///		/note	����ϵͳ�Դ������������ʱ�����randomizer
	///				���û��ʲ������ɲ��ֵ��㷨û����
	void paintBetweenPoints(const CZ3DPoint &lastLocation, const CZ3DPoint &location/*, float remainder*/);
	
	/// ������ɢ�ɻ��Ƶ�
	/// 
	///		������㣨nodes���γ�һ�����α��������ߣ��ٽ����ߴ�ɢ�����ɸ����Ƶ㣨points��
	/// 
	///		/param points		- ��ɢ��õ��Ļ��Ƶ�����
	///		/ret				- ��ɢ��õ��Ļ��Ƶ���Ŀ
	int flattenedPoints(std::vector<CZ3DPoint> & linePoints);
};

/*
    NSMutableArray      *nodes_;
    BOOL                closed_;
    CGMutablePathRef    pathRef_;
    CGRect              bounds_;
    BOOL                boundsDirty_;
    

@property (nonatomic, assign) BOOL closed;
@property (nonatomic, strong) NSMutableArray *nodes;
@property (nonatomic, strong) WDBrush *brush;
@property (nonatomic) WDColor *color;
@property (nonatomic, assign) float remainder;
@property (nonatomic) WDPathAction action;
@property (nonatomic, assign) float scale;

@property (nonatomic, assign) BOOL limitBrushSize;

+ (WDPath *) pathWithRect:(CGRect)rect;
+ (WDPath *) pathWithOvalInRect:(CGRect)rect;
+ (WDPath *) pathWithStart:(CGPoint)start end:(CGPoint)end;

- (id) initWithRect:(CGRect)rect;
- (id) initWithOvalInRect:(CGRect)rect;
- (id) initWithStart:(CGPoint)start end:(CGPoint)end;
- (id) initWithNode:(WDBezierNode *)node;

- (void) invalidatePath;

- (void) addNode:(WDBezierNode *)node;
- (void) addAnchors;

- (WDBezierNode *) firstNode;
- (WDBezierNode *) lastNode;

- (CGRect) controlBounds;
- (void) computeBounds;

- (void) setClosedQuiet:(BOOL)closed;

- (CGPathRef) pathRef;

- (NSArray *) flattenedPoints;
- (void) flatten;

- (WDRandom *) newRandomizer;
- (CGRect) paint:(WDRandom *)randomizer;

*/
#endif
