#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include <map>
#include "globals.h"
#include "screenmanager.h"
#include "object.h"
#include "rectangle.h"

class ObjectManager {
	private:
		//std::vector<Object*> objects;
		//std::vector<Object*> pause_objects;
		unsigned int count;
		unsigned int pause_count;

		std::map<unsigned int,Object*> objects;
		std::map<unsigned int,Object*> pause_objects;
		
	public:
		// constructor for ObjectManager - controls the objects in the game
		// pre-conditions  ObjectManager does not yet exist
		// post-conditions ObjectManager exists
					
		ObjectManager() : count(0), pause_count(0) {};
		
		// destructor for ObjectManager - deletes instance of ObjectManager object
		// pre-conditions  ObjectManager exists
		// post-conditions ObjectManager no longer exists
		~ObjectManager();
		
		// method for adding objects to the objects map
		// param *object - pointer to an Object
		// return unsigned int - this is the objects id
		// pre-condition - an object exists
		// post-conditions - an object has been added to the object map 	
		unsigned int objects_add(Object *object);
    
		unsigned int objects_type(unsigned int key);
    
		// method for checking if an object exists
		// param key - the key for the object you want to check
		// return bool - returns true if object is found, false if it is not found
		// pre-conditions - you have an object key you want to check
		// post-conditions - you know whether or not the object is in the objects map
		bool objects_exist(unsigned int key);
    
		// method to delete a specific object from the objects map
		// param key - the key for the object you wish to delete
		// return bool - returns true if object deleted, false if doesn't exist
		// pre-conditions- the object exists in the objects map
		// post-conditions - the object has been deleted from the objects map
    
		bool objects_delete(unsigned int key);
		// method to delete all the objects in the objects map
		// pre-conditions - objects map exists
		// post-conditions - the objects map is empty
    
		void objects_clear();
 
		// method for adding objects to the pause_objects map
		// param *object - pointer to an Object
		// return unsigned int - this is the pause_object's id
		// pre-condition - an object exists
		// post-conditions - an object has been added to the pause_objects map 
		unsigned int pause_objects_add(Object *object);

		unsigned int pause_objects_type(unsigned int key);

		// method for checking if an pause_object exists
		// param key - the key for the pause_object you want to check
		// return bool - returns true if object is found, false if it is not found
		// pre-conditions - you have an pause_object key you want to check
		// post-conditions - you know whether or not the object is in the pause_object map
		bool pause_objects_exist(unsigned int key);
    
		// method to delete a specific object from the pause_object map
		// param key - the key for the pause_object you wish to delete
		// return bool - returns true if pause_object deleted, false if doesn't exist
		// pre-conditions- the object exists in the pause_object map
		// post-conditions - the object has been deleted from the pause_object map
		bool pause_objects_delete(unsigned int key);
		// method to delete all the objects in the pause_objects map
		// pre-conditions - pause_objects map exists
		// post-conditions - the pause_objects map is empty
		void pause_objects_clear();
		
		void step();
		void events(SDL_Event *event);
		void draw();
		void load_surfaces();

		struct Collision {
			unsigned int oid;
			unsigned int type;
		};

		std::vector<Collision>* get_collisions(unsigned int OID);
=======
		
		// method to check for collisions between objects
		// param OID - the object id that you want to check
		// return std::vector<unsigned int>* - returns a struct that contains the Object id and the direction of collision
		// post-conditions - know which objects have collided with the object who's id is OID
		std::vector<unsigned int>* get_collisions(unsigned int OID);
>>>>>>> 0b2f447facbd9266941b8adfcfc3375f0007bbcf
};

#endif
