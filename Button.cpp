#include "Button.h"
#include "CommonFunc.h"
#include "BaseObject.h"

Button::Button()
{
	;
}

Button::Button(int x, int y)
{
	position.x = x;
	position.y = y;

	currentSprite = BUTTON_MOUSE_OUT;
}

void Button::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

bool Button::IsInside(SDL_Event* e, int size)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		int button_width, button_height;
		{
			button_width = BUTTON_WIDTH;
			button_height = BUTTON_HEIGHT;
		}

		SDL_GetMouseState(&x, &y);

		bool inside = true;
		if (x < position.x)
		{
			inside = false;
		}
		else if (x > position.x + button_width)
		{
			inside = false;
		}
		else if (y < position.y)
		{
			inside = false;
		}
		else if (y > position.y + button_height)
		{
			inside = false;
		}
		return inside;
	}
	return false;
}

void Button::Show(SDL_Renderer* des, SDL_Rect* currentClip)
{
	SDL_Rect rect_button = { position.x, position.y, currentClip->w, currentClip->h };
	SDL_RenderCopy(des, p_object_, currentClip, &rect_button);
}