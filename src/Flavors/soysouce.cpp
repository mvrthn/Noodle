#include "soysouce.hpp"

#include "../ingredient.hpp"


namespace Noodle {

int SoySouce::evaluate(const Array<5>& cards) const {
    int scores[5] = {0, 2, 5, 9, 14};
    int ingrerdients[4] = {false};
    int x = 0;
    int n = cards.len();
    for(int i = 0; i <= n; i++) {
        const Card* card = cards[i];
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