#include "Protector.h"
#include "Noble.h"
#include <string>
#include <vector>
using namespace std;

namespace WarriorCraft {

	Protector::Protector(const string& name, int strength) : protector_name(name) { ind_strength = strength; }

	bool Protector::is_hired() { return assigned; }

	void Protector::modify_employement(const string& action, Noble& employer) {
		if (action == "hired") {
			// If the Warrior was hired, then we update the Warrior's Noble*, boss,
			// with the given employer. Otherwise, if the Noble is modifying its'
			// employement because it was fired, we simply reset the Warrior's boss
			// to nullptr. Therefore, the second argument, employer, would be redundant 
			// in this case.
			assigned = true;
			boss = &employer;
		}
		// if (action == "fired")
		else {
			assigned = false;
			boss = nullptr;
		}
	}

	const string& Protector::getPname() const { return protector_name; }

	const string& Protector::getBossname() const { return boss->getNname(); }

	int Protector::getPstrength() const { return ind_strength; }

	void Protector::modifyStrength(int new_strength) {
		ind_strength *= new_strength;
	}

	void Protector::defend() const {};

	Wizard::Wizard(const string& name, int strength) : Protector(name, strength) {}

	void Wizard::defend() const {
		cout << "POOF" << endl;
	}

	Warrior::Warrior(const string& name, int strength) : Protector(name, strength) {}

	void Warrior::defend() const {
		cout << this->getPname() << " says: Take that in the name of my lord, " << this->getBossname() << endl;
	}

	Archer::Archer(const string& name, int strength) : Warrior(name, strength) {}

	void Archer::defend() const {
		cout << "TWANG! ";
		Warrior::defend();
	}

	Swordsman::Swordsman(const string& name, int strength) : Warrior(name, strength) {}

	void Swordsman::defend() const {
		cout << "CLANG! ";
		Warrior::defend();
	}

}
