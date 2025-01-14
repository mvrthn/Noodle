#include "chicken.hpp"

#include "../ingredient.hpp"


namespace Noodle {
    

int Chicken::evaluate(const Array<5>& cards) const {
    int ingredients[7] = {0};
    int n = cards.len();
    for(int i = 0; i <= n; i++) {
        const Card* card = cards[i];
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