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
		// Get the item being stored in this inventory slot
		cout << i+1 << ":" <<items[i] << endl;

	}
}



// Get Function
//function which attempts to pick up an item lying on the ground.
void Get( string name )
{
	// Run through the inventory, checking for the first available slot
    for( int i = 0; i < 10; i++ )
    {
            // Found an open slot?
            if( items[i] == "Empty" )
            {
                    // If so, move the item to the slot and overwrite the empty slot with item
                    items[i] = name;


                    // Finished the command
                    return;
            }

    }

    // If execution gets here, it means that there is no open slots available.

    return;         // ABORT!


 }


};

// function that links the inventory to the keys that have to be pressed.
inventory invmain(string keypress,string name,inventory x)
	{
            if (keypress=="g"){
			// Get item
            x.Get(name);

	}
	else if (keypress=="i"){
			// show inventory when i is pressed
            x.ShowInventory();
	 }
	 return x;
	}



//testing if more than set amount of item can be added to inventory
// test part will simulate getting items and adding them to inventory and also simulate the pressing of the 'I' key

int main()
{
    // Initialize the inventory
    inventory test;
    test.init();
    array<string,10> test_item = {"Sword","bow","shield","Rusty Pipe","Arrows","hp potion","Elixir","pistol","Knife","Rifle"};
    for (string s:test_item){
    test=invmain("g",s,test);
    test=invmain("i","",test);
    if (test_item.size() > 10)
    {
        cout << "The Test Failed" <<endl;
    }
    else
         cout << "The Test passed"<<endl;
     }
	// If execution reaches here, the program is finished
	return 0;
}
