#pragma once
#include <random>
#include <chrono>
#include <concepts>
#include <type_traits>

// Declarations for solving the circular dependency problem because of 'Player.hpp' and 'Monster.hpp'
class Player;
class Monster;

// Constrain the type T to be the 'float' or 'int' types
template<typename T>
concept IsFloatOrInt = std::is_same_v<T, float> || std::is_same_v<T, int>;

// Checks whether the type is 'floating-point' type or not
template<typename T>
inline constexpr bool IsFloat = (std::is_floating_point_v<T>) ? true : false;

// Returns the random value in the range of [min, max]
// Takes a 'float' or 'int' template types
template<IsFloatOrInt ValueType>
ValueType GetRandomNumber(ValueType min, ValueType max)
{
	// Chooses the variable type depending on the template type.
	using distribution_type = 
		typename std::conditional_t<IsFloat<ValueType>, std::uniform_real_distribution<float>, std::uniform_int_distribution<int>>;

	// Initialization of Marsenne-Twister random generator using the current time as a seed
	std::mt19937 randGenerator{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };

	// Useful for creating a uniformly distributed values from a random generator
	distribution_type range{ min, max };
	return range(randGenerator);
}