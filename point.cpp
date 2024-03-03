#include "point.hpp"
#include <iostream>
#include <vector>

using namespace std;

// geter (return the boat's Id or boat's Size)
int Boat::get(char *info) const
{
    if (info == "id")
        return id;
    else
        return size;
}

/*
    a fonction who return the position information of a boat
    y to return headY
    x to return headX
*/
int Boat::getPosition(char info)
{
    if (info == 'y')
        return headY;
    else if (info == 'x')
        return headX;
    else
        return orientation;
}

// add one touched boat section
void Boat::setTouched(int n)
{
    touched++;
}

// error gestion for Boat.setBoatPosition (test ande add the position if the position is insaid of the map)
int inMap(char *txt)
{
    int tmp(0);
    do
    {
        cout << txt << endl;
        cin >> tmp;
        if (tmp <= 10 && tmp > 0)
            break;
    } while (1);
    return tmp;
}

// fonction adding a boat to the map
void Boat::setBoatPosition()
{
    int tmp;
    cout << "Chouse a boat" << endl;
    cin >> id; // we need to change something beacause we want to get the boat withe that id, not set a new id
    headX = inMap("position line:");
    headY = inMap("position row:");
    for (int i = 0; i < 3; i++)
    {
        if (headY + 1 >= size)
            cout << "0 (North)";
        if (10 - (headY + 1) >= size)
            cout << "1 (South)";
        if (headX + 1 >= size)
            cout << "2 (West)";
        if (10 - (headX + 1) >= size)
            cout << "3 (East)";
        if ((headY + 1 >= size) && (10 - (headY + 1)) >= size && (headX + 1 >= size) && (10 - (headX + 1) >= size))
            cout << "impossible, this boat is too big for that possition" << endl;
    }
    cout << "orientation (North = 0, South = 1, West = 2, East = 3)" << endl;
    cin >> orientation;
}

// orrientation error gestion
int setOrientation(Boat bt)
{
    int o;
    cout << "orientation: " << endl;
    cin >> o;
    switch (o)
    {
    case 0:
        if (bt.getPosition('y') + 1 >= bt.get("size"))
            return o;
        else
            cout << "unexpected valiu, the place isn't enough" << endl;
        return setOrientation(bt);
        break;
    case 1:
        if (10 - (bt.getPosition('y') + 1) >= bt.get("size"))
            return o;
        else
            cout << "unexpected valiu, the place isn't enough" << endl;
        return setOrientation(bt);
        break;
    case 2:
        if (bt.getPosition('x') + 1 >= bt.get("size"))
            return o;
        else
            cout << "unexpected valiu, the place isn't enough" << endl;
        return setOrientation(bt);
        break;
    case 3:
        if (10 - (bt.getPosition('x') + 1) >= bt.get("size"))
            return o;
        else
            cout << "unexpected valiu, the place isn't enough" << endl;
        return setOrientation(bt);
        break;
    default:
        cout << "unexpected valiu" << endl;
        return setOrientation(bt);
        break;
    }
}

// add the boat (bt) to the map
void Map::boatAdd(Boat bt)
{
    int a = bt.getPosition('p');
    switch (a)
    {
    case 0:
        for (int i(0); i < bt.get("size"); i++)
        {
            map[bt.getPosition('y') - i][bt.getPosition('x')] = bt.get("id");
        }
        break;
    case 1:
        for (int i(0); i < bt.get("size"); i++)
        {
            map[bt.getPosition('y') + i][bt.getPosition('x')] = bt.get("id");
        }
        break;
    case 2:
        for (int i(0); i < bt.get("size"); i++)
        {
            map[bt.getPosition('y')][bt.getPosition('x') - i] = bt.get("id");
        }
        break;
    case 3:
        for (int i(0); i < bt.get("size"); i++)
        {
            map[bt.getPosition('y')][bt.getPosition('x') + 1] = bt.get("id");
        }
        break;
    }
}
