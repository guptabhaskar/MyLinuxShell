default: mkdir rm cat ls shell
	./shell

shell:
	gcc shell.c -o shell

ls:
	gcc ls.c -o ls 

date:
	gcc date.c -o date

cat: cat.c
	gcc cat.c -o cat

rm:
	gcc rm.c -o rm

mkdir:
	gcc mkdir.c -o mkdir

clean:
	rm shell mkdir ls date cat rm
