#include <Windows.h>
#include <iostream>
#include <thread>
#include <conio.h>
#include <sstream>


void createPlace(int& _heightPlace, int& _widthPlace, std::string** _place)
{
    for (int i = 0; i < _heightPlace; i++)
    {
        if (i == _heightPlace - 1)
        {
            for (int j = 0; j < _widthPlace; j++)
                _place[i][j] = '_';
            break;
        }
        for (int j = 0; j < _widthPlace; j++)
            _place[i][j] = ' ';

    }
}

void printConsole(int& _heightPlace, int& _widthPlace, std::string** _place)
{
    for (int i = 0; i < _heightPlace; i++)
    {
        for (int j = 0; j < _widthPlace; j++)
            std::cout << _place[i][j];
        std::cout << '\n';

    }
}
void redrawPlace(int& _heightPlace, int& _widthPlace, std::string** _place)
{
    if (_place[_heightPlace - 1][_widthPlace - 1] == "|")
    {
        for (int i = 0; i < _widthPlace; i++)
        {
            if (i % 2 == 0)
                _place[_heightPlace - 1][i] = "|";
            else
            {
                _place[_heightPlace - 1][i] = "_";
            }
        }
    }
    else
    {
        for (int i = 0; i < _widthPlace; i++)
        {
            if (i % 2 == 0)
                _place[_heightPlace - 1][i] = "_";
            else
            {
                _place[_heightPlace - 1][i] = "|";
            }
        }
    }
}

void messages(bool &_admin)
{
    if (_kbhit())
    {
        auto lol = _getch();
        if (lol == 27)
            _admin = true;
        lol = _getch();
            if (lol == 72) // UP
        {
         
        }
        if (lol == 80) // DOWN
        {

        }
    }

}

std::string** createString(int& _heightPlace, int& _widthPlace)
{
    std::string** place = new std::string * [_heightPlace];
    for (int i = 0; i < _heightPlace; i++)
        place[i] = new std::string[_widthPlace];
    return place;
}
void adminMessage(int& _heightPlace, int& _widthPlace, std::string** _place, int& _scalePlace, bool& _admin)
{
    while (true)
    {


        std::string inputMsg = "";
        std::string comandMsg;
        std::cin >> inputMsg;

        if (inputMsg == "/help")
        {
            std::cout << "\n/setScalePlace - rescaling map: \n" \
                      << "";
            continue;
        }
        
        for (int i = 0; i < inputMsg.length(); i++)
            if (inputMsg[i] != ':')
                comandMsg += inputMsg[i];
            else
                break;
        if (comandMsg == "/setScalePlace")
        {
            delete _place;
            _scalePlace = std::stoi(&inputMsg[inputMsg.length() - 1]);
            _heightPlace = 5 * _scalePlace;
            _widthPlace = 10 * _scalePlace;
            _place = createString(_heightPlace, _widthPlace);
            createPlace(_heightPlace, _widthPlace, _place);
            //printConsole(_heightPlace, _widthPlace, _place);
            _admin = false;
            break;
        }
        //else if ()
        //{

        //}
    }
}

int main()
{
    int scalePlace = 1;
    int heightPlace = 5 * scalePlace;
    int widthPlace = 10 * scalePlace;

    std::string** place = createString(heightPlace, widthPlace);
    bool admin = false;
    


    createPlace(heightPlace, widthPlace, place);
    std::thread th([&]()
        {
            while (true)
            {
                messages(admin);
            }
        });






    while (true)
    {
        redrawPlace(heightPlace, widthPlace, place);
        system("cls");
        printConsole(heightPlace, widthPlace, place);
        if (admin)
            adminMessage(heightPlace, widthPlace, place,scalePlace,admin);

        Sleep(100);
    }
    //return 0;
}

