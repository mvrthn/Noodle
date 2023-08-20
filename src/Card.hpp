#ifndef NOODLE_CARD_H
#define NOODLE_CARD_H


class Card {
public:
    virtual bool isFlavor() = 0;
    virtual bool isIngredient() = 0;
    virtual const char* name() = 0;
};

#endif //NOODLE_CARD_H