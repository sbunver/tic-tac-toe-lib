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
    gameBoard = (char*)malloc(gameSize * gameSize);
    initWithEmptyMarks();
}

void TicTacToe::initWithEmptyMarks()
{
    for(int i = 0; i < gameSize * gameSize; i++)
    {
        gameBoard[i] = 'E';
    }
}

const char* TicTacToe::getGameBoard() const
{
    return gameBoard;
}

bool TicTacToe::isMarkValid(char mark)
{
    return (mark == 'X') || (mark == 'O');
}

bool TicTacToe::isPosValid(unsigned int posX, unsigned int posY)
{
    return (posX <= gameSize) && (posY <= gameSize);
}

bool TicTacToe::isOverwriteable(unsigned int posX, unsigned int posY)
{
    return (gameBoard[(posX * gameSize) + posY] != 'E');
}

void TicTacToe::setMark(char mark, unsigned int posX, unsigned int posY)
{
    gameBoard[(posX * gameSize) + posY] = mark;
}

GAME_STATE TicTacToe::checkRightDiagonal()
{
    char mark = gameBoard[gameSize - 1];
    bool win = 1;
    int col = gameSize - 1;
    int row = 0;
    
    while(row < gameSize && col >= 0)
    {
        if(gameBoard[row * gameSize + col] != mark)
        {
            win = 0;
        }
        row += 1;
        col -= 1;
    }
    if(win)
    {
        if(mark == 'X')
        {
            return GAME_STATE_X_WIN;
        }
        else if(mark == 'O')
        {
            return GAME_STATE_O_WIN;
        }
    }
    return GAME_STATE_CONTINUE;
}

GAME_STATE TicTacToe::checkLeftDiagonal()
{
    char mark = gameBoard[0];
    bool win = 1;
    int col = 1;
    int row = 1;
    
    while(row < gameSize && col < gameSize)
    {
        if(gameBoard[row * gameSize + col] != mark)
        {
            win = 0;
        }
        row += 1;
        col += 1;
    }
    if(win)
    {
        if(mark == 'X')
        {
            return GAME_STATE_X_WIN;
        }
        else if(mark == 'O')
        {
            return GAME_STATE_O_WIN;
        }
    }
    return GAME_STATE_CONTINUE;
}

GAME_STATE TicTacToe::checkVertical()
{
    char mark = 'E';
    bool win = 1;
 
    for(int i = 0; i < gameSize ; i++)
    {
        mark = gameBoard[0 * gameSize + i];
        
        for(int j = 1; j < gameSize; j++)
        {
            if(gameBoard[j * gameSize + i] != mark)
            {
                win = 0;
            }
        }
        
        if(win)
        {
            if(mark == 'X')
            {
                return GAME_STATE_X_WIN;
            }
            else if(mark == 'O')
            {
                return GAME_STATE_O_WIN;
            }
        }
        else
        {
            win = true;
        }
    }
    return GAME_STATE_CONTINUE;
}

GAME_STATE TicTacToe::checkHorizontal()
{
    char mark = 'E';
    bool win = 1;
 
    for(int i = 0; i < gameSize ; i++)
    {
        mark = gameBoard[i * gameSize + 0];
        
        for(int j = 1; j < gameSize; j++)
        {
            if(gameBoard[i * gameSize + j] != mark)
            {
                win = 0;
            }
        }
        
        if(win)
        {
            if(mark == 'X')
            {
                return GAME_STATE_X_WIN;
            }
            else if(mark == 'O')
            {
                return GAME_STATE_O_WIN;
            }
        }
        else
        {
            win = true;
        }
    }
    return GAME_STATE_CONTINUE;
}

GAME_STATE TicTacToe::getGameState()
{
    GAME_STATE horzState = checkHorizontal();
    GAME_STATE vertState = checkVertical();
    GAME_STATE leftDiagState = checkLeftDiagonal();
    GAME_STATE rightDiagState = checkRightDiagonal();
    
    if(horzState != GAME_STATE_CONTINUE)
    {
        return horzState;
    }
    else if(vertState != GAME_STATE_CONTINUE)
    {
        return vertState;
    }
    else if (leftDiagState != GAME_STATE_CONTINUE)
    {
        return leftDiagState;
    }
    else if (rightDiagState != GAME_STATE_CONTINUE)
    {
        return rightDiagState;
    }
    else
    {
        return GAME_STATE_CONTINUE;
    }
}

TIC_TAC_TOE_RET TicTacToe::push(char mark, unsigned int posX, unsigned int posY)
{
    GAME_STATE gameState;
    
    if(!isMarkValid(mark))
    {
        return TIC_TAC_TOE_RET_INVALID_MARK;
    }
    
    if(!isPosValid(posX, posY))
    {
        return TIC_TAC_TOE_RET_OUT_OF_RANGE_POS;
    }
    
    if(isOverwriteable(posX, posY))
    {
        return TIC_TAC_TOE_RET_OVERWRITE;
    }
    
    setMark(mark, posX, posY);
    
    gameState = getGameState();
    
    if(gameState == GAME_STATE_X_WIN)
    {
        return TIC_TAC_TOE_RET_X_WIN;
    }
    else if(gameState == GAME_STATE_O_WIN)
    {
        return TIC_TAC_TOE_RET_O_WIN;
    }
    else if(gameState == GAME_STATE_CONTINUE)
    {
        return TIC_TAC_TOE_RET_PUSH_SUCCESS;
    }
    
    return TIC_TAC_TOE_RET_UNDEFINED;
}

