#pragma once
#include "Timestep.h"
#include "Events/Event.h"

class Layer
{
public:
	virtual ~Layer() {};
	virtual void onAttach() = 0;
	virtual void onDetach() = 0;
	virtual void onUpdate(Timestep ts) = 0;
	virtual void onEvent(Event& e) = 0;
};