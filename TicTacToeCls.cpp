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

