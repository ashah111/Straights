#ifndef SUMHEAP_H
#define SUMHEAP_H 1

#include <memory>
#include <vector>

class SumHeap {
    public:
    SumHeap(unsigned int);

    SumHeap *addChild(unsigned int value);
    SumHeap *getParent();
    size_t numChildren();
    SumHeap *getChild(size_t idx);
    unsigned int getValue();
    void swap(SumHeap *other);

    private:
    unsigned int childTotal;
    unsigned int value;
    SumHeap *parent;
    std::vector<std::unique_ptr<SumHeap>> children;

    bool validate(unsigned int value, SumHeap* heap);
    void updateChildrenTotal(unsigned int val);
};

class InvalidValueException {};

#endif
