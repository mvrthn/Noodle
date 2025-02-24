#pragma once 


#include <string>


namespace Noodle {

class Card {
public:
    Card(int _id, const std::string& _name): ID(_id), name(_name) {}

    inline const int id() const { return ID; }
    inline const std::string& getName() const { return name; }

    virtual bool isFlavor() const = 0;
    virtual bool isIngredient() const = 0;

private:
    const int ID;
    const std::string name;
};
    
} // namespace Noodle