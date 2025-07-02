// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.


#pragma once
#include "menus/AppMenu.hpp"

struct AppStatusMenuLayoutBuilder
{
	static AppStatusMenuLayoutBuilder Info(const std::string& headline,
		const std::string& description,
		std::function<void()> on_click = []() {});

	static AppStatusMenuLayoutBuilder Warning(const std::string& headline,
		const std::string& description,
		std::function<void()> on_click = []() {});

	static AppStatusMenuLayoutBuilder FatalError(const std::string& headline,
		const std::string& description,
		std::function<void()> on_click = []() {});

	static AppStatusMenuLayoutBuilder Choose(const std::string& headline,
		const std::string& description,
		std::function<void()> on_click_Yes = [](){},
		std::function<void()> on_click_No = [](){});

	std::string headline;
	std::string description;


	ftxui::Component layout = ftxui::Component();


};


class AppStatusMenu : public AppMenu
{
public:
	AppStatusMenu(Application* const app, const AppStatusMenuLayoutBuilder& layoutOption);
	~AppStatusMenu();



private:
	void BuildAndRun() override;

	AppStatusMenuLayoutBuilder m_Option;

};