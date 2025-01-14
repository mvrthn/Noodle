#include "beaf.hpp"

#include "../ingredient.hpp"


namespace Noodle {

int Beaf::evaluate(const Array<5>& cards) const {
    int scores[5] = {0, 2, 5, 9, 14};
    int ingrerdients[4] = {false};
    int x = 0;
    int n = cards.len();
    for(int i = 0; i <= n; i++) {
        const Card* card = cards[i];
        if(card->isFlavor()) continue;
        Ingredient* ingredient = (Ingredient*) card;
        if(ingredient->isProtein() && !ingrerdients[ingredient->id() - 3])  {
            ingrerdients[ingredient->id() - 3] = true;
            x++;
        }
    }
    return scores[x];
}

} // namespace Noodle