/*
 * =====================================================================================
 *
 *       Filename:  non_copyable.hpp
 *
 *    Description:  non-copyable
 *
 *        Version:  1.0
 *        Created:  2016/04/06 01时19分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hualin xia (http://swn73.github.io/xiahualin/), hua_lin@live.cn
 *   Organization:  
 *
 * =====================================================================================
 */

namespace xhl{

  /*
   * =====================================================================================
   *        Class:  NoCopy
   *  Description:  non-copyable
   * =====================================================================================
   */
  class NoCopy
  {
    public:
      NoCopy ();                             /* constructor */

    private:
      NoCopy(const NoCopy& other) = delete;
      NoCopy& operator=(const NoCopy&) = delete;

  }; /* -----  end of class NoCopy  ----- */

}
