#include <string>
#include <vector>

class Profile{
  std::string name;
  std::string city;
  std::string country;
  int age;
  std::vector<std::string> hobbies;

  public:
  //Constructors
    Profile(std::string new_name, int new_age, std::string new_city, std::string new_country);

  //Setters
    void set_name(std::string new_name);
    void set_age(int new_age);
    void set_city(std::string new_city);
    void set_country(std::string new_country);


    void view();

    //Getters
    std::string get_name();
    int get_age();
    std::string get_city();
    std::string get_country();
    
};
