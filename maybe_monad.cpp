// Copyright Owen Maule 2022

#include <functional>
#include <memory>

template<typename a, typename b> using fn = std::function<b(const a&)>;
template<typename a> using maybe = std::shared_ptr<a>;
template<typename a> using nothing = std::shared_ptr<a>;
template<typename a> constexpr auto just = std::make_shared<a>;

template<typename a, typename b>
maybe<b> bind(const maybe<a>& x, const fn<a,b>& f) {
	return x ? f(*x) : nothing<b>();
}

auto add_one = [] (const int& x)->int { return x + 1; };
maybe<int> result = bind<int,int>(just(3), add_one);
maybe<int> result2 = bind<int,int>(nothing<int>(), add_one);
