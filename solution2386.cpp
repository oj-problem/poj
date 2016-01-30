/**
 * POJ problem 2386: lake counting.
 *
 * hellfire (asyncloading#163.com)
 * Jan 30th, 2016
 */

#include<iostream>

using namespace std;

void dfs(int x, int y);

int n;
int m;

char martix[100][100];

int main(int argc, char **argv)
{
  int i;
  int j;
  int count = 0;


  cin >> n >> m;

  /* Get characters input */
  for (i = 0; i <n; i ++)
  {
    for (j = 0; j < m; j ++)
    {
      cin >> martix[i][j];
    } 
  }

  for (i = 0; i < n; i ++)
  {
    for (j = 0; j < m; j ++)
    {
      if (martix[i][j] == 'W')
      {
        dfs(i, j);
        count ++;
      } 
    }
  }
  cout << count << endl;
}

void dfs(int x, int y)
{
  /* Change curren position state */
  martix[x][y] = '.';

  /* Express eight direction. */
  int dx;
  int dy;
  for (dx = -1; dx <= 1; dx ++)
  {
    for (dy = -1; dy <= 1;  dy ++)
    {
      int nx = x + dx;
      int ny = y + dy;
      /* Judge wether the point is in field and is adjacent to its neighbors. */
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && martix[nx][ny] == 'W')
      {
        dfs(nx, ny);
      }
    }
  }
}
