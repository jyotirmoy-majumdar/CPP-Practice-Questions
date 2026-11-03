/*
Create an enum class named CharacterState:
- IDLE
- WALKING
- RUNNING
- ATTACKING
- DEAD
1. Store the current state of a character.
2. Create a function that receives the state and displays its description.
3. Create another function that determines whether the character can move.
   - IDLE → Yes
   - WALKING → Yes
   - RUNNING → Yes
   - ATTACKING → No
   - DEAD → No
4. Ask the user to select a new state.
5. Display the state and whether movement is allowed. */

#include <iostream>
using namespace std;

enum class CharacterState
{
    IDLE = 1,
    WALKING,
    RUNNING,
    ATTACKING,
    DEAD
};

void DisplayState(CharacterState state);
bool MovementChecker(CharacterState state);

void DisplayState(CharacterState state)
{
    switch (state)
    {
    case CharacterState::IDLE:
        cout << "The character is in IDLE state " << endl;
        break;

    case CharacterState::WALKING:
        cout << "The character is in WALKING state " << endl;
        break;

    case CharacterState::RUNNING:
        cout << "The character is in RUNNING state " << endl;
        break;

    case CharacterState::ATTACKING:
        cout << "The character is in ATTACKING state " << endl;
        break;

    case CharacterState::DEAD:
        cout << "The character is in DEAD state " << endl;
        break;
    }
}

bool MovementChecker(CharacterState state)
{
    // This function is for the determining whether the state is a movement or not
    if (state == CharacterState::ATTACKING || state == CharacterState::DEAD)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int choice;
    cout << " ----------- CHARACTER STATE -------------- " << endl;
    cout << " |           1 : IDLE                      |" << endl;
    cout << " |           2 : WALKING                   |" << endl;
    cout << " |           3 : RUNNING                   |" << endl;
    cout << " |           4 : ATTACKING                 |" << endl;
    cout << " |           5 : DEAD                      |" << endl;
    cout << " -------------------------------------------" << endl;
    cout << "Enter your choice : " << endl;
    cin >> choice;

    // Input while it meets the criteria
    while (choice < 1 || choice > 5)
    {
        cout << "Wrong Choice " << endl;
        cout << "Enter your choice again: " << endl;
        cin >> choice;
    }

    // Typecasting the choice to its Character State to the variable state
    CharacterState state = static_cast<CharacterState>(choice);

    DisplayState(state);

    if (MovementChecker(state) == false)
    {
        cout << "THE CHARACTER MOVEMENT IS NOT POSSIBLE" << endl;
    }
    else
    {
        cout << "THE CHARACTER MOVEMENT IS POSSIBLE" << endl;
    }
    return 0;
}