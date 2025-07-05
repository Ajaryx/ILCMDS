// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.


#include "PCH.hpp"
#include "core/Application.hpp"

int main(int argc, char* argv[])
{
	Application::GetInstance().InitMenus();
	Application::GetInstance().Run();
	return 0;
}
