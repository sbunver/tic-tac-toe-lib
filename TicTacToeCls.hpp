//
//  TicTacToeCls.hpp
//  tic-tac-toe-lib
//
//  Created by Şafak Batuhan Ünver on 11.09.2021.
//

#ifndef TicTacToeCls_hpp
#define TicTacToeCls_hpp

#include <list>

class TicTacToe
{
private:
    std::list<std::list<char>> gameBoard;
    unsigned int gameSize;
    void initWithEmptyMarks();
public:
    TicTacToe(unsigned int size);
    std::list<std::list<char>> getGameBoard() const;
};

#endif /* TicTacToeCls_hpp */
