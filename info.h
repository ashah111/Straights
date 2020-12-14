#ifndef _INFO_H
#define _INFO_H
#include <cstddef>
#include <memory>
#include "card.h"

// Information for the cell to return i.e. its state (Alive/Dead) and position in grid.
struct Info {
    std::shared_ptr<Card> card;
};

#endif
