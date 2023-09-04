bool feq(double a, double b)
{
  static double EPS = 1e-6;
  return fabs(a-b) < EPS;
}
