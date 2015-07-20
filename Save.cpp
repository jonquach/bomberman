#include "Save.hpp"

Save::Save()
{

}

Save::~Save()
{

}

void        Save::saveFile(std::string const& name, int width, int height, std::vector<Player *> players, int **map, std::vector<int> setting)
{
  std::ofstream myfile;

  myfile.open (name.c_str(), std::ios::out | std::ios::binary);
  if (myfile.is_open()) {
    myfile << "<setting>\n";
    myfile << "<mode>";
    myfile << setting.at(0);
    myfile << "</mode>\n";
    myfile << "<nbJoueur>";
    myfile << setting.at(1);
    myfile << "</nbJoueur>\n";
    myfile << "<modeMap>";
    myfile << setting.at(2);
    myfile << "</modeMap>\n";
    myfile << "<mapChoice>";
    myfile << setting.at(3);
    myfile << "</mapChoice>\n";
    myfile << "</setting>\n";
    myfile << "<game>\n";
    myfile << "<map>\n";
    myfile << "<width>";
    myfile << width;
    myfile << "</width>\n";
    myfile << "<height>";
    myfile << height;
    myfile << "</height>\n";
    myfile << "</map>\n";
    for (std::vector<Player *>::iterator it = players.begin(); it != players.end(); it++)
    {
      myfile << "<player>\n";
      myfile << "<id>";
      myfile << (*it)->getCharacter()->getId();
      myfile << "</id>\n";
      myfile << "<speed>";
      myfile << (*it)->getCharacter()->getSpeed();
      myfile << "</speed>\n";
      myfile << "<nbBomb>";
      myfile << (*it)->getCharacter()->getNbBomb();
      myfile << "</nbBomb>\n";
      myfile << "</player>\n";
    }
    myfile << "------------------------\n";
    for (int x = 0; x < width; x++) {
      for (int y = 0; y < height; y++) {
	myfile << map[x][y];
      }
      myfile << "\n";
    }
  }
  myfile.close();
}

