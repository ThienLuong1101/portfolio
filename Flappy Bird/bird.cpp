#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
class Pipe
{
public:
    sf::RectangleShape top;
    sf::RectangleShape bottom;
    float speed;

    Pipe(float posX, float gapHeight, float width, float speed)
    {
        this->speed = speed;

        top.setSize(sf::Vector2f(width, gapHeight));
        top.setPosition(posX, 0);
        top.setFillColor(sf::Color::Green);

        bottom.setSize(sf::Vector2f(width, 600 - gapHeight - 200)); // Gap is 200 pixels tall
        bottom.setPosition(posX, gapHeight + 200); // Gap is 200 pixels from the top
        bottom.setFillColor(sf::Color::Green);
    }

    void move()
    {
        top.move(-speed, 0);
        bottom.move(-speed, 0);
    }
};

bool checkCollision(const sf::CircleShape& bird, const Pipe& pipe)
{
    // Check for collision between the bird and pipes
    if (bird.getGlobalBounds().intersects(pipe.top.getGlobalBounds()) ||
        bird.getGlobalBounds().intersects(pipe.bottom.getGlobalBounds()))
    {
        return true;
    }
    return false;
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Flappy Bird");
    window.getDefaultView();
 
    sf::CircleShape bird(18.f);
    bird.setFillColor(sf::Color::Yellow);

    // Bird position and vertical velocity
    sf::Vector2f position(200.f, 300.f);
    float velocity = 0.f;
    const float gravity = 0.1f;
    const float jumpStrength = -4.5f;

    // Pipe variables
    std::vector<Pipe> pipes;
    const float pipeWidth = 80.f;
    sf::Clock pipeSpawnClock;
    float pipeSpawnTimer = 2.f;

    const float pipeSpawnInterval = 1000.f; // milliseconds
    const float pipeSpeed = 2.f;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    bool gameActive = true; // Game state
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return 1;
    }
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(100);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(200.f, 200.f);

    int score = 0; // Score counter
    int highest_score = 0;
    

    sf::Text scoreText; // Text to display the score
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(20.f, 20.f);
    
    
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle spacebar for bird flap only when the game is active
            if (gameActive && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                velocity = jumpStrength;
            }

            // Restart the game on spacebar press when game over
            if (!gameActive && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                gameActive = true;
                pipes.clear();
                position = sf::Vector2f(200.f, 300.f);
                velocity = 0.f;
                gameOverText.setString("");
                if(score > highest_score){
                    highest_score = score;
                }
                score = 0; // Reset the score
                
            }
        }

        if (gameActive)
        {
            // Apply gravity to the bird's velocity
            velocity += gravity;

            // Update the bird's position
            position.y += velocity;
            bird.setPosition(position);

            // Keep the bird within the window bounds
            if (position.y < 0)
            {
                position.y = 0;
                velocity = 0;
            }
            else if (position.y > window.getSize().y - bird.getRadius() * 2)
            {
                position.y = window.getSize().y - bird.getRadius() * 2;
                velocity = 0;
            }

            // Check for collisions with pipes and update the score
            for (size_t i = 0; i < pipes.size(); ++i)
            {
                pipes[i].move();
                if (checkCollision(bird, pipes[i]))
                {
                    gameActive = false; // Bird hits a pipe, game over
                    gameOverText.setString("Game Over");
                    break;
                }
                
                
                // Bird passes a pipe, increment the score
                if (position.x == pipes[i].top.getPosition().x  && position.x == pipes[i].bottom.getPosition().x)
                {
                    pipes[i].top.setFillColor(sf::Color::Blue); // Mark the pipe as passed
                    pipes[i].bottom.setFillColor(sf::Color::Blue); // Mark the pipe as passed
                    score++;
                }
                
                
            
                else if (highest_score - score == 2 && highest_score != 0 && (pipes[i].bottom.getPosition().x - position.x == 550 && pipes[i].top.getPosition().x - position.x == 550))
                {   
                    pipes[i].top.setFillColor(sf::Color::Yellow); // Mark the pipe as passed
                    pipes[i].bottom.setFillColor(sf::Color::Yellow); // Mark the pipe as passed
                }
                
                
                
                // Remove off-screen pipes
                if (pipes[i].top.getPosition().x + pipeWidth < 0)
                {
                    pipes.erase(pipes.begin() + i);
                    --i;
                }
            }

            // Spawn pipes
            pipeSpawnTimer += pipeSpawnClock.restart().asMilliseconds();
            if (pipeSpawnTimer >= pipeSpawnInterval)
            {
                float gapHeight = 100.f + std::rand() % 300; // Random gap height
                Pipe pipe(800.f, gapHeight, pipeWidth, pipeSpeed);
                pipes.push_back(pipe);
                pipeSpawnTimer = 0.f;
            }
        }

        // Update the score text
        scoreText.setString("Score: " + std::to_string(score) + "\nHighest: " + std::to_string(highest_score));


        // Clear, draw, and display
        window.clear();
        for (size_t i = 0; i < pipes.size(); ++i)
        {    
            
            
            window.draw(pipes[i].top);
            window.draw(pipes[i].bottom);
        
        }
        window.draw(bird);

        // Display game over text when the game is over
        if (!gameActive)
        {
            window.draw(gameOverText);
        }
        

        // Display the score
        window.draw(scoreText);

        window.display();
    }

    return 0;
}
