template<typename T>
T popcount(T x)
{
  T res = 0;
  for (; x; ++res)
    x &= x - 1;
  return res;
}
