objects = ssglib_gpio.o ssglib_pwm.o ssglib_timer0.o ssglib_timer1.o \
	ssglib_uart0.o ssglib_wdt.o

edit : $(objects)
	cc -o edit $(objects)
ssglib_gpio.o : ssglib_gpio.c N76E003.h
	cc -c ssglib_gpio.c
ssglib_pwm.o : ssglib_pwm.c N76E003.h
	cc -c ssglib_pwm.c
ssglib_timer0.o : ssglib_timer0.c N76E003.h
	cc -c ssglib_timer0.c
ssglib_timer1.o : ssglib_timer1.c N76E003.h
	cc -c ssglib_timer1.c
ssglib_uart0.o : ssglib_uart0.c N76E003.h
	cc -c ssglib_uart0.c
ssglib_wdt.o : ssglib_wdt.c N76E003.h
	cc -c ssglib_wdt.c
clean :
	rm edit $(objects)