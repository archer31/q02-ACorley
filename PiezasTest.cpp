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

static bool checkAllEqual(Piezas pie, char expect) {
  for (unsigned int row = 0; row < 3; row++) {
    for (unsigned int col = 0; col < 4; col++) {
      if (!((char)pie.pieceAt(row, col) == expect)) return false;
    }
  }
  return true;
}

TEST(PiezasTest, constructor) {
  Piezas pie;
  ASSERT_TRUE(checkAllEqual(pie, ' '));
}
TEST(PiezasTest, dropPiece_LowerEdge) {
	Piezas pie;
  ASSERT_EQ((char)pie.dropPiece(0), 'X');
}
TEST(PiezasTest, dropPiece_UpperEdge) {
  Piezas pie;
  ASSERT_EQ((char)pie.dropPiece(3), 'X');
}
TEST(PiezasTest, dropPiece_Mid) {
  Piezas pie;
  ASSERT_EQ((char)pie.dropPiece(2), 'X');
}
TEST(PiezasTest, dropPiece_OutOfBoundsBelow) {
  Piezas pie;
  ASSERT_EQ((char)pie.dropPiece(-1), '?');
}
TEST(PiezasTest, dropPiece_OutOfBoundsAbove) {
  Piezas pie;
  ASSERT_EQ((char)pie.dropPiece(5), '?');
}
TEST(PiezasTest, dropPiece_ColumnFull) {
  Piezas pie;
  pie.dropPiece(0);
  pie.dropPiece(0);
  pie.dropPiece(0);
  ASSERT_EQ((char)pie.dropPiece(0), ' ');
}
TEST(PiezasTest, dropPiece_SwitchTurn) {
  Piezas pie;
  pie.dropPiece(0);
  ASSERT_EQ((char)pie.dropPiece(0), 'O');
}
TEST(PiezasTest, dropPiece_SwitchTurnBack) {
  Piezas pie;
  pie.dropPiece(0);
  pie.dropPiece(0);
  ASSERT_EQ((char)pie.dropPiece(0), 'X');
}
TEST(PiezasTest, pieceAt_InBoundsCorner) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(0,0), ' ');
}
TEST(PiezasTest, pieceAt_InBoundsBottomEdge) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(0,1), ' ');
}
TEST(PiezasTest, pieceAt_InBoundsSideEdge) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(1,0), ' ');
}
TEST(PiezasTest, pieceAt_OutOfBoundsCorner) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(-1,-1), '?');
}
TEST(PiezasTest, pieceAt_OutOfBoundsBottom) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(0,-1), '?');
}
TEST(PiezasTest, pieceAt_OutOfBoundsSide) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(-1,0), '?');
}
TEST(PiezasTest, pieceAt_OutOfBoundsAboveCorner) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(4,5), '?');
}
TEST(PiezasTest, pieceAt_OutOfBoundsAboveSide) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(3,5), '?');
}
TEST(PiezasTest, pieceAt_OutOfBoundsAboveTop) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(4,4), '?');
}
TEST(PiezasTest, pieceAt_Mid) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(2,2), ' ');
}
TEST(PiezasTest, pieceAt_X) {
  Piezas pie;
  pie.dropPiece(0);
  ASSERT_EQ((char)pie.pieceAt(0,0), 'X');
}
TEST(PiezasTest, pieceAt_O) {
  Piezas pie;
  pie.dropPiece(0);
  pie.dropPiece(0);
  ASSERT_EQ((char)pie.pieceAt(1,0), 'O');
}
TEST(PiezasTest, reset_BlankAlready) {
  Piezas pie;
  pie.reset();
  ASSERT_TRUE(checkAllEqual(pie, ' '));
}
TEST(PiezasTest, reset_Full) {
  Piezas pie;
  for (unsigned int row = 0; row < 3; row++) {
    for (unsigned int col = 0; col < 4; col++) {
      pie.dropPiece(col);
    }
  }
  pie.reset();
  ASSERT_TRUE(checkAllEqual(pie, ' '));
}

