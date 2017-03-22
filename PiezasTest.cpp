/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, dropPieceLowerEdge) {
	Piezas pie;
  ASSERT_EQ((char)pie.dropPiece(0), 'X');
}
TEST(PiezasTest, dropPieceUpperEdge) {
  Piezas pie;
  ASSERT_EQ((char)pie.dropPiece(3), 'X');
}
TEST(PiezasTest, dropPieceMid) {
  Piezas pie;
  ASSERT_EQ((char)pie.dropPiece(2), 'X');
}
TEST(PiezasTest, dropPieceOutOfBoundsBelow) {
  Piezas pie;
  ASSERT_EQ((char)pie.dropPiece(-1), '?');
}
TEST(PiezasTest, dropPieceOutOfBoundsAbove) {
  Piezas pie;
  ASSERT_EQ((char)pie.dropPiece(5), '?');
}
TEST(PiezasTest, dropPieceColumnFull) {
  Piezas pie;
  pie.dropPiece(0);
  pie.dropPiece(0);
  pie.dropPiece(0);
  ASSERT_EQ((char)pie.dropPiece(0), ' ');
}
