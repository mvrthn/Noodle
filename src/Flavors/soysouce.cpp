#include "soySouce.hpp"

#include "../ingredient.hpp"


namespace Noodle {

int SoySouce::evaluate(Card* cards,int n) const {
    int scores[5] = {0, 2, 5, 9, 14};
    int ingrerdients[4] = {false};
    int x = 0;
    for(int i = 0; i <= n; i++) {
        Card* card = cards + i;
        if(card->isFlavor()) continue;
        Ingredient* ingredient = (Ingredient*) card;
        if(ingredient->isVege() && !ingrerdients[ingredient->id()])  {
            ingrerdients[ingredient->id()] = true;
            x++;
        }
    }
    return scores[x];
}

} // namespace Noodle