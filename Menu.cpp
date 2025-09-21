#include "Menu.h"
#include "CommonFunc.h"
#include "Button.h"

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
	std::string& player_file)
{
	if (Player1Button.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			Player1Button.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Player1Button.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			/*Mix_PauseMusic();*/
			player_file = "img//Enchantress";
			break;
		}
	}
	else
	{
		Player1Button.currentSprite = BUTTON_MOUSE_OUT;
	}

	if (Player2Button.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			Player2Button.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Player2Button.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			/*Mix_PauseMusic();*/
			player_file = "img//Knight";
			break;
		}
	}
	else
	{
		Player2Button.currentSprite = BUTTON_MOUSE_OUT;
	}

	if (Player3Button.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			Player3Button.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Player3Button.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			/*Mix_PauseMusic();*/
			player_file = "img//Musketeer";
			break;
		}
	}
	else
	{
		Player3Button.currentSprite = BUTTON_MOUSE_OUT;
	}
	BaseObject player_background;
	player_background.LoadImg("img//choose_player.png", des);
	player_background.Render(des, NULL);
	SDL_Rect* currentClip_Player1 = &gPlayer1Button[Player1Button.currentSprite];
	Player1Button.Show(des, currentClip_Player1);

	SDL_Rect* currentClip_Player2 = &gPlayer2Button[Player2Button.currentSprite];
	Player2Button.Show(des, currentClip_Player2);

	SDL_Rect* currentClip_Player3 = &gPlayer3Button[Player3Button.currentSprite];
	Player3Button.Show(des, currentClip_Player3);
}

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
	bool& quit_menu,
	Mix_Chunk* gClick,
	std::string& map_file_index,
	std::string& map_tile_index,
	std::string& map_background, 
	std::string& player_file
	)
{
	if (Map1Button.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			Map1Button.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Map1Button.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			bool is_choose_player = true;
			while (is_choose_player)
			{
				do
				{
					HandleChoosePlayer(e, des, gPlayer1Button, gPlayer2Button, gPlayer3Button, Player1Button, Player2Button, Player3Button, quit_menu, gClick, player_file);
					SDL_RenderPresent(des);
					if (player_file != "")
					{
						is_choose_player = false;
					}
				} while (SDL_PollEvent(e) != 0 && e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION);
			}
			SDL_RenderPresent(des);
			/*Mix_PauseMusic();*/
			map_file_index = "map//Map1//map.dat";
			map_tile_index = "map//Map1//.png";
			map_background = "map//Map1//background.png";
			break;
		}
	}
	else
	{
		Map1Button.currentSprite = BUTTON_MOUSE_OUT;
	}
	//
	if (Map2Button.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			Map2Button.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Map2Button.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			bool is_choose_player = true;
			while (is_choose_player)
			{
				do
				{
					HandleChoosePlayer(e, des, gPlayer1Button, gPlayer2Button, gPlayer3Button, Player1Button, Player2Button, Player3Button, quit_menu, gClick, player_file);
					SDL_RenderPresent(des);
					if (player_file != "")
					{
						is_choose_player = false;
					}
				} while (SDL_PollEvent(e) != 0 && e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION);
			}
			SDL_RenderPresent(des);
			/*Mix_PauseMusic();*/
			map_file_index = "map//Map2//map.dat";
			map_tile_index = "map//Map2//.png";
			map_background = "map//Map2//background.png";
			break;
		}
	}
	else
	{
		Map2Button.currentSprite = BUTTON_MOUSE_OUT;
	}
	//
	if (Map3Button.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			Map3Button.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Map3Button.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			bool is_choose_player = true;
			while (is_choose_player)
			{
				do
				{
					HandleChoosePlayer(e, des, gPlayer1Button, gPlayer3Button, gPlayer3Button, Player1Button, Player2Button, Player3Button, quit_menu, gClick, player_file);
					SDL_RenderPresent(des);
					if (player_file != "")
					{
						is_choose_player = false;
					}
				}
				while (SDL_PollEvent(e) != 0 && e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION);
			}
			/*Mix_PauseMusic();*/
			map_file_index = "map//Map3//map.dat";
			map_tile_index = "map//Map3//.png";
			map_background = "map//Map3//background.png";
			break;
		}
	}
	else
	{
		Map3Button.currentSprite = BUTTON_MOUSE_OUT;
	}
	BaseObject menu_background;
	menu_background.LoadImg("img//Choosemap.png", des);
	menu_background.Render(des, NULL);
	SDL_Rect* currentClip_Map1 = &gMap1Button[Map1Button.currentSprite];
	Map1Button.Show(des, currentClip_Map1);

	SDL_Rect* currentClip_Map2 = &gMap2Button[Map2Button.currentSprite];
	Map2Button.Show(des, currentClip_Map2);

	SDL_Rect* currentClip_Map3 = &gMap3Button[Map3Button.currentSprite];
	Map3Button.Show(des, currentClip_Map3);
}


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
	std::string& map_file_index_,
	std::string& map_tile_index_,
	std::string& map_background,
	std::string& player_file
	)
{
	if (e->type == SDL_QUIT)
	{
		QuitMenu = true;
	}

	if (PlayButton.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			PlayButton.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Play = true;
			Mix_PlayChannel(MIX_CHANNEL, gClick, 0);
			PlayButton.currentSprite = BUTTON_MOUSE_OVER;
			QuitMenu = true;
			bool quit_choose_map = false;
			while (!quit_choose_map)
			{
				do
				{
					HandleMapButton(e, des, gMap1Button, gMap2Button, gMap3Button, Map1Button, Map2Button, Map3Button, gPlayer1Button, gPlayer2Button, gPlayer3Button,
						Player1Button, Player2Button, Player3Button, QuitMenu, gClick, map_file_index_, map_tile_index_, map_background, player_file);
					SDL_RenderPresent(des);
					if (map_file_index_ != "" && map_tile_index_ != "")
					{
						quit_choose_map = true;
					}
				}
				while (SDL_PollEvent(e) != 0 && e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION);
			}
		}
	}
	else
	{
		PlayButton.currentSprite = BUTTON_MOUSE_OUT;
	}
}

