#include "main.h"

/**
 * _printf - Function that produces output
 * according to format.
 *
 * @format: pointer to format string.
 *
 * Description: Function takes a format string
 * [format] and variable number of args using
 * [va_list] and [va_start] macros.
 *
 * Return: total number of outputed chars.
 *
 */

int _printf(const char *format, ...)
{
	int output_chars = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
					char c = va_arg(args, int);

					_putchar(c);
					output_chars++;
					break;
					}
				case 's':
					{
					char *str = va_arg(args, char *);
					int itr;

					while (str[itr])
					{
						_putchar(str[itr]);
						output_chars++;
						itr++;
					}
					break;
					}
				case '%':
					{
					_putchar('%');
					output_chars++;
					break;
					}
				default:
					_putchar(*format);
					output_chars++;
					break;
			}
		}
		else
		{
			_putchar(*format);
			output_chars++;
		}
		format++;
	}
	va_end(args);
	return (output_chars);
}
