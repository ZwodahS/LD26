#include "../gen.h"

Room::Room(Game* game , std::vector<std::vector<char> > roomTemplate)
{
    this->_template = roomTemplate;
    this->_game = game;
}

Room::~Room()
{
}

std::vector<std::vector<Tile*> > Room::generateTile(int rotation)
{
    std::vector<std::vector<Tile*> > out = std::vector<std::vector<Tile*> >(_template.size(),std::vector<Tile*>(_template[0].size(),NULL));
    
    for(int r = 0 ; r < out.size() ; r++)
    {
        for(int c = 0 ; c < out[r].size() ; c++)
        {
            out[r][c] = getTile(r,c,rotation);
        }
    }

    return out;
}

Tile* Room::getTile(int row, int col, int rotation)
{
    int r = 0;
    int c = 0;
    if(rotation == 0)
    {
        r = row;
        c = col;
    }
    else if(rotation == 1 )
    {
        r = col;
        c = _template.size() - row - 1;
    }
    else if(rotation == 2)
    {
        r = _template.size() - row - 1;
        c = _template.size() - col - 1;
    }
    else 
    {
        r = _template.size() - col - 1;
        c = row;
    }

    return getTile(row,col);
}

Tile* Room::getTile(int row, int col)
{
    char t = _template[row][col];

    if(t == '0' || t == 'I')
    {
        return new FloorTile(_game);
    }
    else if(t == '1')
    {
        return new WallTile(_game);
    }
    else if(t == 'D')
    {
        int doDoor = rand() % 10; //1 in 10 chance of a door
        if(doDoor == 0)
        {
            int color = rand() % 3;
            return new ColorDoorTile(_game,color);
        }
        else
        {
            return new FloorTile(_game);
        }
    }
    else if(t == 'X')
    {
        return new ExitTile(_game);
    }
    else if(t == 'K')
    {
        return new ComputerTile(_game);
    }
    else
    {
        return new WallTile(_game); // jsut in case file is corrupted
    }
}
