#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::cout << "Welcome to Fullmetal's image color mask maker.\nEnter the name of your image: \n";
	std::string path;
	std::cin >> path;

	sf::Image im;
	im.loadFromFile(path);
	sf::Color color;
	bool mode = false;
	std::cout << "Enter the mode (\n\t0 - mask this color\n\t1 - mask all except this\n)";
	std::cin >> mode;
	std::cout << "Enter color that you wonna mask: \n";
	std::cout << "R:";
	int colorValue = 0;
	std::cin >> colorValue;
	color.r = colorValue;
	std::cout << "G:";

	std::cin >> colorValue;
	color.g = colorValue;
	std::cout << "B:";
	std::cin >> colorValue;
	color.b = colorValue;
	if (!mode){
		
		im.createMaskFromColor(color);
	}
	else
	{ 
		std::vector<sf::Color> badColors;
		for(int i = 0; i < im.getSize().y; i++)
		{
			for(int j = 0; j < im.getSize().x; j++)
			{
				if(im.getPixel(j, i) != color)
				{
					badColors.push_back(im.getPixel(j, i));
				}
			}
		}
		for (int i = 0; i < badColors.size(); i++)
		{
			im.createMaskFromColor(badColors[i]);
		}
	}
	
	if(im.saveToFile(path)) std::cout << "Image successfully masked. Congrads, mate.\n";
	
	system("pause");
	return 0;
}

