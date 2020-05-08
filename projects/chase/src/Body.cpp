#include <core/Godot.hpp>
#include "Body.h"

using namespace godot;

void Agent::_register_methods() {
	register_method((char*)"_process", &Agent::_process);
	register_method((char*)"_input", &Agent::_input);
}

void Agent::_init() {}

Agent::Agent() {}

Agent::~Agent() {}

void Agent::_process(float delta) 
{
	UpdateMotionFromInput();
	move_and_slide(motion);
}

void Agent::UpdateMotionFromInput() 
{
	Vector2 direction = Vector2(0, 0);

	Input* i = Input::get_singleton();
	
	if (i->is_action_pressed("ui_up"))
		direction.y -= 1;
	if (i->is_action_pressed("ui_down"))
		direction.y += 1;
	if (i->is_action_pressed("ui_left"))
		direction.x -= 1;
	if (i->is_action_pressed("ui_right"))
		direction.x += 1;

    motion = speed * direction.normalized();
    if (dash) {
        motion *= 100;
        dash = false;
    }
}

void Agent::_input(const Ref<InputEvent> &p_event) {
	Ref<InputEventKey> key = p_event;
    if (key.is_valid()) {
        if (key->is_action_pressed("dash")) {
            dash = true;
        }
    }
}

void Devil::_register_methods() {
	register_method((char*)"_process", &Devil::_process);
	register_method((char*)"_draw", &Devil::_draw);
}

void Devil::_init() {
    motion = speed * Vector2(dis(gen), dis(gen)).normalized();
    dis = std::uniform_real_distribution<>(-1, 1);
}

Devil::Devil() {}

Devil::~Devil() {}

void Devil::_draw() {
    draw_circle(Vector2(0, 0), radius, vision_color);
}

void Devil::_process(float delta) {
    timer += delta;
    Vector2 pos = this->get_position();
    if (timer > 1) {
        Node2D* p_agent = Object::cast_to<Node2D>(get_node("/root/Main/Agent"));
        Vector2 target_pos;
        if (p_agent) {
            Vector2 agent_pos = p_agent->get_position();
            if (agent_pos.distance_squared_to(pos) < radius * radius ) {
                target_pos = agent_pos;
            }
            else {
                target_pos = pos + Vector2(dis(gen), dis(gen));
            }
        }
        else {
            target_pos = pos + Vector2(dis(gen), dis(gen));
        }
        motion = speed * (target_pos - pos).normalized();
        timer = 0;
    }
    move_and_slide(motion);
    update();
}
