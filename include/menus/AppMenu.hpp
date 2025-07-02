// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#pragma once

class Application;

class AppMenu abstract
{
public:

	AppMenu(Application* const app);
	virtual ~AppMenu();
	virtual void BuildAndRun() = 0;

protected:
	
	inline static Application* const GetApplication()
	{
		return m_app;
	}

private:

	 inline static Application* m_app;
	
};