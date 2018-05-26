#include "../include/State.h"
 
template <typename T>
mdtModels::State<T>::State()
{
}

template <typename T>
mdtModels::State<T>::State(T value)
{
    state = value;
}

template <typename T>
mdtModels::State<T>::~State()
{
}

template <typename T>
const T mdtModels::State<T>::getState() const 
{
    return this->state;
}

template <typename T>
bool mdtModels::operator==(const State<T> &one,
                          const State<T> &that) {
  return (one.getState() == that.getState());
}

template mdtModels::State<int>::State();
template mdtModels::State<int>::State(int value);
template mdtModels::State<int>::~State();
template const int mdtModels::State<int>::getState() const;
template bool mdtModels::operator==(const State<int> &one,const State<int> &that);