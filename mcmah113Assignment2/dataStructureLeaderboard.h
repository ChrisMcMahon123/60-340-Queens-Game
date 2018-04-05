#pragma once
using namespace System;
using namespace System::Data;

ref class dataStructureLeaderboard {
public:

	property String^ Rank;
	property String^ Name;
	property String^ Date;
	property String^ Queens;
	property String^ Time;
	property String^ Score;

	dataStructureLeaderboard(String^ rank, String^ name, String^ date, String^ numQueens, String^ time, String^ score) {
		this->Rank = rank;
		this->Name = name;
		this->Date = date;
		this->Queens = numQueens;
		this->Time = time;
		this->Score = score;
	}
};

