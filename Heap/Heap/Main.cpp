#include "stdafx.h"
#include <iostream>
#include <string>
#include "Structures.h"
#include "GameObject.h"

int main()
{
	GameObject *go1 = new GameObject(1);
	GameObject *go2 = new GameObject(2);

	delete go1;
	delete go2;

	std::cin.get();
    
	return 0;
}

