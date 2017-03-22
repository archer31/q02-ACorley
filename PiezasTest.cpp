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
TEST(PiezasTest, dropPieceSwitchTurn) {
  Piezas pie;
  pie.dropPiece(0);
  ASSERT_EQ((char)pie.dropPiece(0), 'O');
}
TEST(PiezasTest, dropPieceSwitchTurnBack) {
  Piezas pie;
  pie.dropPiece(0);
  pie.dropPiece(0);
  ASSERT_EQ((char)pie.dropPiece(0), 'X');
}
TEST(PiezasTest, pieceAtInBoundsCorner) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(0,0), ' ');
}
TEST(PiezasTest, pieceAtInBoundsBottomEdge) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(0,1), ' ');
}
TEST(PiezasTest, pieceAtInBoundsSideEdge) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(1,0), ' ');
}
TEST(PiezasTest, pieceAtOutOfBoundsCorner) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(-1,-1), '?');
}
TEST(PiezasTest, pieceAtOutOfBoundsBottom) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(0,-1), '?');
}
TEST(PiezasTest, pieceAtOutOfBoundsSide) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(-1,0), '?');
}
TEST(PiezasTest, pieceAtOutOfBoundsAboveCorner) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(4,5), '?');
}
TEST(PiezasTest, pieceAtOutOfBoundsAboveSide) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(3,5), '?');
}
TEST(PiezasTest, pieceAtOutOfBoundsAboveTop) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(4,4), '?');
}
TEST(PiezasTest, pieceAtMid) {
  Piezas pie;
  ASSERT_EQ((char)pie.pieceAt(2,2), ' ');
}
TEST(PiezasTest, pieceAtX) {
  Piezas pie;
  pie.dropPiece(0);
  ASSERT_EQ((char)pie.pieceAt(0,0), 'X');
}
TEST(PiezasTest, pieceAtO) {
  Piezas pie;
  pie.dropPiece(0);
  pie.dropPiece(0);
  ASSERT_EQ((char)pie.pieceAt(1,0), 'O');
}

