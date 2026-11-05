/*
1. Create two enum classes
CharacterClass
- WARRIOR
- MAGE
- ARCHER
CharacterStatus
- ALIVE
- STUNNED
- DEFEATED
2. Create a struct named Character
It should contain:
- name — string
- characterClass — CharacterClass
- health — integer
- status — CharacterStatus
3. Store multiple characters
- Ask the user how many characters they want to register (maximum 5).
- Store them in an array of structs.
- Use a loop to fill their information.
- Let the user select their character class using an integer menu.
- Initially, every character should have ALIVE status.
4. Create a function: DisplayCharacter
Receives one Character and displays:
- Name
- Character class
- Health
- Current status
Use switch to display the enum descriptions.
5. Create a function: CheckStatus
Receives one Character and determines their status based on health:
Health	Status
Greater than 50	ALIVE
1–50	STUNNED
0 or below	DEFEATED

The function must return a CharacterStatus.
6. Create a function: CanAttack
Receives one Character and returns a bool.

Rules:
- ALIVE → Can attack (true)
- STUNNED → Cannot attack (false)
- DEFEATED → Cannot attack (false)
7. Create a battle simulation
After registering all characters:
1. Display all registered characters.
2. Ask the user to select a character.
3. Ask how much damage that character receives.
4. Subtract the damage from their health.
5. Update their status using CheckStatus().
6. Display their updated information.
7. Check whether they can attack using CanAttack().
Allow the user to repeat this process for another character until they choose to exit.
8. Final statistics
When the user exits, display:
- Total number of characters.
- Number of ALIVE characters.
- Number of STUNNED characters.
- Number of DEFEATED characters.
- Name of the character with the highest remaining health.
*/

#include <iostream>
#include <string>

using namespace std;

enum class CharacterClass
{
    // enum class for the type of character
    WARRIOR = 1,
    MAGE,
    ARCHER
};

enum class CharacterStatus
{
    // enum class for the charracter status
    ALIVE = 1,
    STUNNED,
    DEFEATED
};

struct Character
{
    // a structure
    string name;
    int health;
    CharacterClass charclass;
    CharacterStatus charsts;
};

// function prototyping
void DisplayCharacter(Character);
CharacterStatus CheckStatus(Character);
bool CanAttack(Character);

void DisplayCharacter(Character c)
{
    // a fucntion to print the character registry: name, type, status
    cout << " -------------------- CHARACTER REGISTRY ---------------------- " << endl;
    cout << "NAME : " << c.name << endl;
    cout << "HEALTH : " << c.health << endl;

    switch (c.charclass)
    {
    case CharacterClass::WARRIOR:
        cout << "The character is WARRIOR " << endl;
        break;

    case CharacterClass::MAGE:
        cout << "The character is MAGE " << endl;
        break;

    case CharacterClass::ARCHER:
        cout << "The character is ARCHER " << endl;
        break;
    }

    switch (c.charsts)
    {
    case CharacterStatus::ALIVE:
        cout << "The character is ALIVE " << endl;
        break;

    case CharacterStatus::STUNNED:
        cout << "The character is STUNNED " << endl;
        break;

    case CharacterStatus::DEFEATED:
        cout << "The character is DEFEATED " << endl;
        break;
    }
}

CharacterStatus CheckStatus(Character c1)
{
    // function to check whether the character status based on its health
    int h = c1.health;
    if (h > 50)
    {
        return CharacterStatus::ALIVE;
    }
    else if (h >= 1 && h <= 50)
    {
        return CharacterStatus::STUNNED;
    }
    else
    {
        return CharacterStatus::DEFEATED;
    }
}

bool CanAttack(Character c3)
{
    // a fuction that returns whether a character can attack or not based on its health parameter
    switch (c3.charsts)
    {
    case CharacterStatus::ALIVE:
        return true;

    case CharacterStatus::DEFEATED:
    case CharacterStatus::STUNNED:
        return false;

    default:
        return false;
    }
}

