enum Direction { NORTH, SOUTH, EAST, WEST };

// interface class
class MapSite {
public:
    virtual void Enter() = 0;
};

class Room : public MapSite {
public:
    Room(int RoomNo);

    MapSite* GetSide(Direction) const;
    void SetSide(Direction, MapSite*);

    virtual void Enter();
private:
    MapSite* _sides[4]; // 4방향, MapSite의 서브클래스가 옴
    int _roomNumber;
};

class Wall : public MapSite {
public:
    Wall();

    virtual void Enter();
};

class Door : public MapSite {
public:
    Door(Room* = 0, Room* = 0);

    virtual void Enter();
    Room* OtherSideFrom(Room*);

private:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
};

class Maze {
public:
    Maze();

    void AddRoom(Room*);
    Room* RoomNo(int) const; //room searching 
private:
    // ...
};
