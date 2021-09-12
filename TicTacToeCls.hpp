//
//  TicTacToeCls.hpp
//  tic-tac-toe-lib
//
//  Created by Şafak Batuhan Ünver on 11.09.2021.
//

#ifndef TicTacToeCls_hpp
#define TicTacToeCls_hpp

#include <list>

enum TIC_TAC_TOE_RET
{
    TIC_TAC_TOE_RET_OVERWRITE,
    TIC_TAC_TOE_RET_PUSH_SUCCESS,
    TIC_TAC_TOE_RET_INVALID_MARK,
    TIC_TAC_TOE_RET_OUT_OF_RANGE_POS,
    TIC_TAC_TOE_RET_X_WIN,
    TIC_TAC_TOE_RET_O_WIN,
    TIC_TAC_TOE_RET_PUSH_TURN_ERROR,
    TIC_TAC_TOE_RET_UNDEFINED
};

enum GAME_STATE
{
    GAME_STATE_CONTINUE,
    GAME_STATE_X_WIN,
    GAME_STATE_O_WIN
};

class TicTacToe
{
private:
    char* gameBoard;
    unsigned int gameSize;
    char gameTurn;
    void initWithEmptyMarks();
    bool isMarkValid(char mark);
    bool isPosValid(unsigned int posX, unsigned int posY);
    bool isPosOverwriteable(unsigned int posX, unsigned int posY);
    bool isOverwriteable(unsigned int posX, unsigned int posY);
    void setMark(char mark, unsigned int posX, unsigned int posY);
    GAME_STATE getGameState();
    GAME_STATE checkHorizontal();
    GAME_STATE checkVertical();
    GAME_STATE checkLeftDiagonal();
    GAME_STATE checkRightDiagonal();
    bool isGameTurnOk(char mark);
public:
    TicTacToe(unsigned int size);
    const char* getGameBoard() const;
    TIC_TAC_TOE_RET push(char mark, unsigned int posX, unsigned int posY);
};

#endif /* TicTacToeCls_hpp */
