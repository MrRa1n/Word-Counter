build:
	cl /Fe:wordcount.exe wordcount.c readfile.c tokenize.c count.c sort.c
	del *.obj

single-file-to-console:
	wordcount -i single_words_test.txt
sentences-file-to-console:
	wordcount -i sentences_test.txt
single-file-to-file:
	wordcount -i single_words_test.txt -o single_words_count.txt
sentences-file-to-file:
	wordcount -i sentences_test.txt -o sentences_word_count.txt
console-to-console:
	wordcount
console-to-file:
	wordcount -o console_to_file.txt
# Run commands for ignoring character case
single-file-to-console-c:
	wordcount -i single_words_test.txt -c
sentences-file-to-console-c:
	wordcount -i sentences_test.txt -c
single-file-to-file-c:
	wordcount -i single_words_test.txt -o single_words_count.txt -c
sentences-file-to-file-c:
	wordcount -i sentences_test.txt -o sentences_word_count.txt -c
console-to-console-c:
	wordcount -c
console-to-file-c:
	wordcount -o console_to_file.txt -c

clean:
	del *.exe
	del *.obj