//
// Created by sarah on 8/10/22.
//
#include <iostream>
#include "Calculator.h"

void Calculator::create_numbers() {
    int button_count = 0;
    for (auto button : button_numbers)
    {
        NumberButton temp(GAP_WIDTH + (button_count % 3 * (BUTTON_SIZE + GAP_WIDTH)),
                    SCREEN_SIZE + (BUTTON_SIZE + GAP_HEIGHT) * (button_count / 3),
                    button);
        num_buttons.push_back(temp);
        ++button_count;
    }
}

void Calculator::create_operators() {
    int button_count = 0;
    for (auto button : button_operators)
    {
        OperatorButton temp (WIDTH - GAP_WIDTH - BUTTON_SIZE, SCREEN_SIZE + (BUTTON_SIZE + GAP_HEIGHT) * button_count, button);
        op_buttons.push_back(temp);
        ++button_count;
    }
}

void Calculator::draw_buttons() {
    for (auto button : num_buttons)
    {
        button.draw();
    }

    for (auto button : op_buttons)
    {
        button.draw();
    }
    equal.draw();
    DrawText( number_string.c_str(), WIDTH - MeasureText(number_string.c_str(), 30) - GAP_WIDTH, GAP_HEIGHT, 30, GREEN);
}

void Calculator::check_input() {
    for (auto button : num_buttons)
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(),button.get_rect()))
        {
            // button.click(number_string);
            button.click(calc, calc_screen, current_mode);
        }
    }

    for (auto button : op_buttons)
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(),button.get_rect()))
        {
            button.click(number_string);
        }
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(),equal.get_rect()))
    {
        equal.click(number_string);
    }
}

void Calculator::draw_screen() {
    calc_screen.draw();
}