#ifndef BUTTON_H_
#define BUTTON_H_

#include "BaseObject.h"
#include "CommonFunc.h"

class Button : public BaseObject
{
public:
	ButtonSprite currentSprite;

	Button();

	Button(int x, int y);
	void SetPosition(int x, int y);

	bool IsInside(SDL_Event* e, int size);
	void Show(SDL_Renderer* des, SDL_Rect* currentClip);
private:
	SDL_Point position;
};

#endif // !BUTTON_H_
