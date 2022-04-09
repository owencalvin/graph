//
// Created by owen on 28/03/2022.
//

#pragma once

#include <vector>
#include <sstream>

using namespace std;

/**
 * A priority queue implementation, similar as std::priority_queue
 */
class MinHeap {
private:
    vector<pair<int, int>> heap;

public:
    MinHeap();

    friend ostream &operator<<(ostream &os, const MinHeap &mh);

    string toString() const ;

    /**
     * Determines if the heap is empty
     * @return True if the heap is empty
     */
    bool empty();

    /**
     * Insert a value and a priority in the heap
     * @param priority The priority associated to the value
     * @param value The actual value
     * @return A pointer to the inserted value
     */
    const pair<int, int> *insert(int priority, int value);

    /**
     * Get the minimum value of the heap (=== the top value)
     * @return A pointer to minimum value of the heap (=== the top value)
     */
    const pair<int, int> *minimum();

    /**
     * Return the minimum and remove it from the heap, then reorganize the heap
     * @return A pair, the first value is the priority and the second value is the actual value: pair<int priority, int value>
     */
    pair<int, int> extractMinimum();

    /**
     * Decrease the priority of a value in the heap
     * @param index The value index in the heap
     * @param newPriority The new priority
     */
    void decreasePriority(int index, int newPriority);

    /**
     * Get the index of a value in the priority queue
     * @param value The value to find
     */
    int getIndexByValue(int value);

    /**
     * In french: "RendreMinimier"
     */
    void siftUp();
};
