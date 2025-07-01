// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#pragma once

class Command;

class CommandManager
{
public:
	CommandManager();
	~CommandManager();

	bool Init();

	void Add(const std::string& cmdName,
		const std::string& commandStr,
		const std::string& type,
		const std::string& description);


private:
	bool LoadAllCommands();
	void SaveAllCommands();

	std::vector<Command*> m_v_commands;

	std::string m_path;

};