#pragma once
#include <vector>
#include <string>


struct Attributes {
	int strength;
	int agility;
};

struct room_location {
	int x;
	int y;
};

class Item {
public:
	// Korrektur: hier ist es sinnvoll, das Gewicht bei der Initialisierung
	// gleich zu übergeben !
	Item(std::string name_of_item, float item_weight);
	~Item();
	Attributes getModificators();
	//Korrektur: Setter für Attribut-Modifikatoren hinzugefügt !
	void setModificators(Attributes attrib_mods);
	float getWeight();
protected:
	std::string name;
	float weight;
	Attributes attrib_modificators;
};


class TreasureChest : public Item {
public:
	TreasureChest();
	~TreasureChest();
	std::vector<Item> getContents();
	void addItem(Item* item);
	void removeItem(Item* item);
	bool isEmpty();
private:
	std::vector<Item> contents;
	// float capacity;
};

class AmuletOfFertility : public Item {

};

class Creature {
public:
	Creature(std::string name_of_creature);
	~Creature();

	std::string getName();
	bool addItem(Item* item);
	// Korrektur: setter für max_weight hinzugefügt!
	void setMaxWeight(float max_w);

	void setModificators(Attributes attrib_mods);
	// Korrektur: setter für location hinzugefügt!
	void setCurrentLocation(room_location current_loc);
	void setCurrentLocation(int x, int y);

	//Korrektur: Setter für Attribut-Modifikatoren hinzugefügt !
	void setAttributes(Attributes attrib_mods);

protected:
	std::string name;
	// Maximales Gewicht, welches das Lebewesen tragen kann !
	float max_weight;
	std::vector<Item*> carried_items;
	Attributes attribs;
	room_location current_location;
};

class Hero : public Creature {
public:

	Hero(std::string name_of_creature) : Creature(name_of_creature) {

	}

};

class Monster : public Creature {
public:

	Monster(std::string name_of_creature) : Creature(name_of_creature) {

	}
	~Monster(){}


};

class Weapon : public Item {
public:

	Weapon(std::string name_of_item, float item_weight) :Item(name_of_item, item_weight) {

	}

};

// Raum
class Room {
public:
	Room();
	~Room();
	void addItem(Item *item);
	void addCreature(Creature *creatures);
	std::vector<Item*> getItems();
	std::vector<Creature*> getCreatures();

private:
	std::vector<Item*> items_in_room;
	std::vector<Creature*> creatures_in_room;
};

// Der Dungeon
class Dungeon {
public:
	// korrektur: höhe, breite !
	Dungeon(int , int);
	~Dungeon();
	Room* getRoom(int x, int y);

private:
	int width, height;
	Room **rooms;
};

class Game {
public:
	Game(int dungeon_height, int dungeon_width, int number_of_monsters);
	~Game();

	Creature* fight(Creature*, Creature*);

private:
	// the dungeon !
	// Korrektur: Zeiger !
	Dungeon* dungeon;

	std::vector<Monster> monsters;

	//The hero!
	Hero *gregor_bob;

};
