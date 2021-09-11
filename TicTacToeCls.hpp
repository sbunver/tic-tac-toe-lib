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
    TIC_TAC_TOE_RET_OUT_OF_RANGE_POS
};

class TicTacToe
{
private:
    char* gameBoard;
    unsigned int gameSize;
    void initWithEmptyMarks();
    bool isMarkValid(char mark);
    bool isPosValid(unsigned int posX, unsigned int posY);
    bool isPosOverwriteable(unsigned int posX, unsigned int posY);
    bool isOverwriteable(unsigned int posX, unsigned int posY);
public:
    TicTacToe(unsigned int size);
    const char* getGameBoard() const;
    TIC_TAC_TOE_RET push(char mark, unsigned int posX, unsigned int posY);
};

#endif /* TicTacToeCls_hpp */
