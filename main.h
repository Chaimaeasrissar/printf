#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define FL_MINUS 1
#define FL_PLUS 2
#define FL_ZERO 4
#define FL_HASH 8
#define FL_SPACE 16

/* SIZES */
#define SI_LONG 2
#define SI_SHORT 1

/**
 * struct frmt - Struct op
 *
 * @frmt: The format.
 * @func: The function associated.
 */
struct frmt
{
	char frmt;
	int (*func)(va_list, char[], int, int, int, int);
};

/* Structs */
typedef struct custom_format
{
    char spec;
    int (*func)(va_list args_list, char output_buffer[]);
} custom_format_t;

int _printf(const char *format, ...);
int handle_print(const char *frmt, int *j,
va_list list_a, char buffer[], int flags, int width, int precision, int size);
int handle_flags(const char *format, int index, int *flags);
int handle_precision(const char *format, int index, int *precision);
int custom_printf(const char *format, ...);
int write_unsignd(int is_negative, int ind,
char buffer[],int flags, int width, int precision, int size);
int write_unsignd(int chars_printed, int j, char output_buffer[]);
/**
 * typedef struct frmt frmt_t - Struct op
 *
 * @frmt: The format.
 * @frm_t: The function associated.
 */
typedef struct frmt frmt_t;

int _printf(const char *format, ...);
int handle_print(const char *frmt, int *j,
va_list list_a, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_octal_lower(va_list args_list, char output_buffer[]);
int print_hexadecimal_lower(va_list args_list, char output_buffer[]);
int print_hexa_upper_lower(va_list args_list, char output_buffer[]);
int print_plus_flag(va_list args_list, char output_buffer[]);
int print_space_flag(va_list args_list, char output_buffer[]);
int print_hash_flag(va_list args_list, char output_buffer[]);
int print_rot13(va_list args_list, char output_buffer[]);
/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *j);
int get_width(const char *format, int *j, va_list list_a);
int get_precision(const char *format, int *j, va_list list_a);
int get_size(const char *format, int *j);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char cr, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char Pad, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char Pad, char extra_c, int Pad_start);

int write_unsignd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
