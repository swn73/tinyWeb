/*
 * =====================================================================================
 *
 *       Filename:  rb_tree.hpp
 *
 *    Description:  rb tree
 *
 *        Version:  1.0
 *        Created:  2016/04/06 15时16分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hualin xia (http://swn73.github.io/xiahualin/), hua_lin@live.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#include <map>


namespace xhl{

  /*
   * =====================================================================================
   *        Class:  RbTree
   *  Description:  rb tree
   * =====================================================================================
   */
  template < class Key, class Value >
    class RbTree
    {
      public:
        /* ====================  LIFECYCLE     ======================================= */
        RbTree ();                             /* constructor */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

      protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

      private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */
        std::map<Key,Value> tree;

    }; /* ----------  end of template class RbTree  ---------- */
}
