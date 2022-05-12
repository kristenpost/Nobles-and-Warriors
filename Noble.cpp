#include "Noble.h"
#include "Protector.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;

namespace WarriorCraft {

	Noble::Noble(const string& name, int given_strength) : name(name) { strength = given_strength; }

	void Noble::battle(Noble& noble2) {
		cout << getNname() << " battles " << noble2.getNname() << endl;
		int strength1, strength2 = 0;
		strength1 = getStrength();
		strength2 = noble2.getStrength();
		// Case 1: When both nobles are dead to begin with:
		if (!(alive()) && !(noble2.alive())) {
			cout << "Oh, NO! They're both dead. Yuck!\n";
		}
		// Case 2: When a noble requests a battle with someone who's already dead
		else if (!noble2.alive()) {
			cout << "He's dead, " << getNname() << endl;
		}
		// Case 3: When the two nobles (and therefore armies) have the same strength before battle, and then both die:
		else if (strength1 == strength2) {
			updateStrength(0);
			noble2.updateStrength(0);
			defend();
			noble2.defend();
			is_alive = false;
			noble2.is_alive = false;
			cout << "Mutual Annihilation: " << getNname() << " and " << noble2.getNname() << " die at each other's hands.\n";
		}
		// Case 4: When the nobles have different strengths (and the opponent is not dead)
		else {
			defend();
			noble2.defend();
			if (strength1 > strength2) {
				float ratio = (1 - ((float)strength2 / (float)strength1));
				noble2.updateStrength(0);
				noble2.is_alive = false;
				updateStrength(ratio);
				cout << getNname() << " defeats " << noble2.getNname() << endl;
			}
			else if (strength1 < strength2) {
				float ratio = (1 - ((float)strength1 / (float)strength2));
				updateStrength(0);
				is_alive = false;
				noble2.updateStrength(ratio);
				cout << noble2.getNname() << " defeats " << getNname() << endl;
			}
		}
	}

	bool Noble::alive() { return is_alive; }

	const string& Noble::getNname() const { return name; }

	int Noble::getStrength() const { return strength; }

	void Noble::updateStrength(int new_strength) { strength *= new_strength; }

	PersonWithStrengthToFight::PersonWithStrengthToFight(const string& given_name, int given_strength) : Noble(given_name, given_strength) {}

	void PersonWithStrengthToFight::defend() const {
		cout << "Ugh!" << endl;
	}

	Lord::Lord(const string& given_name) : Noble(given_name, 0) {}

	// Hire Method
	bool Lord::hires(Protector& potential_hire) {
		// Before Lord can hire a protector, they must check to see if the protector, 
		// potential_hire, is already employed by another Noble. No transaction can take place if so.
		if (!potential_hire.is_hired()) {
			potential_hire.modify_employement("hired", *this);
			Protector* new_hire = &potential_hire;
			army.push_back(new_hire);
			updateStrength(potential_hire.getPstrength());
			return true;
		}
		return false;
	}

	// Fire Method
	bool Lord::fire(Protector& employee2fire) {
		// Before a Noble can fire a Protector, we need to make sure
		// the employee is indeed employed and the Noble is not dead
		if (!employee2fire.is_hired() || !(alive())) {
			cout << "Could not fire " << employee2fire.getPname() << endl;
			return false;
		}
		// Even if the Protector ("employee to be fired") is employed and the Noble ordering the firing
		// is alive (and therefore still able to request a battle, hire, and fire), we need to execute
		// a for loop to make sure the employee/protector to be fired is being fired by his/her
		// employer.  For example, Noble Jim can't fire Protector Xena if Xena doesn't work for Jim.
		else {
			bool fired_complete = false;
			for (size_t i = 0; i < army.size(); ++i) {
				if ((army[i]) == &employee2fire) {
					for (size_t j = i; j < army.size() - 1; j++) {
						army[j] = army[j + 1];
					}
					army.pop_back();
					fired_complete = true;
					break;
				}
			}
			if (fired_complete) {
				employee2fire.modify_employement("fired", *this);
				cout << "You don't work for me anymore " << employee2fire.getPname() << "! -- " << this->getNname() << endl;
			}
			return fired_complete;
		}
	}

	void Lord::defend() const {
		for (Protector* protector : army) {
			protector->defend();
		}
	}

	// Get Strength method (sum of all current employees strengths)
	int Lord::getStrength() const {
		int strength = 0;
		for (Protector* protector : army) {
			strength += protector->getPstrength();
		}
		return strength;
	}

	// Update Strength method
	void Lord::updateStrength(int new_strength) {
		for (Protector* protector : army) {
			protector->modifyStrength(new_strength);
		}
	}
}
