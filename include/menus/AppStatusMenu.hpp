// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.


#pragma once
#include "menus/AppMenu.hpp"

struct AppStatusMenuLayoutOption
{
	static AppStatusMenuLayoutOption Info(const std::string& headline,
		const std::string& description,
		const std::string& btnText);

	static AppStatusMenuLayoutOption Warning(const std::string& headline,
		const std::string& description,
		const std::string& btnText);

	static AppStatusMenuLayoutOption FatalError(const std::string& headline,
		const std::string& description,
		const std::string& btnText,
		std::function<void()> on_click);
	static AppStatusMenuLayoutOption Choose();

};


class AppStatusMenu : public AppMenu
{
public:
	AppStatusMenu(Application* const app, const AppStatusMenuLayoutOption& layoutOption);
	~AppStatusMenu();

private:
	void BuildAndRun() override;

	AppStatusMenuLayoutOption m_Option;

};