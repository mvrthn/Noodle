#include "shrimp.hpp"

#include "../ingredient.hpp"


namespace Noodle {

int Shrimp::evaluate(const Array<5>& cards) const {
    int v = 0, p = 0, m = 0;
    int n = cards.len();
    for(int i = 0; i <= n; i++) {
        const Card* card = cards[i];
        if(card->isFlavor()) continue;
        Ingredient* ingredient = (Ingredient*) card;
        bool b = false;
        if(ingredient->isVege()) {
            v++;
            b = true;
        }
        if(ingredient->isProtein()) {
            p++;
            b = true;
        }
        if(b) m++;
    } 
    int x = 0;
    while(v && p) {
        x++;
        v--;
        p--;
    }
    return x <= m / 2 ? 4 * x : 4 * m;
}

} // namespace Noodle