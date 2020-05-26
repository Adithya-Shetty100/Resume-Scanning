a.out:resume_ser.o resume_cl.o
	gcc resume_ser.o resume_cl.o
resume_cl.o:resume_cl.c resume.h
	gcc -c resume_cl.c
resume_ser.o:resume_ser.c resume.h
	gcc -c resume_ser.c
