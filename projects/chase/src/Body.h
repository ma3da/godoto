#pragma once

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>
#include <InputEvent.hpp>
#include <InputEventKey.hpp>
#include <random>
#include "Root.h"

namespace godot {
	class Agent : public KinematicBody2D 
	{
	
	// Godot structure
	private:
		GODOT_CLASS(Agent, KinematicBody2D)
	public:
		static void _register_methods();
		void _init();
		void _process(float delta);
        void _input(const Ref<InputEvent> &p_event);

	public:
		Agent();
		~Agent();

		const int speed = 100;
        bool dash = false;

		void UpdateMotionFromInput();

	private:
		Vector2 motion;
	};

    class Devil: public KinematicBody2D {
	// Godot structure
	private:
		GODOT_CLASS(Devil, KinematicBody2D)
	public:
		static void _register_methods();
		void _init();
		void _process(float delta);
        void _draw();

    public:
        Devil();
        ~Devil();

        int speed = 100;
    private:
        Vector2 motion;
        float timer = 0;
        float radius = 128;
        Color vision_color = Color(1, 1, 1, .5);

        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis;

    };
}