int main()
{
    cout << " ------------------- REGISTER THE CHARACTERS ----------------------- " << endl;
    int charnum, i;
    cout << "Enter the number of characters you want to register :" << endl;
    cin >> charnum;
    while (charnum < 1 || charnum > 5)
    {
        cout << "Can not register more than 5 characters " << endl;
        cout << "Please enter again :" << endl;
        cin >> charnum;
    }

    Character character[5];

    for (i = 0; i < charnum; i++)
    {
        // for loop to register each character with repeated no of times
        cout << "Enter Character Name, Health, Character Class and Character Status :" << endl;
        cin >> character[i].name;
        cin >> character[i].health;
        cout << '\n';
        cout << "Enter the choice for the character class :" << endl;
        cout << "1 : WARRIOR" << endl;
        cout << "2 : MAGE" << endl;
        cout << "3 : ARCHER" << endl;

        int choice;

        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cout << "WRONG CHOICE " << endl;
            cout << "Enter the choice again :" << endl;
            cout << "1 : WARRIOR" << endl;
            cout << "2 : MAGE" << endl;
            cout << "3 : ARCHER" << endl;
            cin >> choice;
        }

        character[i].charclass = static_cast<CharacterClass>(choice);
        character[i].charsts = CharacterStatus::ALIVE;
    }

    for (i = 0; i < charnum; i++)
    {
        character[i].charsts = CheckStatus(character[i]);
    }

    for (i = 0; i < charnum; i++)
    {
        if (CanAttack(character[i]) == true)
        {
            cout << "THE CHARACTER CAN ATTACK " << endl;
        }
        else
        {
            cout << "THE CHARACTER CAN NOT ATTACK " << endl;
        }
    }

    int battlechoice;
    cout << "Enter 1 to continue to battle and 0 to exit the battle ";
    cin >> battlechoice;

    while (battlechoice != 1 && battlechoice != 0)
    {
        cout << "WRONG INPUT " << endl;
        cout << "Enter again : ";
        cin >> battlechoice;
    }

    while (battlechoice == 1)
    {
        // while loop to simulate the battle conditions
        for (i = 0; i < charnum; i++)
        {
            DisplayCharacter(character[i]);
        }

        int selectedCharacter;

        cout << "Select a character:" << endl;
        cin >> selectedCharacter;

        while (selectedCharacter < 1 || selectedCharacter > charnum)
        {
            cout << "Invalid selection. Enter again: ";
            cin >> selectedCharacter;
        }

        int damage;
        cout << "Enter the amount of damage you want to cause to the selected character ";
        cin >> damage;

        // damage calculation of the particular character selected
        character[selectedCharacter - 1].health = character[selectedCharacter - 1].health - damage;
        character[selectedCharacter - 1].charsts = CheckStatus(character[selectedCharacter - 1]);

        DisplayCharacter(character[selectedCharacter - 1]);

        if (CanAttack(character[selectedCharacter - 1]) == true)
        {
            cout << "The character CAN ATTACK " << endl;
        }
        else
        {
            cout << "The character CAN NOT ATTACK " << endl;
        }

        cout << "Enter again 1 to continue to battle and 0 to exit the battle :" << endl;
        cin >> battlechoice;

        while (battlechoice != 1 && battlechoice != 0)
        {
            cout << "WRONG INPUT " << endl;
            cout << "Enter again : ";
            cin >> battlechoice;
        }

        if (battlechoice == 0)
        {
            break;
        }
    }

    int alivecount = 0, stunnedcount = 0, defeatedcount = 0;

    for (i = 0; i < charnum; i++)
    {
        // for loop to count the characters based on their status
        if (character[i].charsts == CharacterStatus::ALIVE)
        {
            alivecount = alivecount + 1;
        }
        else if (character[i].charsts == CharacterStatus::STUNNED)
        {
            stunnedcount = stunnedcount + 1;
        }
        else if (character[i].charsts == CharacterStatus::DEFEATED)
        {
            defeatedcount = defeatedcount + 1;
        }
    }

    cout << " -------------- CHARACTER NUMBER STATICS -------------- " << endl;
    cout << "Total number of characters are : " << charnum << endl;
    cout << "Number of ALIVE CHARACTERS : " << alivecount << endl;
    cout << "Number of STUNNED CHARACTERS : " << stunnedcount << endl;
    cout << "Number of DEFEATED CHARACTERS : " << defeatedcount << endl;

    int maxhealthind = 0;

    for (i = 1; i < charnum; i++)
    {
        // for loop to find the index of the character with the maximum health
        if (character[i].health > character[maxhealthind].health)
        {
            maxhealthind = i;
        }
    }
    cout << "Character with the maximum health : " << character[maxhealthind].name << endl;
    cout << "The health is : " << character[maxhealthind].health;

    return 0;
}
