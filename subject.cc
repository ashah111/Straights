#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "subject.h"
#include "observer.h"
#include "card.h"

void Subject::attach(Observer *o) {
	observers.emplace_back(o);
}

void Subject::notifyObservers() {
	for (auto &ob : observers) {
		ob->notify( *this );

	}
}

Subject::~Subject() {}
