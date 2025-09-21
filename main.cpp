
#include "CommonFunc.h"
#include "BaseObject.h"
#include "Map.h"
#include "MainObject.h";
#include "ImpTimer.h"
#include "ThreatsObject.h"
#include "ExplosionObject.h"
#include "Text.h"
#include "Menu.h"
#include "PlayerPower.h"
#include "Geometric.h"
#include "BossObject.h"
#include "Button.h"
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


BaseObject g_background;
BaseObject g_Menu;      
BaseObject g_lose_menu;

TTF_Font* font_time = NULL;

Button PlayButton(HELP_BUTTON_POSX, HELP_BUTTON_POSY);
Button HelpButton(PLAY_BUTTON_POSX, PLAY_BUTTON_POSY);
Button ExitButton(EXIT_BUTTON_POSX, EXIT_BUTTON_POSY);
Button BackButton(BACK_BUTTON_POSX, BACK_BUTTON_POSY);
Button PauseButton(PAUSE_BUTTON_POSX, PAUSE_BUTTON_POSY);
Button ContinueButton(PAUSE_BUTTON_POSX, PAUSE_BUTTON_POSY);
Button Map1Button(MAP1_BUTTON_POSX, MAP1_BUTTON_POSY);
Button Map2Button(MAP2_BUTTON_POSX, MAP2_BUTTON_POSY);
Button Map3Button(MAP3_BUTTON_POSX, MAP3_BUTTON_POSY);
Button ExitToMenuButton(QUIT_PAUSE_BUTTON_POSX, QUIT_PAUSE_BUTTON_POSY);
Button Player1Button(PLAYER1_BUTTON_POSX, PLAYER1_BUTTON_POSY);
Button Player2Button(PLAYER2_BUTTON_POSX, PLAYER2_BUTTON_POSY);
Button Player3Button(PLAYER3_BUTTON_POSX, PLAYER3_BUTTON_POSY);

SDL_Rect gPlayButton[BUTTON_TOTAL];
SDL_Rect gHelpButton[BUTTON_TOTAL];
SDL_Rect gExitButton[BUTTON_TOTAL];
SDL_Rect gBackButton[BUTTON_TOTAL];
SDL_Rect gPauseButton[BUTTON_TOTAL];
SDL_Rect gContinueButton[BUTTON_MOUSE_OVER];
SDL_Rect gPlayAgainButton[BUTTON_TOTAL];
SDL_Rect gMap1Button[BUTTON_MOUSE_OVER];
SDL_Rect gMap2Button[BUTTON_MOUSE_OVER];
SDL_Rect gMap3Button[BUTTON_MOUSE_OVER];
SDL_Rect gExitToMenuButton[BUTTON_TOTAL];
SDL_Rect gPlayer1Button[BUTTON_TOTAL];
SDL_Rect gPlayer2Button[BUTTON_TOTAL];
SDL_Rect gPlayer3Button[BUTTON_TOTAL];

bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
        return false;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    g_window = SDL_CreateWindow("Kaintd Advanture",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    if (g_window == NULL)
    {
        success = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
            success = false;
        else
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
                success = false;
        }

        if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        {
            success = false;
        }

        g_sound_bullet = Mix_LoadWAV(g_name_audio_bullet_main1);
        /*g_sound_bullet[1] = Mix_LoadWAV(g_name_audio_bullet_main2);*/
        g_sound_explosion = Mix_LoadWAV(g_name_audio_ex_main);
        g_sound_ex_main = Mix_LoadWAV(g_name_audio_ex_threats);
        g_music = Mix_LoadMUS(g_music_sound);
        g_click = Mix_LoadWAV(g_click_);
        g_jump = Mix_LoadWAV(g_jump_);

        if (g_sound_bullet == NULL || g_sound_explosion == NULL)
        {
            return false;
        }

        if (TTF_Init() == -1)
        {
            success = false;
        }

        font_time = TTF_OpenFont("font//dlxfont.ttf", 15);
        if (font_time == NULL)
        {
            success = false;
        }
    }

    return success;
}

