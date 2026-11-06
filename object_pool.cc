#include <functional>
#include <algorithm>

#include "object_pool.hh"
#include "pool_item.hh"


void ObjectPool::add(PoolItem &item)
{
    pool_items.push_back(&item);
}

int ObjectPool::count()
{
  return std::distance(pool_items.begin(), pool_items.end());
}

int ObjectPool::countActive()
{
    return std::count_if(pool_items.begin(), pool_items.end(), [](PoolItem* item) { return item->active; });
}

PoolItem *ObjectPool::findByName(const char *name)
{
    auto object =  std::find_if(pool_items.begin(), pool_items.end(), [name](PoolItem* item) { return item->name == name; });
    if(object!=pool_items.end())     return *object;
    return nullptr;

}

PoolItem *ObjectPool::findByRef(const PoolItem &item)
{
    auto object = std::find_if(pool_items.begin(), pool_items.end(), [&item](PoolItem* pool_item) { return pool_item == &item; });
    if(object!=pool_items.end())     return *object;
    return nullptr;   
}

void ObjectPool::activate(const char *name)
{
    auto item = findByName(name);
    if (item) {
        item->active = true;
    }
}

void ObjectPool::deactivate(const char *name)
{
    auto item = findByName(name);
    if (item) {
        item->active = false;
    }
}

void ObjectPool::updateAll()
{
    std::for_each(pool_items.begin(), pool_items.end(), [](PoolItem* item) { item->update(); });
}

void ObjectPool::updateActive()
{
    std::for_each(pool_items.begin(), pool_items.end(), [](PoolItem* item) { if(item->active) item->update(); });
}

void ObjectPool::drawAll()
{
    std::for_each(pool_items.begin(), pool_items.end(), [](PoolItem* item) { item->draw(); });

}

void ObjectPool::drawActive()
{
    std::for_each(pool_items.begin(), pool_items.end(), [](PoolItem* item) { if(item->active) item->draw(); });

}

void ObjectPool::remove(PoolItem &item)
{
    std::remove_if(pool_items.begin(), pool_items.end(), [&item](PoolItem* pool_item) { return pool_item == &item; });

}

void ObjectPool::removeByName(const char *name)
{
    std::remove_if(pool_items.begin(), pool_items.end(), [name](PoolItem* pool_item) { return pool_item->name == name; });

}

void ObjectPool::removeInactive()
{
    std::remove_if(pool_items.begin(), pool_items.end(), [](PoolItem* pool_item) { return !pool_item->active; });
}
