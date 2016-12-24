#include "Position.h"

Position::Position(int x, int y) {
	Position::x = x;
	Position::y = y;
}

Position::~Position(){}

int Position::GetX() {
	return x;
}

int Position::GetY() {
	return y;
}