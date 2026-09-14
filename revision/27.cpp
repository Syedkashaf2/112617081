class Player {
private:
  int health;
  int score;

public:
  void setHealth(int h) {
    health = h;
    if (health < 0) {
      health = 0;
    }
  }

  void takeDamage(int damage) { health = health - damage; }
};

int main() {
  Player p1;
  // p1.health = 100; Error because the health is private.
  p1.setHealth(100);
  p1.takeDamage(10);

  return 0;
}
