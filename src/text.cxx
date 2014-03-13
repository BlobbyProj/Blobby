#include "text.h"

Text::Text(double x, double y, std::string text, int flags)
{
	std::cout << "error with ctor" << std::endl;
	apply_flags(flags);
	type = 10;

	textStr = text;

	position.x = x;
	position.y = y;
}

void Text::draw()
{
	std::cout << "error with draw" << std::endl;
	screen_manager->text_apply(position.x, position.y, textStr);
}