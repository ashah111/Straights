#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include "sumheap.h"

using namespace std;

SumHeap::SumHeap(unsigned int x) : value{x}, parent{nullptr}, childTotal{0} {}

bool SumHeap::validate(unsigned int val, SumHeap *heap){
  if (heap->childTotal + val >= heap->value || heap->childTotal + val < heap->childTotal || heap->childTotal + val < val) return false;
  SumHeap *it = heap->parent;
  while (it != nullptr){
    if (it->childTotal + val >= it->value || it->childTotal + val < it->childTotal || it->childTotal + val < val) return false;
    it = it->parent;
  }
  return true;
}

void SumHeap::updateChildrenTotal(unsigned int val){
  childTotal += val;
  SumHeap *it = parent;
  while (it != nullptr){
    it->childTotal += val;
    it = it->parent;
  }
}

SumHeap* SumHeap::addChild(unsigned int val){
  if (!validate(val,this)) throw InvalidValueException();
  else updateChildrenTotal(val);
  unique_ptr<SumHeap> child = make_unique<SumHeap>(val);
  child->parent = this;
  children.emplace_back(move(child));
  SumHeap *tmp = children.back().get();
  return tmp;
}

SumHeap* SumHeap::getParent(){
  return parent;
}

size_t SumHeap::numChildren(){
  return children.size();
}

SumHeap* SumHeap::getChild(size_t idx){
  if (idx > children.size()) return nullptr;
  return children[idx].get();
}

unsigned int SumHeap::getValue(){
  return value;

}

void SumHeap::swap(SumHeap *other){
  if(parent == nullptr || other->parent == nullptr) throw InvalidValueException();
  unsigned int o = other->childTotal + other->value;
  unsigned int t = this->childTotal + this->value;

  if (parent != other->parent){
    if (o == t){
      //If both sides will have same value after swap, this swap will be valid
    } else if (o < t){
      //Validate swap from this -> other only
      if (!validate(t-o, other->parent)) throw InvalidValueException();
    } else {
      //Validate swap from other -> this only
      if (!validate(o-t, this->parent)) throw InvalidValueException();
    }
  }

  int idx1;
  int idx2;
  auto itThis = find_if(this->parent->children.begin(), this->parent->children.end(), [&](unique_ptr<SumHeap>& p){
    return p.get() == this;
  });

  if(itThis != this->parent->children.end()){
    idx1 = distance(this->parent->children.begin(), itThis);
  }

  auto itOther = find_if(other->parent->children.begin(), other->parent->children.end(), [&](unique_ptr<SumHeap>& p){
    return p.get() == other;
  });

  if(itOther != other->parent->children.end()){
    idx2 = distance(other->parent->children.begin(), itOther);
  }

  this->parent->children.push_back(move(other->parent->children[idx2]));
  other->parent->children.erase(other->parent->children.begin() + idx2);

  other->parent->children.push_back(move(this->parent->children[idx1]));
  this->parent->children.erase(this->parent->children.begin() + idx1);
}
