#pragma once
#include "entity.hh"

class PoolItem : public Entity
{        
    public:
        // Other methods or properties must be here
        std::string name;
        bool active;
        PoolItem(const std::string& name, bool active) : name(name), active(active)
        {

        }
        void update() override; // Provided method, do not change
    
        void draw() override; // Provided method, do not change

};
