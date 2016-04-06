/*
 * =====================================================================================
 *
 *       Filename:  t_singleton.cpp
 *
 *    Description:  unit test of singleton
 *
 *        Version:  1.0
 *        Created:  2016/04/06 11时52分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hualin xia (http://swn73.github.io/xiahualin/), hua_lin@live.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#include "../base/singleton.hpp"
#include <iostream>
#include <thread>

class A{
public:
  int d;
  char c;
  A():d(8),c('@'){}
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
  
  std::cout<<xhl::Singleton<A>::getInstance().d<<std::endl;
  
  return 0;
}				/* ----------  end of function main  ---------- */
