#include <iostream>
#include <string>
using namespace std;
#include "Field.h"
#include "Character.h"

int main() {
	Character c("Johny", 'a', "Healthy", 10);
	Field f(10, 10);
	f.insertCharacter(c);
	f.printField();
	return 0;
}
