#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class a {
	private:
		int hp, atk, def, critr, critd, sp;
		string name;
	
	public:
		a() {
			hp = 0;
			atk = 0;
            def = 0;
            critr = 0;
            critd = 0;
            sp = 0;
            name = "";
		}

        void init(int hp, int atk, int def, int critr, int critd, int sp, const string& name) {
            this->hp = hp;
            this->atk = atk;
            this->def = def;
            this->critr = critr;
            this->critd = critd;
            this->sp = sp;
            this->name = name;
        }

        string getName() {
            return name;
        }

        int getHP() {
            return hp;
        } 

        void show() {
            cout << "Name: " << name << endl;
            cout << "HP: " << hp << endl;
            cout << "ATK: " << atk << endl;
            cout << "DEF: " << def << endl;
            cout << "CRIT Rate: " << critr << "%" << endl;
            cout << "CRIT DMG: " << critd << "%" << endl;
            cout << "SP: " << sp << endl;
        }

        void attack(a& target) {
            int damage = atk - target.def;
            if (damage < 0) damage = 0;

            // Calculate critical hit
            int critChance = rand() % 100;
            if (critChance < critr) {
                damage = damage * (100 + critd) / 100;
                cout << name << " lands a critical hit!" << endl;
            }

            target.hp -= damage;
            if (target.hp < 0) target.hp = 0;

            cout << name << " attacks " << target.name << " for " << damage << " damage!" << endl;
        }

        void heal() {
            int amount = rand() % sp;
            hp += amount;
            cout << name << " heals for " << amount << " HP!" << endl;
        }
};

void c1action(a& character1, a& character2) {
    int action;
    cout << "Choose action for " << character1.getName() << ": 1. Attack 2. Heal: ";
    cin >> action;
    if (action == 1) {
        character1.attack(character2);
    } else if (action == 2) {
        character1.heal();
    } else {
        cout << "Invalid action!" << endl;
    }
}

void c2action(a& character1, a& character2) {
    int action;
    cout << "Choose action for " << character2.getName() << ": 1. Attack 2. Heal: ";
    cin >> action;
    if (action == 1) {
        character2.attack(character1);
    } else if (action == 2) {
        character2.heal();
    } else {
        cout << "Invalid action!" << endl;
    }
}

int main() {
    while(true) {
        a character1, character2;

        
        int hp, atk, def, critr, critd, sp;
        char name[50];
        cout << "Enter character 1 name: ";
        cin >> name;
        cout << "Enter character 1 details (HP ATK DEF CRIT_RATE CRIT_DMG SP): ";
        cin >> hp >> atk >> def >> critr >> critd >> sp;
        character1.init(hp, atk, def, critr, critd, sp, name);

        cout << "Enter character 2 name: ";
        cin >> name;
        cout << "Enter character 2 details (HP ATK DEF CRIT_RATE CRIT_DMG SP): ";
        cin >> hp >> atk >> def >> critr >> critd >> sp;
        character2.init(hp, atk, def, critr, critd, sp, name);

        while(character1.getHP() > 0 && character2.getHP() > 0) {
            c1action(character1, character2);
            if (character2.getHP() <= 0) {
                cout << character2.getName() << " has been defeated!" << endl;
                break;
            }

            c2action(character2, character1);
            if (character1.getHP() <= 0) {
                cout << character1.getName() << " has been defeated!" << endl;
                break;
            }
        }

        return 0;
    }
}