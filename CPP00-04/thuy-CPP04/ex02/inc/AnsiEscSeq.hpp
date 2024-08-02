#ifndef ANSI_HPP
#define ANSI_HPP


# define RESET 		"\033[m"

//TEXT FORMATTING***************************************
# define BOLD 		"\033[1m"
# define DIM 		"\033[2m"
# define ITALIC 	"\033[3m"
# define UNDERLINE 	"\033[4m" 
# define INVERSE	"\033[7m" 
# define STRIKE		"\033[8m" 
# define CROSSED	"\033[9m" 


//TEXT COLORS******************************************
# define BLACK		"\033[30m" 
# define RED		"\033[31m" 
# define GREEN		"\033[32m" 
# define YELLOW		"\033[33m" 
# define BLUE		"\033[34m" 
# define MAGENTA	"\033[35m" 
# define CYAN		"\033[36m"
# define WHITE		"\033[37m" 


//BRIGHT TEXT COLORS***********************************
#define BLACK_BRT    "\033[90m"
#define RED_BRT      "\033[91m"
#define GREEN_BRT    "\033[92m"
#define YELLOW_BRT   "\033[93m"
#define BLUE_BRT     "\033[94m"
#define MAGENTA_BRT  "\033[95m"
#define CYAN_BRT     "\033[96m"
#define WHITE_BRT    "\033[97m"


//BOLD AND BRIGHT TEXT COLORS**************************
# define BLACK_BB	"\033[1;30m"  
# define RED_BB		"\033[1;31m" 
# define GREEN_BB	"\033[1;32m"
# define YELLOW_BB	"\033[1;33m" 
# define BLUE_BB	"\033[1;34m" 
# define MAGENTA_BB	"\033[1;35m"  
# define CYAN_BB	"\033[1;36m" 
# define WHITE_BB	"\033[1;37m"


#endif