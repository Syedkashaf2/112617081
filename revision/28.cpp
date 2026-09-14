class Player {
private:
  int health{};

public:
  // ddecleration
  void setHealth(int h);
  void takeDamage(int damage);
};

void Player::setHealth(int h) { health = h; }

void Player::takeDamage(int damage) { health = health - damage; }

int main() {
  Player p1;
  p1.setHealth(100);
  return 0;
}
