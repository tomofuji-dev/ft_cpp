#include "Harl.hpp"
#include <iostream>

#define R	"\033[1;31m"
#define Y	"\033[1;33m"
#define E	"\033[00m"

#define MSG_DEBUG	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#define MSG_INFO	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define MSG_WARN	"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define MSG_ERR		"This is unacceptable! I want to speak to the manager now."
#define USAGE		"Probably complaining about insignificant problems. Enter level: {'DEBUG', 'INFO', 'WARNING', 'ERROR'}"

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::debug() {
	std::cout << Y << "[debug]\n" << E << MSG_DEBUG << std::endl;
}

void	Harl::info() {
	std::cout << Y << "[info]\n" << E << MSG_INFO << std::endl;
}

void	Harl::warning() {
	std::cout << Y << "[warning]\n" << E << MSG_WARN << std::endl;
}

void	Harl::error() {
	std::cout << Y << "[error]\n" << E << MSG_ERR << std::endl;
}

void	Harl::usage() {
	std::cout << R << "[usage]\n" << USAGE << E << std::endl;
}

void	Harl::complain(std::string level) {
	const std::string levelName[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::usage };
	
	size_t	level_i = 0;
	for (; level_i < 4 && level != levelName[level_i]; level_i++);
	(this->*f[level_i])();
}

void	Harl::filter(std::string level) {
	const std::string levelName[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	size_t	level_i = 0;
	for (; level_i < 4 && level != levelName[level_i]; level_i++);

	switch(level_i) {
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
			Harl::error();
			break;
		default:
			Harl::usage();
	}
	return ;
}
