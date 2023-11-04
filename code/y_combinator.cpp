/*
Used to define recursive lambdas,  first argument is the function itself

auto value = y_combinator([](auto &&gcd, int a, int b) -> int {
  return b ? gcd(b, a % b) : a;
});
*/
template <class Fun> class y_combinator_result {
	Fun fun_;

  public:
	template <class T>
	explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

	template <class... Args> decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
