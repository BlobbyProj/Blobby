#include "text.h"

Text::Text(double x, double y, std::string text, int flags)
{
	apply_flags(flags);
	type = 10;

	textStr = text;
	
	// assigns font and size for text string
	font = TTF_OpenFont("Vera.ttf", 30);

	// position of text object
	position.x = x;
	position.y = y;
}

Text::~Text()
{
	TTF_CloseFont(font);
}
void Text::draw()
{
	// applies string as texture at x,y position
	screen_manager->text_apply(position.x, position.y, textStr, font);
}