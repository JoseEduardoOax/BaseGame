#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

namespace ECS{

template<typename T>
using Vec_t = std::vector<T>;

template<typename Key_t, typename Value_t>
using Hash_t = std::unordered_map<Key_t, Value_t>;

template<typename T>
using Uptr = std::unique_ptr<T>;

using EntityID_t = std::size_t;
using ComponentID_t = std::size_t;
using ComponentTypeID_t = std::size_t;

}//namespace ECS
