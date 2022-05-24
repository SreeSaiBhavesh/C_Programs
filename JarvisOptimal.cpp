#include <bits/stdc++.h>
using namespace std; 
struct Point					// To store the co-ordinates of every point
{
    int x, y;
} ;

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; 	 // colinear
    return (val > 0)? 1: 2; 	// clock or counterclock wise
}
// Prints convex hull of a set of n points
void convexHull(Point points[], int n)
	{
    // There must be at least 3 points
    if (n < 3) return;
    // Initialize Result
    vector<Point> hull;
    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    
    int p = l, q;
    do
    {
        // Add current point to result
        hull.push_back(points[p]);
        
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
           
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
       
        p = q;
    } while (p != l);  // While we don't come to first point
    // Print Result
    for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n";
}
// Driver program to test above functions
int main()
{
    Point points[] = {{-7,8},{-4,6},{2,6},{6,4},{8,6},{7,-2},{4,-6},{8,-7},{0,0},
      {3,-2},{6,-10},{0,-6},{-9,-5},{-8,-2},{-8,0},{-10,3},{-2,2},{-10,4}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
