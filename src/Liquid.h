#ifndef LIQUID_H
#define LIQUID_H

#pragma once
class Liquid{
public:
	float x, y, w, h;
	float c;
	Liquid();
	Liquid(float x, float y, float w, float h, float c);
	void display();
};

#endif