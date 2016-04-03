/*
 * =====================================================================================
 *
 *       Filename:  singleton.hpp
 *
 *    Description:  singleton holder
 *
 *        Version:  1.0
 *        Created:  2016/04/03 17时22分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  hualin xia (http://swn73.github.io/xiahualin/), hua_lin@live.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef SINGLETON_H
#define SINGLETON_H


/* 
 * =====================================================================================
 *        Class:  Singleton
 *  Description:  singleton
 * =====================================================================================
 */

template < class T >
class Singleton
{
  public:
    // ====================  LIFECYCLE     =======================================
    Singleton (){};                                               /* constructor      */
    Singleton ( const Singleton &other ) = delete;                /* copy constructor */
    ~Singleton ();                                                /* destructor       */

    /* ====================  OPERATORS     ======================================= */
    Singleton& operator = ( const Singleton &other ) = delete;    // assignment operator

    /* ====================  ACCESSORS     ======================================= */
    static T& getInstance(){
      static T instance;
      return instance;
    }

  protected:
    /* ====================  METHODS       ======================================= */

    /* ====================  DATA MEMBERS  ======================================= */

  private:
    /* ====================  METHODS       ======================================= */

    /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of template class Singleton  ----- */

#endif // SINGLETON_H
