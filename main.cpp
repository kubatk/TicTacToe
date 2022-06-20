#include <SFML/Graphics.hpp>
#include <iostream>
#include "classes/Game.h"
#include "classes/Menu.h"


int main()
{

/* MENU */

    //Build window
    sf::RenderWindow menu(sf::VideoMode(650, 900), "Projekt CPP", sf::Style::Close | sf::Style::Titlebar);

    //Init menu
    Menu main_menu;


    while (menu.isOpen())
    {

        //Check if game started
        if (main_menu.is_start_pressed()) {
            menu.close();
        }

        sf::Event event;
        while (menu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                menu.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                main_menu.action(menu);
            }
        }

        menu.clear(sf::Color::White);

        //render objects
        main_menu.draw(menu);

        menu.display();
    }

/* GAME */

    if (!main_menu.is_start_pressed()) {
        return 0;
    }

    //Build window
    sf::RenderWindow window(sf::VideoMode(650, 900), "Projekt CPP", sf::Style::Close | sf::Style::Titlebar);
    
    //Load fonts
    sf::Font comici;
    comici.loadFromFile("fonts/comici.ttf");

    //Load header
    sf::Text header;
    header.setCharacterSize(40);
    header.setFillColor(sf::Color::Black);
    header.setStyle(sf::Text::Bold);
    header.setFont(comici);
    header.setString("Kolej na gracza:");
    header.setPosition({ 50, 80 });

    //Load X and O textures
    sf::Texture sign_x, sign_o;
    sign_x.loadFromFile("images/x.png");
    sign_o.loadFromFile("images/o.png");

    //Round indicator
    sf::RectangleShape round_sign;
    round_sign.setSize({ 80, 80 });
    round_sign.setPosition({ 380, 70 });
    round_sign.setTexture(&sign_o);


    //Init Game object
    int size = main_menu.get_size();
    int win = main_menu.get_win();
    int difficulty = main_menu.get_difficulty();
    bool is_ai = main_menu.get_players_count() == 1 ? true : false;
    Game gra(size, win, is_ai);
    char current_sign = 'o';
    bool game_finished = false;
    Player* current_player = gra.get_player_by_sign(current_sign);
    Field* ai_movement;


    //Main loop
    while (window.isOpen())
    {
        //Check if win or full
        if (gra.look_for_win() || gra.get_board()->is_full()) {
            game_finished = true;
            if (gra.look_for_win()) {
                header.setString("Wygrana gracza: ");
                if (gra.get_winner()->get_symbol() == 'o') round_sign.setTexture(&sign_o);
                else round_sign.setTexture(&sign_x);
            }
            else {
                header.setString("Gra zakonczona remisem");
                round_sign.setTexture(NULL);
                round_sign.setFillColor(sf::Color(0, 0, 0, 0));
            }
        }

        //Event handler
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //Mouse click
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left && !current_player->is_ai())
                {
                    //Get clicked field
                    Field *clicked = gra.get_board()->get_clicked_field(window);

                    
                    if (clicked != nullptr) {
                        std::cout << "Pole: " << clicked->get_x() << ", " << clicked->get_y() << " | ";

                        //Change owner
                        if (clicked->get_owner() == nullptr && !game_finished) {
                            std::cout << "Zmieniam wlasciciela.";
                            gra.set_field_owner(clicked->get_x(), clicked->get_y(), current_sign);
                            if (current_sign == 'x') {
                                current_sign = 'o';
                                round_sign.setTexture(&sign_o);
                            } 
                            else {
                                current_sign = 'x';
                                round_sign.setTexture(&sign_x);
                            }
                            current_player = gra.get_player_by_sign(current_sign);

                            
                        }
                        std::cout << std::endl;
                        continue;
                    }
                }
            }
            
        }
        //AI move
        if (current_player->is_ai() && !gra.get_board()->is_full()) {
            std::cout << "Inicjuje ruch AI - ";

            if (difficulty == 1) {
                ai_movement = gra.random_empty_field();
                if (ai_movement != nullptr) {
                    std::cout << "Wylosowane pole: (" << ai_movement->get_x() << ", " << ai_movement->get_y() << ")" << std::endl;
                    gra.set_field_owner(ai_movement->get_x(), ai_movement->get_y(), current_sign);
                    if (current_sign == 'x') {
                        current_sign = 'o';
                        round_sign.setTexture(&sign_o);
                    }
                    else {
                        current_sign = 'x';
                        round_sign.setTexture(&sign_x);
                    }
                    current_player = gra.get_player_by_sign(current_sign);
                }
            }
            else {
                ai_movement = gra.get_ai_move(difficulty);
                if (ai_movement != nullptr) {
                    std::cout << "Wybrane pole: (" << ai_movement->get_x() << ", " << ai_movement->get_y() << ")" << std::endl;
                    gra.set_field_owner(ai_movement->get_x(), ai_movement->get_y(), current_sign);
                    if (current_sign == 'x') {
                        current_sign = 'o';
                        round_sign.setTexture(&sign_o);
                    }
                    else {
                        current_sign = 'x';
                        round_sign.setTexture(&sign_x);
                    }
                    current_player = gra.get_player_by_sign(current_sign);
                }
            }
            
            
            std::cout << std::endl;
            continue;
        }

        
        //render windows elements
        window.clear(sf::Color::White);
        window.draw(header);
        window.draw(round_sign);

        gra.get_board()->draw_grid(window);

        window.display();
    }

    return 0;
}

