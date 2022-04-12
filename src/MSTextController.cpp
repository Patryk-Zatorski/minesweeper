#include "MSTextController.hpp"
#include "MSBoardTextView.hpp"
#include "MinesweeperBoard.hpp"
#include <iostream>

using namespace std;

MSTextController::MSTextController(MinesweeperBoard &gameboard, MSBoardTextView &gameview):board{gameboard},view{gameview}
{}
void MSTextController::play()
{
    int col,row;
    char playerInput;
    
    while(board.getGameState()==GameState::RUNNING)
    {
        system("clear");
        view.display();
        cout<<endl<<"Wybierz rzad w ktorym chcesz wykonac akcje(1-"<<board.getBoardHeight()<<")"<<endl;
        cin>>row;
        
        //checks if player input is correct
        while(row>board.getBoardHeight() || row<1)
        {
            cout<<"niepoprawna wartosc!"<<endl;
            cin>>row;
        }

        cout<<endl<<"Wybierz kolumne w ktorej chcesz wykonac akcje(1-"<<board.getBoardWidth()<<")"<<endl;
        cin>>col;
        
        //checks if player input is correct
        while(col>board.getBoardWidth() || col<1)
        {
            cout<<"niepoprawna wartosc!"<<endl;
            cin>>col;
        }

        col--;
        row--;

        cout<<endl<<"Wpisz [P] aby odkryc pole lub [F] aby postawic/sciagnac flage"<<endl;
        cin>>playerInput;

        //checks if player input is correct
        while(playerInput!='P'&& playerInput!='F')
        {
            cout<<"niepoprawna wartosc!"<<endl;
            cin>>playerInput;
        }

        //makes the move
        if(playerInput=='P')
        {
            board.revealField(row,col);
        }
        else
        {
            board.toggleFlag(row,col);
        }
    }
    if(board.getGameState()==GameState::FINISHED_WIN){cout<<endl<<"Zwyciestwo!!!";}
    else{cout<<endl<<"Przegrales :(";}
}