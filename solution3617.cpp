/**
 * POJ problem 3617: Best cow line.
 * Use greedy algorithm.
 * 
 * hellfire (asyncloading#163.com)
 * Jan 31st, 2016
 */
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
  int i;
  int n;
  cin >> n;
  char str[2000];

  for (i = 0; i < n; i ++)
  {
    cin >> str[i];    
  }

  int a = 0;
  int b = n - 1;

  bool left = false;

  int count = 0;

  while (a <= b)
  {
    for (i = 0; a + i <= b - i; i ++)
    {
      if(str[a + i] < str[b - i])
      {
        left = true;
        break;        
      }
      else if (str[a + i] > str[b - i])
      {
        left = false;
        break;
      }
    }
    if (left)
    {
      cout << str[a ++];
    }
    else
    {
      cout << str[b --];
    }
    count ++;
    if (count % 80 == 0)
    {
      cout << endl;
    }
  }
  cout << endl;   
}