void HandleHelpButton(SDL_Event* e,
	SDL_Rect(&gBackButton)[BUTTON_TOTAL],
	Button& HelpButton,
	Button& BackButton,
	SDL_Renderer* des,
	bool& Quit_game,
	Mix_Chunk* gClick)
{
	if (HelpButton.IsInside(e, COMMON_BUTTON))
	{
		BaseObject g_introduction;
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			HelpButton.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			HelpButton.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);

			bool ReadDone = false;
			while (!ReadDone)
			{
				do
				{
					if (e->type == SDL_QUIT)
					{
						ReadDone = true;
						Quit_game = true;
					}
					if (BackButton.IsInside(e, COMMON_BUTTON))
					{
						switch (e->type)
						{
						case SDL_MOUSEMOTION:
							BackButton.currentSprite = BUTTON_MOUSE_OVER;
							break;
						case SDL_MOUSEBUTTONDOWN:
							BackButton.currentSprite = BUTTON_MOUSE_OVER;
							Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
							ReadDone = true;
							break;
						}
					}
					else
					{
						BackButton.currentSprite = BUTTON_MOUSE_OUT;
					}

					g_introduction.LoadImg("img//instruction.png", des);
					g_introduction.Render(des, NULL);

					SDL_Rect* currentClip_Back = &gBackButton[BackButton.currentSprite];
					BackButton.Show(des, currentClip_Back);

					SDL_RenderPresent(des);
				} while (SDL_PollEvent(e) != 0 && e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION);
			}
			break;
		}
	}
	else
	{
		HelpButton.currentSprite = BUTTON_MOUSE_OUT;
	}
}

