#include "../include/State.hpp"
namespace mdtModels {
template <typename T> State<T>::State() {}

template <typename T> State<T>::State(T value) { state = value; }

template <typename T> State<T>::~State() {}

template <typename T> const T State<T>::getState() const { return this->state; }

template <typename T>
bool operator==(const State<T> &one, const State<T> &that) {
  return (one.getState() == that.getState());
}

template State<int>::State();
template State<int>::State(int value);
template State<int>::~State();
template const int State<int>::getState() const;
template bool operator==(const State<int> &one, const State<int> &that);
} // namespace mdtModels