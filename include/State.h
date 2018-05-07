#pragma once

namespace mdtModels {

template <typename T> class State {
public:
  T value;
  inline State() {}
  /// Distruttore vuoto.
  inline ~State() {}
};
} // namespace mdtModels