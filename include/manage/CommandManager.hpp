// This file is part of ILCMDS
// Copyright (c) 2025 Joel Fritsch (aka. Ajaryx)
// Licensed under the MIT License. See LICENSE file in the project root.

#pragma once

class Command;

constexpr const char* DEFAULT_DATA_FILE_NAME = "CMD_Data.json";

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
	bool SaveAllCommands();
	//Command save list
	bool CreateDataFile();
	bool IsDataFileEmpty(std::ifstream& file) const;

	std::vector<Command*> m_v_commands;

	std::string m_path;

};