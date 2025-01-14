#include "chicken.hpp"

#include "../ingredient.hpp"


namespace Noodle {
    

int Chicken::evaluate(Card* cards, int n) const {
    int ingredients[7] = {0};
    for(int i = 0; i <= n; i++) {
        Card* card = cards + i;
        if(card->isFlavor()) continue;
        Ingredient* ingredient = (Ingredient*) card;
        ingredients[ingredient->id()]++;
    }
    int max = 1;
    for(int x : ingredients) {
        if(x > max) {
            max = x;
        }
    }
    return max == 1 ? 0 : (max == 2 ? 6 : 10);
}

} // namespace Noodle