// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#pragma once
#include "menus/AppMenu.hpp"


class AppAddCommandMenu : public AppMenu
{
public:
	AppAddCommandMenu(class Application* const app);
	~AppAddCommandMenu();
private:

	// Inherited via AppMenu
	void BuildAndRun() override;
};