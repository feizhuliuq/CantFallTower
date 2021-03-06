#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include <cocos2d.h>
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Util/TDPoint.h"
#include "Entity/Entity.h"
#include "Enemy/Enemy.h"
#include <cmath>

class Enemy;
class Entity;

using namespace cocostudio::timeline;
class GameScene:public cocos2d::Layer
{
protected:

	cocos2d::Vector<Enemy*> enemyList;

	void clearRemovedEnemyFromList();

public:

	static cocos2d::Scene* createScene();
	
	virtual bool init();

	CREATE_FUNC(GameScene);

	static cocos2d::Vector<TDPoint*> allPoint;//保存所有路径转弯点

	int enemyMaxCount; //敌人最大数量
	int enemyCreated;
	
	void EnemyCreat(float dt);//产生一波怪物

	// 用于单一Entity进行判定检测，一般情况下由Entity自身调用，指定singleEnemy以判定单个目标（会检查目标有效性）
	void judgeEntityBounding(Entity* entity, Enemy* singleEnemy = nullptr);

	void getEnemyInDistance(cocos2d::Vector<Enemy*>& list, const cocos2d::Vec2& pos, double dist);
	
	Enemy* getNearestEnemy(const cocos2d::Vec2& pos, double dist=INFINITY);

	void initAllPoints();//加载敌人行走路径点

	void addTDSelect(int r, int c);//添加塔的选择面板
	void selectTD(cocos2d::Ref* obj);//建塔的回调

	int nowRow, nowCol;//点击处的行列信息，供造塔过程使用
	int towerInfo[11][17];//建塔信息,行列信息完全和二维数组相同，左上角为原点，屏幕原点,11行，17列

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);	
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);	
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);


};

#endif