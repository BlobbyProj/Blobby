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
    
    	// method for checking the type of an object
		// param key - the key for the object you wish to know the type of
		// return unsigned int - either returns the int that represents the object type (defined in object.h) or returns 0
		// pre-conditions - a object exists
		// post-condition - you know the type of the object
		unsigned int objects_type(unsigned int key);
    
        // method for checking if an object exists
        // param key - the key for the object you want to check
        // return bool - returns true if object is found, false if it is not found
        // pre-conditions - you have an object key you want to check
        // post-conditions - you know whether or not the object is in the objects map
		bool objects_exist(unsigned int key);
		
		// method for getting a pointer to a desired object
		// param key - the key of the object you want to get
		// return Object* - returns a pointer to the desired object
		// pre-conditions - the object must exist
		// post-conditions - you now have a pointer to the object
		Object *objects_get(unsigned int key);
    
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
		
		// method for checking the type of an pause_object
		// param key - the key for the pause_object you wish to know the type of
		// return unsigned int - either returns the int that represents the pause_object type (defined in object.h) or returns 0
		// pre-conditions - a pause_object exists
		// post-condition - you know the type of the pause_object
		unsigned int pause_objects_type(unsigned int key);
    
        // method for checking if an pause_object exists
        // param key - the key for the pause_object you want to check
        // return bool - returns true if object is found, false if it is not found
        // pre-conditions - you have an pause_object key you want to check
        // post-conditions - you know whether or not the object is in the pause_object map
		bool pause_objects_exist(unsigned int key);
		// method for getting a pointer to a desired pause_object
		// param key - the key of the pause_object you want to get
		// return Object* - returns a pointer to the desired pause_object
		// pre-conditions - the pause_object must exist
		// post-conditions - you now have a pointer to the pause_object
		Object *pause_objects_get(unsigned int key);
    
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
		
        // called every iteration of the game loop
        // Calls step() on each object or paused object, depending on if game is paused
		void step();
    
        // called every time there is an event
        // Calls events() on each object or paused object, depending on if game is paused
		void events(SDL_Event *event);
    
        // calls screenmanager->texture_apply to add background image to texture
        // Calls draw() on each object or paused object, depending on if game is paused
        // post-conditions all objects appear on texture
		void draw();
    
        // Calls load_surfaces() on each object or paused object, depending on if game is paused
        // post-conditions all objects have their images loaded
		void load_surfaces();
		
		//struct to represent a collision, contains the OID (id of the object) and type of Collision
		struct Collision {
			unsigned int oid;
			unsigned int type;
		};

        // method to check for collisions between objects
        // param OID - the object id that you want to check
        // return std::vector<Collisions>* - returns a struct that contains the Object id and the direction of collision
        // post-conditions - know which objects have collided with the object who's id is OID
		std::vector<Collision>* get_collisions(unsigned int OID);
};

#endif
