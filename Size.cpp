#include "Size.h"

Size::Size(int w, int h){
	width = w;
	height = h;
}

int Size::GetWidth() {
	return width;
}

int Size::GetHeight() {
	return height;
}

Size::~Size(){}
