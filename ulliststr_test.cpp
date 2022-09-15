/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include "ulliststr.cpp"
#include <bits/stdc++.h>

using namespace std;


int main(int argc, char* argv[])
{
  ULListStr a = ULListStr();
  for (int i = 0; i < 20; i++) a.push_back(to_string(i));
  for (int i = 20; i < 40; i++) a.push_front(to_string(i));
  cout << "size = "  << a.size() << endl;
  cout << "front = " << a.front() << endl;
  cout << "back = " << a.back() << endl;
  for (int i = 0; i < 10; i++) a.pop_back();
  cout << a.size() << endl;
  for (int i = 0; i < 29; i++) a.pop_front();
  cout << "size = "  << a.size() << endl;
  cout << "front = " << a.front() << endl;
  cout << "back = " << a.back() << endl;
  a.pop_back();
  cout << "size = "  << a.size() << endl;
  return 0;
}
