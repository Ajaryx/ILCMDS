// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#pragma once

class Application;

class AppMenu abstract
{
public:

	AppMenu();
	virtual ~AppMenu();
	virtual void Build() = 0;
	inline ftxui::Component GetLayout() const
	{
		return MenuLayout;
	}

protected:
	ftxui::Component MenuLayout;

private:

	
	
};