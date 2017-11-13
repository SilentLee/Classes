#include "CG_ResolutionAdapter.h"

CG_ResolutionAdapter::CG_ResolutionAdapter()
{
	node = NULL;
}

CG_ResolutionAdapter::~CG_ResolutionAdapter()
{
	// 有造成 内存泄漏 或 寻址不到 的可能
	node = NULL;
}

void CG_ResolutionAdapter::init()
{
	auto director = Director::getInstance();
	VisibleSize = director->getVisibleSize();

	SizeAdjustFactor = VisibleSize.width / designResolutionSize.width;
	PosAdjustFactor = VisibleSize.width / designResolutionSize.width;

	log("分辨率适配器初始化成功");
}

// 尺寸转换
void CG_ResolutionAdapter::sizeAdp()
{
	node->setScale(SizeAdjustFactor);
}

// 设置绝对坐标
void CG_ResolutionAdapter::setAdpPosWithAbsoluteValue(int posX, int posY)
{
	node->setPosition(posX * PosAdjustFactor, posY * PosAdjustFactor);
}

void CG_ResolutionAdapter::setAdpPosXWithAbsoluteValue(int posX)
{
	node->setPositionX(posX * PosAdjustFactor);
}

void CG_ResolutionAdapter::setAdpPosYWithAbsoluteValue(int posY)
{
	node->setPositionY(posY * PosAdjustFactor);
}

// 设置相对坐标
void CG_ResolutionAdapter::setAdpPosWithRelativeValue(float posX, float posY)
{
	node->setPosition(posX * designResolutionSize.width * PosAdjustFactor, posY * designResolutionSize.height * PosAdjustFactor);
}

void CG_ResolutionAdapter::setAdpPosXWithRelativeValue(float posX)
{
	node->setPositionX(posX * designResolutionSize.width * PosAdjustFactor);
}

void CG_ResolutionAdapter::setAdpPosYWithRelativeValue(float posY)
{
	node->setPositionY(posY * designResolutionSize.height * PosAdjustFactor);
}

// 设置绝对设备尺寸
void CG_ResolutionAdapter::setRealPosWithAbsoluteValue(int posX, int posY)
{
	node->setPosition(posX, posY);
}

void CG_ResolutionAdapter::setRealPosXWithAbsoluteValue(int posX)
{
	node->setPositionX(posX);
}

void CG_ResolutionAdapter::setRealPosYWithAbsoluteValue(int posY)
{
	node->setPositionY(posY);
}

// 设置方格坐标
void CG_ResolutionAdapter::setPosInSquare(float posX, float posY)
{
	float rectPosX = ((int)(posX / PosAdjustFactor / SQUARE_WIDTH_DOUBLE_BATTLE)) * SQUARE_WIDTH_DOUBLE_BATTLE * PosAdjustFactor;
	float rectPosY = ((int)(posY / PosAdjustFactor / SQUARE_WIDTH_DOUBLE_BATTLE)) * SQUARE_WIDTH_DOUBLE_BATTLE * PosAdjustFactor;
	node->setPosition(rectPosX, rectPosY);
}

void CG_ResolutionAdapter::setPosXInSquare(float posX)
{
	float rectPosX = ((int)(posX / PosAdjustFactor / SQUARE_WIDTH_DOUBLE_BATTLE)) * SQUARE_WIDTH_DOUBLE_BATTLE * PosAdjustFactor;
	node->setPositionX(rectPosX);
}

void CG_ResolutionAdapter::setPosYInSquare(float posY)
{
	float rectPosY = ((int)(posY / PosAdjustFactor / SQUARE_WIDTH_DOUBLE_BATTLE)) * SQUARE_WIDTH_DOUBLE_BATTLE * PosAdjustFactor;
	node->setPositionY(rectPosY);
}

// 设置相对尺寸
void CG_ResolutionAdapter::setSizeAdp(float scale)
{
	node->setScale(scale * SizeAdjustFactor);
}

// 获取绝对适配坐标
Vec2 CG_ResolutionAdapter::getAdpPosWithAbsoluteValue()
{
	float posX = node->getPositionX() / PosAdjustFactor;
	float posY = node->getPositionY() / PosAdjustFactor;
	return Vec2(posX, posY);
}

float CG_ResolutionAdapter::getAdpPosXWithAbsoluteValue()
{
	return node->getPositionX() / PosAdjustFactor;
}

float CG_ResolutionAdapter::getAdpPosYWithAbsoluteValue()
{
	return node->getPositionY() / PosAdjustFactor;
}

// 获取相对适配坐标
Vec2 CG_ResolutionAdapter::getAdpPosWithRelativeValue()
{
	float posX = node->getPositionX() / designResolutionSize.width / PosAdjustFactor;
	float posY = node->getPositionY() / designResolutionSize.height / PosAdjustFactor;
	return Vec2(posX, posY);
}

float CG_ResolutionAdapter::getAdpPosXWithRelativeValue()
{
	return node->getPositionX() / designResolutionSize.width / PosAdjustFactor;
}

float CG_ResolutionAdapter::getAdpPosYWithRelativeValue()
{
	return node->getPositionY() / designResolutionSize.height / PosAdjustFactor;
}

// 获取绝对设备尺寸
Vec2 CG_ResolutionAdapter::getRealPosWithAbsoluteValue()
{
	return node->getPosition();
}

float CG_ResolutionAdapter::getRealPosXWithAbsoluteValue()
{
	return node->getPositionX();
}

float CG_ResolutionAdapter::getRealPosYWithAbsoluteValue()
{
	return node->getPositionY();
}