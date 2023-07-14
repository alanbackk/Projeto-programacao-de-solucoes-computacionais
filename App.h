#include <iostream>
#include <string>
#include "AppFunc.h"

using namespace std;

class App:public AppFunc {
public:
  void start();
  void run();
  void finish();
};