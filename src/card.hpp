#pragma once 


#include <string>


namespace Noodle {

class Card {
public:
    Card(const std::string& _name): name(_name) {}

    inline const std::string& getName() const { return name; }

    virtual bool isFlavor() const = 0;
    virtual bool isIngredient() const = 0;

private:
    const std::string name;
};
    
} // namespace Noodle