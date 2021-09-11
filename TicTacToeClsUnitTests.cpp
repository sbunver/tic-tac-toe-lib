//
//  TicTacToeClsUnitTests.cpp
//  tic-tac-toe-lib
//
//  Created by Şafak Batuhan Ünver on 11.09.2021.
//

#include <gtest/gtest.h>
#include "TicTacToeCls.hpp"

TEST(TTTUnitTests, constructGameBoard)
{
    TicTacToe game(3);
    const char* gameBoard = game.getGameBoard();
    
    for(int i = 0; i < 3 * 3; i++)
    {
        GTEST_ASSERT_EQ(gameBoard[i], 'E');
    }
}

TEST(TTTUnitTests, INVALID_MARK)
{
    TicTacToe game(5);
    
    GTEST_ASSERT_EQ(game.push('I', 0, 0), TIC_TAC_TOE_RET_INVALID_MARK);
}

TEST(TTTUnitTests, OUT_OF_RANGE_POS)
{
    TicTacToe game(3);
    
    GTEST_ASSERT_EQ(game.push('X', 40, 0), TIC_TAC_TOE_RET_OUT_OF_RANGE_POS);
}

TEST(TTTUnitTests, X_WIN_HORZ_TEST1)
{
    TicTacToe game(3);
    
    GTEST_ASSERT_EQ(game.push('X', 0, 0), TIC_TAC_TOE_RET_PUSH_SUCCESS);
    GTEST_ASSERT_EQ(game.push('X', 0, 1), TIC_TAC_TOE_RET_PUSH_SUCCESS);
    GTEST_ASSERT_EQ(game.push('X', 0, 2), TIC_TAC_TOE_RET_X_WIN);
}

TEST(TTTUnitTests, X_WIN_VERT_TEST1)
{
    TicTacToe game(3);
    
    GTEST_ASSERT_EQ(game.push('X', 0, 0), TIC_TAC_TOE_RET_PUSH_SUCCESS);
    GTEST_ASSERT_EQ(game.push('X', 1, 0), TIC_TAC_TOE_RET_PUSH_SUCCESS);
    GTEST_ASSERT_EQ(game.push('X', 2, 0), TIC_TAC_TOE_RET_X_WIN);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
