// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.


#pragma once

class Application
{
public:
	Application();
	~Application();


	void Run();
	void drawUI(ftxui::Component& comp);
	void BreakCurrentLoop();
private:

	ftxui::ScreenInteractive m_Screen;
	
};