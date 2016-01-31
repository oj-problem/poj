/**
 * POJ probem 3624: 0/1 knapsack algorithm
 * Basically, use brute force search method (dfs).
 * A better way is to use DP.
 *
 * hellfire (asyncloading#163.com)
 * Jan 31th, 2016
 */

#include<iostream>
using namespace std;

int n;
int m;
int w[3402];                /* Weight. */
int d[3402];                /* Value. */           
int mem[3402][12880];       /* Memory array. */

int dfs(int i, int j)
{
  int res;
  if (mem[i][j] >= 0)
  {
    return mem[i][j];
  }
  if (i == n)
  {
    res = 0;
  }
  else if (w[i] > j )
  {
    res = dfs(i + 1, j);
  }
  else 
  {
    res = max(dfs(i + 1, j), dfs(i + 1, j - w[i]) + d[i]);
  }
  return mem[i][j] = res;
}

int main(int argc, char **argv)
{
  memset(mem, -1, sizeof(mem));
  cin >> n >> m;
  int k;
  for (k = 0; k < n; k ++)
  {
    cin >> w[k] >> d[k];
  }
  int result = dfs(0, m);
  cout << result << endl;
}
