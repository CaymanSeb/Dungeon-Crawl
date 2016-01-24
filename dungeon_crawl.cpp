#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

#include "dungeon_crawl.h"

/////////////////////////////
//                        //
// ITEM IMPLEMENTATION   //
//                      //
/////////////////////////
Item::Item(std::string name_of_item, float item_weight) {
	name = name_of_item;
	weight = item_weight;
}

Attributes Item::getModificators() {
	return attrib_modificators;
}

void Item::setModificators(Attributes attrib_mods) {
	attrib_modificators = attrib_mods;
}

float Item::getWeight() {
	return weight;
}

/////////////////////////////////
//                            //
// CREATURE IMPLEMENTATION   //
//                          //
/////////////////////////////

Creature::Creature(std::string name_of_creature) {
	current_location.x = 0;
	current_location.y = 0;

	name = name_of_creature;
}

std::string Creature::getName() {
	return name;
}

bool Creature::addItem(Item* item) {

	float summeGewicht = 0;

	for (std::vector<Item>::size_type x = 0; x < carried_items.size(); x++) {
		summeGewicht = summeGewicht + carried_items[x]->getWeight();
	}

	summeGewicht = summeGewicht + item->getWeight();

	if (summeGewicht > max_weight)
	{
		return false;
	}
	else {
		carried_items.push_back(item);
		return true;
	}

}

void Creature::setMaxWeight(float max_w) {
	max_weight = max_w;
}

void Creature::setCurrentLocation(room_location current_loc) {
	current_location = current_loc;
}

void Creature::setCurrentLocation(int x, int y) {
	current_location.x = x;
	current_location.x = y;
}

/////////////////////////////
//                        //
// ROOM IMPLEMENTATION   //
//                      //
/////////////////////////

Room::Room() {
	std::cout << "Room initialized !" << std::endl;
}

Room::~Room() {
	std::cout << "Room destroyed !" << std::endl;
}

void Room::addItem(Item *item) {
	items_in_room.push_back(item);
}

void Room::addCreature(Creature *creature) {
	creatures_in_room.push_back(creature);
}

std::vector<Item*> Room::getItems() {
	return items_in_room;
}

std::vector<Creature*> Room::getCreatures() {
	return creatures_in_room;
}

////////////////////////////////
//                           //
// DUNGEON IMPLEMENTATION   //
//                         //
////////////////////////////

Dungeon::Dungeon(int init_width, int init_height) {
	width = init_width;
	height = init_height;
	// initialize the dungeon
	for (int i = 0; i < width; i++) {
		std::cout << "Raum-Reihe " << i << std::endl;
		rooms[i] = new Room[height];

		for (int j = 0; j < height; j++) {
			std::cout << "Raum-Spalte " << j << std::endl;
			Room new_room;
			rooms[i][j] = new_room;
		}
	}
}

Dungeon::~Dungeon() {
	for (int i = 0; i < width; i++) {

		delete rooms[i];
	}
}

Room* Dungeon::getRoom(int x, int y) {
	// check if room actually exists !
	if (x > width && y > height) {
		return NULL;
	}
	return &rooms[x][y];
}

////////////////////////////////
//                           //
// GAME IMPLEMENTATION      //
//                         //
////////////////////////////

Game::Game(int dungeon_height, int dungeon_width, int number_of_monsters) {
	// initialize dungeon
	dungeon = new Dungeon(dungeon_width, dungeon_height);

	// initialize default weapon
	Weapon* kurzschwert = new Weapon ("Kurzschwert", 2.0);
	Attributes kurzschwert_mods;
	kurzschwert_mods.strength = 3;
	kurzschwert_mods.agility = -1;
	kurzschwert->setModificators(kurzschwert_mods);

	// initialize hero
	Hero* gregor_bob = new Hero("Gregor-Bob");
	Attributes hero_attribs;
	hero_attribs.strength = 6;
	hero_attribs.agility = 7;
	gregor_bob->setMaxWeight(10.0);
	gregor_bob->addItem(kurzschwert);
	gregor_bob->setModificators(hero_attribs);

	// initialize monsters and distribute over dungeon
	for (int i = 0; i < number_of_monsters; i++) {
		Monster* monster = new Monster("generic_monster");
		float monster_x = rand() % dungeon_width;
		float monster_y = rand() % dungeon_height;

		Attributes monster_attribs;
		monster_attribs.strength = 10;
		monster_attribs.agility = 5;
		monster->setAttributes(monster_attribs);

		monster->setCurrentLocation(monster_x, monster_y);
		dungeon->getRoom(monster_x, monster_y)->addCreature(monster);
												 }
																		}
