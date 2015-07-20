#ifndef     SAVE_HPP_
#define     SAVE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "AObject.hpp"
#include "Character.hpp"
#include "Player.hpp"
#include "AObject.hpp"

class Save
{
public:
    Save();
    ~Save();
public:
    void saveFile(std::string const& name, int width, int height, std::vector<Player *> players, int **map, std::vector<int> setting);
};

#endif