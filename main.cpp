#include <iostream>
#include <future>
#include <chrono>
#include <list>

using namespace std;

template<typename T>
list<T> sequentialQuickSort(list<T> input){
    if (input.empty())
        return input;

    list<T> result;
    // copy the elements of the input list into the result list
    // starting pos, the source list , the source starting point
    result.splice(result.begin(), input,  input.begin());
    // choose the pivot to be the first element in the list
    const T &pivot = *result.begin();
    // get iterator of the elements less than the pivot
    auto dividePoint = partition(
            input.begin(),
            input.end(),
            [&](T const &t){return t<pivot;});
    // get a list of the lower elements
    list<T> lowerPart;
    lowerPart.splice(lowerPart.begin(), input, input.begin(), dividePoint);
    // repeat the sort for the two parts
    future<list<T>> newLower(async(&sequentialQuickSort<T>, move(lowerPart)));
    auto newHigher  (sequentialQuickSort(move(input)));
    // collect them in the result list
    result.splice(result.end(), newHigher);
    result.splice(result.begin(), newLower.get());

    return result;
}

int main() {
    list<int> elements = {2,3,1,4,6,5,10,9,2,3,1,4,6,5,10,9,2,3,1,4,6,5,10,9,2,3,1,4,6,5,10,9};
    list<int> result = sequentialQuickSort(elements);

    for(auto const &i: result)
        cout << i;

    return 0;
}
