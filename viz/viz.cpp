#include <SFML/Graphics.hpp>
#include <optional> // Необходим для std::optional

int main()
{
    // Инициализация VideoMode уже корректна для SFML 3.0.0
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Window");

    while (window.isOpen())
    {
        // Новый способ обработки событий в SFML 3.0.0
        std::optional<sf::Event> optEvent;
        while (optEvent = window.pollEvent()) // pollEvent() теперь не принимает аргументов и возвращает std::optional
        {
            sf::Event event = *optEvent; // Извлекаем событие из std::optional

            // Проверка типа события с использованием event.is<>()
            if (event.is<sf::Event::Closed>())
            {
                window.close();
            }
            // Сюда можно добавить обработку других событий, например:
            /*
            else if (auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                }
            }
            */
        }

        window.clear(); // Очищаем окно (по умолчанию черным цветом)
        // Здесь будет ваш код для отрисовки объектов
        window.display();
    }

    return 0;
}