#pragma once
#include <Godot.hpp>
#include <Node2D.hpp>
#include <InputEvent.hpp>
#include <InputEventKey.hpp>
#include <SceneTree.hpp>

namespace godot {
	class Root : public Node2D {
		GODOT_CLASS(Root, Node2D)
	public:
		static void _register_methods();
		void _init();
		void _ready();

		Root();
		~Root();

		void _input(const Ref<InputEvent> &p_event);
	};
}

