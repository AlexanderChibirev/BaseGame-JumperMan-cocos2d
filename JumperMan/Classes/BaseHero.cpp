 #include "BaseHero.h"

USING_NS_CC;

BaseHero::BaseHero()
{
	
}

BaseHero * BaseHero::create()
{
	BaseHero *hero = new (std::nothrow) BaseHero();
	if ( (hero && hero->initWithFile("hero/Hero1.png")) && (hero->init()) )
	{
		hero->autorelease();
		return hero;
	}
	CC_SAFE_DELETE(hero);
	return nullptr;
}

bool BaseHero::init()
{
	m_visibleSize = Director::getInstance()->getVisibleSize();
	m_origin = Director::getInstance()->getVisibleOrigin();

	setPosition(Point(m_visibleSize.width / 2 + m_origin.x, m_visibleSize.height / 2 + m_origin.y));

	auto spriteBody = PhysicsBody::createBox(getContentSize());
	spriteBody->setVelocity(Vect(0,-200));
	spriteBody->setCollisionBitmask(BIRD_COLLISION_BITMASK);
	spriteBody->setContactTestBitmask(true);
	setPhysicsBody(spriteBody);
	return true;
}