/**
 * POJ 1852: Ants
 *
 * hellfire (asyncloading#163.com)
 * Jan 30th, 2016
 */

#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
  int i;      
  int count;                /* Input cases count. */
  cin >> count;

  for (i = 0; i < count; i ++)
  {
    int l;             /* The length of pole. */
    int n;             /* The quantites of ants. */

    cin >> l >> n;
    
    int j;
    int min_t = 0;     /* The earliest time is each ant go to nearest side. */
    int max_t = 0;     /* The latest time is each ant go to farest side. */
    for (j = 0; j < n; j ++)
    {
      int ant;
      cin >> ant;
      min_t = max(min_t, min(ant, l - ant));
      max_t = max(max_t, max(ant, l - ant));
    }
    cout << min_t << ' ' << max_t << endl;
  }
}
