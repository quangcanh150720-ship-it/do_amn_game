
#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "CommonFunc.h"
#include "BaseObject.h"

#define MAX_TILES 20

class TileMap : public BaseObject
{
public:
    TileMap() { ; }
    ~TileMap() { ; }
};


class GameMap
{
public:
    GameMap() { ; }
    ~GameMap() { ; }

    void LoadMap(std::string name);
    void LoadTiles(SDL_Renderer* screen, std::string path);
    void DrawMap(SDL_Renderer* screen);
    Map getMap() const { return game_map_; };
    void SetMap(Map& map_data) { game_map_ = map_data; };
private:
    Map game_map_;
    TileMap tile_map[MAX_TILES];
};

#endif