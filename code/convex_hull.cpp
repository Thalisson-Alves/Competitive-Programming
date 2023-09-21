template<const bool include_collinear=false, typename T>
vector<Point<T>> convex_hull(vector<Point<T>> pts)
{
  if (pts.size() == 1) return pts;
 
  sort(all(pts));
  auto p1 = pts[0], p2 = pts.back();
  vector<Point<T>> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for (size_t i = 1; i < pts.size(); i++)
  {
    if (i == pts.size() - 1 or cw<include_collinear>(p1, pts[i], p2))
    {
      while (up.size() >= 2 and !cw<include_collinear>(up[up.size()-2], up[up.size()-1], pts[i]))
        up.pop_back();
      up.push_back(pts[i]);
    }
    if (i == pts.size() - 1 or ccw<include_collinear>(p1, pts[i], p2))
    {
      while (down.size() >= 2 and !ccw<include_collinear>(down[down.size()-2], down[down.size()-1], pts[i]))
        down.pop_back();
      down.push_back(pts[i]);
    }
  }
 
  if constexpr (include_collinear)
  {
    if (up.size() == pts.size())
    {
      reverse(all(pts));
      return pts;
    }
  }
 
  up.insert(up.end(), down.rbegin() + 1, down.rend() - 1);
  return up;
}
