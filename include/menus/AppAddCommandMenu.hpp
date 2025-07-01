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

	//build CMD Name | CMD commandStr | CMD TYPE | CMD description -input bar
	ftxui::Component BuildUserInputsLayout(
	ftxui::Component& container,
	ftxui::Component& NameBar,
	ftxui::Component& cmdStrBar,
	ftxui::Component& cmdType,
	ftxui::Component& cmdDescBar);

	
	void MakeInputBarOptions(
		ftxui::InputOption& NameOpt,
		ftxui::InputOption& cmdStrOpt,
		ftxui::InputOption& cmdTypeOpt,
		ftxui::InputOption& cmdDescBarOpt);

	ftxui::Component BuildBottomBtnsLayout(ftxui::Component& container, ftxui::Component& confirmBtn, ftxui::Component& backBtn);
	void MakeBtnOptions(ftxui::ButtonOption& confirmBtn, ftxui::ButtonOption& backBtn);

	std::string CMD_NameStr = "";
	std::string CMD_Str_Str = "";
	std::string CMD_TypeStr = "";
	std::string CMD_DescStr = "";

	const uint8_t maxCharacterLenght = 255;
};