#include "Fruit.h"


void Fruit::DrawFruit(Board brd,Location & floc)const
{
	brd.DrawCell(floc, Colors::Red);
}