bool LoadBackground(std::string map_background)
{
    bool ret = g_background.LoadImg(map_background, g_screen);
    if (ret == false)
        return false;

    return true;
}

void LoadButton()
{
    PlayButton.LoadImg("img//Button//play_button.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; ++i)
    {
        gPlayButton[i].x = 150 * i;
        gPlayButton[i].y = 0;
        gPlayButton[i].w = 150;
        gPlayButton[i].h = 98;
    }
    HelpButton.LoadImg("img//Button//help_button.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; ++i)
    {
        gHelpButton[i].x = 150 * i;
        gHelpButton[i].y = 0;
        gHelpButton[i].w = 150;
        gHelpButton[i].h = 98;
    }
    ExitButton.LoadImg("img//Button//exit_button.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; ++i)
    {
        gExitButton[i].x = 150 * i;
        gExitButton[i].y = 0;
        gExitButton[i].w = 150;
        gExitButton[i].h = 98;
    }
    PauseButton.LoadImg("img//Button//pause_button.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; ++i)
    {
        gPauseButton[i].x = 64 * i;
        gPauseButton[i].y = 0;
        gPauseButton[i].w = 64;
        gPauseButton[i].h = 64;
    }
    BackButton.LoadImg("img//Button//back_button.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; ++i)
    {
        gBackButton[i].x = 100 * i;
        gBackButton[i].y = 0;
        gBackButton[i].w = 100;
        gBackButton[i].h = 78;
    }
    ContinueButton.LoadImg("img//Button//continue_button.png", g_screen);
    for (int i = 0; i < BUTTON_MOUSE_OVER; ++i)
    {
        gContinueButton[i].x = 0;
        gContinueButton[i].y = 0;
        gContinueButton[i].w = 232;
        gContinueButton[i].h = 47;
    }
    Map1Button.LoadImg("img//Button//mapbutton1.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; ++i)
    {
        gMap1Button[i].x = 150 * i;
        gMap1Button[i].y = 0;
        gMap1Button[i].w = 150;
        gMap1Button[i].h = 98;
    }
    Map2Button.LoadImg("img//Button//mapbutton2.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; ++i)
    {
        gMap2Button[i].x = 150 * i;
        gMap2Button[i].y = 0;
        gMap2Button[i].w = 150;
        gMap2Button[i].h = 98;
    }
    Map3Button.LoadImg("img//Button//mapbutton3.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; ++i)
    {
        gMap3Button[i].x = 150 * i;
        gMap3Button[i].y = 0;
        gMap3Button[i].w = 150;
        gMap3Button[i].h = 98;
    }
    ExitToMenuButton.LoadImg("img//Button//back_button.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; i++)
    {
        gExitToMenuButton[i].x = 100 * i;
        gExitToMenuButton[i].y = 0;
        gExitToMenuButton[i].w = 100;
        gExitToMenuButton[i].h = 78;
    }
    Player1Button.LoadImg("img/Button//Enchantress.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; i++)
    {
        gPlayer1Button[i].x = 100 * i;
        gPlayer1Button[i].y = 0;
        gPlayer1Button[i].w = 100;
        gPlayer1Button[i].h = 100;
    }

    Player2Button.LoadImg("img/Button//Knight.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; i++)
    {
        gPlayer2Button[i].x = 100 * i;
        gPlayer2Button[i].y = 0;
        gPlayer2Button[i].w = 100;
        gPlayer2Button[i].h = 100;
    }
    Player3Button.LoadImg("img/Button//Musketeer.png", g_screen);
    for (int i = 0; i < BUTTON_TOTAL; i++)
    {
        gPlayer3Button[i].x = 100 * i;
        gPlayer3Button[i].y = 0;
        gPlayer3Button[i].w = 100;
        gPlayer3Button[i].h = 100;
    }

    SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
    SDL_RenderClear(g_screen);
    Mix_PlayMusic(g_music, -1);

}

void close()
{
    g_background.Free();

    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}

std::vector<ThreatsObject*> MakeThreadList()
{
    std::vector<ThreatsObject*> list_threats;


    ThreatsObject* dynamic_threats = new ThreatsObject[20];
    for (int i = 0; i < 20; i++)
    {
        ThreatsObject* p_threat = (dynamic_threats + i);
        if (p_threat != NULL)
        {
            p_threat->LoadImg("img//threat_left.png", g_screen);
            p_threat->set_clips();
            p_threat->set_type_move(ThreatsObject::MOVE_IN_SPACE_THREAT);
            p_threat->set_x_pos(500 + i * 500);
            p_threat->set_y_pos(200);
            int pos1 = p_threat->get_x_pos() - 60;
            int pos2 = p_threat->get_x_pos() + 60;
            p_threat->SetAnimationPos(pos1, pos2);
            p_threat->set_input_left(1);
            list_threats.push_back(p_threat);
        }
    }



    ThreatsObject* threats_objs = new ThreatsObject[20];
    for (int i = 0; i < 20; i++)
    {
        ThreatsObject* p_threat = (threats_objs + i);
        if (p_threat != NULL)
        {
            p_threat->LoadImg("img//threat_level_left.png", g_screen);
            p_threat->set_clips();
            p_threat->set_x_pos(700 + i * 1200);
            p_threat->set_y_pos(250);
            p_threat->set_type_move(ThreatsObject::STATIC_THREAT);
            p_threat->set_input_left(0);
            p_threat->set_check_dynamic(0);
            BulletObject* p_bullet = new BulletObject();
            p_threat->InitBullet(p_bullet, g_screen);

            list_threats.push_back(p_threat);
        }
    }

    return list_threats;
}

bool ValidateLogin(const std::string& username, const std::string& password)
{
    std::ifstream infile("account.txt");
    if (!infile.is_open())  
    {
        std::cerr << "Không thể mở file account.txt\n";
        return false;
    }

    std::string line, u, p;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        iss >> u >> p;
        if (u == username && p == password)
        {
            return true; // đăng nhập thành công
        }
    }
    return false;
}

struct TextBox {
    SDL_Rect rect;
    std::string content;
    bool active;
    bool isPassword;

    TextBox(int x, int y, int w, int h, bool pw = false) {
        rect = { x, y, w, h };
        content = "";
        active = false;
        isPassword = pw;
    }

    void Render(SDL_Renderer* renderer, TTF_Font* font, SDL_Color textColor) {
        // Vẽ khung
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &rect);

        // Nếu là password thì render *
        std::string display = content;
        if (isPassword) {
            display = std::string(content.size(), '*');
        }

        if (!display.empty()) {
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, display.c_str(), textColor);
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_Rect dst = { rect.x + 5, rect.y + 5, textSurface->w, textSurface->h };
            SDL_RenderCopy(renderer, textTexture, NULL, &dst);
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);
        }
    }
};


bool ShowLoginScreen(SDL_Renderer* renderer, TTF_Font* font, std::string& outUser, std::string& outPass) {
    SDL_Event e;
    bool quit = false;
    bool loginSuccess = false;

    SDL_Color textColor = { 255, 255, 255, 255 };

    TextBox userBox(300, 200, 200, 40, false);
    TextBox passBox(300, 260, 200, 40, true);

    SDL_Rect loginButton = { 300, 320, 200, 40 };

    SDL_StartTextInput();

    while (!quit && !loginSuccess) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x = e.button.x;
                int y = e.button.y;
                SDL_Point point = { x, y };
                userBox.active = SDL_PointInRect(&point, &userBox.rect);
                passBox.active = SDL_PointInRect(&point, &passBox.rect);

                // Click login
                if (x > loginButton.x && x < loginButton.x + loginButton.w &&
                    y > loginButton.y && y < loginButton.y + loginButton.h) {
                    if (ValidateLogin(userBox.content, passBox.content)) {
                        outUser = userBox.content;
                        outPass = passBox.content;
                        loginSuccess = true;
                    }
                    else {
                        std::cout << "Sai username/password!\n";
                    }
                }
            }
            else if (e.type == SDL_TEXTINPUT) {
                if (userBox.active) {
                    userBox.content += e.text.text;
                }
                else if (passBox.active) {
                    passBox.content += e.text.text;
                }
            }
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_BACKSPACE) {
                    if (userBox.active && !userBox.content.empty())
                        userBox.content.pop_back();
                    else if (passBox.active && !passBox.content.empty())
                        passBox.content.pop_back();
                }
            }
        }

        // Vẽ màn hình
        SDL_SetRenderDrawColor(renderer, 0, 0, 64, 255);
        SDL_RenderClear(renderer);

        userBox.Render(renderer, font, textColor);
        passBox.Render(renderer, font, textColor);

        // Vẽ nút login
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &loginButton);

        SDL_RenderPresent(renderer);
    }

    SDL_StopTextInput();

    return loginSuccess;
}


        int main(int argc, char* argv[])
    {
    
        // tao man hinh dang nhap truoc khi vao game 
        bool successValidate = false;
        

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
            return -1;
        }

        if (TTF_Init() == -1) {
            std::cout << "TTF could not initialize! TTF_Error: " << TTF_GetError() << "\n";
            return -1;
        }

        SDL_Window* window = SDL_CreateWindow("Login Screen",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            800, 600, SDL_WINDOW_SHOWN);

        if (window == NULL) {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
            return -1;
        }

        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL) {
            std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << "\n";
            return -1;
        }

        TTF_Font* font = TTF_OpenFont("font//ARIAL.TTF", 24);
        if (font == NULL) {
            std::cout << "Failed to load font! TTF_Error: " << TTF_GetError() << "\n";
            return -1;
        }

        std::string username, password;
        bool login = ShowLoginScreen(renderer, font, username, password);

        if (login) {
            std::cout << "Đăng nhập thành công với user: " << username << "\n";
            // ở đây anh có thể nhảy vào menu game của mình
            bool is_play_menu = true;

            while (is_play_menu)
            {
                bool Quit_Menu = false;
                bool Play_Again = false;
                ImpTimer fps_timer;
                std::string map_tile_index;
                std::string map_file_index;
                std::string map_background;
                std::string player_file_;
                if (InitData() == false) {
                    return -1;
                }

                LoadButton();

                while (!Quit_Menu)
                {
                    SDL_Rect* currentClip_Play = &gPlayButton[PlayButton.currentSprite];
                    SDL_Rect* currentClip_Help = &gHelpButton[HelpButton.currentSprite];
                    SDL_Rect* currentClip_Exit = &gExitButton[ExitButton.currentSprite];
                    SDL_Event e_mouse;
                    while (SDL_PollEvent(&e_mouse) != 0)
                    {
                        if (e_mouse.type == SDL_QUIT)
                        {
                            Quit_Menu = true;
                        }
                        bool Quit_Game = false;
                        HandlePlayButton(&e_mouse, g_screen, PlayButton, Quit_Menu, Play_Again, g_click, gMap1Button, gMap2Button, gMap3Button, Map1Button, Map2Button, Map3Button, gPlayer1Button, gPlayer2Button, gPlayer3Button, Player1Button, Player2Button, Player3Button, map_file_index, map_tile_index, map_background, player_file_);
                        HandleHelpButton(&e_mouse, gBackButton, HelpButton, BackButton, g_screen, Quit_Game, g_click);
                        HandleExitButton(&e_mouse, ExitButton, Quit_Game, g_click);
                        if (Quit_Game == true)
                        {
                            return 0;
                        }
                    }

                    g_Menu.LoadImg("img//mainmenu.png", g_screen);
                    g_Menu.Render(g_screen, NULL);
                    PlayButton.Show(g_screen, currentClip_Play);
                    HelpButton.Show(g_screen, currentClip_Help);
                    ExitButton.Show(g_screen, currentClip_Exit);
                    SDL_RenderPresent(g_screen);
                }


                while (Play_Again)
                {
                    if (LoadBackground(map_background) == false)
                        return -1;
                    GameMap game_map;
                    game_map.LoadMap(map_file_index);
                    game_map.LoadTiles(g_screen, map_tile_index);

                    MainObject p_player;
                    p_player.LoadImg("img//Enchantress//player_right.png", g_screen);
                    p_player.set_clips();

                    PlayerPower player_power;
                    player_power.Init(g_screen);

                    PlayerMoney player_money;
                    player_money.Init(g_screen);
                    player_money.SetPos(SCREEN_WIDTH * 0.5 - 300, 8);

                    std::vector<ThreatsObject*> threats_list = MakeThreadList();

                    BossObject bossObject;
                    bool ret = bossObject.LoadImg("img//boss_object.png", g_screen);
                    bossObject.set_clips();
                    int xPosBoss = MAX_MAP_X * TILE_SIZE - SCREEN_WIDTH * 0.6;
                    bossObject.set_xpos(xPosBoss);
                    bossObject.set_ypos(10);

                    ExplosionObject exp_threat;
                    bool tRet = exp_threat.LoadImg("img//exp3.png", g_screen);
                    if (!tRet) return -1;
                    exp_threat.set_clip();

                    ExplosionObject exp_main;
                    bool mRet = exp_main.LoadImg("img//exp3.png", g_screen);
                    exp_main.set_clip();
                    if (!mRet) return -1;

                    int num_die = 0;

                    TextObject time_game;
                    time_game.SetColor(TextObject::WHITE_TEXT);

                    TextObject mark_game;
                    mark_game.SetColor(TextObject::WHITE_TEXT);
                    UINT mark_value = 0;
                    bool is_back_to_menu = false;

                    TextObject money_game;
                    money_game.SetColor(TextObject::WHITE_TEXT);
                    bool is_quit = false;
                    bool Game_State = true;
                    while (!is_quit)
                    {
                        if (Game_State)
                        {
                            fps_timer.start();

                            g_background.Render(g_screen, NULL);

                            Map map_data = game_map.getMap();

                            while (SDL_PollEvent(&g_event) != 0)
                            {
                                p_player.HandelInputAction(g_event, g_screen, g_jump, player_file_);
                                HandlePauseButton(&g_event, g_screen, gContinueButton, PauseButton, ContinueButton, Game_State, g_click);
                                HandleQuitToMenuButton(&g_event, ExitToMenuButton, g_click, Play_Again, is_play_menu, is_quit);
                            }

                            p_player.HandleBullet(g_screen);
                            p_player.SetMapXY(map_data.start_x_, map_data.start_y_);
                            p_player.DoPlayer(map_data);
                            p_player.Show(g_screen, player_file_);

                            game_map.SetMap(map_data);
                            game_map.DrawMap(g_screen);
                            GeometricFormat rectangle_size(0, 0, SCREEN_WIDTH, 40);
                            ColorData color_data(36, 36, 36);
                            Geometric::RenderRectangle(rectangle_size, color_data, g_screen);

                            GeometricFormat outLineSize(1, 1, SCREEN_WIDTH - 1, 38);
                            ColorData color_data2(255, 255, 255);

                            Geometric::RenderOutline(outLineSize, color_data2, g_screen);

                            // background for power and diamond

                            player_power.Show(g_screen);
                            player_money.Show(g_screen);

                            for (int i = 0; i < threats_list.size(); i++)
                            {
                                ThreatsObject* p_threat = threats_list.at(i);
                                if (p_threat != NULL)
                                {
                                    p_threat->ImpMoveType(g_screen);
                                    p_threat->DoPlayer(map_data);
                                    p_threat->SetMapXY(map_data.start_x_, map_data.start_y_);
                                    p_threat->MakeBullet(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
                                    p_threat->Show(g_screen);

                                    SDL_Rect rect_player = p_player.GetRectFrame();
                                    bool bCol1 = false;
                                    std::vector<BulletObject*> tBullet_list = p_threat->get_bullet_list();
                                    for (int jj = 0; jj < tBullet_list.size(); ++jj)
                                    {
                                        BulletObject* pt_bullet = tBullet_list.at(jj);
                                        if (pt_bullet)
                                        {
                                            bCol1 = SDLCommonFunc::CheckCollision(pt_bullet->GetRect(), rect_player);
                                            if (bCol1)
                                            {
                                                p_threat->RemoveBullet(jj);
                                                break;
                                            }
                                        }
                                    }

                                    SDL_Rect rect_threat = p_threat->GetRectFrame();
                                    bool bCol2 = SDLCommonFunc::CheckCollision(rect_player, rect_threat);
                                    if (bCol1 || bCol2)
                                    {
                                        int width_exp_frame = exp_main.get_frame_width();
                                        int heiht_exp_height = exp_main.get_frame_heigh();
                                        for (int ex = 0; ex < 4; ex++)
                                        {
                                            int x_pos = (p_player.GetRect().x + p_player.get_frame_width() * 0.5) - width_exp_frame * 0.5;
                                            int y_pos = (p_player.GetRect().y + p_player.get_frame_height() * 0.5) - heiht_exp_height * 0.5;

                                            exp_main.set_frame(ex);
                                            exp_main.SetRect(x_pos, y_pos);
                                            exp_main.Show(g_screen);
                                            SDL_RenderPresent(g_screen);
                                        }

                                        Mix_PlayChannel(-1, g_sound_ex_main, 0);

                                        num_die++;
                                        if (num_die <= 3)
                                        {
                                            p_player.SetRect(0, 0);
                                            p_player.set_comeback_time(10);
                                            SDL_Delay(1000);
                                            player_power.Decrease();
                                            player_power.Render(g_screen);
                                            continue;
                                        }
                                        else
                                        {
                                            is_quit = true;
                                        }
                                    }
                                }
                            }

                            int frame_exp_width = exp_threat.get_frame_width();
                            int frame_exp_heigh = exp_threat.get_frame_heigh();

                            std::vector<BulletObject*> bullet_arr = p_player.get_bullet_list();
                            for (int r = 0; r < bullet_arr.size(); ++r)
                            {
                                BulletObject* p_bullet = bullet_arr.at(r);
                                if (p_bullet != NULL)
                                {
                                    for (int t = 0; t < threats_list.size(); ++t)
                                    {
                                        ThreatsObject* obj_threat = threats_list.at(t);
                                        if (obj_threat != NULL)
                                        {

                                            SDL_Rect tRect;
                                            tRect.x = obj_threat->GetRect().x;
                                            tRect.y = obj_threat->GetRect().y;
                                            tRect.w = obj_threat->get_width_frame();
                                            tRect.h = obj_threat->get_height_frame();

                                            SDL_Rect bRect = p_bullet->GetRect();

                                            bool bCol = SDLCommonFunc::CheckCollision(bRect, tRect);

                                            if (bCol)
                                            {
                                                mark_value++;
                                                for (int ex = 0; ex < NUM_FRAME_EXP; ++ex)
                                                {
                                                    int x_pos = p_bullet->GetRect().x - frame_exp_width * 0.5;
                                                    int y_pos = p_bullet->GetRect().y - frame_exp_heigh * 0.5;

                                                    exp_threat.set_frame(ex);
                                                    exp_threat.SetRect(x_pos, y_pos);
                                                    exp_threat.Show(g_screen);
                                                }

                                                p_player.RemoveBullet(r);
                                                obj_threat->Free();
                                                threats_list.erase(threats_list.begin() + t);

                                                Mix_PlayChannel(-1, g_sound_explosion, 0);

                                            }
                                        }
                                    }
                                }
                            }
                            SDL_Rect* currentClip_Pause = &gPauseButton[PauseButton.currentSprite];
                            PauseButton.Show(g_screen, currentClip_Pause);

                            SDL_Rect* currentClip_BackToMenu = &gExitToMenuButton[ExitToMenuButton.currentSprite];
                            ExitToMenuButton.Show(g_screen, currentClip_BackToMenu);

                            /*if (is_back_to_menu)
                            {
                                BaseObject g_pause_menu;
                                g_pause_menu.LoadImg("img//pause_menu.png", g_screen);
                                SDL_Rect renderquad = { 250, 126, 740, 370 };
                                SDL_RenderCopy(g_screen, g_pause_menu.GetObject(), NULL, &renderquad);
                            }*/

                            std::string str_time = "Time: ";
                            Uint32 time_val = SDL_GetTicks() / 1000;
                            Uint32 val_time = 400 - time_val;
                            if (val_time <= 0)
                            {
                                is_quit = true;
                                DrawEndGameSelection(&g_event, g_screen, Play_Again);
                            }
                            else
                            {
                                std::string str_val = std::to_string(val_time);
                                str_time += str_val;

                                time_game.SetText(str_time);
                                time_game.LoadFromRenderText(font_time, g_screen);
                                time_game.RenderText(g_screen, SCREEN_WIDTH - 200, 15);
                            }

                            std::string val_str_mark = std::to_string(mark_value);
                            std::string strMark("Score: ");
                            strMark += val_str_mark;

                            mark_game.SetText(strMark);
                            mark_game.LoadFromRenderText(font_time, g_screen);
                            mark_game.RenderText(g_screen, SCREEN_WIDTH * 0.5 - 50, 15);

                            int money_count = p_player.GetMoneyCount();
                            std::string money_str = std::to_string(money_count);

                            money_game.SetText(money_str);
                            money_game.LoadFromRenderText(font_time, g_screen);
                            money_game.RenderText(g_screen, SCREEN_WIDTH * 0.5 - 250, 15);

                            int val = MAX_MAP_X * TILE_SIZE - (map_data.start_x_ + p_player.GetRect().x);
                            if (val <= SCREEN_WIDTH)
                            {
                                bossObject.SetMapXY(map_data.start_x_, map_data.start_y_);
                                bossObject.DoPlayer(map_data);
                                bossObject.MakeBullet(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
                                bossObject.Show(g_screen);
                            }

                            SDL_RenderPresent(g_screen);

                            int real_imp_time = fps_timer.get_ticks();
                            int time_one_frame = 1000 / FRAME_PER_SECOND;

                            if (real_imp_time < time_one_frame)
                            {
                                int delay_time = time_one_frame - real_imp_time;
                                if (delay_time >= 0)
                                    SDL_Delay(delay_time);
                            }
                        }

                    }
                    // hàm này sẽ hoạt động khi ta nhấn space, quyết định xem có chơi tiếp hay không
                    DrawEndGameSelection(&g_event, g_screen, Play_Again);

                    if (Play_Again == false)
                    {
                        for (int i = 0; i < threats_list.size(); i++)
                        {
                            ThreatsObject* p_threat = threats_list.at(i);
                            if (p_threat)
                            {
                                p_threat->Free();
                                p_threat = NULL;
                            }
                        }
                        threats_list.clear();
                        close();
                    }
                }
            }
            return 0;
        }
        else {
            std::cout << "Thoát chương trình.\n";
        }

        // Giải phóng
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();

        
    }

