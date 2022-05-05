#include <iostream>
#include <string>
class Fruit {
  std::string name_;
  std::string color_;
  public:
  Fruit(const std::string& name, const std::string color): name_{name}, color_{color} {}
  
  const std::string& getName() const { return name_; }
	const std::string& getColor() const { return color_; }
	
	friend std::ostream& operator<<(std::ostream& out, const Fruit& fruit) {
    out << fruit.getName() << ' ' << fruit.getColor();
    return out;
  }
};

class Apple: public Fruit {
  double fiber_;
  public:
  Apple(const std::string& name, const std::string color, double fiber=0): Fruit{name, color}, fiber_{fiber} {}
  double getFiber() const { return fiber_; }
  friend std::ostream& operator<<(std::ostream& out, const Apple& apple) {
    out << apple.getName() << ' ' << apple.getColor() << ' ' << apple.getFiber();
    return out;
  }
};

class Banana: public Fruit {
  public:
  Banana(const std::string& name, const std::string color): Fruit{name, color} {}
};

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}
