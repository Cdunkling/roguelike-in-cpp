#include <iostream>
#include <string>
#include <array>


using namespace std;
class inventory{
protected:
// The player's inventory
array<string,10> items;
public:
// sets up the array so that the slots are empty
void init(){
for (int i=0; i<10 ; i++){
 items[i]="Empty";
 }
}

array <string, 10> getitems(){
return items;

}

void ShowInventory()
{

	cout << "Inventory" << endl;
	cout << "---------"<< endl;
	for( int i = 0; i < items.size(); i++ )
	{
		// Grab the item type being stored in this inventory slot
		cout << i+1 << ":" <<items[i] << endl;

	}
}



// Get Function
//	User command function which attempts to pick up an item lying on the ground.
void Get( void )
{
	// Run through the inventory, checking for the first available slot
    for( int i = 0; i < 10; i++ )
    {
            // Found an open slot?
            if( items[i] == "Empty" )
            {
                    // If so, move the item to the slot and remove it from the world
                    items[i] = "Test Item";


                    // Finished the command
                    return;
            }

    }

    // If execution gets here, it means that there is no open slots available.

    return;         // ABORT!


 }


};


int main(void)
{
    inventory test;
    test.init();

    // Initialize the inventory

	// Main game loop
	while( true )
	{
		// Draw the inventory
		test.ShowInventory();

		//For the user input
		string keypress;
		cin >> keypress;

		if (keypress=="g"){
			// Get item
            test.Get();
	}
	}
	// If execution reaches here, the program is finished
	return 0;
}
