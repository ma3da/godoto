#include "Root.h"

using namespace godot;


void Root::_register_methods() {
	register_method((char*)"_input", &Root::_input);
	register_method((char*)"_ready", &Root::_ready);
}

void Root::_init() {}
Root::Root() {}
Root::~Root() {}

void Root::_input(const Ref<InputEvent> &p_event) {
	Ref<InputEventKey> key = p_event;
    if (key.is_valid()) {
        if (key->is_action_pressed("quit")) {
			get_tree()->quit();
		}
	}
}

void Root::_ready() {
}
