//
//  TicTacToeCls.cpp
//  tic-tac-toe-lib
//
//  Created by Şafak Batuhan Ünver on 11.09.2021.
//

#include "TicTacToeCls.hpp"

TicTacToe::TicTacToe(unsigned int size)
{
    gameSize = size;
    gameBoard.resize(gameSize);
    initWithEmptyMarks();
}

void TicTacToe::initWithEmptyMarks()
{
    for(auto& g : gameBoard)
    {
        for(int i = 0; i < gameSize; i++)
        {
            g.push_back('E');
        }
    }
}

std::list<std::list<char>> TicTacToe::getGameBoard() const
{
    return gameBoard;
}

bool TicTacToe::isMarkValid(char mark)
{
    return (mark == 'X') || (mark == 'O');
}

bool TicTacToe::isPosValid(unsigned int posX, unsigned int posY)
{
    return (posX > gameSize) || (posY > gameSize);
}

TIC_TAC_TOE_RET TicTacToe::push(char mark, unsigned int posX, unsigned int posY)
{
    if(!isMarkValid(mark))
    {
        return TIC_TAC_TOE_RET_INVALID_MARK;
    }
    
    if(!isPosValid(posX, posY))
    {
        return TIC_TAC_TOE_RET_OUT_OF_RANGE_POS;
    }
    
    return TIC_TAC_TOE_RET_PUSH_SUCCESS;
}

