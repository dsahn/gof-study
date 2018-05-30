/* https://en.wikipedia.org/wiki/Factory_method_pattern 
 * shared_ptr 을 활용하여 만듬 */
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Room {
public:
    Room() { cout << "normal room" << endl; }
    void connect(shared_ptr<Room> rhs) {}
};

class MagicRoom : public Room {
public:
    MagicRoom() { cout << "magic room" << endl; }
};

class MazeGame {
public:
    MazeGame() : rooms() {}
    void BuildMaze()
    {
        shared_ptr<Room> room1 = makeRoom();
        shared_ptr<Room> room2 = makeRoom();
        room1->connect(room2);
        rooms.push_back(room1);
        rooms.push_back(room2);
    }
protected:
    virtual shared_ptr<Room> makeRoom() = 0;
private:
    vector<shared_ptr<Room>> rooms;
};

class MagicMazeGame : public MazeGame {
    virtual shared_ptr<Room> makeRoom() {
        return make_shared<MagicRoom>();
    }
};

class OrdinaryMazeGame : public MazeGame {
    virtual shared_ptr<Room> makeRoom() {
        return make_shared<Room>();
    }
};

int main()
{
    MazeGame *ordinarygame = new OrdinaryMazeGame();
    MazeGame *magicgame = new MagicMazeGame();

    ordinarygame->BuildMaze();
    magicgame->BuildMaze();
    return 0;
}
