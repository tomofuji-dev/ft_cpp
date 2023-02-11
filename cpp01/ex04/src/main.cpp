/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:16:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2023/02/11 13:03:06 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define SUCCESS 	0
#define FAILURE 	1

#define N_ARGS 		4
#define FNAME		1
#define DEST		2
#define SRC			3

#define USAGE		"usage: ./exe <fname> <query> <to_str>"
#define ERR_ARGC	"invalid argc"
#define ERR_QUERY	"query must not be empty"
#define ERR_OPEN	"cannot open file"

#define TEXT_RED	"\033[1;31m"
#define TEXT_YELLOW	"\033[1;33m"

std::string	read_file(const std::string fname) {
	std::ifstream is(fname);
	if (!is) {
		throw std::string(ERR_OPEN);
	}
	std::stringstream ss;
	ss << is.rdbuf();
	return ss.str();
}

void	query_to_str(std::string& src_content, \
					const std::string query, \
					const std::string to_str) {
	std::string::size_type pos = src_content.find(query);
	while (pos != std::string::npos) {
		src_content.erase(pos, query.length());
		src_content.insert(pos, to_str);
		pos = src_content.find(query, pos + to_str.length());
	}
	return ;
}

void	write_file(const std::string fname, const std::string src_content) {
	std::ofstream of(fname + ".replace");
	if (!of) {
		throw std::string(ERR_OPEN);
	}
	of << src_content;
	return ;
}

void	replace(const std::string fname, \
				const std::string query, \
				const std::string to_str) {
	std::string src_content = read_file(fname);
	query_to_str(src_content, query, to_str);
	write_file(fname, src_content);
	return ;
}

int main(int argc, char *argv[]) {
	try {
		if (argc != N_ARGS) {
			std::cout << TEXT_YELLOW << USAGE << TEXT_YELLOW << std::endl;
			throw std::string(ERR_ARGC);
		}
		const std::string fname(argv[FNAME]);
		const std::string query(argv[DEST]);
		const std::string to_str(argv[SRC]);
		if (query.empty()) {
			throw std::string(ERR_QUERY);
		}
		replace(fname, query, to_str);
		return SUCCESS;
	}
	catch (const std::string& e) {
		std::cerr << TEXT_RED <<  e << TEXT_RED << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << TEXT_RED << e.what() << TEXT_RED << std::endl;
	}
	return FAILURE;
}