#ifndef MENU_H_
#define MENU_H_

#include "BaseObject.h"
#include "Button.h"

void HandlePlayButton(SDL_Event* e,
    SDL_Renderer* des,
    Button& PlayButton,
    bool& QuitMenu,
    bool& Play,
    Mix_Chunk* gClick,
    SDL_Rect(&gMap1Button)[1],
    SDL_Rect(&gMap2Button)[1],
    SDL_Rect(&gMap3Button)[1],
    Button& Map1Button,
    Button& Map2Button,
    Button& Map3Button,
    SDL_Rect(&gPlayer1Button)[BUTTON_TOTAL],
    SDL_Rect(&gPlayer2Button)[BUTTON_TOTAL],
    SDL_Rect(&gPlayer3Button)[BUTTON_TOTAL],
    Button& Player1Button,
    Button& Player2Button,
    Button& Player3Button,
    std::string& map_file_index,
    std::string& map_tile_index,
    std::string& map_background,
    std::string& player_file
    );

void HandleHelpButton(SDL_Event* e,
    SDL_Rect(&gBackButton)[BUTTON_TOTAL],
    Button& HelpButton,
    Button& BackButton,
    SDL_Renderer* gRenderer,
    bool& Quit_game,
    Mix_Chunk* gClick);

void HandleExitButton(SDL_Event* e,
    Button& ExitButton,
    bool& Quit,
    Mix_Chunk* gClick);

void HandleContinueButton(Button ContinueButton,
    SDL_Event* e,
    SDL_Renderer* gRenderer,
    SDL_Rect(&gContinueButton)[BUTTON_MOUSE_OVER],
    bool& Game_State, Mix_Chunk* gClick);

void HandlePauseButton(SDL_Event* e,
    SDL_Renderer* gRenderer,
    SDL_Rect(&gContinueButton)[BUTTON_MOUSE_OVER],
    Button& PauseButton,
    Button ContinueButton,
    bool& game_state,
    Mix_Chunk* gClick
    );
void DrawEndGameSelection(/*LTexture gLoseTexture,*/
    SDL_Event* e,
    SDL_Renderer* gRenderer,
    bool& Play_Again);

void HandleMapButton(SDL_Event* e,
    SDL_Renderer* des,
    SDL_Rect(&gMap1Button)[1],
    SDL_Rect(&gMap2Button)[1],
    SDL_Rect(&gMap3Button)[1],
    Button& Map1Button,
    Button& Map2Button,
    Button& Map3Button,
    SDL_Rect(&gPlayer1Button)[BUTTON_TOTAL],
    SDL_Rect(&gPlayer2Button)[BUTTON_TOTAL],
    SDL_Rect(&gPlayer3Button)[BUTTON_TOTAL],
    Button& Player1Button,
    Button& Player2Button,
    Button& Player3Button,
    bool& quit,
    Mix_Chunk* gClick,
    std::string& map_file_index,
    std::string& map_tile_index,
    std::string& map_background,
    std::string& player_file
    );

void HandleQuitToMenuButton(SDL_Event* e,
    Button& ExitToMenuButton,
    Mix_Chunk* gClick,
    bool& Play_Again, 
    bool& is_play_menu,
    bool& is_quit
    );

void HandleChoosePlayer(SDL_Event* e,
    SDL_Renderer* des,
    SDL_Rect(&gPlayer1Button)[BUTTON_TOTAL],
    SDL_Rect(&gPlayer2Button)[BUTTON_TOTAL],
    SDL_Rect(&gPlayer3Button)[BUTTON_TOTAL],
    Button& Player1Button,
    Button& Player2Button,
    Button& Player3Button,
    bool& quit,
    Mix_Chunk* gClick,
    std::string& player_file);

#endif // !MENU_H_
