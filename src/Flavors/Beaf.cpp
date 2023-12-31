#include "Beaf.hpp"
#include "../Ingredient.hpp"

int Beaf::evaluate(Card* cards,int n) {
    int scores[5] = {0, 2, 5, 9, 14};
    int ingrerdients[4] = {false};
    int x = 0;
    for(int i = 0; i <= n; i++) {
        Card* card = cards + i;
        if(card->isFlavor()) continue;
        Ingredient* ingredient = (Ingredient*) card;
        if(ingredient->isProtein() && !ingrerdients[ingredient->id() - 3])  {
            ingrerdients[ingredient->id() - 3] = true;
            x++;
        }
    }
    return scores[x];
}