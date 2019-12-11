#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	
	bool isAlive();
	

protected:
	int health;
	int maxHealth;
};

