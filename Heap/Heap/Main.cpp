#include "stdafx.h"
#include <iostream>
#include <string>
#include "Structures.h"
#include "GameObject.h"

using namespace std;

int main()
{
	//cout << "Heap Created" << endl;

	GameObject *go = new GameObject(1);
	delete go;
	
	cin.get();
    
	return 0;
}

