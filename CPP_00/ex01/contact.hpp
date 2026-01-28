#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <algorithm>

/*The contact fields are: first name, last name, nickname, phone number, and
darkest secret.*/
class Contact {
private:
	int			id;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string darkest_secret;
	bool		existing;

public:
	// constructors :
	Contact();
	~Contact();

	// setters :
	void		set_id(int id);
	void		set_first_name(std::string first_name);
	void		set_last_name(std::string last_name);
	void		set_nickname(std::string nickname);
	void		set_phone_number(std::string nickname);
	void		set_darkest_secret(std::string nickname);
	void		set_existing(bool existing);

	void		set_contact(std::string first_name,
				std::string last_name, std::string nickname,
				std::string phone_number, std::string darkest_secret);
	// getters :
	int			get_id(void);
	bool		get_existing(void);
	std::string	get_first_name(void);
	std::string	get_last_name(void);
	std::string	get_nickname(void);
	std::string	get_phone_number(void);
	std::string	get_darkest_secret(void);
};

#endif