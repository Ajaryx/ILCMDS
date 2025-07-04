// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.


#pragma once

class Application
{
public:
	
	Application(const Application&) = delete;
	
	static Application& GetInstance()
	{
		static Application instance;
		return instance;
	}

	 void Run();

	 void drawUI(ftxui::Component& comp);
	 void BreakCurrentLoop();

	/*the entire app WILL be closed*/
	void FORCE_SHUTDOWN();
private:

	ftxui::ScreenInteractive m_Screen = ftxui::ScreenInteractive::TerminalOutput();

	Application();
	
};