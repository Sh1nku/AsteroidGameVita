#pragma once

enum TYPE {
  GAMEOBJECT, PLAYER, ASTEROID
};

class GameObject {
public:
  GameObject();
  virtual ~GameObject();
  virtual void hit();
  virtual TYPE getType();
};
