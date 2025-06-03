#include <SFML/Graphics.hpp>
#include <optional>
#include <functional>
#include <vector>
#include <string>
#include "C:\Visual Studio\SD_proj3\DataStructures_HashTableDictionary\dictionary_avl.h"

enum class Screen {
    MainMenu,
    AvlMenu,
    Display,
    TreeView
};

int main() 
{
    DictionaryAVL dict(10);
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Window", sf::State::Fullscreen);
    //sf::RenderWindow window(sf::VideoMode({1280u, 720u}), "SFML Window");
    int selectedBucket = 0;
    const int bucketCount = dict.getSize();

    sf::Font font;
    if (!font.openFromFile("GOTHICB.ttf")) return 1;

    std::vector<std::string> mainMenuItems = {"AVL Tree", "Exit"};
    int mainMenuSelected = 0;

    std::vector<std::string> avlMenuItems = {"Insert element", "Remove element", "Fill with random values", "Display", "Exit"};
    int avlMenuSelected = 0;

    Screen currentScreen = Screen::MainMenu;

    std::function<void(const AVLNode*, float, float, float)> drawTree;
    drawTree = [&](const AVLNode* node, float x, float y, float xOffset) {
        if (!node) return;

        // Нарисовать ребра к детям
        if (node->left) {
            sf::VertexArray line(sf::PrimitiveType::Lines, 2);
            line[0].position = sf::Vector2f(x, y);
            line[1].position = sf::Vector2f(x - xOffset, y + 80);
            window.draw(line);
            drawTree(node->left, x - xOffset, y + 80, xOffset / 1.7f);
        }
        if (node->right) {
            sf::VertexArray line(sf::PrimitiveType::Lines, 2);
            line[0].position = sf::Vector2f(x, y);
            line[1].position = sf::Vector2f(x + xOffset, y + 80);
            window.draw(line);
            drawTree(node->right, x + xOffset, y + 80, xOffset / 1.7f);
        }

        // Нарисовать сам узел (круг)
        sf::CircleShape circle(24);
        circle.setOrigin(sf::Vector2f(24.f, 24.f));
        circle.setPosition(sf::Vector2f(x, y));
        circle.setFillColor(sf::Color(200, 220, 255));
        circle.setOutlineColor(sf::Color::Black);
        circle.setOutlineThickness(2.f);
        window.draw(circle);

        // Нарисовать ключ
        sf::Text keyText(font, std::to_string(node->key), 20);
        keyText.setFillColor(sf::Color::Black);
        keyText.setPosition(sf::Vector2f(x - 12, y - 16));
        window.draw(keyText);
    };

    while (window.isOpen())
    {
        std::optional<sf::Event> optEvent;
        while (optEvent = window.pollEvent())
        {
            sf::Event event = *optEvent;
            if (event.is<sf::Event::Closed>()) window.close();

            if (currentScreen == Screen::MainMenu) {
                if (auto* key = event.getIf<sf::Event::KeyPressed>()) {
                    if (key->code == sf::Keyboard::Key::Up)
                        mainMenuSelected = (mainMenuSelected + mainMenuItems.size() - 1) % mainMenuItems.size();
                    if (key->code == sf::Keyboard::Key::Down)
                        mainMenuSelected = (mainMenuSelected + 1) % mainMenuItems.size();
                    if (key->code == sf::Keyboard::Key::Enter) {
                        if (mainMenuSelected == 0) {
                            currentScreen = Screen::AvlMenu;
                        }
                        if (mainMenuSelected == 1) window.close();
                    }
                }
            }

            else if (currentScreen == Screen::AvlMenu) {
                if (auto* key = event.getIf<sf::Event::KeyPressed>()) {
                    if (key->code == sf::Keyboard::Key::Up)
                        avlMenuSelected = (avlMenuSelected + avlMenuItems.size() - 1) % avlMenuItems.size();
                    if (key->code == sf::Keyboard::Key::Down)
                        avlMenuSelected = (avlMenuSelected + 1) % avlMenuItems.size();
                    if (key->code == sf::Keyboard::Key::Enter) {
                        if (avlMenuSelected == 0) {
                            // insert
                            dict.insert(12, 5);
                        }
                        if (avlMenuSelected == 1) {
                            // remove
                            dict.remove(12);
                        }
                        if (avlMenuSelected == 2) {
                            // fill random
                            dict.fillRandom(100, 1, 1000, 1, 100);

                        }
                        if (avlMenuSelected == 3) {
                            currentScreen = Screen::Display;
                        }
                        if (avlMenuSelected == 4) {
                            currentScreen = Screen::MainMenu;
                        }
                    }
                }
            }

            else if (currentScreen == Screen::Display) {
                if (auto* key = event.getIf<sf::Event::KeyPressed>()) {
                    if (key->code == sf::Keyboard::Key::Left)
                        selectedBucket = (selectedBucket + bucketCount - 1) % bucketCount;
                    if (key->code == sf::Keyboard::Key::Right)
                        selectedBucket = (selectedBucket + 1) % bucketCount;
                    if (key->code == sf::Keyboard::Key::Escape)
                        currentScreen = Screen::AvlMenu;
                    if (key->code == sf::Keyboard::Key::Enter)
                        currentScreen = Screen::TreeView; // move to tree
    }
}

            else if (currentScreen == Screen::TreeView) {
                if (auto* key = event.getIf<sf::Event::KeyPressed>()) {
                    if (key->code == sf::Keyboard::Key::Escape)
                        currentScreen = Screen::Display;
                }
            }
        }

        window.clear(sf::Color(7, 107, 148));

        if (currentScreen == Screen::MainMenu) {
            for (size_t i = 0; i < mainMenuItems.size(); ++i) {
                sf::Text text(font, mainMenuItems[i], 40);
                text.setPosition(sf::Vector2f(100.f, 100.f + i * 60.f));
                text.setFillColor(i == mainMenuSelected ? sf::Color::Yellow : sf::Color(224, 247, 198));
                window.draw(text);
            }
        }

        else if (currentScreen == Screen::AvlMenu) {
            for (size_t i = 0; i < avlMenuItems.size(); ++i) {
                sf::Text text(font, avlMenuItems[i], 36);
                text.setPosition(sf::Vector2f(120.f, 100.f + i * 55.f));
                text.setFillColor(i == avlMenuSelected ? sf::Color::Yellow : sf::Color(224, 247, 198));
                window.draw(text);
            }
        }

        else if (currentScreen == Screen::Display) {
            const int bucketCount = dict.getSize();
            const float cellWidth = 80.f;
            const float cellHeight = 50.f;
            const float gap = 10.f;
            const float totalWidth = bucketCount * cellWidth + (bucketCount - 1) * gap;
            const float startX = (window.getSize().x - totalWidth) / 2.f;
            const float startY = 200.f;

            for (int i = 0; i < bucketCount; ++i) {
                sf::RectangleShape cell(sf::Vector2f(cellWidth, cellHeight));                
                cell.setPosition(sf::Vector2f(startX + i * (cellWidth + gap), startY));
                cell.setFillColor(i == selectedBucket ? sf::Color(255, 255, 100) : sf::Color(200, 220, 255));
                cell.setOutlineColor(sf::Color::Black);
                cell.setOutlineThickness(2.f);
                window.draw(cell);

                sf::Text numText(font, std::to_string(i), 24);
                numText.setPosition(sf::Vector2f(cell.getPosition().x + 10, cell.getPosition().y + 10));
                numText.setFillColor(sf::Color::Black);
                window.draw(numText);
            }

            
        }

        else if (currentScreen == Screen::TreeView) {
            const AVLTree& tree = dict.getBucket(selectedBucket).tree;
            if (tree.getRoot()) {
                drawTree(tree.getRoot(), window.getSize().x / 2.f, 150.f, 180.f);
            }
            sf::Text backText(font, "ESC - exit", 20);
            backText.setPosition(sf::Vector2f(100.f, 100.f));
            backText.setFillColor(sf::Color::Yellow);
            window.draw(backText);
        }

        window.display();
    }
    return 0;
}