void HandleExitButton(SDL_Event* e,
	Button& ExitButton,
	bool& Quit,
	Mix_Chunk* gClick)
{
	if (ExitButton.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			ExitButton.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Quit = true;
			ExitButton.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			break;
		}
	}
	else
	{
		ExitButton.currentSprite = BUTTON_MOUSE_OUT;
	}
}

void HandleContinueButton(Button ContinueButton,
	/*LTexture gContinueButtonTexture,*/
	SDL_Event* e,
	SDL_Renderer* des,
	SDL_Rect(&gContinueButton)[BUTTON_MOUSE_OVER],
	bool& Game_State,
	Mix_Chunk* gClick)
{
	bool Back_To_Game = false;
	while (!Back_To_Game)
	{
		do
		{
			if (ContinueButton.IsInside(e, SMALL_BUTTON))
			{
				switch (e->type)
				{
				case SDL_MOUSEMOTION:
					ContinueButton.currentSprite = BUTTON_MOUSE_OVER;
					break;
				case SDL_MOUSEBUTTONDOWN:
				{
					ContinueButton.currentSprite = BUTTON_MOUSE_OVER;
					Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
					Mix_ResumeMusic();
					Game_State = true;
					Back_To_Game = true;
				}
				break;
				}
			}
			if (ContinueButton.IsInside(e, SMALL_BUTTON))
			{
				switch (e->type)
				{
				case SDL_MOUSEMOTION:
					// 
					break;
				case SDL_MOUSEBUTTONDOWN:
				{
					/*ContinueButton.currentSprite = BUTTON_MOUSE_OVER;*/
					Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
					Mix_ResumeMusic();
					Game_State = true;
					Back_To_Game = true;
				}
				break;
				}
			}
		} while (SDL_WaitEvent(e) != 0 && e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION);
	}
}

void HandlePauseButton(SDL_Event* e,
	SDL_Renderer* des,
	SDL_Rect(&gContinueButton)[BUTTON_MOUSE_OVER],
	Button& PauseButton,
	Button ContinueButton,
	/*LTexture gContinueButtonTexture,*/
	bool& Game_State,
	Mix_Chunk* gClick
	)
{
	if (PauseButton.IsInside(e, SMALL_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			PauseButton.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			PauseButton.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			Mix_PauseMusic();

			break;
		case SDL_MOUSEBUTTONUP:
			Game_State = false;
			HandleContinueButton(ContinueButton, e, des, gContinueButton, Game_State, gClick);
			break;
		}
	}
	else
	{
		PauseButton.currentSprite = BUTTON_MOUSE_OUT;
	}
}

void DrawEndGameSelection(/*LTexture gLoseTexture,*/
	SDL_Event* e,
	SDL_Renderer* gRenderer,
	bool& Play_Again)
{
	if (Play_Again)
	{
		bool End_Game = false;
		while (!End_Game)
		{
			while (SDL_PollEvent(e) != 0)
			{
				if (e->type == SDL_QUIT)
				{
					Play_Again = false;
				}

				if (e->type == SDL_KEYDOWN)
				{
					switch (e->key.keysym.sym)
					{
					case SDLK_SPACE:
						End_Game = true;
						break;
					case SDLK_ESCAPE:
						End_Game = true;
						Play_Again = false;
						break;
					}
				}
			}
			BaseObject g_lose_menu;
			g_lose_menu.LoadImg("img//lose.png", gRenderer);
			SDL_Rect renderquad = { 320, 160, 640, 320 };
			SDL_RenderCopy(gRenderer, g_lose_menu.GetObject(), NULL, &renderquad);
			SDL_RenderPresent(gRenderer);
		}
	}
}

void HandleQuitToMenuButton(SDL_Event* e,
	Button& ExitToMenuButton,
	Mix_Chunk* gClick,
	bool& Play_Again,
	bool& is_play_menu,
	bool& is_quit
	)
{
	if (ExitToMenuButton.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			ExitToMenuButton.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Play_Again = false;
			is_quit = true;
			ExitToMenuButton.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			break;
		}
	}
	else
	{
		ExitToMenuButton.currentSprite = BUTTON_MOUSE_OUT;
	}
}

