#pragma once
#include "Button.h"


class Menu {
private:
    //Elementy okna
    Textarea* title;
    Textarea* choose_mode;
    Button* one_player;
    Button* two_players;
    Textarea* choose_difficulty;
    Button* easy;
    Button* normal;
    Button* hard;
    Textarea* choose_size;
    Button* size_m;
    Button* size_i;
    Button* size_p;
    Textarea* choose_win;
    Button* win_m;
    Button* win_i;
    Button* win_p;
    Button* start;

    //Ustawienia
    int players_count = 1;
    int difficulty = 1;
    int size = 3;
    int win = 3;

    bool start_pressed = false;

public:
    Menu() {
        //Elementy okna
        title = new Textarea({ 0,50 }, 50, "Gra w kolko i krzyzyk");
        title->center();

        choose_mode = new Textarea({ 0,140 }, 30, "Wybierz tryb:");
        choose_mode->center();
        one_player = new Button({ 164, 195 }, { 150, 50 });
        one_player->set_border(3, sf::Color::Black);
        one_player->set_display_text("1 Gracz", 25);
        two_players = new Button({ 324, 195 }, { 150, 50 });
        two_players->set_border(3, sf::Color::Black);
        two_players->set_display_text("2 Graczy", 25);

        choose_difficulty = new Textarea({ 0, 260 }, 30, "Wybierz poziom trudnosci:");
        choose_difficulty->center();
        easy = new Button({ 100, 310 }, { 150, 50 });
        easy->set_border(3, sf::Color::Black);
        easy->set_display_text("Latwy", 25);
        normal = new Button({ 260, 310 }, { 150, 50 });
        normal->set_border(3, sf::Color::Black);
        normal->set_display_text("Normalny", 25);
        normal->set_color(176, 176, 176);
        hard = new Button({ 420, 310 }, { 150, 50 });
        hard->set_border(3, sf::Color::Black);
        hard->set_display_text("Trudny", 25);
        hard->set_color(176, 176, 176);

        choose_size = new Textarea({ 50, 390 }, 30, "Wybierz rozmiar planszy:");
        size_m = new Button({ 430, 385 }, { 50, 50 });
        size_m->set_border(3, sf::Color::Black);
        size_m->set_texture("images/minus.png");
        size_i = new Button({ 480, 385 }, { 80, 50 });
        size_i->set_border(3, sf::Color::Black);
        size_i->set_display_text(std::to_string(size), 30);
        size_p = new Button({ 560, 385 }, { 50, 50 });
        size_p->set_border(3, sf::Color::Black);
        size_p->set_texture("images/plus.png");


        choose_win = new Textarea({ 50, 460 }, 30, "Ile symboli zeby wygrac:");
        win_m = new Button({ 430, 455 }, { 50, 50 });
        win_m->set_border(3, sf::Color::Black);
        win_m->set_texture("images/minus.png");
        win_i = new Button({ 480, 455 }, { 80, 50 });
        win_i->set_border(3, sf::Color::Black);
        win_i->set_display_text(std::to_string(win), 30);
        win_p = new Button({ 560, 455 }, { 50, 50 });
        win_p->set_border(3, sf::Color::Black);
        win_p->set_texture("images/plus.png");

        start = new Button({ 120, 650 }, { 400, 100 });
        start->set_border(5, sf::Color(3, 163, 22));
        start->set_color(59, 255, 82);
        start->set_display_text("Rozpocznij gre", 50);
    }

    ~Menu() {
        delete title;
        delete choose_mode;
        delete one_player;
        delete two_players;
        delete choose_difficulty;
        delete easy;
        delete normal;
        delete hard;
        delete choose_size;
        delete size_m;
        delete size_i;
        delete size_p;
        delete choose_win;
        delete win_m;
        delete win_i;
        delete win_p;
        delete start;
    }

    void draw(sf::RenderWindow& menu) {

        one_player->set_color(255, 255, 255);
        two_players->set_color(255, 255, 255);
        if (players_count == 1)
            one_player->set_color(91, 240, 109);
        else if (players_count == 2)
            two_players->set_color(91, 240, 109);

        easy->set_color(255, 255, 255);
        normal->set_color(255, 255, 255);
        hard->set_color(255, 255, 255);
        if (difficulty == 1)
            easy->set_color(91, 240, 109);
        if (difficulty == 2)
            normal->set_color(91, 240, 109);
        if (difficulty == 3)
            hard->set_color(91, 240, 109);

        size_i->set_display_text(std::to_string(size), 30);
        win_i->set_display_text(std::to_string(win), 30);


        title->draw_text(menu);

        choose_mode->draw_text(menu);
        one_player->draw_button(menu);
        two_players->draw_button(menu);

        if (players_count == 1) {
            choose_difficulty->draw_text(menu);
            easy->draw_button(menu);
            normal->draw_button(menu);
            hard->draw_button(menu);
        }

        choose_size->draw_text(menu);
        size_m->draw_button(menu);
        size_i->draw_button(menu);
        size_p->draw_button(menu);

        choose_win->draw_text(menu);
        win_m->draw_button(menu);
        win_i->draw_button(menu);
        win_p->draw_button(menu);
        start->draw_button(menu);
    }

    void action(sf::RenderWindow &window) {
        //Wybór graczy
        if (one_player->isMouseOver(window)) {
            players_count = 1;
        }
        if (two_players->isMouseOver(window)) {
            players_count = 2;
        }

        //Wybór poziomu trudnoœci
        if (easy->isMouseOver(window)) {
            difficulty = 1;
        }
        if (normal->isMouseOver(window)) {
            difficulty = 2;
        }
        if (hard->isMouseOver(window)) {
            difficulty = 3;
        }

        //Wybór rozmiaru planszy
        if (size_m->isMouseOver(window)) {
            if (size > 3) size--;
            if (win > size) win = size;
        }
        if (size_p->isMouseOver(window)) {
            if (size < 10) size++;
        }

        //Wybór wygranej
        if (win_m->isMouseOver(window)) {
            if (win > 3) win--;
        }
        if (win_p->isMouseOver(window)) {
            if (win < size) win++;
        }

        //start gry
        if (start->isMouseOver(window)) {
            start_pressed = true;
        }


    }
    int get_players_count() {
        return players_count;
    }
    int get_difficulty() {
        return difficulty;
    }
    int get_size() {
        return size;
    }
    int get_win() {
        return win;
    }

    bool is_start_pressed() {
        return start_pressed;
    }
};