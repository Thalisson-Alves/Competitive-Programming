#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()

namespace rng {
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  uniform_real_distribution<double> dist(0.0, 1.0);

  inline void set_seed(int seed) { mt.seed(seed); }

  inline double next_double() { return dist(mt); }
  inline double next_double(double l, double r) {
    assert(l <= r);
    return l + next_double() * (r - l);
  }
  template<typename T, typename = typename enable_if<is_integral<T>::value>::type> inline T next_int(T r) {
    assert(r > 0);
    return T(mt() % r);
  }
  template<typename T, typename = typename enable_if<is_integral<T>::value>::type> inline T next_int(T l, T r) {
    assert(l <= r);
    return l + (T)(mt() % (r - l + 1));
  }

  template<typename T> inline void shuffle(vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
      int j = next_int(i, (int)v.size() - 1);
      swap(v[i], v[j]);
    }
  }

  template<typename T> inline T choose(const vector<T> &v) { return v[next_int((int)v.size())]; }
  template<typename T> inline T choose(const initializer_list<T> &v) { return *next(v.begin(), next_int((int)v.size())); }

  template<typename T> inline vector<T> sample(const vector<T> &v, int k) {
    vector<int> idx((int)v.size());
    iota(idx.begin(), idx.end(), 0);
    shuffle(idx);
    vector<T> ans(k);
    for (int i = 0; i < k; i++) ans[i] = v[idx[i]];
    return ans;
  }
}

struct Args {
  int number_of_cases;
  bool include_number_of_cases;
  int seed;

  Args() : number_of_cases(1), seed((int)chrono::steady_clock::now().time_since_epoch().count()) {}
} args;


void help() {
  cout << "Usage: ./generator [options]" << '\n';
  cout << "Options:" << '\n';
  cout << "  -n, --number-of-cases <number>  Number of test cases (default: 1)" << '\n';
  cout << "  -i, --include-number-of-cases   Include number of test cases in the first line" << '\n';
  cout << "  -s, --seed <number>             Seed (default: current time)" << '\n';
  cout << "  -h, --help                      Print this help message" << '\n';
  exit(0);
}

Args parse_args(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    string arg(argv[i]);
    if (arg == "-n" or arg == "--number-of-cases") {
      if (i+1 >= argc) {
        cerr << "Missing number of cases" << '\n';
        exit(1);
      }
      args.number_of_cases = stoi(argv[++i]);
    } else if (arg == "-i" or arg == "--include-number-of-cases") {
      args.include_number_of_cases = true;
    } else if (arg == "-s" or arg == "--seed") {
      if (i+1 >= argc) {
        cerr << "Missing seed" << '\n';
        exit(1);
      }
      args.seed = stoi(argv[++i]);
    } else if (arg == "-h" or arg == "--help") {
      help();
      exit(0);
    } else {
      cerr << "Unknown option: " << arg << '\n';
      exit(1);
    }
  }

  return args;
}

string test_generator();
int main(int argc, char *argv[]) {
  args = parse_args(argc, argv);
  rng::set_seed(args.seed);

  if (args.include_number_of_cases) {
    cout << args.number_of_cases << '\n';
  }
  for (int i = 0; i < args.number_of_cases; i++) {
    cout << test_generator();
  }

  return 0;
}

string test_generator() {
  stringstream ss;

  return ss.str();
}
