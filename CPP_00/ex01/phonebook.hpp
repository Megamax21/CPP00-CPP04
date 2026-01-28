#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
private:
	Contact	contacts[8];

public:
	// Constructor
	PhoneBook();

	int			phone_book_loop(void);
	int			search_loop(void);
	int			get_prompt_value(std::string prompt);
	int			get_free_id(void);
	int			check_if_contact(void);
	void		renew_contacts(void);
	void		fill_contact(void);
	int			show_list(void);
	int			present_contact(int id);
	int			is_digit(std::string str);
	std::string	get_short_str(std::string s);
};

#endif