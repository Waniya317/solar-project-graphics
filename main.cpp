//#include <SFML/Graphics.hpp>
//#include<iostream>
//#include<string>
//using namespace std;
//using namespace sf;
//int main()
//{
//	
//	RenderWindow window(VideoMode(800, 600), "Main Menu");
//	Font font;
//	if (!font.loadFromFile("C:\\Users\\user\\source\\repos\\sfml practice\\Debug\\arial.ttf")) {
//		cerr << "Could not load font\n";
//		return -1;
//	}
//	Text companyLabel("Welcome to Our Solar Cost Estimator",font,36);
//	companyLabel.setPosition(100, 150);
//	Text nameLabel("Enter your Name:", font, 36);
//	nameLabel.setPosition(100, 250);
//	Text cnicLabel("Enter your CNIC:", font, 36);
//	cnicLabel.setPosition(100, 350);
//	string nameInput = "";
//	string cnicInput = "";
//
//	Text nameField(nameInput, font, 36);
//	nameField.setPosition(350, 250);
//	nameField.setFillColor(sf::Color::White);
//
//	Text cnicField(cnicInput, font, 36);
//	cnicField.setPosition(350, 350);
//	cnicField.setFillColor(sf::Color::White);
//	Text instruction("Press Enter to submit", font, 20);
//	instruction.setPosition(300, 400);
//	instruction.setFillColor(sf::Color::Yellow);
//	bool editingName = true;
//
//    while (window.isOpen()) {
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == Event::Closed) {
//                window.close();
//            }
//
//           
//            if (event.type == Event::TextEntered) {
//                
//                if (event.text.unicode == '\b') {
//                    if (editingName && !nameInput.empty()) {
//                        nameInput.pop_back();  
//                    }
//                    else if (!editingName && !cnicInput.empty()) {
//                        cnicInput.pop_back();  
//                    }
//                }
//                
//                else if (event.text.unicode == '\r') {
//                    if (editingName) {
//                        editingName = false;  
//                    }
//                    else if (cnicInput.length() == 13) {
//                        cout << "Name: " << nameInput << "\n";
//                        cout << "CNIC: " << cnicInput << "\n";
//                        window.close();  
//                    }
//                    else {
//                        cout<< "CNIC must be 13 digits long.\n";
//                    }
//                }
//                
//                else if (event.text.unicode < 128) {
//                    if (editingName) {
//                       
//                        nameInput += static_cast<char>(event.text.unicode);
//                    }
//                    else {
//                        
//                        if (isdigit(event.text.unicode) && cnicInput.length() < 13) {
//                            cnicInput += static_cast<char>(event.text.unicode);
//                        }
//                    }
//                }
//            }
//        }
//        
//        nameField.setString(nameInput);
//        cnicField.setString(cnicInput);
//
//        
//        window.clear();
//        window.draw(companyLabel);
//        window.draw(nameLabel);
//        window.draw(cnicLabel);
//        window.draw(nameField);
//        window.draw(cnicField);
//        window.draw(instruction);
//        window.display();
//    }
//
//    return 0;
//}
//
//
//
//
//
//









#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Main Menu");
    Font font;
    if (!font.loadFromFile("C:\\Users\\user\\source\\repos\\sfml practice\\Debug\\arial.ttf")) {
        cerr << "Could not load font\n";
        return -1;
    }

    Text companyLabel("Welcome to Our Solar Cost Estimator", font, 36);
    companyLabel.setPosition(100, 50);

    Text nameLabel("Enter your Name:", font, 36);
    nameLabel.setPosition(100, 150);

    Text cnicLabel("Enter your CNIC:", font, 36);
    cnicLabel.setPosition(100, 250);

    string nameInput = "";
    string cnicInput = "";

    Text nameField(nameInput, font, 36);
    nameField.setPosition(350, 150);
    nameField.setFillColor(sf::Color::White);

    Text cnicField(cnicInput, font, 36);
    cnicField.setPosition(350, 250);
    cnicField.setFillColor(sf::Color::White);

    Text instruction("Press Enter to submit", font, 20);
    instruction.setPosition(300, 400);
    instruction.setFillColor(sf::Color::Yellow);

    bool editingName = true;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            // Handle Text Input
            if (event.type == Event::TextEntered) {
                // Handle Backspace
                if (event.text.unicode == '\b') {
                    if (editingName && !nameInput.empty()) {
                        nameInput.pop_back();  // Remove last character from name input
                    }
                    else if (!editingName && !cnicInput.empty()) {
                        cnicInput.pop_back();  // Remove last character from CNIC input
                    }
                }
                // Handle Enter key to switch input or submit
                else if (event.text.unicode == '\r') { // Enter key
                    if (editingName) {
                        editingName = false;  // Switch to CNIC input
                    }
                    else if (cnicInput.length() == 13) {
                        cout << "Name: " << nameInput << "\n";
                        cout << "CNIC: " << cnicInput << "\n";
                        window.close();  // Close the window after input is complete
                    }
                    else {
                        cout << "CNIC must be 13 digits long.\n";
                    }
                }
                // Handle regular character input
                else if (event.text.unicode < 128) { // ASCII characters only
                    if (editingName) {
                        nameInput += static_cast<char>(event.text.unicode);  // Append to name input
                    }
                    else {
                        if (isdigit(event.text.unicode) && cnicInput.length() < 13) {
                            cnicInput += static_cast<char>(event.text.unicode);  // Append digits to CNIC
                        }
                    }
                }
            }
        }

        // Update displayed text
        nameField.setString(nameInput);
        cnicField.setString(cnicInput);

        // Draw everything
        window.clear();
        window.draw(companyLabel);
        window.draw(nameLabel);
        window.draw(cnicLabel);
        window.draw(nameField);
        window.draw(cnicField);
        window.draw(instruction);
        window.display();
    }

    return 0;
}

