#include "text.h"

Text::Text(double x, double y, std::string text, int flags)
{
	apply_flags(flags);
	type = 10;

	textStr = text;
	font = TTF_OpenFont("Vera.ttf", 30);

	position.x = x;
	position.y = y;
}

Text::~Text()
{
	TTF_CloseFont(font);
}
void Text::draw()
{
	screen_manager->text_apply(position.x, position.y, textStr, font);
}