#include <bitset>
#include <algorithm>

#include "cppunit/cppunit_proxy.h"

#if !defined (STLPORT) || defined(_STLP_USE_NAMESPACES)
using namespace std;
#endif

//
// TestCase class
//
class BitsetTest : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(BitsetTest);
  CPPUNIT_TEST(bitset1);
  CPPUNIT_TEST_SUITE_END();

protected:
  void bitset1();
  static void disp_bitset(char const* pname, bitset<13U> const& bset);
};

CPPUNIT_TEST_SUITE_REGISTRATION(BitsetTest);

//
// tests implementation
//
void BitsetTest::bitset1()
{
  bitset<13U> b1(0xFFFF);
  bitset<13U> b2(0x1111);
  CPPUNIT_ASSERT(b1.size() == 13);
  CPPUNIT_ASSERT(b1 == 0x1FFF);
  CPPUNIT_ASSERT(b2.size() == 13);
  CPPUNIT_ASSERT(b2 == 0x1111);

#if !defined (STLPORT) || !defined (_STLP_NON_TYPE_TMPL_PARAM_BUG)
  b1 = b1 ^ (b2 << 2);
  CPPUNIT_ASSERT(b1 == 0x1BBB);

  CPPUNIT_ASSERT(b1.count() == 10);
  CPPUNIT_ASSERT(b2.count() == 4);

#  if defined (STLPORT) && !defined (_STLP_NO_EXTENSIONS)
  size_t __pos = b2._Find_first();
  CPPUNIT_ASSERT( __pos == 0 );
  __pos = b2._Find_next(__pos);
  CPPUNIT_ASSERT( __pos == 4 );
  __pos = b2._Find_next(__pos);
  CPPUNIT_ASSERT( __pos == 8 );
  __pos = b2._Find_next(__pos);
  CPPUNIT_ASSERT( __pos == 12 );
  __pos = b2._Find_next(__pos);
  CPPUNIT_ASSERT( __pos == 13 );
#  endif
#endif
}
