#pragma once

#include "entity.hh"
#include <list>
class PoolItem;
class ObjectPool {

private:
std::list<PoolItem*> pool_items;

public:
    // Constructor
    ObjectPool(){};
    ObjectPool(const char* name, bool active){};
    ~ObjectPool() {} ;

    // Update method for the entity, can be overriden and called from the game state Update method

    // Draw method for the entity, can be overriden and called from the game state Draw method

    void add(PoolItem& item);
    int count();
    int countActive();
    PoolItem* findByName(const char* name);
    PoolItem* findByRef(const PoolItem& item);
    void activate(const char* name);
    void deactivate(const char* name);
    void updateAll() ;

    void updateActive();
    void drawAll();    
    void drawActive();    

    void remove(PoolItem& item);
    void removeByName(const char* name);

    void removeInactive();




    // Public member variables
    const char* name;
    bool active;
};
